/* Normal motions */
void forward(char speed);
void reverse(char speed);

/* spins */
void spin_left(char speed_l, char speed_r, char speed_u, char speed_d);
void spin_right(char speed_l, char speed_r, char speed_u, char speed_d);

/* Point turns */
void point_left(char speed);
void point_left_reverse(char speed);
void point_right(char speed);
void point_right_reverse(char speed);

/* Sliding Motions */
void slide_left(char speed);
void slide_right(char speed);
void turn_slide_right(char speed_u, char speed_d);
void turn_slide_left(char speed_u, char speed_d);

/* Bud motors */
void bud_up(char speed);
void bud_down(char speed);

/* Breaks */
void breaks(char input);

/* direction constants */
void right_wheel_front();
void right_wheel_back();
void left_wheel_front();
void left_wheel_back();
void up_wheel_left();
void up_wheel_right();
void down_wheel_left();
void down_wheel_right();
void bud_wheel_up();
void bud_wheel_down();
void wheel_same(char input);

