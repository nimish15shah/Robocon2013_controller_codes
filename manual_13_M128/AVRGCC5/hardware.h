// Motor Direction Pins
#define MOTOR_DIRECTION_DDR		DDRA
#define MOTOR_DIRECTION_PORT	PORTA
#define MOTOR_DIRECTION_PIN		PINA
#define DIRECTION_DRIVE_L_1		PA6
#define DIRECTION_DRIVE_L_2		PA7

#define DIRECTION_DRIVE_R_1		PA3
#define DIRECTION_DRIVE_R_2		PA2

#define DIRECTION_DRIVE_U_1		PA5
#define DIRECTION_DRIVE_U_2		PA4

#define DIRECTION_DRIVE_D_1		PA1
#define DIRECTION_DRIVE_D_2		PA0

//Driving Motor PWM pins	
#define MOTOR_DRIVE_L_DDR		DDRB
#define MOTOR_DRIVE_L_PORT		PORTB
#define MOTOR_DRIVE_L_PWM		PB5

#define MOTOR_DRIVE_R_DDR		DDRB
#define MOTOR_DRIVE_R_PORT		PORTB
#define MOTOR_DRIVE_R_PWM		PB6

#define MOTOR_SLIDE_U_DDR		DDRB
#define MOTOR_SLIDE_U_PORT		PORTB
#define MOTOR_SLIDE_U_PWM		PB7

#define MOTOR_SLIDE_D_DDR		DDRB
#define MOTOR_SLIDE_D_PORT		PORTB
#define MOTOR_SLIDE_D_PWM		PB4

// Bud motor 
#define MOTOR_BUD_DDR		DDRE
#define MOTOR_BUD_PORT		PORTE
#define MOTOR_BUD_PWM		PE3
#define MOTOR_BUD_1			PE2
#define MOTOR_BUD_2			PE1

// Shaft Encoder Hardware
#define ENCODER_DDR		DDRD
#define ENCODER_PORT	PORTD
#define ENCODER_PIN		PIND
#define ENCODER_R		PD0
#define ENCODER_L		PD1
#define ENCODER_U		PD2

// Communication
#define COMM_DDR		DDRC
#define COMM_PORT		PORTC
#define COMM_PIN		PINC
#define COMM_START		PC7

// FRONT Sensors
#define ARM_LINEAR_SENSOR_DDR	DDRF
#define ARM_LINEAR_SENSOR_PORT	PORTF
#define ARM_LINEAR_SENSOR_PIN	PINF
#define ARM_LINEAR_SENSOR		PF0

#define ARM_ANGLE_SENSOR_DDR	DDRF
#define ARM_ANGLE_SENSOR_PORT	PORTF
#define ARM_ANGLE_SENSOR_PIN	PINF
#define ARM_ANGLE_SENSOR		PF1

//Front Switches
#define ARM_LINEAR_SWITCH_DDR	DDRF
#define ARM_LINEAR_SWITCH_PORT	PORTF
#define ARM_LINEAR_SWITCH_PIN	PINF
#define ARM_LINEAR_SWITCH		PF2

#define ARM_ANGLE_SWITCH_DDR	DDRF
#define ARM_ANGLE_SWITCH_PORT	PORTF
#define ARM_ANGLE_SWITCH_PIN	PINF
#define ARM_ANGLE_SWITCH		PF3

// Rear Sensors
#define BUD_ANGLE_SENSOR_DDR		DDRF
#define BUD_ANGLE_SENSOR_PORT		PORTF
#define BUD_ANGLE_SENSOR_PIN		PINF
#define BUD_ANGLE_SENSOR			PF4

// Rear Switches
#define BUD_ANGLE_SWITCH_DDR		DDRF
#define BUD_ANGLE_SWITCH_PORT		PORTF
#define BUD_ANGLE_SWITCH_PIN		PINF
#define BUD_ANGLE_SWITCH			PF5

#define ELECTROMAGNET_LIMIT_SWITCH_DDR		DDRF
#define ELECTROMAGNET_LIMIT_SWITCH_PORT		PORTF
#define ELECTROMAGNET_LIMIT_SWITCH_PIN		PINF
#define ELECTROMAGNET_LIMIT_SWITCH			PF6

#define ELECTROMAGNET_CONTACT_SWITCH_DDR	DDRF
#define ELECTROMAGNET_CONTACT_SWITCH_PORT	PORTF
#define ELECTROMAGNET_CONTACT_SWITCH_PIN	PINF
#define ELECTROMAGNET_CONTACT_SWITCH		PF7

// Path follow Sensors
#define LEFT_LINE_SENSOR_DDR	DDRD
#define LEFT_LINE_SENSOR_PORT	PORTD
#define LEFT_LINE_SENSOR_PIN	PIND
#define LEFT_LINE_SENSOR_1		PD4
#define LEFT_LINE_SENSOR_2		PD5

#define RIGHT_LINE_SENSOR_DDR	DDRD
#define RIGHT_LINE_SENSOR_PORT	PORTD
#define RIGHT_LINE_SENSOR_PIN	PIND
#define RIGHT_LINE_SENSOR_1		PD6
#define RIGHT_LINE_SENSOR_2		PD7

		