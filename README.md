SPI_STC
=======
Basically the same as Arduino, just view http://arduino.cc/en/Reference/SPI for reference.
Add function: SPI_pin for SPI pin to switch.
Diff function: 1. SPI_begin need a parameter for master and slave(I use 15L CPU so slave fuction was not complete right now)

2. SPI_setClockDivider only has four input choices because of hardware limitation:
SPI_CLOCK_DIV4
SPI_CLOCK_DIV16
SPI_CLOCK_DIV64
SPI_CLOCK_DIV128	

ATTENTION: 1. according to offical document, when CPHA=0, SSIG should be 0 too. Which is not solved yet.

2. When using interrupt, you should first enable the interrupt in CPU by yourself.
