/* In-built Macros-
-> if(bit_is_clear(PORTB,PB6))	// used to check if any bit is clear
-> if(bit_is_set(PINA,PA6))	// used to check if any bit is set
-> _BV(PB6) (1<<#PB6th position#) // Extensively used everywhere
-> _delay_ms(100) //Time in ms should be written in brackets
				   _delay_us() also available

-> _sei();	// set globat interrupt enable
-> _cli();	// disable global interrupts
*/

#define _WV(X) (1<<X)
#define BIT_SET(A,B)		(A & _WV(B)) // eg- if(BIT_SET(var_x,5))
#define BIT_CLEAR(A,B)		((A&_WV(B)>>B)^0x01) // eg- if(BIT_CLEAR(temp,6))
#define CHECK(A,B)			(A & _WV(B)) 
