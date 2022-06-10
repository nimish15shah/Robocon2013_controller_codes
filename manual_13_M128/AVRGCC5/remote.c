/*
 * CProgram1.c
 *
 * Created: 22-12-2012 04:22:02
 *  Author: compaq
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "initialize.h"
#include "LCD.h"
#include "hardware.h"
#include "timer.h"
#include "steering.h"
#include "shaft_parameters.h"
#include "macros.h"
#include "comm.h"
#include "path_1.h"
#include "path_2.h"
#include "remote.h"

void scan_remote()
{
	DDRB &= 0xF0; // configuring Keypad pins as inputs in case not configured
	PORTB |= 0x0F;
	DDRE &= ~(_BV(PE6)) & ~(_BV(PE7));
	PORTE |= _BV(PE6) | _BV(PE7);
	
	if( ((~PINB) & 0b00000111) ) 
	{
		remote_value= ((~PINB) & 0b00000111);
	}
	
	else if (bit_is_clear(PINB,PB3))
	{
		remote_value= 8;
	}

	else if (bit_is_clear(PINE,PE6))
	{
		remote_value= 9;
	}

	else if (bit_is_clear(PINE,PE7))
	{
		remote_value= 0;
	}

	else
	{
		remote_value= 21;
	}
}

void remote_path()
{
	while (remote_value == 21)
	{
		scan_remote();
	}
	
}
