#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "PS2.h"
#include "SPI.h"
#include "LCD.h"

/*
void PS2_init()
{
//	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
// Just for fun- Sending cmd 0x42 and polls the data
/*
//while(1)
{
	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
	a=0;
	b=0;
	c=0;
	a= SPI_send(0x01);	//initializeing conversation
	b= SPI_send(0x42);	// Command
	c= SPI_send(0x00); // 3rd Byte of Header byte

	d= SPI_send(0x00); // 6 time pass bytes
	e= SPI_send(0x00); // 6 time pass bytes
	f= SPI_send(0x00); // 6 time pass bytes
	g= SPI_send(0x00); // 6 time pass bytes
	h= SPI_send(0x00); // 6 time pass bytes
	i= SPI_send(0x00); // 6 time pass bytes
	g= SPI_send(0x00); // 6 time pass bytes
	h= SPI_send(0x00); // 6 time pass bytes
	i= SPI_send(0x00); // 6 time pass bytes

	g= SPI_send(0x00); // 6 time pass bytes
	h= SPI_send(0x00); // 6 time pass bytes
	i= SPI_send(0x00); // 6 time pass bytes
	g= SPI_send(0x00); // 6 time pass bytes
	h= SPI_send(0x00); // 6 time pass bytes
	i= SPI_send(0x00); // 6 time pass bytes

	g= SPI_send(0x00); // 6 time pass bytes
	h= SPI_send(0x00); // 6 time pass bytes
	i= SPI_send(0x00); // 6 time pass bytes
	g= SPI_send(0x00); // 6 time pass bytes
	h= SPI_send(0x00); // 6 time pass bytes
	i= SPI_send(0x00); // 6 time pass bytes

	_delay_us(30);
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low

	display_hex(a,0,1,1);
	display_hex(b,0,1,5);
	display_hex(c,0,1,9);
	display_binary(d,2,1);
	display_binary(e,2,10);
//	display_num(f,3,2,9);
	_delay_ms(1000);
//	while(1);
}

// Enter Config Mode- Command 0x43

	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
//	SPCR |= _BV(SPE);
	a=0;
	b=0;
	c=0;
//	d=0;
	a= SPI_send(0x01);	//initializeing conversation
	b= SPI_send(0x43);	// Command
	c= SPI_send(0x00); // 3rd Byte of Header byte
	
	d= SPI_send(0x01); // 6 time pass bytes
	e= SPI_send(0x00); // 6 time pass bytes
	display_hex(a,0,1,1);
	display_hex(b,0,1,5);
	display_hex(c,0,1,9);
	display_binary(d,2,1);
	display_binary(e,2,10);

	
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
//	SPCR &= ~(_BV(SPE));
	_delay_ms(20);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(10);
//	while(1);
// Enter Analog Mode- Command 0x44
	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
	a=0;
	b=0;
	c=0;
	a= SPI_send(0x01);	//initializeing conversation
	b= SPI_send(0x44);	// Command
	c= SPI_send(0x00); // 3rd Byte of Header byte
	
	d= SPI_send(0x01); // 6 time pass bytes
	e= SPI_send(0x03); // 6 time pass bytes
	f= SPI_send(0x00); // 6 time pass bytes
	g= SPI_send(0x00); // 6 time pass bytes
	h= SPI_send(0x00); // 6 time pass bytes
	i= SPI_send(0x00); // 6 time pass bytes

	display_hex(a,0,1,1);
	display_hex(b,0,1,5);
	display_hex(c,0,1,9);
	display_binary(d,2,1);
	display_binary(e,2,10);

	
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
	_delay_ms(20);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(1);
	
// Setup motors- 0x4D
	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
	a=0;
	b=0;
	c=0;

	a= SPI_send(0x01);	//initializeing conversation
	b= SPI_send(0x4D);	// Command
	c= SPI_send(0x00); // 3rd Byte of Header byte
	
	d= SPI_send(0x00); // 6 time pass bytes
	e= SPI_send(0x01); // 6 time pass bytes
	f= SPI_send(0xff); // 6 time pass bytes
	g= SPI_send(0xff); // 6 time pass bytes
	h= SPI_send(0xff); // 6 time pass bytes
	i= SPI_send(0xff); // 6 time pass bytes

	display_hex(a,0,1,1);
	display_hex(b,0,1,5);
	display_hex(c,0,1,9);
	display_binary(d,2,1);
	display_binary(e,2,10);
	
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
	_delay_ms(10);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(1);
//Enable Pressure on switches- 0x4F
	a= SPI_send(0x01);	//initializeing conversation
	a= SPI_send(0x4F);	// Command
	a= SPI_send(0x00); // 3rd Byte of Header byte
	
	a= SPI_send(0xFF); // 6 time pass bytes
	a= SPI_send(0xFF); // 6 time pass bytes
	a= SPI_send(0x03); // 6 time pass bytes
	a= SPI_send(0x00); // 6 time pass bytes
	a= SPI_send(0x00); // 6 time pass bytes
	a= SPI_send(0x00); // 6 time pass bytes
	
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
	_delay_ms(10);
	_delay_ms(20);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(1);

//Exit Config Mode- 0x43
	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
	a=0;
	b=0;
	c=0;
	a= SPI_send(0x01);	//initializeing conversation
	b= SPI_send(0x43);	// Command
	c= SPI_send(0x00); // 3rd Byte of Header byte
	
	d= SPI_send(0x00); // 6 time pass bytes
	f= SPI_send(0x5A); // 6 time pass bytes
	g= SPI_send(0x5A); // 6 time pass bytes
	h= SPI_send(0x5A); // 6 time pass bytes
	i= SPI_send(0x5A); // 6 time pass bytes
	j= SPI_send(0x5A); // 6 time pass bytes
	
	display_hex(a,0,1,1);
	display_hex(b,0,1,5);
	display_hex(c,0,1,9);
	display_binary(d,2,1);
	display_binary(e,2,10);
	
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
	_delay_ms(20);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(1);

	SPCR |= _BV(SPIE);
	spi_i=0;
	SPDR= PS2_POLLBUTTON[spi_i];
}
*/
void read_values()
{
	SPI_PORT &= ~(_BV(SS_PIN));
	a=0;
	b=0;
	c=0;
	a= SPI_send(0x01);	//initializeing conversation
	a= SPI_send(0x42);	// Command
	a= SPI_send(0x00); // 3rd Byte of Header byte
	
	a= SPI_send(0x00); // 6 time pass bytes
	b= SPI_send(0x00); // 6 time pass bytes
	c= SPI_send(0x00); // 6 time pass bytes
	d= SPI_send(0x00); // 6 time pass bytes
	e= SPI_send(0x00); // 6 time pass bytes
	f= SPI_send(0x00); // 6 time pass bytes


	g= SPI_send(0x00); // 6 time pass bytes
	h= SPI_send(0x00); // 6 time pass bytes
	i= SPI_send(0x00); // 6 time pass bytes
	j= SPI_send(0x00); // 6 time pass bytes
	k= SPI_send(0x00); // 6 time pass bytes
	l= SPI_send(0x00); // 6 time pass bytes

	m= SPI_send(0x00); // 6 time pass bytes
	n= SPI_send(0x00); // 6 time pass bytes
	o= SPI_send(0x00); // 6 time pass bytes
	p= SPI_send(0x00); // 6 time pass bytes
	q= SPI_send(0x00); // 6 time pass bytes
	r= SPI_send(0x00); // 6 time pass bytes

	display_hex(c,0,1,1);
	display_hex(d,0,1,4);
	display_hex(e,0,1,7);
	display_hex(f,0,1,10);
	display_hex(g,0,1,13);

	display_hex(h,0,2,1);
	display_hex(k,0,2,4);
	display_hex(l,0,2,7);
	display_hex(m,0,2,10);
	display_hex(n,0,2,13);

	SPI_PORT |= _BV(SS_PIN);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(1);

}

void PS2_init()
{
	char  PS2_CONFIGMODE[5]= {0x01, 0x43, 0x00, 0x01, 0x00};
	char  PS2_ANALOGMODE[9]= {0x01, 0x44, 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00};
	char  PS2_SETUPMOTOR[9]= {0x01, 0x4D, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff};
//	char  PS2_RETURNPRES[9]= {0x01, 0x4f, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00};
	char  PS2_EXITCONFIG[9]= {0x01, 0x43, 0x00, 0x00, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a};

// Enter Config mode
	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
	a=0;
	b=0;
	c=0;
	SPI_send_array(PS2_CONFIGMODE,5);		
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
	_delay_ms(20);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(1);

// Enter Analog Mode
	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
	a=0;
	b=0;
	c=0;
	SPI_send_array(PS2_ANALOGMODE,9);		
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
	_delay_ms(20);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(1);
// Setup Motor
	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
	a=0;
	b=0;
	c=0;
	SPI_send_array(PS2_SETUPMOTOR,9);		
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
	_delay_ms(20);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(1);
// Exit Config
	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
	a=0;
	b=0;
	c=0;
	SPI_send_array(PS2_EXITCONFIG,9);
	SPI_PORT |= _BV(SS_PIN);	// Driving Attention Low
	_delay_ms(20);
	SPI_DDR= 0x00;
	SPI_PORT= 0x00;
	_delay_ms(10);
	SPI_DDR |= (_BV(MOSI_PIN)) | _BV(SCK_PIN) | _BV(SS_PIN);
	SPI_PORT |= _BV(MISO_PIN);
	_delay_ms(1);

	SPCR |= _BV(SPIE);
	spi_i=0;

	volatile char ps2_init_array[9]= {0x01, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	volatile int ps2_init_i;
	for(ps2_init_i=0; ps2_init_i<10; ps2_init_i++)
	{
		PS2_POLLBUTTON[ps2_init_i] = ps2_init_array[ps2_init_i];
	}

	SPI_PORT &= ~(_BV(SS_PIN));	//ATT held low	
	a=0;
	b=0;
	c=0;
	SPDR= PS2_POLLBUTTON[spi_i];

}
