/*
 * TIM_INTERFACE.h
 *
 *  Created on: Aug 11, 2021
 *      Author: Eng-Ahmed Shalaby
 */

#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_

#define tim0_normal    0
#define tim0_pwm       1
#define tim0_ctc       2
#define tim0_pwmfast   3

#define OC0_notconect        0
#define OC0_toggel           1
#define OC0_set              2
#define OS0_clear            3

#define OC0_invert           2
#define OC0_noninvert        3

#define tim2_normal    0
#define tim2_pwm       1
#define tim2_ctc       2
#define tim2_pwmfast   3

#define OC2_notconect        0
#define OC2_toggel           1
#define OC2_set              2
#define OS2_clear            3

#define OC2_invert           2
#define OC2_noninvert        3


void TIM1_VoidInt(void);
void TIM1_TOPVALU(u16 Copy_u16TopValu);
void TIM1_SETCHANALCOMPERMATCH(u16 Copy_u16Toutcompermatch);
u16 TIM1_VoidGetTimerValue(void);
void TIM1_VoidSetTimerValue(u16 value);

void PWM_VoidSetOCR0(u8 Copy_u8OCR0Valu);
void TIM0_VoidInt(void);
u8 TIM0_VoidGetTimerValue(void);
void TIM0_VoidSetTimerValue(u8 value);
void EXTI_u8TimsetCallBack(void(*copy_pvtntfun)(void));
void __vector_11(void)__attribute__((signal));
void __vector_10(void)__attribute__((signal));
#define NULL (void*)0


void PWM_VoidSetOCR2(u8 Copy_u8OCR0Valu);
void TIM2_VoidInt(void);
u8 TIM2_VoidGetTimerValue(void);
void TIM2_VoidSetTimerValue(u8 value);

void Servo_void_Init(u16 TopValue);


#endif /* TIM_INTERFACE_H_ */
