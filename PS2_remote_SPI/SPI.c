#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "PS2.h"
#include "SPI.h"
#include "LCD.h"

void SPI_init()
{


	// All pins o/p except MISO, Pull up enabled on MISO
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	
	// SPI interrupt disabled, SPI enable, will be enabled after initialization
	// LSB first, Master Mode,
	// First edge of Clock- Falling
	// Sample on Trailling Edge
	// Clock Frequency 500kHz for 8MHZ crystal
	SPCR= 0b00111101;
}

char SPI_send(char send_x)
{
	
	SPDR= send_x;
	while(!(SPSR & _BV(SPIF)))
	{
		;
	}		
	_delay_us(30);
	send_x= SPDR;

	return(send_x);
}

void SPI_STC_vect()
{	
}
