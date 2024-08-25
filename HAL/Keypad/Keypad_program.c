/*
 * Keypad_program.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Abdelrhman M Eissa
 */


#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "Keypad_private.h"
#include "Keypad_config.h"
#include "Keypad_interface.h"




void Keypad_voidInit(void)
{
	for(u8 i=0; i<NUMBER_OF_COLS; i++)
	{
		DIO_u8SetPinDirection(cols[i].port, cols[i].pin, OUTPUT);
		DIO_u8SetPinValue(cols[i].port, cols[i].pin, HIGH);
	}

	for(u8 i=0; i<NUMBER_OF_ROWS; i++)
	{
		DIO_u8SetPinDirection(rows[i].port, rows[i].pin, INPUT);
		DIO_PULLUP_PIN(rows[i].port, rows[i].pin);
	}

}


u8 Keypad_u8GetValue(void)
{
	for(int i=0; i<NUMBER_OF_COLS;i++)
	{
		DIO_u8SetPinValue(cols[i].port, cols[i].pin, LOW);
		for(int j=0; j<NUMBER_OF_ROWS;j++)
		{
			if(DIO_u8GetPinValue(rows[j].port, rows[j].pin) == LOW)
			{
				while(DIO_u8GetPinValue(rows[j].port, rows[j].pin) == LOW);
				return characters[i][j];
			}
		}
		DIO_u8SetPinValue(cols[i].port, cols[i].pin, HIGH);
	}
	return KEYPAD_NULL_RETURN;
}
