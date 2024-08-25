/*
 * Keypad_config.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef KEYPAD_KEYPAD_CONFIG_H_
#define KEYPAD_KEYPAD_CONFIG_H_

#define KEYPAD_COL0_PORT   PORTA
#define KEYPAD_COL0_PIN   PIN0

struct pin
{
	u8 port;
	u8 pin;
};

const struct pin cols[]=
{
		{PORTB, PIN4},
		{PORTB, PIN5},
		{PORTB, PIN6},
		{PORTB, PIN7}
};

const struct pin rows[]=
{
		{PORTB, PIN0},
		{PORTB, PIN1},
		{PORTB, PIN2},
		{PORTB, PIN3}
};

#define NUMBER_OF_COLS	(sizeof(cols)/sizeof(struct pin))
#define NUMBER_OF_ROWS	(sizeof(rows)/sizeof(struct pin))


u8 characters[NUMBER_OF_COLS][NUMBER_OF_ROWS] =
{
		{'7', '4', '1', 'C'},
		{'8', '5', '2', '0'},
		{'9', '6', '3', '='},
		{'/', '*', '-', '+'},
};

#endif /* KEYPAD_KEYPAD_CONFIG_H_ */
