
//
#define SPI_busy					while(SPI0->STATUS&1)

//
u32 SPI(u32 d)
{
	SPI0->TX=d;
	SPI_busy;
	return SPI0->RX;
}
//

