#ifndef _CONFIG_H
#define _CONFIG_H
/**************************/
#include "reg51.h"
typedef 	unsigned char	u8;
sfr SPSTAT = 0xCD;
sfr SPCTL  = 0xCE;
sfr SPDAT  = 0xCF;
sfr IE2   = 0xAF;
sfr AUXR1 = 0xA2;

#define	SPIF	0x80
#define	WCOL	0x40
/**************************/

#endif
