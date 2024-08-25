/*
 * GIE_program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Abdelrhman M Eissa
 */


#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "GIE_private.h"
#include "GIE_interface.h"


void GIE_Enable(void)
{
	SET_BIT(SREG_Register, I_Bit);
}

void GIE_Disable(void)
{
	CLEAR_BIT(SREG_Register, I_Bit);
}
