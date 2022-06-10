/*
 * CProgram1.c
 *
 * Created: 22-12-2012 05:38:22
 *  Author: compaq
 */ 

void drive_valve(char valve_driving_instruction)
{
	VALVE_DDR= 0xFF;

	switch (valve_driving_instruction)
	{
		case : 0	// initialization- Everything Released
			VALVE_PORT= 0b01111111;
			break;
		case : 1	// Pick all Buns
			VALVE_PORT= 0x00;
			break;
		case : 2	// Release first 3 buns
			VALVE_PORT= 0b00000111;
			break;
		case : 3	// Release remaining 6 buns
			VALVE_PORT= 0b01111111;
			break;
	}
}

void drive_front_motor(char motor_driving_instruction)
{
	switch (motor_driving_instruction)
	{
		case : 0	// Both front motor breaked
			ARM_ANGLE_MOTOR_DDR &= ~(_BV(ARM_ANGLE_MOTOR));
			ARM_LINEAR_MOTOR_DDR &= ~(_BV(ARM_LINEAR_MOTOR));
			break;

		// Cases for linear motor, no effect on arm motor
		case : 1	// Linear motor break
			ARM_LINEAR_MOTOR_DDR &= ~(_BV(ARM_LINEAR_MOTOR));
			break;
		case : 2	// Linear motor up
			ARM_LINEAR_MOTOR_DDR |= _BV(ARM_LINEAR_MOTOR);
			ARM_LINEAR_MOTOR_PORT |= _BV(ARM_LINEAR_MOTOR);
			break;
		case : 3	// Linear motor down
			ARM_LINEAR_MOTOR_DDR |= _BV(ARM_LINEAR_MOTOR);
			ARM_LINEAR_MOTOR_PORT &= ~(_BV(ARM_LINEAR_MOTOR));
			break;
		
		// Cases for Angle motor, no effect on linear motor
		case : 4	// Angle motor break
			ARM_ANGLE_MOTOR_DDR &= ~(_BV(ARM_LINEAR_MOTOR));
			break;
		case : 5	// Angle motor Up
			ARM_ANGLE_MOTOR_DDR |= _BV(ARM_LINEAR_MOTOR);
			ARM_ANGLE_MOTOR_PORT |= _BV(ARM_LINEAR_MOTOR);
			break;
		case : 6	// Angle motor Down
			ARM_ANGLE_MOTOR_DDR |= _BV(ARM_LINEAR_MOTOR);
			ARM_ANGLE_MOTOR_PORT &= ~(_BV(ARM_LINEAR_MOTOR));
			break;

	}
}

void drive_electromagnet_mechanism(char bud_driving_instruction)
{
	switch(bud_driving_instruction)
	{
		case : 0	// Electromagnet ON & Motor Braked
			ELECTROMAGNET_ENABLE_DDR |= _BV(ELECTROMAGNET_ENABLE);
			ELECTROMAGNET_ENABLE_PORT |= _BV(ELECTROMAGNET_ENABLE);
			ELECTROMAGNET_DRIVE_DDR &= ~(_BV(ELECTROMAGNET_DRIVE));
			break;
	
		case : 1	// Electromagnet ON, no effect on Motor
			ELECTROMAGNET_ENABLE_DDR |= _BV(ELECTROMAGNET_ENABLE);
			ELECTROMAGNET_ENABLE_PORT |= _BV(ELECTROMAGNET_ENABLE);
			break;

		case : 2	// Electromagnet OFF, no effect on Motor
			ELECTROMAGNET_ENABLE_DDR |= _BV(ELECTROMAGNET_ENABLE);
			ELECTROMAGNET_ENABLE_PORT &= ~(_BV(ELECTROMAGNET_ENABLE));
			break;

		case : 3	// no effect on Electromagnet, Motor Braked
			ELECTROMAGNET_DRIVE_DDR &= ~(_BV(ELECTROMAGNET_DRIVE));
			break;

		case : 4	// no effect on Electromagnet, Motor-Streched Conditn
			ELECTROMAGNET_DRIVE_DDR |= _BV(ELECTROMAGNET_DRIVE);
			ELECTROMAGNET_DRIVE_PORT |= _BV(ELECTROMAGNET_DRIVE);
			break;

		case : 5	// no effect on Electromagnet, Motor-Release Conditn
			ELECTROMAGNET_DRIVE_DDR |= _BV(ELECTROMAGNET_DRIVE);
			ELECTROMAGNET_DRIVE_PORT &= ~(_BV(ELECTROMAGNET_DRIVE));
			break;
	}
}