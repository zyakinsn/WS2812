/****************************************************************************
 * @file     PinConfig.c
 * @version  V1.23
 * @Date     2022/11/12-00:59:58 
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2013-2022 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M482LIDAE(LQFP48)
Pin Configuration:
Pin1:SPI1_MISO
Pin2:SPI1_MOSI
Pin3:SPI1_CLK
Pin4:SPI1_SS
Pin5:PB.1
Pin6:PB.0
Pin7:EBI_nRD
Pin8:EBI_nWR
Pin11:PF.5
Pin15:EBI_AD7
Pin16:EBI_AD6
Pin17:PA.5
Pin18:QEI0_A
Pin19:QEI0_B
Pin20:SPI0_CLK
Pin21:SPI0_MISO
Pin22:SPI0_MOSI
Pin25:ICE_DAT
Pin26:ICE_CLK
Pin27:EBI_AD5
Pin28:EBI_AD4
Pin29:EBI_AD3
Pin30:EBI_AD2
Pin31:EBI_AD1
Pin32:EBI_AD0
Pin33:USB_VBUS
Pin34:USB_D-
Pin35:USB_D+
Pin36:USB_OTG_ID
Pin40:PC.14
Pin41:EADC0_CH15
Pin42:CLKO
Pin43:UART0_TXD
Pin44:UART0_RXD
Pin47:EBI_nCS0
Pin48:PB.6
********************/

#include "M480.h"

/*
 * @brief This function provides the configured MFP registers
 * @param None
 * @return None
 */
void PIN_Init(void)
{
    //SYS->GPA_MFPH = 0xEEEE2200UL;
    //SYS->GPA_MFPL = 0x220EE444UL;
    //SYS->GPB_MFPH = 0x1E660000UL;
    //SYS->GPB_MFPL = 0x80555500UL;
    //SYS->GPC_MFPH = 0x00000000UL;
    //SYS->GPC_MFPL = 0x00222222UL;
    //SYS->GPF_MFPL = 0x000000EEUL;

    /* If the macros do not exist in your project, please refer to the corresponding header file in Header folder of the tool package */
    SYS->GPA_MFPH = SYS_GPA_MFPH_PA15MFP_USB_OTG_ID | SYS_GPA_MFPH_PA14MFP_USB_D_P | SYS_GPA_MFPH_PA13MFP_USB_D_N | SYS_GPA_MFPH_PA12MFP_USB_VBUS | SYS_GPA_MFPH_PA11MFP_EBI_nRD | SYS_GPA_MFPH_PA10MFP_EBI_nWR;
    SYS->GPA_MFPL = SYS_GPA_MFPL_PA7MFP_EBI_AD7 | SYS_GPA_MFPL_PA6MFP_EBI_AD6 | SYS_GPA_MFPL_PA5MFP_GPIO | SYS_GPA_MFPL_PA4MFP_QEI0_A | SYS_GPA_MFPL_PA3MFP_QEI0_B | SYS_GPA_MFPL_PA2MFP_SPI0_CLK | SYS_GPA_MFPL_PA1MFP_SPI0_MISO | SYS_GPA_MFPL_PA0MFP_SPI0_MOSI;
    SYS->GPB_MFPH = SYS_GPB_MFPH_PB15MFP_EADC0_CH15 | SYS_GPB_MFPH_PB14MFP_CLKO | SYS_GPB_MFPH_PB13MFP_UART0_TXD | SYS_GPB_MFPH_PB12MFP_UART0_RXD;
    SYS->GPB_MFPL = SYS_GPB_MFPL_PB7MFP_EBI_nCS0 | SYS_GPB_MFPL_PB6MFP_GPIO | SYS_GPB_MFPL_PB5MFP_SPI1_MISO | SYS_GPB_MFPL_PB4MFP_SPI1_MOSI | SYS_GPB_MFPL_PB3MFP_SPI1_CLK | SYS_GPB_MFPL_PB2MFP_SPI1_SS | SYS_GPB_MFPL_PB1MFP_GPIO | SYS_GPB_MFPL_PB0MFP_GPIO;
    SYS->GPC_MFPH = SYS_GPC_MFPH_PC14MFP_GPIO;
    SYS->GPC_MFPL = SYS_GPC_MFPL_PC5MFP_EBI_AD5 | SYS_GPC_MFPL_PC4MFP_EBI_AD4 | SYS_GPC_MFPL_PC3MFP_EBI_AD3 | SYS_GPC_MFPL_PC2MFP_EBI_AD2 | SYS_GPC_MFPL_PC1MFP_EBI_AD1 | SYS_GPC_MFPL_PC0MFP_EBI_AD0;
    SYS->GPF_MFPL = SYS_GPF_MFPL_PF5MFP_GPIO | SYS_GPF_MFPL_PF1MFP_ICE_CLK | SYS_GPF_MFPL_PF0MFP_ICE_DAT;

    return;
}

/*** (C) COPYRIGHT 2013-2022 Nuvoton Technology Corp. ***/