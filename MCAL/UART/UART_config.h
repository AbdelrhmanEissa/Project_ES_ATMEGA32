/*
 * UART_config.h
 *
 *  Created on: Aug 7, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_

#define UART_MODE_ASYNC		0b0
#define UART_MODE_SYNC		0b1

#define UART_PARITY_DISABLED	0b00
#define UART_PARITY_EVEN		0b10
#define UART_PARITY_ODD			0b11

#define UART_STOPBITS_1			0b0
#define UART_STOPBITS_2			0b1

#define	UART_CHAR_SIZE_5		0b000
#define	UART_CHAR_SIZE_6		0b001
#define	UART_CHAR_SIZE_7		0b010
#define	UART_CHAR_SIZE_8		0b011
//#define	UART_CHAR_SIZE_9		0b111

#define	UART_BAUDRATE_2k4		207
#define	UART_BAUDRATE_4k8		103
#define	UART_BAUDRATE_9k6		51
#define	UART_BAUDRATE_14k4		34
#define	UART_BAUDRATE_19k2		24
#define	UART_BAUDRATE_28k4		12

/* Configurations */
#define UART_MODE			UART_MODE_ASYNC
#define UART_PARITY	 		UART_PARITY_DISABLED
#define UART_STOPBITS		UART_STOPBITS_2
#define	UART_CHAR_SIZE		UART_CHAR_SIZE_8
#define	UART_BAUDRATE		UART_BAUDRATE_9k6



#endif /* MCAL_UART_UART_CONFIG_H_ */
