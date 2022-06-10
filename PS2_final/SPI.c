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
	SPCR= 0b01111101;
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

void SPI_send_array(char *a, char cmd_length)
{
	int spi_send_array_i;
	for(spi_send_array_i=0; spi_send_array_i<cmd_length; spi_send_array_i++)
	{
		data_array[spi_send_array_i]= SPI_send(*a);
		a++;
	}
}

void SPI_STC_vect()
{
	_delay_us(30);
	data_array[spi_i]= SPDR;
	if(spi_i>8)
	{
		spi_i=0;
		SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
		_delay_ms(20);
		SPI_DDR= 0x00;
		SPI_PORT= 0x00;
		_delay_ms(10);
		SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
		SPI_PORT |= _BV(MISO_PIN);
		_delay_ms(1);
		SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
		a=0;
		b=0;
		c=0;
		SPDR= PS2_POLLBUTTON[spi_i];
	}
	else
	{
		spi_i++;
		SPDR= PS2_POLLBUTTON[spi_i];
	}
}
