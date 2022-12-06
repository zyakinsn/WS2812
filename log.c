

Tlog dlog;
#define LOG_MAX_MASK			0x0FFF
#define LOG_SIZE					((sizeof(Tlog)/8+((sizeof(Tlog)%8)?1:0))*8)
#define LOG_BUF_SIZE			512	
#define LOG_LEN						LOG_BUF_SIZE/LOG_SIZE

typedef struct Trd
{
	u8*b;
	u16 len;
}Trd;
//
u8 log_stat;
enum LOG_CAUSE
{
	N0LL,
	WEB,
	SNMP,
	AUTOMATIC_ERR,
	AUTOMATIC_OK,
	CRITICAL_OFF,
	ALARM_B,
	OK_B
}LOG_CAUSE;
//
Trd read_log(u16 adr,u16 mask,u16 max,u16 cnt,u8*buf);
void write_log(u32 adr,u16 cnt,u8*d);
//
struct point
{
	u16 start;
	u16 stop;
}point;
//
void set_log()
{
//	dlog.time=time;
	dlog.line=log_stat==CRITICAL_OFF?0x80:par.line;
	dlog.cause=log_stat;
//
	if(I2C_ReadBuf(I2C1,0xD0,10,&point,sizeof(point)))return;
	point.start&=LOG_MAX_MASK;
	point.stop&=LOG_MAX_MASK;
	u32 a=ADDRESS_LOG+(u32)point.stop*LOG_SIZE;
	if(a>=ADDRESS_LOG&&a<(ADDRESS_LOG+0x10000))write_log(a,sizeof(dlog),(u8*)&dlog);
	point.stop=(point.stop-1)&LOG_MAX_MASK;
	if(point.stop>=point.start)point.start=(point.stop-1)&LOG_MAX_MASK;	
	I2C_WriteBuf(I2C1,0xD0,10,(u8*)&point,sizeof(point));
//
	log_stat=0;
}
//
u8*get_log(u16 adr,u8*buf)
{
	Trd r;
	u16*d=(u16*)buf;
//
	d[0]=0;
	d[1]=0;
	if(I2C_ReadBuf(I2C1,0xD0,10,&point,sizeof(point)))return buf;
//
	if(point.stop==point.start){*d++=0;*d++=0;}
	else
	{
		u16 a=point.stop+adr;
		d[0]=adr;
		if(point.start>point.stop)
		{
			if(a<LOG_MAX_MASK)
			{
				d[1]=LOG_LEN;
				r=read_log(a+1,LOG_MAX_MASK,point.start,LOG_LEN,&buf[4]);
				if(r.len<LOG_LEN)d[1]=r.len;
			}
		}
		else
		{
			if(a<=LOG_MAX_MASK)
			{
				a=(a+1)&LOG_MAX_MASK;
				r=read_log(a,LOG_MAX_MASK,point.start,LOG_LEN,&buf[4]);
				d[1]=r.len;
//				if(r.len<LOG_LEN)
//				{
////					a=(r.len+a)&LOG_MAX_MASK;
////					d[0]=a;
////					
////					r=read_log(a,LOG_MAX_MASK,point.start,LOG_LEN,&buf[4+r.len*LOG_SIZE]);
////					d[1]=r.len;
//					
//					
//				}
			}
			else
			{
				a&=LOG_MAX_MASK;
				r=read_log(a,LOG_MAX_MASK,point.start,LOG_LEN,&buf[4]);
				d[1]=r.len;
			}
		}
		if(adr>LOG_MAX_MASK)d[1]=0;
	}
	return buf;
}
//









