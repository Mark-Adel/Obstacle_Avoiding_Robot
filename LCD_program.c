/*
 * LCD_program.c
 *
 *  Created on: Aug 15, 2021
 *      Author: DELL
 */
#include"util/delay.h"
#include "../Lib/STD_TYPES.h"
#include "../Lib/BIT_MATH.h"

#include "Dio_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"

#define CLEAR_LCD_BIT	LCD_voidSendData(' ')

void LCD_voidSendCommand(u8 Copy_u8Command)
{
/*1-set RS  with low --> command*/
	DIO_voidSetPinValue( LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8LOW);
/*2- SET RW TO LOW TO write*/
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);
/*3-set command on data pins*/
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);
/*4- Send enable pulse*/
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);



}
void LCD_voidSendData(u8 Copy_u8Data)
{
	/*1-set RS  with high --> command*/
		DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_u8HIGH);
	/*2- SET RW TO LOW TO write*/
		DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_u8LOW);
	/*3-set command on data pins*/
		DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Data);
	/*4- Send enable pulse*/
		DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8HIGH);
		_delay_ms(2);
		DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_u8LOW);
}

void LCD_voidInit(void)
{
	DIO_voidSetPortDirection(LCD_DATA_PORT, 0xff);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, DIO_u8PIN_0, DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, DIO_u8PIN_1, DIO_u8OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, DIO_u8PIN_2, DIO_u8OUTPUT);

	_delay_ms(30);
	LCD_voidSendCommand(0b00111000);

	LCD_voidSendCommand(0b00001100);

	LCD_voidSendCommand(1);
}

void LCD_voidSendString(char * Copy_Pstring)
{
	u8 Local_u8Itretion=0;
	while( Copy_Pstring[Local_u8Itretion]!='\0')
	{
		LCD_voidSendData(Copy_Pstring[Local_u8Itretion]);
		Local_u8Itretion ++;
	}


}

void LCD_VoidGotoXY(u8 Copy_U8XPos, u8 Copy_U8YPos)
{
	u8 Local_u8Address ;
	if (Copy_U8XPos==0)
	{
		Local_u8Address = Copy_U8YPos;
		LCD_voidSendCommand(128+Local_u8Address);


	}
	else if (Copy_U8XPos==1)
	{
		Local_u8Address = 0x40+Copy_U8YPos;
		LCD_voidSendCommand(128+Local_u8Address);
	}
	else
	{

	}


}

void LCD_VoidSpecialCaCharactar(u8 Copy_u8Pattern[][8],u8 Copy_U8CharactarNum)
{
	u8 Local_u8Address;
	u8 Local_u8Counter;
	u8 Local_u8Counter2;

	//calc cgram block address
	for ( Local_u8Counter2=0;Local_u8Counter2<Copy_U8CharactarNum;Local_u8Counter2++)
	{
	  Local_u8Address = Local_u8Counter2*8;

	LCD_voidSendCommand(Local_u8Address+64);


	for (Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{

		LCD_voidSendData(Copy_u8Pattern[Local_u8Counter2][Local_u8Counter]);
	}


	}
}


void LCD_Clear_Bits(u8 num){
	for(u8 i = 0; i<num; i++)
	{
		CLEAR_LCD_BIT;
	}

}
void print_num(u16 y)
{
	u8 e=0;
	s8 i;
   u8 arr[7]={0};
	while (y!=0)
	{
		arr[e]=(y % 10);
		//LCD_VoidGotoXY(0,15-e);
		y/=10;
		e++;
	}
	for( i =(e-1);i>=0;i--)
	{
		LCD_voidSendData(arr[i]+'0');
	}

}

