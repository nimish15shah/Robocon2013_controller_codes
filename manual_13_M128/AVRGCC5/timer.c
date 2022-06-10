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

void init_timer()
{
// Initialize Timer-2 for time base of Shaft Encoders 
	TCCR2= 0b00001101;	// CTC mode, 1024 prescaler at 8Mhz for 10ms delay
	OCR2= 255;//78;	//10ms delay
	TIMSK |= _BV(OCIE2);	// Interrupt at Compare match enable

	TCCR2= 0b00001000;	// Timer Stopped, Will be started when required


// Initialize timers for Base Motors
	// Timer-1
	TCCR1A= 0b10101001;	//8-bit fast PWM,
	TCCR1B= 0b00001010; //Prescaler-8 at 8Mhz to get 
						// PWM frequency of 4Khz
	OCR1AH= 0x00;
	OCR1AL= 0x00;

	OCR1BH= 0x00;
	OCR1BL= 0x00;
	
	OCR1BH= 0x00;
	OCR1BL= 0x00;

	TIMSK |= (1<<TOIE1);

	// Timer-3
	TCCR3A= 0b10101001;	//8-bit fast PWM,
	TCCR3B= 0b00001010; //Prescaler-8 at 8Mhz to get 
						// PWM frequency of 4Khz
	OCR3AH= 0x00;
	OCR3AL= 0x00;

	OCR3BH= 0x00;
	OCR3BL= 0x00;
	
	OCR3BH= 0x00;
	OCR3BL= 0x00;

	ETIMSK |= (1<<TOIE3);

	// Timer-0 
	TCCR0= 0b01101010;	//Fast PWM, Prescaler-8
	OCR0= 0x00;
}


ISR(TIMER1_OVF_vect)
{
	OCR1AH= 0x00;
	OCR1AL= pwm_right;

	OCR1BH= 0x00;
	OCR1BL= pwm_left;

	OCR1CH= 0x00;
	OCR1CL= pwm_down;
}

ISR(TIMER3_OVF_vect)
{
	OCR3AH= 0x00;
	OCR3AL= pwm_bud;
}

ISR(TIMER0_OVF_vect)
{
	OCR0= pwm_up;
}


ISR(TIMER2_COMP_vect)
{
	count_prescaler++;
	if(count_prescaler==1)
	{
		count_prescaler=0;
		if(count_left != desired_count_left)
		{
			error_count_left= desired_count_left-count_left;		
			error_pwm_left= /*error_factor*/7 * error_count_left;
			pwm_left= pwm_left + (0.1* error_count_left/1);
			if(pwm_left<0)
			{
				pwm_left=0;
			}
		
			if(pwm_left>255)
			{
				pwm_left=255;
			}
	
		}

		if(count_right != desired_count_right)
		{
			error_count_right= desired_count_right-count_right;		
			error_pwm_right= /*error_factor*/7 * error_count_right;
			pwm_right= pwm_right + (0.1* error_count_right/1);

			if(pwm_right<0)
			{
				pwm_right=0;
			}
		
			if(pwm_right>255)
			{
				pwm_right=255;
			}
		}
		rpm_measured_l= (count_left*600)/ 36;
		rpm_measured_r= (count_right*600)/ 36;

		count_right=0;
		count_left=0;
		PORTD= PORTD ^ _BV(PD5);
	}
}



