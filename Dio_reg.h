/*
 * Dio_reg.h
 *
 *  Created on: Aug 12, 2021
 *      Author: DELL
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

/*Group A registers*/
#define PORTA            *((volatile u8*)0x3B)
#define DDRA             *((volatile u8*)0x3A)
#define PINA             *((volatile u8*)0x39)
/*Group B registers*/
#define PORTB            *((volatile u8*)0x38)
#define DDRB             *((volatile u8*)0x37)
#define PINB             *((volatile u8*)0x36)
/*Group C registers*/
#define PORTC            *((volatile u8*)0x35)
#define DDRC             *((volatile u8*)0x34)
#define PINC             *((volatile u8*)0x33)
/*Group D registers*/
#define PORTD            *((volatile u8*)0x32)
#define DDRD             *((volatile u8*)0x31)
#define PIND             *((volatile u8*)0x30)






#endif /* DIO_REG_H_ */
