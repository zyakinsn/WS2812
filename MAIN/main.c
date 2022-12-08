
#include "main.h"

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
	D7=0;
}
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
			
		if(!tmr)
		{

			tmr=250;				//1ms timer

//			leds[0]=0x0000FF;
//			leds[1]=0x0000FF; //GRB
//			leds[2]=0xFF00FF;
//			leds[3]=0xFFFFFF;
//			leds[4]=0x111111;

			

		//	u8 i;
			color=(red<<8)+(green<<16)+blue;
			leds[blink]=color;
			
			
			color2=((red-128)<<8)+((red-128)<<16)+(red-128);
			color3=((red-192)<<8)+((red-192)<<16)+(red-192);
			color4=0x101010;
			color5=0x010101;
			color6=0x000000;
			
			leds[blink-1]=color2;
			leds[blink-2]=color3;
			leds[blink-3]=color4;
			leds[blink-4]=color5;
			leds[blink-5]=color6;			
			
//			if(blink>=8)
//			{
//					for(i=1;i<9;i++)
//					{
//					 color=((red-32*i)<<8)+((red-32*i)<<16)+(red-32*i);
//						if(red-32*i<=0)color=0x000000;
//					 leds[blink-i]=color;	
//					}	
//		  }
			RGB();//2,0xFFFFFF);	
			
	//		leds[blink]=0x000000;
			
			
			(blink>=LEDS-1)?(blink=0):blink++;

			//				if(blink>=LEDS-2) blink=0;
//					else blink++;

			D0=!D0;
		}// end timer
	} //end while
}		//end main
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
//void TMR1_IRQHandler(void)
//{
//	TIMER_ClearIntFlag(TIMER1);
////
////	static u16 t;
//	


