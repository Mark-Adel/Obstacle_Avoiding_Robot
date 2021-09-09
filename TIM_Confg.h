/*
 * TIM_Confg.h
 *
 *  Created on: Aug 11, 2021
 *      Author: Eng-Ahmed Shalaby
 */

#ifndef TIM_CONFG_H_
#define TIM_CONFG_H_
#define TIM0_Prescal      2         //(1=tim_1 ,2= tim_8 ,3=tim_64 ,4=tim_256 ,5=tim_1024 ,6=tim0_extpint0_fal,7=tim0_extpint0_ris)
#define TIM0_Mod               tim0_pwmfast   //(tim0_normal , tim0_pwm , tim0_ctc ,tim0_pwmfast)
#define TIM0_NOPWM_MOD         OC0_notconect       //(OC0_notconect ,OC0_toggel ,OC0_set ,OS0_clear)
#define TIM0_FASTPWM_MOD       OC0_noninvert       //(OC0_notconect ,OC0_invert ,OC0_noninvert )
#define TIM0_PHCORECTPWM_MOD   OC0_noninvert       //(OC0_notconect ,OC0_invert ,OC0_noninvert )

/*.....timer 1 .....confegration.......*/
#define TIM1_Prescal      2      //  (0 , 1 , 2= 8 , 3= 64 , 4= 256 , 5= 1024  , 6= EXCLC_T1_FAL   ,7=   EXTCLC_T1_RIS)
#define WAVGENEGATION     14
/* 0 = normal   ,.. 1 =  pwm_phc_8bit ,.. 2 = pwm_phc_9bit ,..3 =pwm_phc_10bit ,..4 =CTC_top_OCR1A
 * ..5 =Fast PWM_8-bit,..6= Fast PWM_9-bit  ,..7 = Fast PWM_10-bit,..8 = PWM_Phase_and Frequency Correct_TOP_ICR1
 *..9 = PWM_Phase_and Frequency Correct_TOP_OCR1A ,..10= PWM Phase Correct_IOP_ICR1,..11=PWM Phase Correct_IOP_OCR1A
 *..12 = CTC_top_ICR1 ,..14=Fast PWM_TOP_ICR1,...15=Fast PWM_TOP_OCR1
 *  */
#define TIM1_NOPWM_MOD_OC1A         0       //( 0=OC1A_notconect ,.. 1=OC1A_toggel,..2= OS1A_clear,..3=OC1A_set )
#define TIM1_NOPWM_MOD_OC1B         0       //( 0 =OC1B_notconect ,..1= OC1B_toggel ,..2= OS1B_clear,..3= OC1B_set)
#define TIM0_FASTPWM_MOD_OC1A       2       //(0 = OC1A_notconect,..1= TOGEL_WG15,..2= OC1A_noninvert ,..3= OC1A_invert  )
#define TIM0_FASTPWM_MOD_OC1B       0       //(0= OC1B_notconect  ,..2=OC1B_noninvert,..3=OC1B_invert )
#define TIM0_PHCORECTPWM_MOD_OC1A   0       //(0 = OC1A_notconect,..1= TOGEL_WG9,..2=OC1A_CLEARUPCON,..3=OC1A_SETUPCON )
#define TIM0_PHCORECTPWM_MOD_OC1B   0       //(0= OC1B_notconect  ,..2=OC1B_CLEARUPCON,..3=SETUPCON )


/*.....timer 2 .....confegration.......*/
#define TIM2_Prescal      2         //(1=tim_1 ,2= tim_8 ,3=tim_64 ,4=tim_256 ,5=tim_1024 ,6=tim0_extpint0_fal,7=tim0_extpint0_ris)
#define TIM2_Mod               tim2_pwmfast   //(tim2_normal , tim2_pwm , tim2_ctc ,tim2_pwmfast)
#define TIM2_NOPWM_MOD         OC2_toggel       //(OC2_notconect ,OC2_toggel ,OC2_set ,OS0_clear)
#define TIM2_FASTPWM_MOD       OC2_noninvert       //(OC2_notconect ,OC2_invert ,OC2_noninvert )
#define TIM2_PHCORECTPWM_MOD   OC2_noninvert       //(OC2_notconect ,OC2_invert ,OC2_noninvert )


#endif /* TIM_CONFG_H_ */
