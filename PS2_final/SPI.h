#define SPI_DDR		DDRB
#define SPI_PORT	PORTB
#define SPI_PIN		PINB
#define SS_PIN		PB0
#define SCK_PIN		PB1
#define MOSI_PIN	PB2
#define MISO_PIN	PB3


void SPI_init();
char SPI_send(char);
volatile char a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r;
volatile int spi_display_i;
volatile int spi_i;
void SPI_send_array(char *a, char cmd_length);

