void PS2_init();
void read_values();

volatile char cmd_array[21];
volatile char data_array[21];

char  PS2_POLLBUTTON[9];//= {0x01, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
