/*
 * UART_program.c
 *
 *  Created on: Aug 7, 2024
 *      Author: Abdelrhman M Eissa
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"


static void(*gftpr)(void)=NULL;

void UART_Init(void)
{
	u8 Temp_UCSRC	= 0b1000000;

	/* Set Mode Sync/Async */
	Temp_UCSRC |= (UART_MODE << UMSEL);

	/* Set Parity */
	Temp_UCSRC |= (UART_PARITY << UPM0);

	/* Select Stop Bits */
	Temp_UCSRC |= (UART_STOPBITS << USBS);

	/* Select Char size */
	Temp_UCSRC |= ((UART_CHAR_SIZE & 0b11) << UCSZ0);
	UCSRB |= (GET_BIT(UART_CHAR_SIZE, 2)) << UCSZ2;

	/* Set Baud-rate */
	UBRRL = (u8) UART_BAUDRATE;

	/* Enable Transmitter and Receiver */
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);

	UCSRC = Temp_UCSRC;
}

void UART_EnableInterruptReceive(void)
{
	SET_BIT(UCSRB, RXCIE);


}
u8 UART_RecieveByte(void)
{
	while(GET_BIT(UCSRA, RXC) == 0);

		return UDR;
}

void UART_SendByte(u8 byte)
{
	while(GET_BIT(UCSRA, UDRE) == 0);
	UDR = byte;
}

void UART_SetCallBack(void (*fptr)(void))
{
	gftpr=fptr;


}

void __vector_13(void) __attribute ((signal));
void __vector_13(void){
	gftpr();

}


void UART_Sendstr(u8 * res , u8 length )
{
	for (u8 i=0 ; i < length ; i++){
	       			while(GET_BIT(UCSRA, UDRE) == 0);
	       					UDR = res[i];
	       			}

}
