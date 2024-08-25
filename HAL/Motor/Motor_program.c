/*
 * Motor_program.c
 *
 *  Created on: Jul 31, 2024
 *      Author: Abdelrhman M Eissa
 */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "Motor_private.h"
#include "Motor_config.h"
#include "Motor_interface.h"
#include <util/delay.h>

void Motor_Init(void)
{
	DIO_u8SetPinDirection(MOTOR_CCW_PORT, MOTOR_CCW_PIN, OUTPUT);
	DIO_u8SetPinDirection(MOTOR_CW_PORT, MOTOR_CW_PIN, OUTPUT);
	Motor_Stop();
}
void Motor_SetDirection(u8 L_u8Direction)
{
	switch(L_u8Direction)
	{
	case MOTOR_CW:
		DIO_u8SetPinValue(MOTOR_CCW_PORT, MOTOR_CCW_PIN, LOW);
		_delay_ms(1);
		DIO_u8SetPinValue(MOTOR_CW_PORT, MOTOR_CW_PIN, HIGH);
		break;
	case MOTOR_CCW:
		DIO_u8SetPinValue(MOTOR_CW_PORT, MOTOR_CW_PIN, LOW);
		_delay_ms(1);
		DIO_u8SetPinValue(MOTOR_CCW_PORT, MOTOR_CCW_PIN, HIGH);
		break;
	}
}
void Motor_Stop(void)
{
	DIO_u8SetPinValue(MOTOR_CCW_PORT, MOTOR_CCW_PIN, LOW);
	DIO_u8SetPinValue(MOTOR_CW_PORT, MOTOR_CW_PIN, LOW);
}
