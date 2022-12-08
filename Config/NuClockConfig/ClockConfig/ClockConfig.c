/****************************************************************************
 * @file     ClockConfig.c
 * @version  V1.06
 * @Date     2022/12/07-21:36:52 
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2013-2022 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M482LIDAE(LQFP48)
Base Clocks:
LIRC:10kHz
HIRC:12MHz
HXT:12MHz
PLL:192MHz
HSUSB_OTG_PHY:30MHz
HCLK:192MHz
PCLK0:192MHz
PCLK1:192MHz
Enabled-Module Frequencies:
CLKO=Bus Clock(HCLK):192MHz/Engine Clock:12MHz
CRC=Bus Clock(HCLK):192MHz
EBI=Bus Clock(HCLK):192MHz
ISP=Bus Clock(HCLK):192MHz/Engine Clock:12MHz
PDMA=Bus Clock(HCLK):192MHz
TMR0=Bus Clock(PCLK0):192MHz/Engine Clock:192MHz
WDT=Bus Clock(PCLK0):192MHz/Engine Clock:10kHz
WWDT=Bus Clock(PCLK0):192MHz/Engine Clock:93.75kHz
********************/

#include "M480.h"

/*----------------------------------------------------------------------------
  Define HXT clock.
  Please locate and modify the real one in your project.
  Otherwise, the project may fail to build.
 *----------------------------------------------------------------------------*/
#define __HXT         (12000000UL)  /*!< High Speed External Crystal Clock Frequency */

/*
 * @brief This function updates clock registers to fulfill the configuration
 * @param None
 * @return None
 */
void CLK_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    //CLK->PWRCTL   = (CLK->PWRCTL   & ~(0x0000000FUL)) | 0x0000001DUL;
    //CLK->PLLCTL   = (CLK->PLLCTL   & ~(0x000FFFFFUL)) | 0x0000821EUL;
    //CLK->CLKDIV0  = (CLK->CLKDIV0  & ~(0xFFFFFFFFUL)) | 0x00000000UL;
    //CLK->CLKDIV1  = (CLK->CLKDIV1  & ~(0x00FFFFFFUL)) | 0x00000000UL;
    //CLK->CLKDIV3  = (CLK->CLKDIV3  & ~(0xFFFF0000UL)) | 0x00000000UL;
    //CLK->CLKDIV4  = (CLK->CLKDIV4  & ~(0x0000FFFFUL)) | 0x00000000UL;
    //CLK->PCLKDIV  = (CLK->PCLKDIV  & ~(0x00000077UL)) | 0x00000000UL;
    //CLK->CLKSEL0  = (CLK->CLKSEL0  & ~(0x00F0013FUL)) | 0x00F3013AUL;
    //CLK->CLKSEL1  = (CLK->CLKSEL1  & ~(0xFF777703UL)) | 0x85222203UL;
    //CLK->CLKSEL2  = (CLK->CLKSEL2  & ~(0x00003FFFUL)) | 0x00002BABUL;
    //CLK->CLKSEL3  = (CLK->CLKSEL3  & ~(0xFF03013FUL)) | 0x5500003FUL;
    //CLK->AHBCLK   = (CLK->AHBCLK   & ~(0x0003D4EEUL)) | 0x0000008EUL;
    //CLK->APBCLK0  = (CLK->APBCLK0  & ~(0x7F3FF7FFUL)) | 0x00000045UL;
    //CLK->APBCLK1  = (CLK->APBCLK1  & ~(0x4CCF1347UL)) | 0x00000000UL;
    //CLK->CLKOCTL  = (CLK->CLKOCTL  & ~(0x0000007FUL)) | 0x00000030UL;
    //SysTick->CTRL = (SysTick->CTRL & ~(0x00000005UL)) | 0x00000004UL;

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* If the macros do not exist in your project, please refer to the related clk.h in Header folder of the tool package */
    /* Set XT1_OUT(PF.2) and XT1_IN(PF.3) to input mode */
    PF->MODE &= ~(GPIO_MODE_MODE2_Msk | GPIO_MODE_MODE3_Msk);

    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk|CLK_PWRCTL_HIRCEN_Msk|CLK_PWRCTL_HXTEN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk|CLK_STATUS_HIRCSTB_Msk|CLK_STATUS_HXTSTB_Msk);

    /* Disable PLL first to avoid unstable when setting PLL */
    CLK_DisablePLL();

    /* Set PLL frequency */
    CLK->PLLCTL = (CLK->PLLCTL & ~(0x000FFFFFUL)) | 0x0000821EUL;

    /* Waiting for PLL ready */
    CLK_WaitClockReady(CLK_STATUS_PLLSTB_Msk);

    /* Set HCLK clock */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_PLL, CLK_CLKDIV0_HCLK(1));

    /* Set PCLK-related clock */
    CLK->PCLKDIV = (CLK_PCLKDIV_PCLK0DIV1 | CLK_PCLKDIV_PCLK1DIV1);

    /* Enable IP clock */
    CLK_EnableModuleClock(CRC_MODULE);
    CLK_EnableModuleClock(EBI_MODULE);
    CLK_EnableModuleClock(ISP_MODULE);
    CLK_EnableModuleClock(PDMA_MODULE);
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(WDT_MODULE);
    CLK_EnableModuleClock(WWDT_MODULE);
    CLK_EnableCKO(CLK_CLKSEL1_CLKOSEL_HXT, MODULE_NoMsk, 1);
    CLK->CLKOCTL = CLK->CLKOCTL & ~CLK_CLKOCTL_CLK1HZEN_Msk;

    /* Set IP clock */
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_PCLK0, MODULE_NoMsk);
    CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDTSEL_LIRC, MODULE_NoMsk);
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL1_WWDTSEL_HCLK_DIV2048, MODULE_NoMsk);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /* Lock protected registers */
    SYS_LockReg();

    return;
}

/*** (C) COPYRIGHT 2013-2022 Nuvoton Technology Corp. ***/
