/*
 * TIM0_program.c
 *
 *  Created on: Aug 1, 2024
 *      Author: Abdelrhman M Eissa
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "TIM0_private.h"
#include "TIM0_config.h"
#include "TIM0_interface.h"

u32 NoCounts;
u32 preload;

void (* func_ptr_ovf)(void);
void (* func_ptr_ctc)(void);

void TIM0_Init(void)
{

#if TIM0_MODE == TIM_NORMAL
	// Normal Mode
	CLEAR_BIT(TCCR0_Register, WGM00);
	CLEAR_BIT(TCCR0_Register, WGM01);

	// Enable Overflow Interrupt
	SET_BIT(TIMSK_Register, TOIE0);
#elif TIM0_MODE == TIM_CTC
	// Normal Mode
	CLEAR_BIT(TCCR0_Register, WGM00);
	SET_BIT(TCCR0_Register, WGM01);

	// Enable CTC Interrupt
	SET_BIT(TIMSK_Register, OCIE0);
#endif


}

void TIM0_SetValueUS(u32 us)
{

#if TIM0_MODE == TIM_NORMAL
	// F_CPU = 8Mhz
	// Prescaler 8
	// Timer Freq = 1MHz
	// Tick_Time = 1uS
	// OVF Time = 2^(8 bits) * 1uS = 256uS

	NoCounts = us/256;
	u32 mod = us%256;
	preload = 256 - mod;

	TCNT0_Register = preload;
#elif TIM0_MODE == TIM_CTC
	for(u8 x = 255; x > 0; x--)
	{
		if(us%x == 0)
		{
			OCR0_Register = x;
			NoCounts = us/x;
			break;
		}
	}
#endif

	// Set Clock Source (Prescaler: 8)
	CLEAR_BIT(TCCR0_Register, CS00);
	SET_BIT(TCCR0_Register, CS01);
	CLEAR_BIT(TCCR0_Register, CS02);
}

void TIM0_Disable(void)
{
	// Disable Timer (No clk)
	CLEAR_BIT(TCCR0_Register, CS00);
	CLEAR_BIT(TCCR0_Register, CS01);
	CLEAR_BIT(TCCR0_Register, CS02);
}

void TIM0_SetOVFCallback(void (* ptr)(void))
{
	func_ptr_ovf = ptr;
}

void TIM0_SetCTCCallback(void (* ptr)(void))
{
	func_ptr_ctc = ptr;
}

void __vector_11(void)
{
	static u32 counter = 0;
	if(counter == NoCounts)
	{
		func_ptr_ovf();
		counter = 0;
		TCNT0_Register = preload;
	}
	counter++;
}

void __vector_10(void)
{
	static u32 counter = 0;
	if(counter == NoCounts)
	{
		func_ptr_ctc();
		counter = 0;
	}
	counter++;
}
