/*
 *
 LCD_program.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Abdelrhman M Eissa
 */


#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

void LCD_voidInit(void)
{
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_EN_PIN, OUTPUT);

	//Set data pins direction
	DIO_u8SetPinDirection(LCD_DATA_PORT, PIN0, OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, PIN1, OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, PIN2, OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, PIN3, OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, PIN4, OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, PIN5, OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, PIN6, OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, PIN7, OUTPUT);

	_delay_ms(30);

	LCD_voidSendCommand(0x33); /* Init. */
	LCD_voidSendCommand(0x32); /* Init. */

	LCD_voidSendCommand(LCD_FUNCTION_8BIT_2LINE);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_DISPLAY_ON);
	_delay_ms(1);
	LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
	_delay_ms(5);
	LCD_voidSendCommand(LCD_ENTRY_MODE_INC);
	_delay_ms(2);

}

void LCD_voidSendCommand(u8 u8CmdCopy)
{
	DIO_u8SetPortValue(LCD_DATA_PORT, u8CmdCopy);
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, LOW);
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, LOW);
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
	_delay_us(100);
}

void LCD_voidPrintChar(char u8CharCopy)
{
	DIO_u8SetPortValue(LCD_DATA_PORT, u8CharCopy);

	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, HIGH);
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, LOW);
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
	_delay_us(100);
}

void LCD_voidPrintStr(const char * s8StringCopy)
{
	while(* s8StringCopy)
	{
		LCD_voidPrintChar(* s8StringCopy);
		s8StringCopy++;
	}
}

void LCD_voidGotoRowCol(u8 u8RowCopy, u8 u8ColCopy)
{
	u8 Address;
	switch(u8RowCopy)
	{
	case 0:	Address = u8ColCopy;
			break;
	case 1:	Address = u8ColCopy + 0x40;
			break;
	case 2:	Address = u8ColCopy + 0x10;
			break;
	case 3:	Address = u8ColCopy + 0x50;
			break;
	}
	LCD_voidSendCommand(LCD_MOVE_CURSOR | Address);
}

void SetDDRAM_Add(u8 address) {
    SET_BIT(address, 7);
    LCD_voidSendCommand(address);
}


/*
void LCD_voidSendData(u8 L_u8Data)
{
		DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN,HIGH );

		 DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN,LOW );



	 DIO_u8SetPortValue(LCD_DATA_PORT, L_u8Data);
	 //voidSendEnablePulse();

*/
