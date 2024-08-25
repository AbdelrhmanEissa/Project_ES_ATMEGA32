/*
 * LED_program.c
 *
 *  Created on: Jul 25, 2024
 *      Author: Abdelrhman M Eissa
 */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"

void LED_voidInit()
{
	for(u8 i =0; i< NO_LEDS; i++)
	DIO_u8SetPinDirection(leds[i].port, leds[i].pin, OUTPUT);
}

void LED_voidSetLEDHigh(u8 L_u8led)
{
	if(L_u8led < NO_LEDS)
	{
		DIO_u8SetPinValue(leds[L_u8led].port, leds[L_u8led].pin, HIGH);
	}
}

void LED_voidSetLEDLow(u8 L_u8led)
{
	if(L_u8led < NO_LEDS)
	{
		DIO_u8SetPinValue(leds[L_u8led].port, leds[L_u8led].pin, LOW);
	}
}
