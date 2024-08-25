/*
 * Servo_program.c
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdelrhman M Eissa
 */


#include "../../LIB/STD_Types.h"
#include "../../MCAL/TIM1/TIM1_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "Servo_private.h"
#include "Servo_config.h"
#include "Servo_interface.h"

void Servo_Init(void)
{
	DIO_u8SetPinDirection(PORTD, PIN5, OUTPUT);
	DIO_u8SetPinDirection(PORTD, PIN4, OUTPUT);
	TIM1_voidFPWMInit(SERVO_PERIOD_US);
}

void Servo_SetAngle(u8 servo, s8 angle)
{
	u32 tmp = (angle + (s8) 90);
	tmp = (tmp * 1000)/180;

	switch(servo)
	{
	case SERVO1: TIM1_setDutyCycle(SERVO1_CH, 1000 + ((u16) tmp)); break;
	case SERVO2: TIM1_setDutyCycle(SERVO2_CH, 1000 + ((u16) tmp)); break;
	}

}
