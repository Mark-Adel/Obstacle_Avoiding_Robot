/*
 * ultrasonic_interface.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Eng-Ahmed Shalaby
 */
#include "std_types.h"
#include "bit_math.h"
#include "util/delay.h"
#include "Dio_interface.h"
#include "ultrsonic_config.h"
#include "tim_interface.h"
#include "globel_int_interface.h"
#include "dio_reg.h"
#include "exti_interface.h"

extern u32 local_timval;

void ULT_Int(void)
{
	DIO_voidSetPinDirection(UIT_PORT , UIL_TRIGPIN ,DIO_u8OUTPUT);
	//DIO_voidSetPinDirection(UIT_PORT , UIL_ECHOPIN ,DIO_u8INPUT);
	GLOBEL_INTENABEL();
	TIM0_VoidInt();
	EXTI0_VoidInti();
	EXTI_VoidSenseLevel(EXT_INT0,EXTI_RISYNG_EDGE);
}
u16 ULT_Read(void)
{

	DIO_voidSetPinValue(UIT_PORT , UIL_TRIGPIN ,1);
	_delay_us(10);
	DIO_voidSetPinValue(UIT_PORT , UIL_TRIGPIN ,0);
     _delay_ms(60);

   return local_timval;
}
