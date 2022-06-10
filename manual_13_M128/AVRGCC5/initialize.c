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

void initialize()
{
	init_ports();
	init_variables();
	init_timer();
	init_shaft_parameters();
//	if(LCD==1)
	{
		init_LCD();
	}
}

void init_ports()
{
	MOTOR_DIRECTION_DDR= 0xFF;
	MOTOR_DRIVE_L_DDR |= _BV(MOTOR_DRIVE_L_PWM);
	MOTOR_DRIVE_R_DDR |= _BV(MOTOR_DRIVE_R_PWM);
	MOTOR_SLIDE_D_DDR |= _BV(MOTOR_SLIDE_D_PWM);
	MOTOR_SLIDE_U_DDR |= _BV(MOTOR_SLIDE_U_PWM);
	PORTB &= 0x0F;	// Without declaration of Macro for Pwm pins
/*	MOTOR_BUD_DDR |= _BV(MOTOR_BUD_PWM) | _BV(MOTOR_BUD_1) | _BV(MOTOR_BUD_2);
	MOTOR_BUD_PORT &= ~(_BV(MOTOR_BUD_PWM)) & ~(_BV(MOTOR_BUD_1)) & ~(_BV(MOTOR_BUD_2));
*/
	ENCODER_DDR &= ~(_BV(ENCODER_R)) & ~(_BV(ENCODER_L)) & ~(_BV(ENCODER_U));
	ENCODER_PORT |= _BV(ENCODER_R) | _BV(ENCODER_L) | _BV(ENCODER_U);
	
	LEFT_LINE_SENSOR_DDR &= ~(_BV(LEFT_LINE_SENSOR_1)) & ~(_BV(LEFT_LINE_SENSOR_2));
	LEFT_LINE_SENSOR_PORT |= _BV(LEFT_LINE_SENSOR_1) | _BV(LEFT_LINE_SENSOR_2);
	RIGHT_LINE_SENSOR_DDR &= ~(_BV(RIGHT_LINE_SENSOR_1)) & ~(_BV(RIGHT_LINE_SENSOR_2));
	RIGHT_LINE_SENSOR_PORT |= _BV(RIGHT_LINE_SENSOR_1) | _BV(RIGHT_LINE_SENSOR_2);
}

void init_variables()
{
	LCD=0;

	float_convert=1;
	count_left=0;
	count_right=0;
	count_up=0;
	count_r_units=0;
	count_r_tens=0;
	count_r_hund=0;
	count_l_units=0;
	count_l_tens=0;
	count_l_hund=0;
	count_u_units=0;
	count_u_tens=0;
	count_u_hund=0;
	pwm_left=0;
	pwm_right=0;
	pwm_bud=0;
	pwm_up=0;
	pwm_down=0;
}
