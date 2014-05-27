#ifndef	__SPI_H
#define	__SPI_H

#include	"STC15Fxxxx.H"

#define	SPI_MODE_Master	1
#define	SPI_MODE_Slave 	0
#define SPI_ENABLE 0xC0
#define SPI_ENABLE_MASK 0xC0

#define MSBFIRST 1
#define LSBFIRST 0

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C
#define SPI_MODE_MASK 0x0C

#define SPI_CLOCK_DIV4		0x00
#define SPI_CLOCK_DIV16 	0x01
#define SPI_CLOCK_DIV64 	0x02
#define SPI_CLOCK_DIV128	0x03
#define SPI_CLOCK_MASK 		0x03

#define SPI_PIN0	0x00
#define SPI_PIN1	0x04
#define SPI_PIN2	0x08
#define SPI_PIN_MASK 0x0C

void	SPI_begin(u8 mode);
void	SPI_attachInterrupt(void);
void	SPI_detachInterrupt(void);
void	SPI_setBitOrder(u8 bitOrder);
void	SPI_setDataMode(u8 dataMode);
void	SPI_setClockDivider(u8 rate);
void	SPI_pin(u8 pinSelect);
u8 SPI_transfer(u8 SPI_data);

#endif
