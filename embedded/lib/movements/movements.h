#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#include <Servo.h>

void move_y_axis(Servo &tilt_servo, int &tilt_angle , char movement);
void move_x_axis(char movement);
void shoot(Servo &shoot_servo);
void toggle_impulse(bool &impulse_on);

#endif