/*
 * manula_13_M32.c
 *
 * Created: 22-12-2012 05:23:26
 *  Author: compaq
 */ 

#include <avr/io.h>

int main(void)
{
	sei();
	initialize();
	
	while (COMM_PIN& 0b10000000)
	{
		;
	}

	comm_instruction= ~COMM_PIN & 0b01111111;
	
	switch (comm_instruction)
	{
		case : 1	// initialization- Everything Released
			drive_valve(0);
			break;
		case : 2	// Pick all Buns
			drive_valve(1);
			break;
		case : 3	// Release first 3 buns
			drive_valve(2);
			break;
		case : 4	// Release remaining 6 buns
			drive_valve(3);
			break;
	
		case : 10	// Both front motor breaked
			drive_front_motor(0);
			break;
		case : 11	// Linear motor break
			drive_front_motor(1);
			break;
		case : 12	// Linear motor Up	
			drive_front_motor(2);
			break;
		case : 13	// Linear motor Down
			drive_front_motor(3);
			break;
		case : 14	// Angle motor Breaked
			drive_front_motor(4);
			break;
		case : 15	// Angle motor Up
			drive_front_motor(5);
			break;
		case : 16	// Angle motor Down
			drive_front_motor(6);
			break;
		
		case : 20	// Electromagnet ON and Motor Breaked
			drive_electromagnet_mechanism(0);
			break;
		case : 21	// Electromagnet On, no effect on Motor
			drive_electromagnet_mechanism(1);
			break;
		case : 22	// Electromagnet Off, no effect on Motor
			drive_electromagnet_mechanism(2);
			break;
		case : 23	// no effect on Electromagnet, Motor Braked
			drive_electromagnet_mechanism(3);
			break;
		case : 24	// no effect on Electromagnet, Motor-Streched Conditn
			drive_electromagnet_mechanism(4);
			break;
		case : 25	// no effect on Electromagnet, Motor-Release Conditn
			drive_electromagnet_mechanism(5);
			break;	
	}
}