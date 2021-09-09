/*
 * EXTI_reg.h
 *
 *  Created on: Aug 8, 2021
 *      Author: Eng-Ahmed Shalaby
 */

#ifndef EXTI_REG_H_
#define EXTI_REG_H_

/*   */
#define MCUCR  *((volatile u8 *)0x55)
#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3


#define MCUCSR  *((volatile u8 *)0x54)
#define MCUCR_ISC2  6

#define SREG  *((volatile u8 *)0x5F)
#define SREG_EIG    7

#define GICR  *((volatile u8 *)0x5B)
#define GICR_INT0   6
#define GICR_INT1   7
#define GICR_INT2   5

#define GIFR  *((volatile u8 *)0x5A)
#define GIFR_INTF0   6
#define GIFR_INTF1   7
#define GIFR_INTF2   5



#endif /* EXTI_REG_H_ */
