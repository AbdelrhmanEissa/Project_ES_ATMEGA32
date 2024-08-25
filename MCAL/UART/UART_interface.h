/*
 * UART_interface.h
 *
 *  Created on: Aug 7, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_Init(void);
u8 UART_RecieveByte(void);
void UART_SendByte(u8 byte);
void UART_SetCallBack(void (*fptr)(void));
void UART_EnableInterruptReceive(void);
void UART_Sendstr(u8 * res , u8 length );

#endif /* MCAL_UART_UART_INTERFACE_H_ */
