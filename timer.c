




void timer()
{
	static s8 f[7];
	const u8 WD[8]=
	{
		0x40,
		0x01,
		0x02,
		0x04,
		0x08,
		0x10,
		0x20,
		0x00
	};
	u8 day=WD[time.day];
	for(u8 i=0;i<7;i++)
	{
		if(timers[i].day&day)
		{
			if(time.h==timers[i].time[0].h&&
				 time.m==timers[i].time[0].m&&
				 time.s==timers[i].time[0].s&&f[i]<=0)
			{
				f[i]=1;
				par.out[i]=1;
			}
			else
			if(time.h==timers[i].time[1].h&&
				 time.m==timers[i].time[1].m&&
				 time.s==timers[i].time[1].s&&f[i]>=0)
			{
				f[i]=-1;
				par.out[i]=0;
			}else f[i]=0;
		}else f[i]=0;
	}
}
//










