 /*
  * tegra_generic_codec.c  --  Generic codec interface for tegra
  *
  * Copyright  2011 Nvidia Graphics Pvt. Ltd.
  *
  * Author: Sumit Bhattacharya
  *             sumitb@nvidia.com
  *  http://www.nvidia.com
  *
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

#include "tegra_soc.h"

static struct snd_soc_codec* tegra_generic_codec;
static struct platform_device* tegra_generic_codec_dev;

// Stubbed implementations of generic codec ops
static int tegra_generic_codec_startup(struct snd_pcm_substream *substream,
			  struct snd_soc_dai *dai)
{
	return 0;
}

static void tegra_generic_codec_shutdown(struct snd_pcm_substream *substream,
			    struct snd_soc_dai *dai)
{
	return;
}
static int tegra_generic_codec_hw_params(struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params,
				struct snd_soc_dai *dai)
{
	return 0;
}

static int tegra_generic_codec_mute(struct snd_soc_dai *dai, int mute)
{
	return 0;
}


static int tegra_generic_codec_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	return 0;
}

static int tegra_generic_codec_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				 int clk_id, unsigned int freq, int dir)
{
	return 0;
}

static struct snd_soc_dai_ops tegra_generic_codec_stub_ops = {
	.startup	= tegra_generic_codec_startup,
	.shutdown	= tegra_generic_codec_shutdown,
	.hw_params	= tegra_generic_codec_hw_params,
	.digital_mute	= tegra_generic_codec_mute,
	.set_fmt	= tegra_generic_codec_set_dai_fmt,
	.set_sysclk	= tegra_generic_codec_set_dai_sysclk,
};

struct snd_soc_dai_driver tegra_generic_codec_dai_driver[] = {
	{
		.name = "tegra_generic_voice_codec",
		.id = 0,
		.playback = {
			.stream_name    = "Playback",
			.channels_min   = 1,
			.channels_max   = 1,
			.rates          = TEGRA_VOICE_SAMPLE_RATES,
			.formats        = SNDRV_PCM_FMTBIT_S16_LE,
		},
		.capture = {
			.stream_name    = "Capture",
			.channels_min   = 1,
			.channels_max   = 1,
			.rates          = TEGRA_VOICE_SAMPLE_RATES,
			.formats        = SNDRV_PCM_FMTBIT_S16_LE,
		},
		.ops = &tegra_generic_codec_stub_ops,
		.playback = {
			.stream_name    = "Playback",
			.channels_min   = 2,
			.channels_max   = 2,
			.rates          = TEGRA_SAMPLE_RATES,
			.formats        = SNDRV_PCM_FMTBIT_S16_LE,
		},
		.capture = {
			.stream_name    = "Capture",
			.channels_min   = 2,
			.channels_max   = 2,
			.rates          = TEGRA_SAMPLE_RATES,
			.formats        = SNDRV_PCM_FMTBIT_S16_LE,
		},
		.ops = &tegra_generic_codec_stub_ops,
	}
};
EXPORT_SYMBOL_GPL(tegra_generic_codec_dai_driver);

static int tegra_generic_codec_probe(struct snd_soc_codec *codec)
{
/*	int i, ret = 0;

	tegra_generic_codec = kzalloc(sizeof(struct snd_soc_codec), GFP_KERNEL);
	if (!tegra_generic_codec)
		return -ENOMEM;

	mutex_init(&tegra_generic_codec->mutex);

	tegra_generic_codec->dev = &pdev->dev;
	tegra_generic_codec->name = "tegra_generic_codec";
	tegra_generic_codec->owner = THIS_MODULE;
	tegra_generic_codec->dai = tegra_generic_codec_dai;
	tegra_generic_codec->num_dai = ARRAY_SIZE(tegra_generic_codec_dai);
	tegra_generic_codec->write = NULL;
	tegra_generic_codec->read = NULL;
	for (i = 0; i < tegra_generic_codec->num_dai; i++)
		tegra_generic_codec_dai[i].dev = &pdev->dev;

	INIT_LIST_HEAD(&tegra_generic_codec->dapm_widgets);
	INIT_LIST_HEAD(&tegra_generic_codec->dapm_paths);

	ret = snd_soc_register_codec(tegra_generic_codec);
	if (ret != 0) {
		pr_err("codec: failed to register tegra_generic_codec\n");
		goto codec_err;
	}

	ret = snd_soc_register_dais(tegra_generic_codec_dai, ARRAY_SIZE(tegra_generic_codec_dai));
	if (ret != 0) {
		pr_err("codec: failed to register dais\n");
		goto dai_err;
	}*/

	return 0;
/*dai_err:
	snd_soc_unregister_codec(tegra_generic_codec);
codec_err:
	kfree(tegra_generic_codec);
	tegra_generic_codec = NULL;

	return ret;*/
}

static int tegra_generic_codec_remove(struct snd_soc_codec *codec)
{
/*	int i;

	if (!tegra_generic_codec)
		return 0;

	snd_soc_unregister_dais(tegra_generic_codec_dai->dev, ARRAY_SIZE(tegra_generic_codec_dai));
	snd_soc_unregister_codec(tegra_generic_codec->dev);
	kfree(tegra_generic_codec);
	tegra_generic_codec = NULL;
	for (i = 0; i < tegra_generic_codec->num_dai; i++)
		tegra_generic_codec_dai[i].dev = NULL;*/

	return 0;
}

static struct snd_soc_codec_driver soc_codec_dev_tegra_generic = {
	.probe =	tegra_generic_codec_probe,
	.remove =	tegra_generic_codec_remove,
//	.suspend =	tegra_generic_suspend,
//	.resume =	tegra_generic_resume,
	.read = NULL,
	.write = NULL,
//	.set_bias_level = wm8400_set_bias_level,
};

static int __devinit tegra_generic_probe(struct platform_device *pdev)
{
	return snd_soc_register_codec(&pdev->dev,
	                             &soc_codec_dev_tegra_generic,
	                             &tegra_generic_codec_dai_driver[0],
	                             ARRAY_SIZE(tegra_generic_codec_dai_driver));
}

static int __devexit tegra_generic_remove(struct platform_device *pdev)
{
	snd_soc_unregister_codec(&pdev->dev);
	return 0;
}

static struct platform_driver tegra_generic_codec_driver = {
	.driver = {
		   .name = "tegra-generic-codec",
		   .owner = THIS_MODULE,
		   },
	.probe = tegra_generic_probe,
	.remove = __devexit_p(tegra_generic_remove),
};

static void __exit tegra_generic_exit(void)
{
	tegra_generic_codec_remove(tegra_generic_codec_dev);
	platform_device_unregister(tegra_generic_codec_dev);
	tegra_generic_codec_dev = 0;
}

static __init int tegra_generic_init(void)
{
	return platform_driver_register(&tegra_generic_codec_driver);
}

module_init(tegra_generic_init);
module_exit(tegra_generic_exit);

/* Module information */
MODULE_DESCRIPTION("Tegra ALSA Generic Codec Interface");
MODULE_LICENSE("GPL");

