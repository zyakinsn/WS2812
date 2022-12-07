
#include "main.h"

<<<<<<< Updated upstream
void low (void)
{D7=1;
	delay_tick(18);
	D7=0;
	delay_tick(35);
}
//
void hiw (void)
{D7=1;
	delay_tick(35);
	D7=0;
	delay_tick(12);
}
//
void RGB ()//(u8 *leds)
{	u8 i,j;		
	for(j=0;j<LEDS;j++) 
	{
		for(i=0;i<24;i++) leds[j]&(0x800000>>i)?hiw():low();//G	
	}
	
		
}
=======

void 
>>>>>>> Stashed changes
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
    TIMER_Open(TIMER0,TIMER_PERIODIC_MODE,3500);	//Start timer0
    TIMER_EnableInt(TIMER0);
    NVIC_EnableIRQ(TMR0_IRQn);
    TIMER_Start(TIMER0);
		
//    TIMER_Open(TIMER1,TIMER_PERIODIC_MODE,48000*2);
//    TIMER_EnableInt(TIMER1);
//    NVIC_EnableIRQ(TMR1_IRQn);
//    TIMER_Start(TIMER1);		
		__enable_irq();
	
	}
	while(1)
	{
		WDTclr;
//
<<<<<<< Updated upstream
=======
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


>>>>>>> Stashed changes
		if(!tmr)
		{
			u8 i,j;
			tmr=100;				//1ms timer

			leds[0]=0x0000FF;
			leds[1]=0x0000FF; //GRB
			leds[2]=0xFF00FF;
			leds[3]=0xFFFFFF;
			leds[4]=0x010101;
			
<<<<<<< Updated upstream
			RGB();//2,0xFFFFFF);
//		for(j=0;j<8;j++)
//		{			
//			for(i=0;i<8;i++) hiw();//G	
//			for(i=0;i<8;i++) low();//R
//			for(i=0;i<8;i++) low();//R			
//		}	
//			D7=0;
		}
	} //end while
}		//end main
=======
			D0 = !D0;
			D1 = !D0;
			D2 = D0;
			D3 = !D0;
			D4 = D0;
			D5 = !D0;
			D6 = D0;
//			D7 = !D0;			

			}

	}
}
>>>>>>> Stashed changes
//
void TMR0_IRQHandler(void)//1ms
{
	TIMER_ClearIntFlag(TIMER0);
//

	if(tmr)tmr--;
//	if(ts_tmr>1)ts_tmr--;
	
//	fp();
	D7 = !D7;
	
	tick=1;
}


//
//void TMR1_IRQHandler(void)
//{
//	TIMER_ClearIntFlag(TIMER1);
////
////	static u16 t;
//	


