
#include "M480.h"
#include "D:\PROJECTS_ARTEM\INC\ARM\type.h"
#include "..\MAIN\pins.h"
#include "delay.h"
#include "string.h"
#include "stdio.h"
#include "..\MAIN\address.h"


#define DEF_PASS					0x5A5E783A

#define ADC_ERR 					0
#define OFS		 						10
#define FLTR		 					100

#define RAB_CLS						8
#define RAB_OPN						5
//
u8 to_sw;
u16 RAB_busy;
u16 tmr;
u8 tick;
u8 blink;
u8 to_send;
u8 to_save;
u8 to_boot;
u8 manual;
s8 rot;
u8 rel;
u8 key;
u8 eeprom_temp1=0;
u8 eeprom_temp2=0;
u8 leds;
u8 fadc;
u16 color;

//
float za,zb,zc,zd,ze;
//

//
u32 del_tmr[7];
u16 batt;
u32 hold;

//
void sim_send(u8 n,u8*t);
void save_param(void);
void read_param(void);
void sw(u8 x);
//
void CLK_Init(void);
void PIN_Init(void);

