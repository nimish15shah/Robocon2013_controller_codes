/*
 * IncFile1.h
 *
 * Created: 22-12-2012 05:27:07
 *  Author: compaq
 */ 


// Comm Port
#define COMM_DDR		DDRB
#define COMM_PORT		PORTB
#define COMM_PIN		PINB

// Valve Hardware
#define VALVE_DDR		DDRA
#define VALVE_PORT		PORTA
#define VALVE_PIN		PINA

// Front mechanism motors
#define ARM_LINEAR_MOTOR_DDR	DDRC
#define ARM_LINEAR_MOTOR_PORT	PORTC
#define ARM_LINEAR_MOTOR_PIN	PINC
#define ARM_LINEAR_MOTOR		PC1

#define ARM_ANGLE_MOTOR_DDR		DDRC
#define ARM_ANGLE_MOTOR_PORT	PORTC
#define ARM_ANGLE_MOTOR_PIN		PINC
#define ARM_ANGLE_MOTOR			PC2

// Rear Mechanisms
#define ELECTROMAGNET_ENABLE_DDR	DDRC
#define ELECTROMAGNET_ENABLE_PORT	PORTC
#define ELECTROMAGNET_ENABLE_PIN	PINC
#define ELECTROMAGNET_ENABLE		PC3

#define ELECTROMAGNET_DRIVE_DDR		DDRC
#define ELECTROMAGNET_DRIVE_PORT	PORTC
#define ELECTROMAGNET_DRIVE			PC4

 