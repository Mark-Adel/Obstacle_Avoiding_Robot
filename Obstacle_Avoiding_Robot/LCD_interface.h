/*
 * LCD_interface.h
 *
 *  Created on: Aug 15, 2021
 *      Author: DELL
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit(void);
void LCD_voidSendString( char * Copy_Pstring);
void print_num( u16 y);
void LCD_VoidGotoXY(u8 Copy_U8XPos, u8 Copy_U8YPos);
void LCD_VoidSpecialCaCharactar(u8 Copy_u8Pattern[][8], u8 Local_U8CCopy_U8CharactarNum);
#define LCD_CLEAR   LCD_voidSendCommand(1)

void LCD_Clear_Bits(u8 num);

#endif /* LCD_INTERFACE_H_ */
