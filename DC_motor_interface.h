/*
 * DC_motor_interface.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Mark A. Rateb
 */

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_
#include "../LIB/STD_TYPES.h"

void DC_MOTOR_void_init(void);

void Move_right(u8 speed);

void Move_left (u8 speed);


void GO_Straight(u8 speed);

void GO_Backward(u8 speed);

void DC_MOTOR1_PWM(u8 local_copy_pwm_value);
void DC_MOTOR2_PWM(u8 local_copy_pwm_value);

void DC_MOTOR_STOP(void);

#endif /* DC_MOTOR_INTERFACE_H_ */
