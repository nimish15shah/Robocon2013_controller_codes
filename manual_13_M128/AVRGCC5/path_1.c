/*
 * CProgram1.c
 *
 * Created: 22-12-2012 04:57:13
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

void init_path_1()
{
	volatile char task_flag=0;
	// Valves all open
		comm_send(1);

	// Initializing Front Motors
		ARM_LINEAR_SWITCH_DDR &= ~(_BV(ARM_LINEAR_SWITCH));
		ARM_LINEAR_SWITCH_PORT |= _BV(ARM_LINEAR_SWITCH);
		ARM_ANGLE_SWITCH_DDR &= ~(_BV(ARM_ANGLE_SWITCH));
		ARM_ANGLE_SWITCH_PORT |= _BV(ARM_ANGLE_SWITCH);
		comm_send(10);	// Both motors Breaked

		while (task_flag != 0x0F)
		{
		// initializing Front Arm's Hieght
			if(bit_is_set(ARM_LINEAR_SWITCH_PIN,ARM_LINEAR_SWITCH))
			{
				comm_send(13);
			}
			else
			{
				comm_send(11);
				task_flag |= _WV(0);
			}
		// Initializing Front Arm's Angle
			if(bit_is_set(ARM_ANGLE_SWITCH_PIN,ARM_ANGLE_SWITCH))
			{
				comm_send(15);
			}
			else
			{
				comm_send(14);
				task_flag |= _WV(1);
			}
		// Initializing Bud Angle
			if (bit_is_set(BUD_ANGLE_SWITCH_PIN,BUD_ANGLE_SWITCH))
			{
				bud_up(255);
			} 
			else
			{
				breaks('b');
				task_flag |= _WV(2);
			}
		// Initializing Electromagnet
			if(bit_is_set(ELECTROMAGNET_CONTACT_SWITCH_PIN,ELECTROMAGNET_CONTACT_SWITCH))
			{
				comm_send(25);				
			}		
			else
			{
				comm_send(21);
				if (bit_is_set(ELECTROMAGNET_LIMIT_SWITCH_PIN,ELECTROMAGNET_LIMIT_SWITCH))
				{
					comm_send(24);
				} 
				else
				{
					comm_send(20);
					task_flag |= _WV(3);
				}
			}
		// Everything Initialized
		}

}


void execute_path_1()
{
	volatile char check_flag=0;	
	
}
