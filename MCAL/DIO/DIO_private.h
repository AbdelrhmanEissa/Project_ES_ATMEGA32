/*
 * DIO_private.h
 *
 *  Created on: Jul 25, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_



#define PIND_Register 		(*((volatile u8 *) 0x30))
#define DDRD_Register 		(*((volatile u8 *) 0x31))
#define PORTD_Register 		(*((volatile u8 *) 0x32))

#define PINC_Register 		(*((volatile u8 *) 0x33))
#define DDRC_Register 		(*((volatile u8 *) 0x34))
#define PORTC_Register 		(*((volatile u8 *) 0x35))

#define PINB_Register 		(*((volatile u8 *) 0x36))
#define DDRB_Register 		(*((volatile u8 *) 0x37))
#define PORTB_Register 		(*((volatile u8 *) 0x38))

#define PINA_Register 		(*((volatile u8 *) 0x39))
#define DDRA_Register 		(*((volatile u8 *) 0x3A))
#define PORTA_Register 		(*((volatile u8 *) 0x3B))




#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
