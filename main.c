/*
 * main.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Eng-Ahmed Shalaby
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "uitrasonic_intreface.h"
#include "Dio_interface.h"
#include "LCD_Interface.h"
#include "lcd_config.h"
#include "util/delay.h"
#include "dc_motor_interface.h"
#include "tim_interface.h"

u8 Global_Counter = 0;
u32 local_timval = 0;



int main(void){
	DC_MOTOR_void_init();
	ULT_Int();
	LCD_voidInit();
	Servo_void_Init(20000);
	LCD_voidSendString("DISTANCE : ");
	u16 distance = 0;
	while(1)
	{
		distance = ULT_Read();
		LCD_VoidGotoXY(0,12);
		print_num(distance);
		LCD_Clear_Bits(2);

		if (distance<30)
		{
			DC_MOTOR_STOP();
			for(u16 i = 1500 ; i <= 2000; i+=100)
			{
				TIM1_SETCHANALCOMPERMATCH(i);
				distance = ULT_Read();
				if(distance > 30){
					Move_right(200);
					break;
				}
			}
			for(u16 i = 2000 ; i >= 1000; i-=100)
			{
				TIM1_SETCHANALCOMPERMATCH(i);
				distance = ULT_Read();
				if(distance > 30){
					Move_left(200);
					break;
				}
			}
			TIM1_SETCHANALCOMPERMATCH(1500);
			_delay_ms(500);
			GO_Straight(200);
		}
		else
		{
			GO_Straight(200);
		}


	}


	return 0;
}
