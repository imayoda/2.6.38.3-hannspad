/*
 * arch/arm/mach-tegra/board-smba1002-usb.c
 *
 * Copyright (C) 2011 Eduardo Jos� Tagle <ejtagle@tutopia.com>
 * Copyright (C) 2011 Jens Andersen <jens.andersen@gmail.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

/* All configurations related to USB */
 
#include <linux/console.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sysfs.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/dma-mapping.h>
#include <linux/platform_data/tegra_usb.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/reboot.h>
#include <linux/i2c-tegra.h>
#include <linux/mfd/tps6586x.h>

#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <asm/mach/time.h>
#include <asm/setup.h>

#include <mach/io.h>
#include <mach/iomap.h>
#include <mach/irqs.h>
#include <mach/gpio.h>
#include <mach/clk.h>
#include <mach/usb_phy.h>
#include <mach/system.h>

#include <linux/usb/f_accessory.h>

#include "board.h"
#include "board-smba1002.h"
#include "clock.h"
#include "gpio-names.h"
#include "devices.h"

static struct tegra_utmip_config utmi_phy_config[] = {
	[0] = {
		.hssync_start_delay = 0,
		.idle_wait_delay 	= 17,
		.elastic_limit 		= 16,
		.term_range_adj 	= 6, 	/*  xcvr_setup = 9 with term_range_adj = 6 gives the maximum guard around */
		.xcvr_setup 		= 15, 	/*  the USB electrical spec. This is true across fast and slow chips, high */
									/*  and low voltage and hot and cold temperatures */
		.xcvr_lsfslew 		= 2,	/*  -> To slow rise and fall times in low speed eye diagrams in host mode */
		.xcvr_lsrslew 		= 2,	/*                                                                        */
		.vbus_gpio		= SMBA1002_USB0_VBUS,
	},
	[1] = {
		.hssync_start_delay = 0,
		.idle_wait_delay 	= 17,
		.elastic_limit 		= 16,
		.term_range_adj 	= 6,	/*  -> xcvr_setup = 9 with term_range_adj = 6 gives the maximum guard around */
		.xcvr_setup 		= 8,	/*     the USB electrical spec. This is true across fast and slow chips, high */
									/*     and low voltage and hot and cold temperatures */
		.xcvr_lsfslew 		= 2,	/*  -> To slow rise and fall times in low speed eye diagrams in host mode */
		.xcvr_lsrslew 		= 2,	/*                                                                        */
		.vbus_gpio		= SMBA1002_USB0_VBUS,
		.shared_pin_vbus_en_oc	= true,
	},
};

static struct tegra_ulpi_config ulpi_phy_config = {
	.reset_gpio = SMBA1002_USB1_RESET,
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,38)
	.clk = "cdev2",
#else
	.clk = "clk_dev2",
#endif
#if 0
	.inf_type = TEGRA_USB_LINK_ULPI,
#endif
};

static struct tegra_ehci_platform_data tegra_ehci_pdata[] = {
	[0] = {
		.phy_config = &utmi_phy_config[0],
		.operating_mode = TEGRA_USB_OTG, /* DEVICE is slave here / HOST*/
		.power_down_on_bus_suspend = 0,
	},
	[1] = {
		.phy_config = &ulpi_phy_config,
		.operating_mode = TEGRA_USB_HOST,
		.power_down_on_bus_suspend = 1,
	},
	[2] = {
		.phy_config = &utmi_phy_config[1],
		.operating_mode = TEGRA_USB_HOST,
		.power_down_on_bus_suspend = 0,
	},
};

struct platform_device *usb_host_pdev = NULL;
static struct platform_device * tegra_usb_otg_host_register(void)
{
	int val;
	struct platform_device *pdev = NULL;
	void *platform_data;

	pr_info("%s: enabling USB host mode\n", __func__);	
	
	gpio_direction_input(SMBA1002_USB0_VBUS);

	msleep(10);
	
	pdev = platform_device_alloc(tegra_ehci1_device.name,
			tegra_ehci1_device.id);
	if (!pdev)
		goto err_2;

	val = platform_device_add_resources(pdev, tegra_ehci1_device.resource,
		tegra_ehci1_device.num_resources);
	if (val)
		goto error;

	pdev->dev.dma_mask =  tegra_ehci1_device.dev.dma_mask;
	pdev->dev.coherent_dma_mask = tegra_ehci1_device.dev.coherent_dma_mask;
	
	platform_data = kmalloc(sizeof(struct tegra_ehci_platform_data), GFP_KERNEL);
	if (!platform_data)
		goto error;

	memcpy(platform_data, tegra_ehci1_device.dev.platform_data,
				sizeof(struct tegra_ehci_platform_data));
	pdev->dev.platform_data = platform_data;
 	
	val = platform_device_add(pdev);
	if (val)
		goto error_add;

	usb_host_pdev = pdev;
	return pdev;

error_add:
	kfree(platform_data);
error:
	platform_device_put(pdev);
err_2:
	pr_err("%s: failed to add the host controller device\n", __func__);	
	return NULL;
}

static void tegra_usb_otg_host_unregister(struct platform_device *pdev)
{
	pr_info("%s: disabling USB host mode\n", __func__);	

	gpio_direction_output(SMBA1002_USB0_VBUS, 0); 

	msleep(500);

	kfree(pdev->dev.platform_data);
	pdev->dev.platform_data = NULL;
	platform_device_unregister(pdev);
	usb_host_pdev = NULL;
}

#ifdef CONFIG_USB_TEGRA_OTG
static struct tegra_otg_platform_data tegra_otg_pdata = {
	.host_register = &tegra_usb_otg_host_register,
	.host_unregister = &tegra_usb_otg_host_unregister,
};
#endif

static struct platform_device *smba1002_usb_devices[] __initdata = {
	&tegra_otg_device,
	//&tegra_usb_mass_storage, 		/* USB gadget */
	//&tegra_usb_acm_device, 		/* USB gadget */
	//&tegra_ehci1_device,
	//&tegra_ehci2_device,
	&tegra_udc_device, 		/* USB gadget */
	//&tegra_ehci2_device,
	&tegra_ehci3_device,
};

static void tegra_set_host_mode(void)
{
#ifdef CONFIG_USB_TEGRA_OTG
	tegra_otg_set_host_mode(true);
	
#else
	if (!usb_host_pdev) {
		usb_host_pdev = tegra_usb_otg_host_register();
	}
#endif
}

static void tegra_set_gadget_mode(void)
{
#ifdef CONFIG_USB_TEGRA_OTG
	tegra_otg_set_host_mode(false);
#else
	if (usb_host_pdev) {
		tegra_usb_otg_host_unregister(usb_host_pdev);
		usb_host_pdev = NULL;
	}
#endif
}

struct kobject *usb_kobj = NULL;

static ssize_t usb_read(struct device *dev, struct device_attribute *attr,
		       char *buf)
{
	int ret = 0;
	
	if (!strcmp(attr->attr.name, "host_mode")) {
		if (usb_host_pdev)
			ret = 1;
	}

	return strlcpy(buf, ret ? "1\n" : "0\n", 3);
}

static ssize_t usb_write(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count)
{
	unsigned long on = simple_strtoul(buf, NULL, 10);

	if (!strcmp(attr->attr.name, "host_mode")) {
		if (on)
			tegra_set_host_mode();
		else
			tegra_set_gadget_mode();
	} 

	return count;
}

static DEVICE_ATTR(host_mode, 0666, usb_read, usb_write);

static struct attribute *usb_sysfs_entries[] = {
	&dev_attr_host_mode.attr,
	NULL
};

static struct attribute_group usb_attr_group = {
	.name	= NULL,
	.attrs	= usb_sysfs_entries,
}; 

int __init smba1002_usb_register_devices(void)
{
	int ret;

	tegra_ehci1_device.dev.platform_data = &tegra_ehci_pdata[0];
	tegra_ehci2_device.dev.platform_data = &tegra_ehci_pdata[1];
	tegra_ehci3_device.dev.platform_data = &tegra_ehci_pdata[2];
#ifdef CONFIG_USB_TEGRA_OTG
	tegra_otg_device.dev.platform_data = &tegra_otg_pdata;
#endif

	gpio_request(SMBA1002_USB0_VBUS, "USB0 VBUS");
	
	gpio_direction_output(SMBA1002_USB0_VBUS, 0 );

	gpio_set_value(SMBA1002_USB0_VBUS, 1 );
	gpio_export(SMBA1002_USB0_VBUS, 0 );
	
	ret = platform_add_devices(smba1002_usb_devices, ARRAY_SIZE(smba1002_usb_devices));
	if (ret)
		return ret;

	tegra_set_gadget_mode();
		
	usb_kobj = kobject_create_and_add("usbbus", NULL);
	if (!usb_kobj) {
		pr_err("Unable to register USB mode switch");
		return 0;	
	}

	return sysfs_create_group(usb_kobj, &usb_attr_group); 
}
