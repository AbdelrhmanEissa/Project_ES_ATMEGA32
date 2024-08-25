/*
 * TIM1_program.c
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdelrhman M Eissa
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "TIM1_private.h"
#include "TIM1_config.h"
#include "TIM1_interface.h"

void (* tim1_callback_ptr)(void);

///////////////////////////////////////
// Normal Mode
void TIM1_voidInit(void)
{
	TCNT1_Register = 0;

	/* Select Normal (OVF) Mode */
	CLEAR_BIT(TCCR1A_Register, WGM10);
	CLEAR_BIT(TCCR1A_Register, WGM11);
	CLEAR_BIT(TCCR1B_Register, WGM12);
	CLEAR_BIT(TCCR1B_Register, WGM13);


	/* Select Pre-scaler */
	CLEAR_BIT(TCCR1B_Register, CS10);
	SET_BIT(TCCR1B_Register, CS11);
	CLEAR_BIT(TCCR1B_Register, CS12);

}

///////////////////////////////////////
// ICU Mode

void TIM1_voidICUInit(void)
{
	TCNT1_Register = 0;

	/* Select Normal (OVF) Mode */
	CLEAR_BIT(TCCR1A_Register, WGM10);
	CLEAR_BIT(TCCR1A_Register, WGM11);
	CLEAR_BIT(TCCR1B_Register, WGM12);
	CLEAR_BIT(TCCR1B_Register, WGM13);

	/* Enable Input Capture Interrupt */
	SET_BIT(TIMSK_Register, TICIE1);

	/* Select Pre-scaler */
	CLEAR_BIT(TCCR1B_Register, CS10);
	SET_BIT(TCCR1B_Register, CS11);
	CLEAR_BIT(TCCR1B_Register, CS12);

}

void TIM1_SetEdge(u8 edge)
{
	switch(edge)
	{
	case ICU_EDGE_FALLING: CLEAR_BIT(TCCR1B_Register, ICES1); break;
	case ICU_EDGE_RISING: SET_BIT(TCCR1B_Register, ICES1); break;
	}
}

u16 TIM1_GetICRValue(void)
{
	return ICR1_Register;
}

void TIM1_setCallback(void (* ptr)(void))
{
	tim1_callback_ptr = ptr;
}


void __vector_6(void)
{
	tim1_callback_ptr();
}


////////////////////////////////////////////////
/// Normal

u16 TIM1_GetCounterValueUs(void)
{
	return TCNT1_Register;
}

void TIM1_ClearCounterValue(void)
{
	TCNT1_Register = 0;
}


///////////////////////////////////////
// PWM Mode
void TIM1_voidFPWMInit(u16 period_us)
{
	TCNT1_Register = 0;

	/* Select Mode 14 (Fast PWM) */
	CLEAR_BIT(TCCR1A_Register, WGM10);
	SET_BIT(TCCR1A_Register, WGM11);
	SET_BIT(TCCR1B_Register, WGM12);
	SET_BIT(TCCR1B_Register, WGM13);

	/* Select OC1A mode */
	TCCR1A_Register &= ~(0b11 << COM1A0);
	TCCR1A_Register |= TIM1_PWM_OC1A_MODE << COM1A0;

	/* Select OC1B mode */
	TCCR1A_Register &= ~(0b11 << COM1B0);
	TCCR1A_Register |= TIM1_PWM_OC1B_MODE << COM1B0;

	ICR1_Register = period_us;

	/* Select Pre-scaler */
	CLEAR_BIT(TCCR1B_Register, CS10);
	SET_BIT(TCCR1B_Register, CS11);
	CLEAR_BIT(TCCR1B_Register, CS12);
}

void TIM1_setDutyCycle(u8 channel, u16 value_us)
{
	switch(channel)
	{
	case PWM_OCR1A:	OCR1A_Register = value_us; break;
	case PWM_OCR1B:	OCR1B_Register = value_us; break;
	}
}
