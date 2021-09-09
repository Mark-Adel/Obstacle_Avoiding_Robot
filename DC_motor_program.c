/*
 * DC_motor_program.c
 *
 *  Created on: Aug 18, 2021
 *      Author: Mark A. Rateb
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

//#include "../Layered_Architecture/MCAL/DIO/DIO_interface.h"

#include "Dio_interface.h"
#include "avr/delay.h"
#include "DC_motor_config.h"
#include "DC_motor_interface.h"
#include "TIM_INTERFACE.h"


void DC_MOTOR_void_init(void){
	TIM2_VoidInt();
	DIO_voidSetPortDirection(DIO_u8PORT_C, 0x3d);
	DIO_voidSetPinDirection(DIO_u8PORT_B, DIO_u8PIN_3, DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORT_D, DIO_u8PIN_7, DIO_u8OUTPUT);
}

void Move_right(u8 speed )
{

	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR1_PIN1, DIO_u8HIGH);
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR1_PIN2, DIO_u8LOW);

	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR2_PIN1, DIO_u8LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR2_PIN2, DIO_u8LOW);
	DC_MOTOR1_PWM(speed);

}

void Move_left (u8 speed)
{

	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR1_PIN1, DIO_u8LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR1_PIN2, DIO_u8LOW);

	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR2_PIN1, DIO_u8LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR2_PIN2, DIO_u8HIGH);
	DC_MOTOR2_PWM(speed);

}


void GO_Straight(u8 speed)
{
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR1_PIN1, DIO_u8LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR1_PIN2, DIO_u8HIGH);

	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR2_PIN1, DIO_u8LOW);
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR2_PIN2, DIO_u8HIGH);
	DC_MOTOR1_PWM(speed);
	DC_MOTOR2_PWM(speed);
}


void GO_Backward(u8 speed){
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR1_PIN1, DIO_u8HIGH);
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR1_PIN2, DIO_u8LOW);

	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR2_PIN1, DIO_u8HIGH);
	DIO_voidSetPinValue(DC_MOTOR_PORT1, DC_MOTOR2_PIN2, DIO_u8LOW);
	DC_MOTOR1_PWM(speed);
	DC_MOTOR2_PWM(speed);
}


void DC_MOTOR1_PWM(u8 local_copy_pwm_value){
	PWM_VoidSetOCR0(local_copy_pwm_value);
}


void DC_MOTOR2_PWM(u8 local_copy_pwm_value){
	PWM_VoidSetOCR2(local_copy_pwm_value);
}






void DC_MOTOR_STOP(void){
	DC_MOTOR1_PWM(0);
	DC_MOTOR2_PWM(0);
}







































