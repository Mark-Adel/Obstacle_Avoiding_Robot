/*
 * EXTI_progr.c
 *
 *  Created on: Aug 8, 2021
 *      Author: Eng-Ahmed Shalaby
 */

#include "std_types.h"
#include "BIT_MATH.h"
#include "EXTI_reg.h"
#include "EXTI_interface.h"
#include "Dio_interface.h"
#include "tim_interface.h"



//extern void (*EXTI_pvINT0FUNC)(void);
//extern void (*EXTI_pvINT1FUNC)(void);
//extern void (*EXTI_pvINT2FUNC)(void);
extern u32 local_timval ;
extern u8 Global_Counter;

void EXTI0_VoidInti(void)
{
	DIO_voidSetPinDirection(EXTI_INT0_PORT,EXTI_INT0_PIN,DIO_u8INPUT);
	//DIO_voidSetPinValue(EXTI_INT0_PORT,EXTI_INT0_PIN,DIO_u8HIGH);
	SET_BIT(GICR,GICR_INT0);
}

void EXTI1_VoidInti(void)
{
	DIO_voidSetPinDirection(EXTI_INT1_PORT,EXTI_INT1_PIN,DIO_u8INPUT);
	DIO_voidSetPinValue(EXTI_INT1_PORT,EXTI_INT1_PIN,DIO_u8HIGH);
	SET_BIT(GICR,GICR_INT1);

}

void EXTI2_VoidInti(void )
{
	DIO_voidSetPinDirection(EXTI_INT2_PORT,EXTI_INT2_PIN,DIO_u8INPUT);
	DIO_voidSetPinValue(EXTI_INT2_PORT,EXTI_INT2_PIN,DIO_u8HIGH);
	SET_BIT(GICR,GICR_INT2);
}


void EXTI_VoidSenseLevel(u8 INT_NUM,u8 Copy_u8INTLevel)
{
	if(INT_NUM==2)
	{
		switch (Copy_u8INTLevel)
		{
		case EXTI_RISYNG_EDGE  :
			SET_BIT(MCUCSR,MCUCR_ISC2);
			break;

		case EXTI_FALLING_EDGE :
			CLR_BIT(MCUCSR,MCUCR_ISC2);
			break;
		}

	}
	else if(INT_NUM==1)
	{
		switch (Copy_u8INTLevel)
		{
		case EXTI_LOW_LEVEL    :
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
			break;


		case EXTI_RISYNG_EDGE  :
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;

		case EXTI_FALLING_EDGE :
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;

		case EXTI_ON_CHANGE   :
			CLR_BIT(MCUCR,MCUCR_ISC11);
			SET_BIT(MCUCR,MCUCR_ISC10);
			break;
		}
	}
	else
	{
		switch (Copy_u8INTLevel)
		{
		case EXTI_LOW_LEVEL    :
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;


		case EXTI_RISYNG_EDGE  :
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;

		case EXTI_FALLING_EDGE :
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;

		case EXTI_ON_CHANGE   :
			CLR_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;
		}

	}
}
void EXTI_VoidDesEnabel(u8 INT_NUM)
{
	switch (INT_NUM)
	{
	case EXT_INT0 :
		CLR_BIT(GICR,GICR_INT0); break;

	case EXT_INT1 :
		CLR_BIT(GICR,GICR_INT1); break;

	case EXT_INT2 :
		CLR_BIT(GICR,GICR_INT2); break;
	}
}



/*void EXTI_u8INT0setCallBack(u8 INT_NUM,void(*copy_pvtntfun)(void))
{
	switch(INT_NUM)
	{
	case EXT_INT0 :
		if (copy_pvtntfun !=NULL)
			{
				EXTI_pvINT0FUNC = copy_pvtntfun;
			}
		break;

	case EXT_INT1 :
			if (copy_pvtntfun !=NULL)
				{
					EXTI_pvINT1FUNC = copy_pvtntfun;
				}
			break;

	case EXT_INT2 :
			if (copy_pvtntfun !=NULL)
				{
					EXTI_pvINT2FUNC = copy_pvtntfun;
				}
			break;
	}

}*/

void __vector_1(void)
{
	u8 static y=0;
	if(y==0)
	{
		TIM0_VoidSetTimerValue(0);
		Global_Counter = 0;
		EXTI_VoidSenseLevel(EXT_INT0,EXTI_FALLING_EDGE);
		y=1;
	}
	else if (y==1)
	{

		local_timval = (Global_Counter * 256UL) + TIM0_VoidGetTimerValue();
		local_timval /= 58;
		EXTI_VoidSenseLevel(EXT_INT0,EXTI_RISYNG_EDGE);
		y=0;
	}
}

void __vector_2(void)
{

}

void __vector_3(void)
	{

	}






