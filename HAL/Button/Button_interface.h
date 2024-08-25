/*
 * Button_interface.h
 *
 *  Created on: Jul 27, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef BUTTON_BUTTON_INTERFACE_H_
#define BUTTON_BUTTON_INTERFACE_H_

#define BUTTON_PRESSED	0
#define BUTTON_RELEASED	1

#define BUTTON1		1


void Button_voidInit();
u8 Button_u8GetStatus(u8 L_u8ButtonNo);
void Button_voidWaitForButton(u8 L_u8ButtonNo);
void Button_voidDebounce(u8 L_u8ButtonNo); // Assignment

#endif /* BUTTON_BUTTON_INTERFACE_H_ */
