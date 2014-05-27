/*Arduino-like SPI library for STC*********************/
/*Add Function: SPI_pin for SPI pin to switch location*/
/*Diff: SPI_begin has mode select
**For master mode, */

#include	"SPI.h"

void	SPI_begin(u8 mode)
{
	SPCTL = (SPCTL & ~SPI_ENABLE_MASK) | SPI_ENABLE;
	if(mode == SPI_MODE_Master) {
		SPCTL |= (1<<4);
  } else {
		SPCTL &= ~(1<<4);
  }
	SPSTAT = SPIF + WCOL;
}

/*Arduino-like interrupt function*******/
/*System interrupt has to be enabled****/
/*Function: Enable or disable interrupt*/

void	SPI_attachInterrupt(void)
{
	IE2 |=  (1<<1);
}
void	SPI_detachInterrupt(void) 
{
	IE2 &= ~(1<<1);
}

/*Arduino-like transfer function****************/
/*INPUT: the data you want to transfer to slave*/
/*Return: the date returned by slave************/

u8	SPI_transfer(u8 SPI_data)
{
	SPDAT = SPI_data;
	while(!(SPSTAT & SPIF))	;
	SPSTAT = SPIF + WCOL;	
	return (SPDAT);
}

/*Arduino-like setBitOrder function*/
/*INPUT: LSBFIRST MSBFIRST**********/
/*Default: MSBFIRST*****************/

void	SPI_setBitOrder(u8 bitOrder)
{
  if(bitOrder == LSBFIRST) {
		SPCTL |= (1<<5);
  } else {
		SPCTL &= ~(1<<5);
  }
}

/*Arduino-like setDataMode function***********************/
/*INPUT: SPI_MODE0 SPI_MODE1 SPI_MODE2 SPI_MODE3*********/
/*Default: SPI_MODE1*************************************/
/*Fuction: Change the DataMode just as described at *****/
/*en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus */

void	SPI_setDataMode(u8 dataMode)
{
	SPCTL = (SPCTL & ~SPI_MODE_MASK) | dataMode;
}

/*Arduino-like setClockDivider function*/
/*INPUT: SPI_CLOCK_DIV4 SPI_CLOCK_DIV8 **
**SPI_CLOCK_DIV16 SPI_CLOCK_DIV32*******/
/*Default: SPI_CLOCK_DIV4***************/

void	SPI_setClockDivider(u8 rate)
{
	SPCTL = (SPCTL & ~SPI_CLOCK_MASK) | rate;
}

/*NEW SPI_pin function**************/
/*INPUT: SPI_PIN0 SPI_PIN1 SPI_PIN2*/
/*Default: SPI_PIN0*****************/

void	SPI_pin(u8 pinSelect)
{
	AUXR1 = (AUXR1 & ~SPI_PIN_MASK) | pinSelect;
}
