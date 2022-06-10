
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

int main(void)
{
	sei();
	initialize();
	PORTD |= _BV(PD5);
//	forward(175);
	
	PORTA = 0b00011001;//0b00101000;
	PORTB |= _BV(PB4);
//	pwm_up=0;
	pwm_left=100;
	pwm_right=100;
	_delay_ms(10000);
	breaks('a');
	pwm_up=0;
	pwm_left=0;
	pwm_right=0;
		
	while(1)
	{
		;	
	}
	pwm_right=185;
	pwm_left= 145;
	_delay_ms(800);
	start_shaft_velocity(200,200);
//	while(1);
	while(count_l_hund<60)
	{
		desired_rpm_l= rpm_measured_l;
		desired_rpm_r= rpm_measured_r;
		last_pwm_left= pwm_left;
		last_pwm_right= pwm_right;
	}
	stop_shaft_velocity();
	breaks('a');
	pwm_right=0;
	pwm_left=0;
	while(1)
	{

		display_num(rpm_measured_r,3,1,1);
		display_num(rpm_measured_l,3,2,1);
		display_num(desired_rpm_r,3,1,5);
		display_num(desired_rpm_l,3,2,5);
		display_num(desired_count_left,2,2,11);
		display_num(desired_count_right,2,1,11);
		display_num(last_pwm_left,3,2,14);
		display_num(last_pwm_right,3,1,14);

	}
	display_num(count_l_hund,8,1,1);
	PORTA= 0x00;
	while(1)
	{
//		PORTE= count_r_units & 0xFF;
		;
	}

	while (remote_value==21)
	{
			scan_remote();
	}
	
	switch (remote_value)
	{
		case 1 :
			init_path_1();
			execute_path_1();
	 		break;
		
		case 2 :
			break;
		
	}

}
