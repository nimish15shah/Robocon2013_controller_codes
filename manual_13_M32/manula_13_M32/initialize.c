/*
 * CProgram1.c
 *
 * Created: 22-12-2012 05:24:35
 *  Author: compaq
 */ 


void initialize()
{
	init_variables();
	init_ports();	
	
}

void init_ports()
{
	// comm port as input
	COMM_DDR =0x00;
	COMM_PORT= 0xFF;
	// both front motor Breaked
	drive_front_motor(0);
}