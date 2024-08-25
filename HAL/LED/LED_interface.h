/*
 * LED_interface.h
 *
 *  Created on: Jul 25, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_

#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4


void LED_voidInit();
void LED_voidSetLEDHigh(u8 L_u8led);
void LED_voidSetLEDLow(u8 L_u8led);


#endif /* LED_LED_INTERFACE_H_ */
