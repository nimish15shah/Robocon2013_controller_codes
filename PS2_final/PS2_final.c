#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "PS2.h"
#include "SPI.h"
#include "LCD.h"

		
int main()
{
	init_LCD();
	SPI_init();
	PS2_init();
	a=0;b=0;c=0;d=0;e=0;f=0;g=0;h=0;i=0;j=0;k=0;l=0;m=0;n=0;o=0;p=0;q=0;r=0;
	command(0x01);
	while(1)
	{

		for(spi_display_i=0; spi_display_i<10; spi_display_i++)
		{
			display_hex(data_array[spi_display_i],0,(spi_display_i/5)+1, 3*(spi_display_i%5)+1); //1,4,7,10,13
		}
//		read_values();
/*		display_num(a,3,1,1);
		display_num(b,3,1,5);
		display_num(c,3,1,9);
		display_num(d,3,2,1);
		display_num(e,3,2,5);
		display_num(f,3,2,9);
*/

/*		display_num(m,3,1,1);
		display_num(n,3,1,5);
		display_num(o,3,1,9);
		display_num(p,3,2,1);
		display_num(q,3,2,5);
		display_num(r,3,2,9);
*/
	}

}

