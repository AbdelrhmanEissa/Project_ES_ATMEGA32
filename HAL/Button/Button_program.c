/*
 * Button_program.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Abdelrhman M Eissa
 */
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Button_private.h"
#include "Button_config.h"
#include "Button_interface.h"

void Button_voidInit()
{
	DIO_u8SetPinDirection(BUTTON1_PORT, BUTTON1_PIN, INPUT);
	DIO_PULLUP_PIN(BUTTON1_PORT, BUTTON1_PIN);
}

u8 Button_u8GetStatus(u8 L_u8ButtonNo)
{
	switch(L_u8ButtonNo)
	{
	case BUTTON1: return DIO_u8GetPinValue(BUTTON1_PORT, BUTTON1_PIN)? BUTTON_RELEASED:BUTTON_PRESSED;
	}
	return DIO_ERROR;
}

void Button_voidWaitForButton(u8 L_u8ButtonNo)
{
	switch(L_u8ButtonNo)
	{
	case BUTTON1: while(DIO_u8GetPinValue(BUTTON1_PORT, BUTTON1_PIN) == HIGH);break;
	}
}
