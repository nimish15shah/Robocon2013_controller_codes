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


void wall_follow()
{
	forward(255);
}

void curve_follow()
{
	last_left_line_read= left_line_read;
	last_right_line_read= right_line_read;
	
	// last two bits: units<->Left_sensor_1 and tens<->Left_sensor_2
	left_line_read = ((LEFT_LINE_SENSOR_PIN&_BV(LEFT_LINE_SENSOR_1))>>LEFT_LINE_SENSOR_1) | ((LEFT_LINE_SENSOR_PIN&_BV(LEFT_LINE_SENSOR_2))>>(LEFT_LINE_SENSOR_2-1));
	
	// last two bits: units<->Right_sensor_1 and tens<->Right_sensor_2
	right_line_read = ((RIGHT_LINE_SENSOR_PIN&_BV(RIGHT_LINE_SENSOR_1))>>RIGHT_LINE_SENSOR_1) | ((RIGHT_LINE_SENSOR_PIN&_BV(RIGHT_LINE_SENSOR_2))>>(RIGHT_LINE_SENSOR_2-1));
	
	if (left_line_read==0)
	{
		left_line_read= last_left_line_read;
	}
	if (right_line_read==0)
	{
		right_line_read= last_right_line_read;
	}
	
	switch (left_line_read)
	{
		case : 1
			pwm_left= 80;
			left_wheel_back();
			break;
		
		case : 2
			pwm_left=80;
			left_wheel_front();
			break;

		case : 3
			breaks('l');
			break;
	}
	
	
	switch (right_line_read)
	{
		case : 1
			pwm_right= 80;
			right_wheel_back();
			break;
		
		case : 2
			pwm_right=80;
			right_wheel_front();
			break;

		case : 3
			breaks('r');
			break;
	}
}

