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


ISR(INT0_vect)
{
	count_right++;
	count_r_units++;

	if(count_r_units>10000)
	{
		count_r_tens++;
		count_r_units=0;
	}

	if(count_r_tens>10000)
	{
		count_r_tens=0;
		count_r_hund++;
	}
	
}

ISR(INT1_vect)
{
	count_left++;
	count_l_units++;

	if(count_l_units>10)
	{
		count_l_tens++;
		count_l_units=0;
	}

	if(count_l_tens>10)
	{
		count_l_tens=0;
		count_l_hund++;
	}
}


ISR(INT2_vect)
{
	count_up++;
	count_u_units++;

	if(count_u_units>10000)
	{
		count_u_tens++;
		count_u_units=0;
	}

	if(count_u_tens>10000)
	{
		count_u_tens=0;
		count_u_hund++;
	}
}


void init_shaft_parameters()
{
	/* Factor that is when multiplied with error in pulse-count
	 will give equivalent pwm error */
	error_factor= 7;//(60.0*1000.0*256.0)/(REFRESH_TIME*360.0*MAX_RPM);
	
	EICRA = 0xFF;	// Rising Edge on Interupt 0 and 1
	EIMSK |= _BV(INT0) | _BV(INT1);
}


void start_shaft_velocity(int rpm_left, int rpm_right)
{
	desired_pwm_left= 145;//(500 * 256/ 600);
	desired_pwm_right= 185;//(rpm_right * 256/ MAX_RPM);

	desired_count_left= 0.91*50;//(rpm_left*360.0*float_convert/(60.0*1000))*REFRESH_TIME; // Time in ms, 360PPR
	desired_count_right= 50;//(rpm_right*360.0*float_convert/(60.0*1000))*REFRESH_TIME; // Time in ms, 360PPR
	
	pwm_right= desired_pwm_right;
	pwm_left=  desired_pwm_left;
//	display_num(pwm_right,4,1,1);
//	display_num(pwm_left,4,2,1);
	TCCR2= 0b00001101;	// start timer
	count_left=0;
	count_right=0;
	
}

void stop_shaft_velocity()
{
	TCCR2= 0b00001000;	// start timer
}
