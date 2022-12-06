
#include "M480.h"
#include "string.h"
#include "crc.h"


typedef struct Tfp
{
	u8*start;
	u8*stop;
}Tfp;
Tfp fp_ptr;
//
typedef __packed struct Trx
{
	__packed struct rx
	{
		u16 len;
		u8 cmd;
		u32 crc;
		u8 buf[512];
	}rx;
	u8 rxf;
}Trx;
Trx fp_rx;
//
Tfp fp_add(void*d,u16 l)
{
	static u8 uart_buf[512];
	if(l)
	{
		fp_ptr.start=uart_buf;
		if(fp_ptr.stop<fp_ptr.start)fp_ptr.stop=fp_ptr.start;
		memcpy(fp_ptr.stop,d,l);
		fp_ptr.stop+=l;
	}else fp_ptr.start=fp_ptr.stop=uart_buf;
	return fp_ptr;
}
//
void fp_send(u8 cmd)
{
	u16 l=fp_ptr.stop-fp_ptr.start;
//
	CRC_SET_SEED(0xFFFFFFFF);
	crc32(fp_ptr.start,l);
	CRC_WRITE_DATA(l);
	CRC_WRITE_DATA(l>>8);
	CRC_WRITE_DATA(cmd);
	u32 crc=CRC->CHECKSUM;
//
	UART0->LINE|=0x30;
	UART0->DAT=l;
	UART0->DAT=l>>8;
	UART0->DAT=cmd;	
	UART0->DAT=crc;
	UART0->DAT=crc>>8;
	UART0->DAT=crc>>16;
	UART0->DAT=crc>>24;
//
	while(fp_ptr.start<fp_ptr.stop)
	{
		if(UART0->FIFOSTS&(1<<23))break;
		UART0->DAT=*fp_ptr.start++;
	}
	UART_EnableInt(UART0,UART_INTEN_THREIEN_Msk);
}
//
void UART0_IRQHandler(void)
{
	u32 i=UART0->INTSTS;
	if(i&UART_INTSTS_THREINT_Msk)
	{
		UART_DisableInt(UART0,UART_INTEN_THREIEN_Msk);
		if(fp_ptr.start<fp_ptr.stop)
		{
			UART0->LINE|=0x30;
			while(fp_ptr.start<fp_ptr.stop)
			{
				if(UART0->FIFOSTS&(1<<23))break;
				UART0->DAT=*fp_ptr.start++;
				UART_EnableInt(UART0,UART_INTEN_THREIEN_Msk);
			}
		}
		else
		{
			UART0->LINE&=~0x10;
			UART0->DAT=0xAB;
			fp_add(0,0);
		}
	}
	if(i&UART_INTSTS_RDAINT_Msk)
	{
		static u8*t;
		while(UART_IS_RX_READY(UART0))
		{
			u8 d=UART0->DAT;
			if(t<(u8*)&fp_rx)t=(u8*)&fp_rx;
			if(t<&fp_rx.rxf)*t++=d;
			if(UART0->FIFOSTS&8&&d==0xAB)
			{
				t=(u8*)&fp_rx;
				crc32(fp_rx.rx.buf,fp_rx.rx.len);
				CRC_WRITE_DATA(fp_rx.rx.len);
				CRC_WRITE_DATA(fp_rx.rx.len>>8);
				CRC_WRITE_DATA(fp_rx.rx.cmd);
				if(CRC->CHECKSUM==fp_rx.rx.crc)fp_rx.rxf=1;
			}
			UART0->FIFOSTS|=8;
		}
	}
}
//
void UART0_init(u32 br)
{
	CLK_EnableModuleClock(UART0_MODULE);
	SYS_ResetModule(UART0_RST);
	UART_Open(UART0,br);
//
	UART0->LINE=UART_WORD_LEN_8|UART_PARITY_ODD|UART_STOP_BIT_1|0x28;
	NVIC_EnableIRQ(UART0_IRQn);
	UART_EnableInt(UART0,UART_INTEN_THREIEN_Msk|UART_INTEN_RDAIEN_Msk);
	UART0->FUNCSEL=3;
	UART0->ALTCTL=0xAB008000;
	fp_add(0,0);
}
//


