/*
 * EXTI_interface.h
 *
 *  Created on: Aug 8, 2021
 *      Author: Eng-Ahmed Shalaby
 */


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_INT0_PORT  DIO_u8PORT_D
#define EXTI_INT1_PORT  DIO_u8PORT_D
#define EXTI_INT2_PORT  DIO_u8PORT_B
#define EXTI_INT0_PIN   DIO_u8PIN_2
#define EXTI_INT1_PIN   DIO_u8PIN_3
#define EXTI_INT2_PIN   DIO_u8PIN_2

#define EXT_INT0             0
#define EXT_INT1             1
#define EXT_INT2             2

#define EXTI_LOW_LEVEL       0
#define EXTI_RISYNG_EDGE     1
#define EXTI_FALLING_EDGE    2
#define EXTI_ON_CHANGE       3
#define NULL (void*)0
void EXTI0_VoidInti(void);
void EXTI1_VoidInti( void);
void EXTI2_VoidInti( void);
void EXTI_VoidSenseLevel(u8 INT_NUM,u8 Copy_u8INTLevel);
void EXTI_VoidDesEnabel(u8 INT_NUM);
void EXTI_u8INT0setCallBack(u8 INT_NUM,void(*copy_pvtntfun)(void));



void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));


#endif /* EXTI_INTERFACE_H_ */
