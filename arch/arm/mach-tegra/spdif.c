/*
 * arch/arm/mach-tegra/spdif.c
 *
 * S/PDIF audio driver
 *
 * Copyright (c) 2011, NVIDIA Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/err.h>
#include <linux/clk.h>
#include <linux/slab.h>
#include <mach/iomap.h>
#include <mach/spdif.h>
#include <mach/dma.h>
#include <mach/audio.h>
#include <mach/dma.h>
#include <mach/audio_switch.h>

#define ENABLE_SPDIF_DEBUG_PRINT	0
#if  ENABLE_SPDIF_DEBUG_PRINT
#define SPDIF_DEBUG_PRINT(fmt, arg...)  printk(fmt, ## arg)
#else
#define SPDIF_DEBUG_PRINT(fmt, arg...) do {} while (0)
#endif

/*FIXME: spdifin clocks for slave are not supported yet */

struct spdif_controller_info {

	struct tegra_spdif_device_context spdev[AUDIO_FIFO_CNT];
	struct tegra_spdif_clk_info spclk;

	unsigned long	base;
	phys_addr_t 	phy_base;
	int 		refcnt;
	void*		reg_cache;
};

static struct spdif_controller_info *spinfo = NULL;

void spdif_save_regs(unsigned long base);
void spdif_restore_regs(unsigned long base);

static inline void spdif_writel(unsigned long base, u32 val, u32 reg)
{
	SPDIF_DEBUG_PRINT("Spdif Write 0x%lx : %08x\n",base + reg, val);
	writel(val, base + reg);
}

static inline u32 spdif_readl(unsigned long base, u32 reg)
{
	u32 val = readl(base + reg);
	SPDIF_DEBUG_PRINT("Spdif Read 0x%lx : %08x\n",base + reg, val);
	return val;
}

int spdif_clock_set_rate(int ifc, int mode, int rate)
{
	spinfo->spdev[mode].ch_prop.clk_rate = rate;

	/* FIXME: stop clock before change if needed */
	if (mode == AUDIO_TX_MODE)
		clk_set_rate(spinfo->spclk.spdifout_clk, rate);
	else
		clk_set_rate(spinfo->spclk.spdifin_clk, rate);

	return 0;
}

int spdif_set_bit_mode(int ifc, unsigned mode)
{
	unsigned long base = spinfo->base;
	u32 val = spdif_readl(base, SPDIF_CTRL_0);
	val &= ~SPDIF_CTRL_0_BIT_MODE_MASK;

	if (mode > SPDIF_BIT_MODE_MODERAW) {
		pr_err("%s: invalid bit_size selector %d\n", __func__,
			mode);
		return -EINVAL;
	}

	val |= mode << SPDIF_CTRL_0_BIT_MODE_SHIFT;

	spdif_writel(base, val, SPDIF_CTRL_0);
	return 0;
}

int spdif_set_sample_rate(int ifc, int fifo_mode, unsigned int sample_rate)
{
	unsigned int rate = 0;
	unsigned long base = spinfo->base;

	unsigned int ch_sta[] = {
		0x0, /* 44.1, default values */
		0x0,
		0x0,
		0x0,
		0x0,
		0x0,
	};

	switch (sample_rate) {
	case 32000:
		ch_sta[0] = 0x3 << 24;
		ch_sta[1] = 0xC << 4;
		break;
	case 44100:
		ch_sta[0] = 0x0;
		ch_sta[1] = 0xF << 4;
		break;
	case 48000:
		ch_sta[0] = 0x2 << 24;
		ch_sta[1] = 0xD << 4;
		break;
	case 88200:
	case 96000:
	case 176400:
	case 192000:
		break;
	default:
		return -1;
	}

	spdif_writel(base, ch_sta[0], SPDIF_CH_STA_TX_A_0);
	spdif_writel(base, ch_sta[1], SPDIF_CH_STA_TX_B_0);
	spdif_writel(base, ch_sta[2], SPDIF_CH_STA_TX_C_0);
	spdif_writel(base, ch_sta[3], SPDIF_CH_STA_TX_D_0);
	spdif_writel(base, ch_sta[4], SPDIF_CH_STA_TX_E_0);
	spdif_writel(base, ch_sta[5], SPDIF_CH_STA_TX_F_0);

	rate = sample_rate << 7; /* sr*128 */
	spdif_clock_set_rate(0, fifo_mode, rate);

	return 0;
}

u32 spdif_get_control(int ifc)
{
	return spdif_readl(spinfo->base, SPDIF_CTRL_0);
}

int spdif_close(int ifc)
{
	SPDIF_DEBUG_PRINT(" %s\n", __func__);

	if (!spinfo)
		return -ENOENT;
	spinfo->refcnt--;

	if (spinfo->refcnt == 0) {
		if (spinfo->spclk.spdifout_clk)
			clk_put(spinfo->spclk.spdifout_clk);

		if (spinfo->spclk.spdifin_clk)
			clk_put(spinfo->spclk.spdifin_clk);

		if (spinfo->spclk.hda2codec_clk)
			clk_put(spinfo->spclk.hda2codec_clk);

	}
	return 0;
}

static int spdif_open(void)
{
	int err = 0;

	SPDIF_DEBUG_PRINT(" %s ++\n", __func__);
	if (!spinfo) {

		spinfo =
		kzalloc(sizeof(struct spdif_controller_info), GFP_KERNEL);

		if (!spinfo)
			return -ENOMEM;

		spinfo->spclk.spdifout_clk = clk_get_sys("spdif_out", NULL);
		if (IS_ERR_OR_NULL(spinfo->spclk.spdifout_clk)) {
			err = -ENOENT;
			spinfo->spclk.spdifout_clk = 0;
			goto fail_spdif_open;
		}

		spinfo->spclk.spdifin_clk = clk_get_sys("spdif_in", NULL);
		if (IS_ERR_OR_NULL(spinfo->spclk.spdifin_clk)) {
			err = -ENOENT;
			spinfo->spclk.spdifin_clk = 0;
			goto fail_spdif_open;
		}

#if !defined(CONFIG_ARCH_TEGRA_2x_SOC)
		spinfo->spclk.hda2codec_clk = clk_get_sys("hda2codec_2x", NULL);
		if (IS_ERR_OR_NULL(spinfo->spclk.hda2codec_clk)) {
			pr_err("couldn't get hda2codec_2x clock\n");
			err = -ENODEV;
			spinfo->spclk.hda2codec_clk = 0;
			goto fail_spdif_open;
		}

		spinfo->reg_cache =
			kzalloc(sizeof(int)*SPDIF_REG_INDEX_MAX, GFP_KERNEL);
#else
		spinfo->reg_cache =
			kzalloc(sizeof(struct spdif_regs_cache), GFP_KERNEL);
#endif

		if (!spinfo->reg_cache)
			goto fail_spdif_open;

		spinfo->refcnt++;
	}

	spinfo->refcnt++;

	SPDIF_DEBUG_PRINT(" %s --\n", __func__);
	return err;

fail_spdif_open:

	spdif_close(0);
	return err;
}

int spdif_get_device_property(int mode, struct tegra_spdif_property *spdifprop)
{
	memcpy(spdifprop,
		&spinfo->spdev[mode].ch_prop,
		sizeof(struct tegra_spdif_property));

	return 0;
}

int spdif_initialize(unsigned long base, int mode)
{
	/* disable interrupts from SPDIF */
	spdif_writel(base, 0x0, SPDIF_CTRL_0);
	spdif_fifo_clear(base, mode);
	spdif_fifo_enable(base, mode, 0);

	spdif_set_bit_mode(base, SPDIF_BIT_MODE_MODE16BIT);
	spdif_set_fifo_packed(base, 1);

	spdif_set_sample_rate(0, mode, 48000);

	return 0;
}

int spdif_init(unsigned long base, phys_addr_t phy_base, int mode,
			struct tegra_spdif_property* spdifprop)
{
	int err = 0;

	SPDIF_DEBUG_PRINT(" %s ++\n", __func__);
	if (spdif_open())
		return err;

	/* open audio_switch first */
	err = audio_switch_open();
	if (err) {
		spdif_close(0);
		return err;
	}

	spinfo->base = base;
	spinfo->phy_base = phy_base;
	spinfo->spdev[mode].ch_prop.bit_size = spdifprop->bit_size;
	spinfo->spdev[mode].ch_prop.channels = spdifprop->channels;
	spinfo->spdev[mode].ch_prop.clk_rate = spdifprop->clk_rate;
	spinfo->spdev[mode].ch_prop.sample_rate = spdifprop->sample_rate;
	spdif_clock_set_parent(0, mode, 0);

	err = spdif_clock_enable(0, mode);
	if (err) {
		audio_switch_close();
		spdif_close(0);
		return err;
	}

	spdif_initialize(base, mode);

	spdif_set_sample_rate(0, mode, spdifprop->sample_rate);

	spdif_clock_disable(0, mode);
	SPDIF_DEBUG_PRINT(" %s --\n", __func__);
	return 0;
}


int spdif_clock_enable(int ifc, int mode)
{
	int err = 0;

	if (!spinfo)
		return -ENOENT;

	SPDIF_DEBUG_PRINT(" %s ++\n", __func__);

	err = audio_switch_enable_clock();
	if (err)
		return err;

	if (spinfo->spdev[mode].clk_refs > 0) {
		spinfo->spdev[mode].clk_refs++;

	} else {

		spdif_clock_set_rate(0, mode,
				spinfo->spdev[mode].ch_prop.clk_rate);

		if (mode == AUDIO_TX_MODE) {
			if (clk_enable(spinfo->spclk.spdifout_clk)) {
				err = PTR_ERR(spinfo->spclk.spdifout_clk);
				goto spdif_clock_enable_failed;
			}
		} else {
			if (clk_enable(spinfo->spclk.spdifin_clk)) {
				err = PTR_ERR(spinfo->spclk.spdifin_clk);
				goto spdif_clock_enable_failed;
			}
		}

		if (spinfo->spclk.hda2codec_clk &&
			clk_enable(spinfo->spclk.hda2codec_clk)) {
			pr_err("failed to enable hda2codec_2x clock\n");
			err = PTR_ERR(spinfo->spclk.hda2codec_clk);
			goto spdif_clock_enable_failed;
		}

		spinfo->spdev[mode].clk_refs++;
	}

	SPDIF_DEBUG_PRINT("%s clk cnt 0x%x\n",
			__func__, spinfo->spdev[mode].clk_refs);
	return err;

spdif_clock_enable_failed:

	spdif_clock_disable(0, mode);
	return err;
}

int spdif_clock_disable(int ifc, int mode)
{
	SPDIF_DEBUG_PRINT(" %s ++\n", __func__);

	if (!spinfo)
		return -ENOENT;

	if (spinfo->spdev[mode].clk_refs > 0) {
		spinfo->spdev[mode].clk_refs--;

		if (spinfo->spdev[mode].clk_refs == 0) {
			if (spinfo->spclk.hda2codec_clk)
				clk_disable(spinfo->spclk.hda2codec_clk);
			if (mode == AUDIO_TX_MODE) {
				if (spinfo->spclk.spdifout_clk)
					clk_disable(spinfo->spclk.spdifout_clk);
			} else {
				if (spinfo->spclk.spdifin_clk)
					clk_disable(spinfo->spclk.spdifin_clk);
			}
		}
	}

	audio_switch_disable_clock();

	SPDIF_DEBUG_PRINT("%s clock count 0x%x\n",
			__func__, spinfo->spdev[mode].clk_refs);
	return 0;
}

int spdif_clock_set_parent(int ifc, int mode, int parent)
{
	/* Fix set the parent properly */
	struct clk *pll_a_out0_clk = clk_get_sys(NULL, "pll_a_out0");

	if (mode == AUDIO_TX_MODE) {
		if (spinfo->spclk.spdifout_clk)
			clk_set_parent(spinfo->spclk.spdifout_clk,
				pll_a_out0_clk);
	} else {
		if (spinfo->spclk.spdifin_clk)
			clk_set_parent(spinfo->spclk.spdifin_clk,
				pll_a_out0_clk);
	}

	return 0;
}


int spdif_suspend(int ifc)
{
	SPDIF_DEBUG_PRINT(" %s ++\n", __func__);

	/* FIXME : check for Rx mode if needed */
	if (spinfo->spdev[AUDIO_TX_MODE].clk_refs == 0)
		spdif_clock_enable(0, AUDIO_TX_MODE);

	spdif_save_regs(spinfo->base);
	audio_switch_suspend();

	spdif_clock_disable(0, AUDIO_TX_MODE);

	return 0;
}

int spdif_resume(int ifc)
{
	SPDIF_DEBUG_PRINT(" %s ++\n", __func__);
	/* FIXME : check for Rx mode if needed */
	spdif_clock_enable(0, AUDIO_TX_MODE);
	audio_switch_resume();
	spdif_restore_regs(spinfo->base);

	return 0;
}
#if defined(CONFIG_ARCH_TEGRA_2x_SOC)

int spdif_fifo_write(int ifc, int mode, u32 data)
{
	unsigned long base = spinfo->base;

	if (mode == AUDIO_TX_MODE) {
		spdif_writel(base, data, SPDIF_DATA_OUT_0);
	} else {
		spdif_writel(base, data, SPDIF_DATA_IN_0);
	}

	return 0;
}

int spdif_fifo_set_attention_level(int ifc, int mode, unsigned int level)
{
	u32 val;
	unsigned long base = spinfo->base;

	if (level > SPDIF_FIFO_ATN_LVL_TWELVE_SLOTS) {
		pr_err("%s: invalid fifo level selector %d\n", __func__,
			level);
		return -EINVAL;
	}

	val = spdif_readl(base, SPDIF_DATA_FIFO_CSR_0);

	if (mode == AUDIO_TX_MODE) {
		val &= ~SPDIF_DATA_FIFO_CSR_0_TX_ATN_LVL_MASK;
		val |= level << SPDIF_DATA_FIFO_CSR_0_TX_ATN_LVL_SHIFT;
	}

	spdif_writel(base, val, SPDIF_DATA_FIFO_CSR_0);
	return 0;
}

int spdif_fifo_clear(int ifc, int mode)
{
	unsigned long base = spinfo->base;

	u32 val = spdif_readl(base, SPDIF_DATA_FIFO_CSR_0);

	if (mode == AUDIO_TX_MODE) {
		val &= ~(SPDIF_DATA_FIFO_CSR_0_TX_CLR |
			SPDIF_DATA_FIFO_CSR_0_TU_CLR);
		val |= SPDIF_DATA_FIFO_CSR_0_TX_CLR |
			SPDIF_DATA_FIFO_CSR_0_TU_CLR;
	}

	spdif_writel(base, val, SPDIF_DATA_FIFO_CSR_0);
	return 0;
}

int spdif_set_fifo_packed(int ifc, unsigned on)
{
	u32 val = spdif_readl(spinfo->base, SPDIF_CTRL_0);

	val &= ~SPDIF_CTRL_0_PACK;
	val |= on ? (SPDIF_CTRL_0_PACK) : 0;
	spdif_writel(spinfo->base, val, SPDIF_CTRL_0);
	return 0;
}

u32 spdif_get_status(int ifc, int mode)
{
	return spdif_readl(spinfo->base, SPDIF_STATUS_0);
}

int spdif_ack_status(int ifc)
{
	unsigned long base = spinfo->base;
	spdif_writel(base, spdif_readl(base, SPDIF_STATUS_0),
				SPDIF_STATUS_0);
	return 0;
}

u32 spdif_get_fifo_scr(int ifc)
{
	return spdif_readl(spinfo->base, SPDIF_DATA_FIFO_CSR_0);
}

phys_addr_t spdif_get_fifo_phy_base(int ifc, int mode)
{
	if (mode == AUDIO_TX_MODE)
		return spinfo->phy_base + SPDIF_DATA_OUT_0;
	else
		return spinfo->phy_base + SPDIF_DATA_IN_0;

	return 0;
}

u32 spdif_get_fifo_full_empty_count(int ifc, int mode)
{
	unsigned long base = spinfo->base;
	u32 val = spdif_readl(base, SPDIF_DATA_FIFO_CSR_0);

	if (mode == AUDIO_TX_MODE) {
		val = val >> SPDIF_DATA_FIFO_CSR_0_TD_EMPTY_COUNT_SHIFT;
		return val & SPDIF_DATA_FIFO_CSR_0_TD_EMPTY_COUNT_MASK;
	}

	return 0;
}

int spdif_get_dma_requestor(int ifc, int fifo_mode)
{
	return TEGRA_DMA_REQ_SEL_SPD_I;
}

int spdif_free_dma_requestor(int ifc, int fifo_mode)
{
	return 0;
}

int spdif_set_dma_channel(int ifc, int fifo_mode, int dma_ch)
{
	return 0;
}

int spdif_set_acif(int ifc, int fifo_mode, void *fmt)
{
	return 0;
}

int spdif_set_fifo_attention(int ifc, int fifo_mode, int buffersize)
{
	int fifoattn = SPDIF_FIFO_ATN_LVL_FOUR_SLOTS;
	spinfo->spdev[fifo_mode].fifo_attn = fifoattn;
	return 0;
}

void spdif_dump_registers(unsigned long base)
{
	struct spdif_regs_cache *regs =
		(struct spdif_regs_cache *) spinfo->reg_cache;

	spdif_save_regs(base);

	pr_info("CTRL   %08x\n", regs->spdif_ctrl_0);
	pr_info("STATUS   %08x\n", regs->spdif_status_0);
	pr_info("STROBE_CTRL   %08x\n", regs->spdif_strobe_ctrl_0);
	pr_info("FIFO_CSR   %08x\n", regs->spdif_data_fifo_scr_0);
	pr_info("CH_STA_RX_A   %08x\n", regs->spdif_ch_sta_rx_a_0);
	pr_info("CH_STA_RX_B   %08x\n", regs->spdif_ch_sta_rx_b_0);
	pr_info("CH_STA_RX_C   %08x\n", regs->spdif_ch_sta_rx_c_0);
	pr_info("CH_STA_RX_D   %08x\n", regs->spdif_ch_sta_rx_d_0);
	pr_info("CH_STA_RX_E   %08x\n", regs->spdif_ch_sta_rx_e_0);
	pr_info("CH_STA_RX_F   %08x\n", regs->spdif_ch_sta_rx_f_0);
	pr_info("CH_STA_TX_A   %08x\n", regs->spdif_ch_sta_tx_a_0);
	pr_info("CH_STA_TX_B   %08x\n", regs->spdif_ch_sta_tx_b_0);
	pr_info("CH_STA_TX_C   %08x\n", regs->spdif_ch_sta_tx_c_0);
	pr_info("CH_STA_TX_D   %08x\n", regs->spdif_ch_sta_tx_d_0);
	pr_info("CH_STA_TX_E   %08x\n", regs->spdif_ch_sta_tx_e_0);
	pr_info("CH_STA_TX_F   %08x\n", regs->spdif_ch_sta_tx_f_0);
	pr_info("USR_STA_RX_A   %08x\n", regs->spdif_usr_sta_rx_a_0);
	pr_info("USR_DAT_TX_A   %08x\n", regs->spdif_usr_dat_tx_a_0);

	pr_info("%s: End.\n", __func__);

}

void spdif_save_regs(unsigned long base)
{
	struct spdif_regs_cache *regs =
		(struct spdif_regs_cache *) spinfo->reg_cache;

	regs->spdif_ctrl_0 = spdif_readl(base, SPDIF_CTRL_0);
	regs->spdif_status_0 = spdif_readl(base, SPDIF_STATUS_0);
	regs->spdif_strobe_ctrl_0 = spdif_readl(base, SPDIF_STROBE_CTRL_0);
	regs->spdif_data_fifo_scr_0 = spdif_readl(base, SPDIF_DATA_FIFO_CSR_0);
	regs->spdif_ch_sta_rx_a_0 = spdif_readl(base, SPDIF_CH_STA_RX_A_0);
	regs->spdif_ch_sta_rx_b_0 = spdif_readl(base, SPDIF_CH_STA_RX_B_0);
	regs->spdif_ch_sta_rx_c_0 = spdif_readl(base, SPDIF_CH_STA_RX_C_0);
	regs->spdif_ch_sta_rx_d_0 = spdif_readl(base, SPDIF_CH_STA_RX_D_0);
	regs->spdif_ch_sta_rx_e_0 = spdif_readl(base, SPDIF_CH_STA_RX_E_0);
	regs->spdif_ch_sta_rx_f_0 = spdif_readl(base, SPDIF_CH_STA_RX_F_0);
	regs->spdif_ch_sta_tx_a_0 = spdif_readl(base, SPDIF_CH_STA_TX_A_0);
	regs->spdif_ch_sta_tx_b_0 = spdif_readl(base, SPDIF_CH_STA_TX_B_0);
	regs->spdif_ch_sta_tx_c_0 = spdif_readl(base, SPDIF_CH_STA_TX_C_0);
	regs->spdif_ch_sta_tx_d_0 = spdif_readl(base, SPDIF_CH_STA_TX_D_0);
	regs->spdif_ch_sta_tx_e_0 = spdif_readl(base, SPDIF_CH_STA_TX_E_0);
	regs->spdif_ch_sta_tx_f_0 = spdif_readl(base, SPDIF_CH_STA_TX_F_0);
	regs->spdif_usr_sta_rx_a_0 = spdif_readl(base, SPDIF_USR_STA_RX_A_0);
	regs->spdif_usr_dat_tx_a_0 = spdif_readl(base, SPDIF_USR_DAT_TX_A_0);
}

void spdif_restore_regs(unsigned long base)
{
	struct spdif_regs_cache *regs =
		(struct spdif_regs_cache *) spinfo->reg_cache;

	spdif_writel(base, regs->spdif_ctrl_0, SPDIF_CTRL_0);
	spdif_writel(base, regs->spdif_status_0, SPDIF_STATUS_0);
	spdif_writel(base, regs->spdif_strobe_ctrl_0, SPDIF_STROBE_CTRL_0);
	spdif_writel(base, regs->spdif_data_fifo_scr_0, SPDIF_DATA_FIFO_CSR_0);
	spdif_writel(base, regs->spdif_ch_sta_rx_a_0, SPDIF_CH_STA_RX_A_0);
	spdif_writel(base, regs->spdif_ch_sta_rx_b_0, SPDIF_CH_STA_RX_B_0);
	spdif_writel(base, regs->spdif_ch_sta_rx_c_0, SPDIF_CH_STA_RX_C_0);
	spdif_writel(base, regs->spdif_ch_sta_rx_d_0, SPDIF_CH_STA_RX_D_0);
	spdif_writel(base, regs->spdif_ch_sta_rx_e_0, SPDIF_CH_STA_RX_E_0);
	spdif_writel(base, regs->spdif_ch_sta_rx_f_0, SPDIF_CH_STA_RX_F_0);
	spdif_writel(base, regs->spdif_ch_sta_tx_a_0, SPDIF_CH_STA_TX_A_0);
	spdif_writel(base, regs->spdif_ch_sta_tx_b_0, SPDIF_CH_STA_TX_B_0);
	spdif_writel(base, regs->spdif_ch_sta_tx_c_0, SPDIF_CH_STA_TX_C_0);
	spdif_writel(base, regs->spdif_ch_sta_tx_d_0, SPDIF_CH_STA_TX_D_0);
	spdif_writel(base, regs->spdif_ch_sta_tx_e_0, SPDIF_CH_STA_TX_E_0);
	spdif_writel(base, regs->spdif_ch_sta_tx_f_0, SPDIF_CH_STA_TX_F_0);
	spdif_writel(base, regs->spdif_usr_sta_rx_a_0, SPDIF_USR_STA_RX_A_0);
	spdif_writel(base, regs->spdif_usr_dat_tx_a_0, SPDIF_USR_DAT_TX_A_0);
}

#else

static int spdif_get_apbif_channel(int fifo_mode)
{
	return spinfo->spdev[fifo_mode].dma_ch;
}

int spdif_set_fifo_packed(int ifc, unsigned on)
{
	/* This register is obsolete after T20 */
	return 0;
}

int spdif_fifo_write(int ifc, int mode, u32 data)
{
	int apbif_ifc = spdif_get_apbif_channel(mode);

	if (apbif_ifc != -ENOENT)
		apbif_fifo_write(apbif_ifc, mode, data);

	return 0;
}

int spdif_fifo_set_attention_level(int ifc, int mode, unsigned int level)
{
	int apbif_ifc = spdif_get_apbif_channel(mode);

	if (apbif_ifc != -ENOENT)
		return apbif_fifo_set_attention_level(apbif_ifc,
					 mode, (level - 1));

	return 0;
}

int spdif_fifo_clear(int ifc, int mode)
{
	int apbif_ifc = spdif_get_apbif_channel(mode);

	if (apbif_ifc != -ENOENT)
		apbif_soft_reset(apbif_ifc, mode, 1);

	return 0;
}

u32 spdif_get_status(int ifc, int mode)
{
	int apbif_ifc = spdif_get_apbif_channel(mode);

	if (apbif_ifc != -ENOENT)
		return apbif_get_fifo_mode(apbif_ifc, mode);

	return 0;
}

int spdif_ack_status(int ifc)
{
	/*FIXME: add apbif call here */
	return 0;
}

u32 spdif_get_fifo_scr(int ifc)
{
	/*FIXME: add apbif call here */
	return 0;
}

phys_addr_t spdif_get_fifo_phy_base(int ifc, int mode)
{
	int apbif_ifc = spdif_get_apbif_channel(mode);

	if (apbif_ifc != -ENOENT)
		return apbif_get_fifo_phy_base(apbif_ifc, mode);

	return 0;
}

u32 spdif_get_fifo_full_empty_count(int ifc, int mode)
{
	int apbif_ifc = spdif_get_apbif_channel(mode);

	if (apbif_ifc != -ENOENT)
		return apbif_get_fifo_freecount(apbif_ifc, mode);

	return 0;
}

int spdif_set_dma_channel(int ifc, int fifo_mode, int dma_ch)
{
	spinfo->spdev[fifo_mode].dma_ch = dma_ch;
	return 0;
}

int spdif_free_dma_requestor(int ifc, int fifo_mode)
{
	int apbif_ifc = spdif_get_apbif_channel(fifo_mode);

	if (apbif_ifc != -ENOENT)
		audio_apbif_free_channel(apbif_ifc, fifo_mode);

	return 0;
}

static  struct audio_cif  spdif_audiocif;

int spdif_set_acif(int ifc, int fifo_mode, void *fmt)
{
	struct audio_cif *cifInfo = (struct audio_cif *)fmt;
	if (fifo_mode == AUDIO_TX_MODE)
		audio_switch_set_acif(spinfo->base +
			 SPDIF_AUDIOCIF_TXDATA_CTRL_0, cifInfo);
	else
		audio_switch_set_acif(spinfo->base +
			 SPDIF_AUDIOCIF_RXDATA_CTRL_0, cifInfo);

	apbif_set_pack_mode(spdif_get_apbif_channel(fifo_mode),
		fifo_mode, AUDIO_FIFO_PACK_16);

	audio_apbif_set_acif(spdif_get_apbif_channel(fifo_mode),
		fifo_mode, cifInfo);

	return 0;
}

int spdif_get_dma_requestor(int ifc, int fifo_mode)
{
	int dma_index =	0;
	struct audio_cif  *tx_audio_cif = &spdif_audiocif;
	int apbif_ifc = ahubrx0_spdif;

	if (fifo_mode == AUDIO_RX_MODE)
		apbif_ifc = ahubtx0_spdif;

	dma_index = apbif_get_channel(apbif_ifc, fifo_mode);

	if (dma_index != -ENOENT) {
		spinfo->spdev[fifo_mode].dma_ch = dma_index - 1;

		/* set spdif audiocif */
		/* setting base value for acif */
		memset(tx_audio_cif, 0 , sizeof(struct audio_cif));
		tx_audio_cif->audio_channels	= AUDIO_CHANNEL_2;
		tx_audio_cif->client_channels	= AUDIO_CHANNEL_2;
		tx_audio_cif->audio_bits	= AUDIO_BIT_SIZE_16;
		tx_audio_cif->client_bits	= AUDIO_BIT_SIZE_16;
		spdif_set_acif(0, fifo_mode, (void *)tx_audio_cif);
	}

	return dma_index;
}

int spdif_set_fifo_attention(int ifc, int fifo_mode, int buffersize)
{
	int fifoattn = SPDIF_FIFO_ATN_LVL_FOUR_SLOTS;

	if (buffersize & 0xF)
		fifoattn = SPDIF_FIFO_ATN_LVL_ONE_SLOT;
	else if ((buffersize >> 4) & 0x1)
		fifoattn = SPDIF_FIFO_ATN_LVL_FOUR_SLOTS;
	else
		fifoattn = SPDIF_FIFO_ATN_LVL_EIGHT_SLOTS;

	spinfo->spdev[fifo_mode].fifo_attn = fifoattn;
	return 0;
}

void spdif_save_regs(unsigned long base)
{
	int i = 0;
	int *regs = (int *) spinfo->reg_cache;

	for (i = 0; i <= SPDIF_REG_INDEX_MAX; i++) {
		regs[i] = spdif_readl(base, (i << 2));
	}
}

void spdif_restore_regs(unsigned long base)
{
	int i = 0;
	int *regs = (int *) spinfo->reg_cache;

	for (i = 0; i <= SPDIF_REG_INDEX_MAX; i++) {
		spdif_writel(base, regs[i], (i << 2));
	}
}

#endif

int spdif_fifo_enable(int ifc, int mode, int on)
{
	u32 val = 0;
	unsigned long base = spinfo->base;

#if !defined(CONFIG_ARCH_TEGRA_2x_SOC)

	int apbif_ifc = spdif_get_apbif_channel(mode);

	if (apbif_ifc == -ENOENT)
		return apbif_ifc;

	apbif_channel_enable(apbif_ifc, mode, on);
#endif

	val = spdif_readl(base, SPDIF_CTRL_0);

	if (mode == AUDIO_TX_MODE) {
		val &= ~(SPDIF_CTRL_0_TU_EN);
		set_reg_mode(val, SPDIF_CTRL_0_TC_EN, on);
		set_reg_mode(val, SPDIF_CTRL_0_TX_EN, on);
	} else {
		set_reg_mode(val, SPDIF_CTRL_0_RX_EN, on);
	}

	if (on)
		spdif_fifo_set_attention_level(ifc, mode,
			spinfo->spdev[mode].fifo_attn);

	spdif_writel(base, val, SPDIF_CTRL_0);
	return 0;
}
