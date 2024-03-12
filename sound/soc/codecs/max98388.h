/* SPDX-License-Identifier: GPL-2.0 */
/*
 * max98388.h -- MAX98388 ALSA SoC audio driver header
 *
 * Copyright(c) 2022, Analog Devices Inc.
 */

#ifndef _MAX98388_H
#define _MAX98388_H

/* Device Status Registers */
#define MAX98388_R2000_SW_RESET			0x2000
#define MAX98388_R2001_INT_RAW1			0x2001
#define MAX98388_R2002_INT_RAW2			0x2002
#define MAX98388_R2004_INT_STATE1		0x2004
#define MAX98388_R2005_INT_STATE2		0x2005
/* Thermal Protection Registers */
#define MAX98388_R2020_THERM_WARN_THRESH	0x2020
/* Error Monitor */
#define MAX98388_R2031_SPK_MON_THRESH		0x2031
#define MAX98388_R2032_SPK_MON_LD_SEL		0x2032
#define MAX98388_R2033_SPK_MON_DURATION		0x2033
#define MAX98388_R2037_ERR_MON_CTRL		0x2037
/* PCM Registers */
#define MAX98388_R2040_PCM_MODE_CFG		0x2040
#define MAX98388_R2041_PCM_CLK_SETUP		0x2041
#define MAX98388_R2042_PCM_SR_SETUP		0x2042
#define MAX98388_R2044_PCM_TX_CTRL1		0x2044
#define MAX98388_R2045_PCM_TX_CTRL2		0x2045
#define MAX98388_R2050_PCM_TX_HIZ_CTRL1		0x2050
#define MAX98388_R2051_PCM_TX_HIZ_CTRL2		0x2051
#define MAX98388_R2052_PCM_TX_HIZ_CTRL3		0x2052
#define MAX98388_R2053_PCM_TX_HIZ_CTRL4		0x2053
#define MAX98388_R2054_PCM_TX_HIZ_CTRL5		0x2054
#define MAX98388_R2055_PCM_TX_HIZ_CTRL6		0x2055
#define MAX98388_R2056_PCM_TX_HIZ_CTRL7		0x2056
#define MAX98388_R2057_PCM_TX_HIZ_CTRL8		0x2057
#define MAX98388_R2058_PCM_RX_SRC1		0x2058
#define MAX98388_R2059_PCM_RX_SRC2		0x2059
#define MAX98388_R205C_PCM_TX_DRIVE_STRENGTH	0x205C
#define MAX98388_R205D_PCM_TX_SRC_EN		0x205D
#define MAX98388_R205E_PCM_RX_EN		0x205E
#define MAX98388_R205F_PCM_TX_EN		0x205F
/* Speaker Channel Control */
#define MAX98388_R2090_SPK_CH_VOL_CTRL		0x2090
#define MAX98388_R2091_SPK_CH_CFG		0x2091
#define MAX98388_R2092_SPK_AMP_OUT_CFG		0x2092
#define MAX98388_R2093_SPK_AMP_SSM_CFG		0x2093
#define MAX98388_R2094_SPK_AMP_ER_CTRL		0x2094
#define MAX98388_R209E_SPK_CH_PINK_NOISE_EN	0x209E
#define MAX98388_R209F_SPK_CH_AMP_EN		0x209F
#define MAX98388_R20A0_IV_DATA_DSP_CTRL		0x20A0
#define MAX98388_R20A7_IV_DATA_EN		0x20A7
#define MAX98388_R20E0_BP_ALC_THRESH		0x20E0
#define MAX98388_R20E1_BP_ALC_RATES		0x20E1
#define MAX98388_R20E2_BP_ALC_ATTEN		0x20E2
#define MAX98388_R20E3_BP_ALC_REL		0x20E3
#define MAX98388_R20E4_BP_ALC_MUTE		0x20E4
#define MAX98388_R20EE_BP_INF_HOLD_REL		0x20EE
#define MAX98388_R20EF_BP_ALC_EN		0x20EF
#define MAX98388_R210E_AUTO_RESTART		0x210E
#define MAX98388_R210F_GLOBAL_EN		0x210F
#define MAX98388_R22FF_REV_ID			0x22FF

/* MAX98388_R2000_SW_RESET */
#define MAX98388_SOFT_RESET			(0x1 << 0)

/* MAX98388_R2020_THERM_WARN_THRESH */
#define MAX98388_THERM_SHDN_THRESH_SHIFT	(0)
#define MAX98388_THERM_WARN_THRESH_SHIFT	(2)

/* MAX98388_R2022_PCM_TX_SRC_1 */
#define MAX98388_PCM_TX_CH_SRC_A_V_SHIFT	(0)
#define MAX98388_PCM_TX_CH_SRC_A_I_SHIFT	(4)

/* MAX98388_R2024_PCM_DATA_FMT_CFG */
#define MAX98388_PCM_MODE_CFG_FORMAT_MASK	(0x7 << 3)
#define MAX98388_PCM_MODE_CFG_FORMAT_SHIFT	(3)
#define MAX98388_PCM_TX_CH_INTERLEAVE_MASK	(0x1 << 2)
#define MAX98388_PCM_FORMAT_I2S			(0x0 << 0)
#define MAX98388_PCM_FORMAT_LJ			(0x1 << 0)
#define MAX98388_PCM_FORMAT_TDM_MODE0		(0x3 << 0)
#define MAX98388_PCM_FORMAT_TDM_MODE1		(0x4 << 0)
#define MAX98388_PCM_FORMAT_TDM_MODE2		(0x5 << 0)
#define MAX98388_PCM_MODE_CFG_CHANSZ_MASK	(0x3 << 6)
#define MAX98388_PCM_MODE_CFG_CHANSZ_16		(0x1 << 6)
#define MAX98388_PCM_MODE_CFG_CHANSZ_24		(0x2 << 6)
#define MAX98388_PCM_MODE_CFG_CHANSZ_32		(0x3 << 6)

/* MAX98388_R2031_SPK_MON_THRESH */
#define MAX98388_SPKMON_THRESH_SHIFT		(0)

/* MAX98388_R2032_SPK_MON_LD_SEL */
#define MAX98388_SPKMON_LOAD_SHIFT		(0)

/* MAX98388_R2033_SPK_MON_DURATION */
#define MAX98388_SPKMON_DURATION_SHIFT		(0)

/* MAX98388_R2037_ERR_MON_CTRL */
#define MAX98388_CLOCK_MON_SHIFT		(0)
#define MAX98388_SPK_MON_SHIFT			(1)

/* MAX98388_R203E_AMP_PATH_GAIN */
#define MAX98388_SPK_DIGI_GAIN_MASK		(0xF << 4)
#define MAX98388_SPK_DIGI_GAIN_SHIFT		(4)
#define MAX98388_FS_GAIN_MAX_MASK		(0xF << 0)
#define MAX98388_FS_GAIN_MAX_SHIFT		(0)

/* MAX98388_R2041_PCM_CLK_SETUP */
#define MAX98388_PCM_MODE_CFG_PCM_BCLKEDGE	(0x1 << 4)
#define MAX98388_PCM_CLK_SETUP_BSEL_MASK	(0xF << 0)

/* MAX98388_R2042_PCM_SR_SETUP */
#define MAX98388_PCM_SR_MASK			(0xF << 0)
#define MAX98388_PCM_SR_IV_MASK			(0xF << 4)
#define MAX98388_PCM_SR_IV_SHIFT			(4)
#define MAX98388_PCM_SR_8000			(0x0 << 0)
#define MAX98388_PCM_SR_11025			(0x1 << 0)
#define MAX98388_PCM_SR_12000			(0x2 << 0)
#define MAX98388_PCM_SR_16000			(0x3 << 0)
#define MAX98388_PCM_SR_22050			(0x4 << 0)
#define MAX98388_PCM_SR_24000			(0x5 << 0)
#define MAX98388_PCM_SR_32000			(0x6 << 0)
#define MAX98388_PCM_SR_44100			(0x7 << 0)
#define MAX98388_PCM_SR_48000			(0x8 << 0)
#define MAX98388_PCM_SR_88200			(0x9 << 0)
#define MAX98388_PCM_SR_96000			(0xA << 0)

/* MAX98388_R2043_AMP_EN */
#define MAX98388_SPK_EN_MASK			(0x1 << 0)
#define MAX98388_SPKFB_EN_MASK			(0x1 << 1)
#define MAX98388_SPKFB_EN_SHIFT			(1)

/* MAX98388_R2052_MEAS_ADC_PVDD_FLT_CFG */
#define MAX98388_FLT_EN_SHIFT			(4)

/* MAX98388_R2058_PCM_RX_SRC1 */
#define MAX98388_PCM_TO_SPK_MONOMIX_CFG_SHIFT	(0)

/* MAX98388_R2059_PCM_RX_SRC2 */
#define MAX98388_RX_SRC_CH0_SHIFT		(0)
#define MAX98388_RX_SRC_CH1_SHIFT		(4)

/* MAX98388_R2091_SPK_CH_CFG */
#define MAX98388_SPK_CFG_DCBLK_SHIFT		(0)
#define MAX98388_SPK_CFG_DITH_EN_SHIFT		(1)
#define MAX98388_SPK_CFG_INV_SHIFT		(2)
#define MAX98388_SPK_CFG_VOL_RMPUP_SHIFT	(3)
#define MAX98388_SPK_CFG_VOL_RMPDN_SHIFT	(4)

/* MAX98388_R2092_SPK_AMP_OUT_CFG */
#define MAX98388_SPK_AMP_OUT_GAIN_SHIFT		(0)
#define MAX98388_SPK_AMP_OUT_MODE_SHIFT		(3)

/* MAX98388_R2093_SPK_AMP_SSM_CFG */
#define MAX98388_SPK_AMP_SSM_EN_SHIFT		(0)
#define MAX98388_SPK_AMP_SSM_MOD_SHIFT		(1)

/* MAX98388_R2094_SPK_AMP_ER_CTRL */
#define MAX98388_EDGE_RATE_RISE_SHIFT		(0)
#define MAX98388_EDGE_RATE_FALL_SHIFT		(2)

/* MAX98388_R209E_SPK_CH_PINK_NOISE_EN */
#define MAX98388_PINK_NOISE_GEN_SHIFT		(0)

/* MAX98388_R20A0_IV_DATA_DSP_CTRL */
#define MAX98388_AMP_DSP_CTRL_VOL_DCBLK_SHIFT	(0)
#define MAX98388_AMP_DSP_CTRL_CUR_DCBLK_SHIFT	(1)
#define MAX98388_AMP_DSP_CTRL_VOL_INV_SHIFT	(2)
#define MAX98388_AMP_DSP_CTRL_CUR_INV_SHIFT	(3)
#define MAX98388_AMP_DSP_CTRL_DITH_SHIFT	(4)

/* MAX98388_R20B2_BDE_L4_CFG_2 */
#define MAX98388_LVL4_HOLD_EN_SHIFT		(6)
#define MAX98388_LVL4_MUTE_EN_SHIFT		(7)

/* MAX98388_R20B5_BDE_EN */
#define MAX98388_BDE_EN_SHIFT			(0)

/* MAX98388_R20D1_DHT_CFG */
#define MAX98388_DHT_ROT_PNT_SHIFT		(0)
#define MAX98388_DHT_SPK_GAIN_MIN_SHIFT		(4)

/* MAX98388_R20D2_DHT_ATTACK_CFG */
#define MAX98388_DHT_ATTACK_RATE_SHIFT		(0)
#define MAX98388_DHT_ATTACK_STEP_SHIFT		(3)

/* MAX98388_R20D3_DHT_RELEASE_CFG */
#define MAX98388_DHT_RELEASE_RATE_SHIFT		(0)
#define MAX98388_DHT_RELEASE_STEP_SHIFT		(3)

/* MAX98388_R20D4_DHT_EN */
#define MAX98388_DHT_EN_SHIFT			(0)

/* MAX98388_R20E0_BP_ALC_THRESH */
#define MAX98388_ALC_THRESH_SHIFT		(0)

/* MAX98388_R20E1_BP_ALC_RATES */
#define MAX98388_ALC_RELEASE_RATE_SHIFT		(0)
#define MAX98388_ALC_ATTACK_RATE_SHIFT		(4)

/* MAX98388_R20E2_BP_ALC_ATTEN */
#define MAX98388_ALC_MAX_ATTEN_SHIFT		(0)

/* MAX98388_R20E3_BP_ALC_REL */
#define MAX98388_ALC_DEBOUNCE_TIME_SHIFT	(0)

/* MAX98388_R20E4_BP_ALC_MUTE */
#define MAX98388_ALC_MUTE_EN_SHIFT		(0)
#define MAX98388_ALC_MUTE_DELAY_SHIFT		(1)
#define MAX98388_ALC_MUTE_RAMP_EN_SHIFT		(4)
#define MAX98388_ALC_UNMUTE_RAMP_EN_SHIFT	(5)

/* MAX98388_R210E_AUTO_RESTART */
#define MAX98388_PVDD_UVLO_AUTORESTART_SHIFT	(0)
#define MAX98388_THERM_AUTORESTART_SHIFT	(1)
#define MAX98388_OVC_AUTORESTART_SHIFT		(2)
#define MAX98388_CMON_AUTORESTART_SHIFT		(3)

/* MAX98388_R210F_GLOBAL_EN */
#define MAX98388_GLOBAL_EN_MASK			(0x1 << 0)

struct max98388_priv {
	struct regmap *regmap;
	struct gpio_desc *reset_gpio;
	unsigned int v_slot;
	unsigned int i_slot;
	unsigned int spkfb_slot;
	bool interleave_mode;
	unsigned int ch_size;
	bool tdm_mode;
};

#endif
