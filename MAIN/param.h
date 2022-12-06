typedef __packed struct TDateTime
{
	u8 year;
	u8 month;
	u8 date;
	u8 day;
	u8 h;
	u8 m;
	u8 s;
}TDateTime;
//
typedef __packed struct Ttime
{
	u8 h;
	u8 m;
	u8 s;
}Ttime;
//
typedef __packed struct Tmsm
{
	u8 m;
	u8 s;
	u16 ms;
}Tmsm;
//
typedef __packed struct Tlog
{
	TDateTime time;//7 bytes
	u8 line;
	u8 cause;
	u8 t[7];
}Tlog;
//
typedef __packed struct Tip
{
	u8 adr[4];
	u8 mask[4];
	u8 gate[4];
	u8 ntp[2][4];
	u8 snmp_serv[2][4];
	u8 snmp_public[16];
	u8 snmp_private[16];
	u8 snmp_trap[16];
}Tip;
//
typedef __packed struct Tval
{
	u16 voltA;
	u16 voltB;
	u16 current;
	s16 phase;
	s16 temp;
	u8 hum;
	s16 vAbuf  [256];
	s16 vBbuf  [256];
	s16 cur_buf[256];
}Tval;
//
typedef __packed struct Ttmr
{
	Tmsm delay;
	Ttime time[2];
	u8 day;
}Ttmr;
//
typedef __packed struct Tpar
{
	u8 line;
	u8 out[7];
	u8 sw0;
	u8 _auto;
	u8 fixB;
	u16 max;
	u16 min;
	u8 hold_b;
	u8 full_off;
	s8 tz;
	u8 ntp_en;
	
	u8 bright;
	UU16 led[8];	
	
	float fft[512];
	u8 sin;
}Tpar;
//
typedef __packed struct Tstat
{
	u8 ntp_val;
}Tstat;
//
typedef __packed struct Tcap
{
	u8 model[32];
	u8 chan[7][16];
}Tcap;
//
























