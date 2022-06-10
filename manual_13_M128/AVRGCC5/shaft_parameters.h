void init_shaft_parameters();
void start_shaft_velocity(int rpm_left,int rpm_right);
void stop_shaft_velocity();

#define MAX_RPM		600
#define REFRESH_TIME	10	// milliseconds
#define WHEEL_DIA	10

volatile long int count_left;
volatile long int count_right;
volatile long int count_up;

volatile int count_r_units;
volatile int count_r_tens;
volatile int count_r_hund;

volatile int count_l_units;
volatile int count_l_tens;
volatile int count_l_hund;

volatile int count_u_units;
volatile int count_u_tens;
volatile int count_u_hund;


volatile long int desired_count_left;
volatile long int desired_count_right;

volatile signed int error_count_left;
volatile signed int error_count_right;

volatile signed int error_pwm_left;
volatile signed int error_pwm_right;

volatile char desired_pwm_left;
volatile char desired_pwm_right;

volatile int rpm_measured_l;
volatile int rpm_measured_r;

volatile int desired_rpm_l;
volatile int desired_rpm_r;

/*Error_Factor= Factor that is when multiplied with error in pulse-count
   will give equivalent pwm error */

volatile char error_factor;  // 255pwm <-> 300RPM <-> 18 steps(counts 
							  //or degrees) hence 1step <-> 14pwm
							  // each data for 10ms
/* float_convert= to convert calculations to float */
volatile float float_convert;
