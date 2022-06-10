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


/* Normal motions */
void forward(char speed)
{
	pwm_right= speed;
	pwm_left= speed;
	right_wheel_front();
	left_wheel_front();
	
	pwm_up=0;
	pwm_down=0;
	wheel_same('2');
}

void reverse(char speed)
{
	pwm_right= speed;
	pwm_left= speed;
	right_wheel_back();
	left_wheel_back();

	pwm_up=0;
	pwm_down=0;
	wheel_same('2');
}

/* spins */
void spin_left(char speed_l, char speed_r, char speed_u, char speed_d)
{
	pwm_right= speed_r;
	pwm_left= speed_l;
	pwm_up= speed_u;
	pwm_down= speed_d;
	right_wheel_front();
	left_wheel_back();
	up_wheel_left();
	down_wheel_right();
}

void spin_right(char speed_l, char speed_r, char speed_u, char speed_d)
{
	pwm_right= speed_r;
	pwm_left= speed_l;
	pwm_up= speed_u;
	pwm_down= speed_d;
	right_wheel_back();
	left_wheel_front();
	up_wheel_right();
	down_wheel_left();
}

/* Point turns */
void point_left(char speed)
{
	breaks('l');
	pwm_right=speed;
	right_wheel_front();

	pwm_up=0;
	pwm_down=0;
	wheel_same('2');
}

void point_left_reverse(char speed)
{
	breaks('l');
	pwm_right=speed;
	right_wheel_back();

	pwm_up=0;
	pwm_down=0;
	wheel_same('2');
}

void point_right(char speed)
{
	breaks('r');
	pwm_right=speed;
	left_wheel_front();

	pwm_up=0;
	pwm_down=0;
	wheel_same('2');
}

void point_right_reverse(char speed)
{
	breaks('r');
	pwm_right=speed;
	left_wheel_back();

	pwm_up=0;
	pwm_down=0;
	wheel_same('2');
}

/* Sliding Motions */
void slide_left(char speed)
{
	pwm_up= speed;
	pwm_down= speed;
	up_wheel_left();
	down_wheel_left();
	
	pwm_up=0;
	pwm_down=0;
	wheel_same('1');
}

void slide_right(char speed)
{
	pwm_up= speed;
	pwm_down= speed;
	up_wheel_right();
	down_wheel_right();
	
	pwm_up=0;
	pwm_down=0;
	wheel_same('1');
}

void turn_slide_right(char speed_u, char speed_d)
{
	pwm_up= speed_u;
	pwm_down= speed_d;
	up_wheel_right();
	down_wheel_right();
	
	pwm_up=0;
	pwm_down=0;
	wheel_same('1');
}

void turn_slide_left(char speed_u, char speed_d)
{
	pwm_up= speed_u;
	pwm_down= speed_d;
	up_wheel_left();
	down_wheel_left();
	
	pwm_up=0;
	pwm_down=0;
	wheel_same('1');
}

void bud_up(char speed)
{
	pwm_bud= speed;
	bud_wheel_up();	
}

void bud_down(char speed)
{
	pwm_bud= speed;
	bud_wheel_down();	
}

/* Breaks */

void breaks(char input)
{
	if(input== 'l')
	{
		pwm_left= 255;
		wheel_same('l');
	}
	if(input== 'r')
	{
		pwm_right= 255;
		wheel_same('r');
	}
	if(input== 'u')
	{
		pwm_up= 255;
		wheel_same('u');
	}
	if(input== 'd')
	{
		pwm_down= 255;
		wheel_same('d');
	}
	if (input== 'b')
	{
		pwm_bud= 255;
		wheel_same('b');
	}
	if(input== '1')
	{
		pwm_left= 255;
		pwm_right= 255;
		wheel_same('1');
	}
	if(input== '2')
	{
		pwm_up= 255;
		pwm_down= 255;
		wheel_same('2');

	}
	if(input== 'a')
	{
		pwm_left= 255;
		pwm_right= 255;

		pwm_up= 255;
		pwm_down= 255;
		wheel_same('a');
	}
}

/* direction constants */
void right_wheel_front()
{
	MOTOR_DIRECTION_PORT |=	_BV(DIRECTION_DRIVE_R_1);
	MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_R_2));
}

void right_wheel_back()
{
	MOTOR_DIRECTION_PORT |=	_BV(DIRECTION_DRIVE_R_2);
	MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_R_1));
}

void left_wheel_front()
{
	MOTOR_DIRECTION_PORT |=	_BV(DIRECTION_DRIVE_L_1);
	MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_L_2));
}

void left_wheel_back()
{
	MOTOR_DIRECTION_PORT |=	_BV(DIRECTION_DRIVE_L_2);
	MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_L_1));
}

void up_wheel_left()
{
	MOTOR_DIRECTION_PORT |=	_BV(DIRECTION_DRIVE_U_1);
	MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_U_2));
}

void up_wheel_right()
{
	MOTOR_DIRECTION_PORT |=	_BV(DIRECTION_DRIVE_U_2);
	MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_U_1));
}

void down_wheel_left()
{
	MOTOR_DIRECTION_PORT |=	_BV(DIRECTION_DRIVE_D_1);
	MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_D_2));
}

void down_wheel_right()
{
	MOTOR_DIRECTION_PORT |=	_BV(DIRECTION_DRIVE_D_2);
	MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_D_1));
}

void bud_wheel_up()
{
	MOTOR_BUD_PORT |= _BV(MOTOR_BUD_1);
	MOTOR_BUD_PORT &= ~(_BV(MOTOR_BUD_2));	
}
void bud_wheel_down()
{
	MOTOR_BUD_PORT |= _BV(MOTOR_BUD_2);
	MOTOR_BUD_PORT &= ~(_BV(MOTOR_BUD_1));	
}


void wheel_same(char input)
{
	if(input== 'r')
	{
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_R_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_R_1));
	}
	if(input== 'l')
	{
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_L_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_L_1));
	}
	if(input== 'u')
	{
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_U_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_U_1));
	}
	if(input== 'd')
	{
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_D_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_D_1));
	}
	if (input== 'b')
	{
		MOTOR_BUD_PORT &= ~(_BV(MOTOR_BUD_2)) & ~(_BV(MOTOR_BUD_1));
	}
	if(input== '1')
	{
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_R_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_R_1));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_L_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_L_1));
	}
	if(input== '2')
	{
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_U_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_U_1));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_D_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_D_1));
	}

	if(input== 'a')
	{
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_U_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_U_1));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_D_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_D_1));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_R_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_R_1));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_L_2));
		MOTOR_DIRECTION_PORT &=	~(_BV(DIRECTION_DRIVE_L_1));
	}

}
