/****************************************************************************
 * @file     PinConfig.c
 * @version  V1.23
<<<<<<< Updated upstream
 * @Date     2022/12/07-21:36:45 
=======
 * @Date     2022/12/07-21:16:33 
>>>>>>> Stashed changes
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2013-2022 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M482LIDAE(LQFP48)
Pin Configuration:
Pin7:PA.11
Pin8:PA.10
Pin9:PA.9
Pin10:PA.8
Pin15:PA.7
Pin16:PA.6
Pin17:PA.5
Pin18:PA.4
Pin19:PA.3
Pin20:PA.2
Pin21:PA.1
Pin22:PA.0
Pin33:PA.12
Pin34:PA.13
Pin35:PA.14
Pin36:PA.15
Pin42:CLKO
********************/

#include "M480.h"

/*
 * @brief This function provides the configured MFP registers
 * @param None
 * @return None
 */
void PIN_Init(void)
{
    //SYS->GPA_MFPH = 0x00000000UL;
    //SYS->GPA_MFPL = 0x00000000UL;
    //SYS->GPB_MFPH = 0x0E000000UL;
    //SYS->GPB_MFPL = 0x00000000UL;
    //SYS->GPC_MFPH = 0x00000000UL;
    //SYS->GPC_MFPL = 0x00000000UL;
    //SYS->GPF_MFPL = 0x00000000UL;

    /* If the macros do not exist in your project, please refer to the corresponding header file in Header folder of the tool package */
    SYS->GPA_MFPH = SYS_GPA_MFPH_PA15MFP_GPIO | SYS_GPA_MFPH_PA14MFP_GPIO | SYS_GPA_MFPH_PA13MFP_GPIO | SYS_GPA_MFPH_PA12MFP_GPIO | SYS_GPA_MFPH_PA11MFP_GPIO | SYS_GPA_MFPH_PA10MFP_GPIO | SYS_GPA_MFPH_PA9MFP_GPIO | SYS_GPA_MFPH_PA8MFP_GPIO;
    SYS->GPA_MFPL = SYS_GPA_MFPL_PA7MFP_GPIO | SYS_GPA_MFPL_PA6MFP_GPIO | SYS_GPA_MFPL_PA5MFP_GPIO | SYS_GPA_MFPL_PA4MFP_GPIO | SYS_GPA_MFPL_PA3MFP_GPIO | SYS_GPA_MFPL_PA2MFP_GPIO | SYS_GPA_MFPL_PA1MFP_GPIO | SYS_GPA_MFPL_PA0MFP_GPIO;
    SYS->GPB_MFPH = SYS_GPB_MFPH_PB14MFP_CLKO;
    SYS->GPB_MFPL = 0x00000000;
    SYS->GPC_MFPH = 0x00000000;
    SYS->GPC_MFPL = 0x00000000;
    SYS->GPF_MFPL = 0x00000000;

    return;
}

/*** (C) COPYRIGHT 2013-2022 Nuvoton Technology Corp. ***/
