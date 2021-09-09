/*
 * TIM_Prog.c
 *
 *  Created on: Aug 11, 2021
 *      Author: Eng-Ahmed Shalaby
 */
#include "std_types.h"
#include "bit_math.h"
#include "tim_interface.h"
#include "tim_reg.h"
#include "tim_confg.h"
#include "Dio_interface.h"

extern u8 Global_Counter;
void TIM0_VoidInt(void)
{
	SET_BIT(TIMSK ,TIMSK_TOIE0  );
	//SET_BIT(TIMSK ,TIMSK_OCIE0   );
	TCCR0  = TCCR0 & 0xf8 ;
	TCCR0 |= TIM0_Prescal ;

#if(TIM0_Mod== tim0_normal )
	CLR_BIT(TCCR0 ,TCCR0_WGM00 );
	CLR_BIT(TCCR0 ,TCCR0_WGM01 );
	switch (TIM0_NOPWM_MOD)
	{
	case OC0_notconect :
		CLR_BIT(TCCR0 ,TCCR0_COM00 );
		CLR_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OC0_toggel :
		SET_BIT(TCCR0 ,TCCR0_COM00 );
		CLR_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OC0_set :
		SET_BIT(TCCR0 ,TCCR0_COM00 );
		SET_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OS0_clear :
		CLR_BIT(TCCR0 ,TCCR0_COM00 );
		SET_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	}
#elif(TIM0_Mod== tim0_pwm)
	SET_BIT(TCCR0 ,TCCR0_WGM00 );
	CLR_BIT(TCCR0 ,TCCR0_WGM01 );

	switch (TIM0_PHCORECTPWM_MOD)
	{
	case OC0_notconect :
		CLR_BIT(TCCR0 ,TCCR0_COM00 );
		CLR_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OC0_toggel :
		SET_BIT(TCCR0 ,TCCR0_COM00 );
		CLR_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OC0_set :
		SET_BIT(TCCR0 ,TCCR0_COM00 );
		SET_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OS0_clear :
		CLR_BIT(TCCR0 ,TCCR0_COM00 );
		SET_BIT(TCCR0 ,TCCR0_COM01 );
		break;

	}

#elif(TIM0_Mod== tim0_ctc)
	CLR_BIT(TCCR0 ,TCCR0_WGM00 );
	SET_BIT(TCCR0 ,TCCR0_WGM01 );

	switch (TIM0_NOPWM_MOD)
	{
	case OC0_notconect :
		CLR_BIT(TCCR0 ,TCCR0_COM00 );
		CLR_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OC0_toggel :
		SET_BIT(TCCR0 ,TCCR0_COM00 );
		CLR_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OC0_set :
		SET_BIT(TCCR0 ,TCCR0_COM00 );
		SET_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OS0_clear :
		CLR_BIT(TCCR0 ,TCCR0_COM00 );
		SET_BIT(TCCR0 ,TCCR0_COM01 );
		break;

	}
#elif(TIM0_Mod== tim0_pwmfast)
	SET_BIT(TCCR0 ,TCCR0_WGM00 );
	SET_BIT(TCCR0 ,TCCR0_WGM01 );

	switch (TIM0_FASTPWM_MOD )
	{
	case OC0_notconect :
		CLR_BIT(TCCR0 ,TCCR0_COM00 );
		CLR_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OC0_invert :
		SET_BIT(TCCR0 ,TCCR0_COM00 );
		SET_BIT(TCCR0 ,TCCR0_COM01 );
		break;
	case OC0_noninvert :
		CLR_BIT(TCCR0 ,TCCR0_COM00 );
		SET_BIT(TCCR0 ,TCCR0_COM01 );
		break;

	}
#else
#warning "write correct tim_mod"


#endif


}
void PWM_VoidSetOCR0(u8 Copy_u8OCR0Valu)
{
	OCR0 = Copy_u8OCR0Valu ;
}
void TIM0_VoidSetTimerValue(u8 value)
{
	TCNT0 = value;
}
u8 TIM0_VoidGetTimerValue(void)
{
	return TCNT0;
}





void TIM1_VoidInt(void)
{
	// PRESCALER .....
	TCCR1B &=0XF8;
	TCCR1B |=TIM1_Prescal;



#if (WAVGENEGATION==0)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1A |= (TIM1_NOPWM_MOD_OC1A*64);
	TCCR1A |= (TIM1_NOPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==1)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1A |=WAVGENEGATION;
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==2)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1A |=WAVGENEGATION;
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==3)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1A |=WAVGENEGATION;
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==4)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=8;
	TCCR1A |= (TIM1_NOPWM_MOD_OC1A*64);
	TCCR1A |= (TIM1_NOPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==5)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=8;
	TCCR1A |=(WAVGENEGATION-4);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==6)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=8;
	TCCR1A |=(WAVGENEGATION-4);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==7)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=8;
	TCCR1A |=(WAVGENEGATION-4);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==8)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=16;
	TCCR1A |=(WAVGENEGATION-8);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==9)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=16;
	TCCR1A |=(WAVGENEGATION-8);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==10)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=16;
	TCCR1A |=(WAVGENEGATION-8);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==11)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=16;
	TCCR1A |=(WAVGENEGATION-8);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_PHCORECTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==12)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=24;
	//TCCR1A |=(WAVGENEGATION-12);
	TCCR1A |= (TIM1_NOPWM_MOD_OC1A*64);
	TCCR1A |= (TIM1_NOPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==14)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=24;
	TCCR1A |=(WAVGENEGATION-12);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1B*16);
#elif(WAVGENEGATION==15)
	TCCR1A &=0x0c;
	TCCR1B &=0xe7;
	TCCR1B |=24;
	TCCR1A |=(WAVGENEGATION-12);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1A*64);
	TCCR1A |= (TIM0_FASTPWM_MOD_OC1B*16);
#else
#warning ""


#endif

}
void TIM1_TOPVALU(u16 Copy_u16TopValu)
{
	ICR1L = Copy_u16TopValu ;
}

void TIM1_SETCHANALCOMPERMATCH(u16 Copy_u16Toutcompermatch)
{
	OCR1AL = Copy_u16Toutcompermatch ;
}

void TIM1_VoidSetTimerValue(u16 value)
{
	TCNT1L = value;
}
u16 TIM1_VoidGetTimerValue(void)
{
	return TCNT1L;
}








/*void EXTI_u8Tim0setCallBack(void(*copy_pvtntfun)(void))
{
	if (copy_pvtntfun!=NULL)
	{
	  TIM_pvTIM0FUNC = copy_pvtntfun;
	}
}*/
void __vector_11(void)
{

	Global_Counter ++;

}
/*
void __vector_10(void)
{
	if (count ==125)
		{
			TIM_pvTIM0FUNC();
			count = 0 ;
		}
		count ++;

}*/




void PWM_VoidSetOCR2(u8 Copy_u8OCR0Valu)
{
	OCR2 = Copy_u8OCR0Valu;
}
void TIM2_VoidInt(void)
{
	TCCR2  = TCCR2 & 0xf8 ;
		TCCR2 |= TIM2_Prescal ;

	#if(TIM2_Mod== tim2_normal )
		CLR_BIT(TCCR2 ,TCCR2_WGM20 );
		CLR_BIT(TCCR2 ,TCCR2_WGM21 );
		switch (TIM2_NOPWM_MOD)
		{
		case OC2_notconect :
			CLR_BIT(TCCR2 ,TCCR2_COM20 );
			CLR_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OC2_toggel :
			SET_BIT(TCCR2 ,TCCR2_COM20 );
			CLR_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OC2_set :
			SET_BIT(TCCR2 ,TCCR2_COM20 );
			SET_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OS2_clear :
			CLR_BIT(TCCR2 ,TCCR2_COM20);
			SET_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		}
	#elif(TIM2_Mod== tim2_pwm)
		SET_BIT(TCCR2 ,TCCR0_WGM20 );
		CLR_BIT(TCCR2 ,TCCR0_WGM21 );

		switch (TIM2_PHCORECTPWM_MOD)
		{
		case OC2_notconect :
			CLR_BIT(TCCR2 ,TCCR2_COM20 );
			CLR_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OC2_toggel :
			SET_BIT(TCCR2 ,TCCR2_COM20 );
			CLR_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OC2_set :
			SET_BIT(TCCR2 ,TCCR2_COM20 );
			SET_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OS2_clear :
			CLR_BIT(TCCR2 ,TCCR2_COM20  );
			SET_BIT(TCCR2 ,TCCR2_COM21 );
			break;

		}

	#elif(TIM2_Mod== tim2_ctc)
		CLR_BIT(TCCR2 ,TCCR2_WGM20 );
		SET_BIT(TCCR2 ,TCCR2_WGM21 );

		switch (TIM2_NOPWM_MOD)
		{
		case OC2_notconect :
			CLR_BIT(TCCR2 ,TCCR2_COM20 );
			CLR_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OC2_toggel :
			SET_BIT(TCCR2 ,TCCR2_COM20  );
			CLR_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OC2_set :
			SET_BIT(TCCR2 ,TCCR2_COM20  );
			SET_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OS2_clear :
			CLR_BIT(TCCR2 ,TCCR2_COM20  );
			SET_BIT(TCCR2 ,TCCR2_COM21 );
			break;

		}
	#elif(TIM2_Mod== tim2_pwmfast)
		SET_BIT(TCCR2 ,TCCR2_WGM20 );
		SET_BIT(TCCR2 ,TCCR2_WGM21 );

		switch (TIM2_FASTPWM_MOD )
		{
		case OC2_notconect :
			CLR_BIT(TCCR2 ,TCCR2_COM20  );
			CLR_BIT(TCCR2 ,TCCR2_COM21 );
			break;
		case OC2_invert :
			SET_BIT(TCCR2 ,TCCR2_COM20  );
			SET_BIT(TCCR2 ,TCCR2_COM21);
			break;
		case OC2_noninvert :
			CLR_BIT(TCCR2 ,TCCR2_COM20  );
			SET_BIT(TCCR2 ,TCCR2_COM21  );
			break;

		}
	#else
	#warning "write correct tim_mod"


	#endif


	}


u8 TIM2_VoidGetTimerValue(void)
{
	return TCNT2 ;

}
void TIM2_VoidSetTimerValue(u8 value)
{
	TCNT2 = value;
}






void Servo_void_Init(u16 TopValue){
	DIO_voidSetPinDirection(DIO_u8PORT_D, DIO_u8PIN_5, DIO_u8OUTPUT); //Servo PWM Signal
	TIM1_VoidInt();
	TIM1_TOPVALU(TopValue);
}
