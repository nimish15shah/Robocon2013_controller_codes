/*
 * CProgram1.c
 *
 * Created: 22-12-2012 06:16:05
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

void comm_send(char comm_instruction)
{
	COMM_DDR= 0xFF;
	COMM_PORT= comm_instruction & 0b01111111;	
	COMM_PORT |= _BV(COMM_START);
	
	_delay_ms(1); // to wait for M32 to understant and analyze the signal

	COMM_DDR= 0x00;
	COMM_PORT= 0xFF;
}
