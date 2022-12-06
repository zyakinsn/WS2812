
#include "main.h"




//
int32_t main(void)
{
	{
		__disable_irq(); 
		SYS_UnlockReg();	//
		CLK->PWRCTL|=CLK_PWRCTL_HXTTBEN_Msk|CLK_PWRCTL_HXTSELTYP_Msk|BIT11;
		CLK_Init();
		PIN_Init();
		SCB->VTOR=0;			//Vector

    SYS_UnlockReg();
    WDT_Open(WDT_TIMEOUT_2POW14, WDT_RESET_DELAY_18CLK, TRUE, TRUE);
		SYS_LockReg();

//		SYS->GPA_MFPH = 0x0EEE2200; // OTG USB pin off	
		//SYS->GPB_MFPH = 0x10220000;

			
	//GPIO_SLEWCTL_FAST

//		EBI->CTL0=0x00000203;//|(1<<24);
//		EBI->TCTL0=0x00000000;		
		
//		GPIO_SetMode(PA,BIT3|BIT4,GPIO_MODE_INPUT);				//QEI pins
//		GPIO_SetMode(PB,BIT0|BIT15,GPIO_MODE_INPUT);			//LCD wait, ADC
//		GPIO_SetMode(PF,BIT0,GPIO_MODE_INPUT);						//BTN0
		
		GPIO_SetMode(PA,BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7,GPIO_MODE_OUTPUT);	//LCD pins (bit8 ALE)
//		GPIO_SetMode(PB,BIT1|BIT2|BIT3|BIT5|BIT6|BIT7|BIT14,GPIO_MODE_OUTPUT);
//		GPIO_SetMode(PC,BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT14,GPIO_MODE_OUTPUT);		//LCD pins
//		GPIO_SetMode(PF,BIT2|BIT4|BIT5,GPIO_MODE_OUTPUT);															//PWR_EN, CSF
		
//		GPIO_SetMode(PB,BIT0|BIT4,GPIO_MODE_OPEN_DRAIN);

//		PA->PUSEL=PUBIT3|PUBIT4; 	//Port A QEI (Encoder) pins PullUp
//		PC->PUSEL=PUBIT0|PUBIT1|PUBIT2|PUBIT3|PUBIT4|PUBIT5; 	//Port A QEI (Encoder) pins PullUp
//
    TIMER_Open(TIMER0,TIMER_PERIODIC_MODE,1000);	//Start timer0
    TIMER_EnableInt(TIMER0);
    NVIC_EnableIRQ(TMR0_IRQn);
    TIMER_Start(TIMER0);
		
//    TIMER_Open(TIMER1,TIMER_PERIODIC_MODE,48000*2);
//    TIMER_EnableInt(TIMER1);
//    NVIC_EnableIRQ(TMR1_IRQn);
//    TIMER_Start(TIMER1);		
		
	
		


//



		__enable_irq();

		
		
//		status=arm_rfft_fast_init_f32(&RFFT,SAMPLE_LENGTH);
		


//
	}
	while(1)
	{
		WDTclr;
//
//		if(press) //press KEY
//		{
//			press=0;
//			
//			
//			switch(key)
//			{ 
////				case 1:write_eep(ADDRESS_PARAM,sizeof(eeprom_temp1),&eeprom_temp1);break;
////				case 2:read_eep(ADDRESS_PARAM,sizeof(eeprom_temp2),&eeprom_temp2);break;
////				case 3:{eeprom_temp1++;zb>=1.0?1.0:(zb+=.1);}break;
////				case 4:clearDisp();break;
////				case 5:zb<=0.1?0.1:(zb-=0.1);break;
//				
//			}

//			//	if(t>=SAMPLE_LENGTH)
////	{
////		t=0;
////		fadc=1;
////		for(u16 i=0;i<SAMPLE_LENGTH;i++)fft_in[i]=(float)fft_tmp[i];
////	}
//			
//		}
//
		if(!tmr)
		{
			tmr=200;				//50ms timer
			
			D0 = !D0;
			D1 = !D0;
			D2 = D0;
			D3 = !D0;
			D4 = D0;
			D5 = !D0;
			D6 = D0;
			D7 = !D0;			

			}

	}
}
//
void TMR0_IRQHandler(void)//1ms
{
	TIMER_ClearIntFlag(TIMER0);
//

	if(tmr)tmr--;
//	if(ts_tmr>1)ts_tmr--;
	
//	fp();
	
	tick=1;
}


//
void TMR1_IRQHandler(void)
{
	TIMER_ClearIntFlag(TIMER1);
//
	static u16 t;
	

//	batt=GetAdcData();

//	t++;
//	if(t>=SAMPLE_LENGTH)
//	{
//		t=0;
////		fadc=1;
////		for(u16 i=0;i<SAMPLE_LENGTH;i++)fft_in[i]=(float)fft_tmp[i];
//	}
//	EADC->SWTRG|=1;
}
//

