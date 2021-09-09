/*
 * Dio_interface.h
 *
 *  Created on: Aug 12, 2021
 *      Author: DELL
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/*Port Defines*/
#define DIO_u8PORT_A            0
#define DIO_u8PORT_B            1
#define DIO_u8PORT_C            2
#define DIO_u8PORT_D            3

/*Pins DEfines*/

#define DIO_u8PIN_0             0
#define DIO_u8PIN_1             1
#define DIO_u8PIN_2             2
#define DIO_u8PIN_3             3
#define DIO_u8PIN_4             4
#define DIO_u8PIN_5             5
#define DIO_u8PIN_6             6
#define DIO_u8PIN_7             7

/*value*/
#define DIO_u8HIGH             1
#define DIO_u8LOW              0
/*Direction PIn*/
#define DIO_u8OUTPUT           1
#define DIO_u8INPUT            0



/*IO Pins*/
void DIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId, u8 Copy_u8PinDir);

void DIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId, u8 Copy_u8PinVal);

u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId);
void DIO_U8TogelPin(u8 Copy_u8PortId,u8 Copy_u8PinId);


/*Port Pins*/
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDir);

void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortVal);



#endif /* DIO_INTERFACE_H_ */
