/*
 * LED_config.h
 *
 *  Created on: Jul 25, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef LED_LED_CONFIG_H_
#define LED_LED_CONFIG_H_

struct led
{
	u8 port;
	u8 pin;
};

struct led leds[]=
{
		{PORTC, PIN0},
		{PORTC, PIN1},
		{PORTC, PIN2},
		{PORTC, PIN3},
		{PORTC, PIN4}
};

#define NO_LEDS	(sizeof(leds)/sizeof(struct led))

#endif /* LED_LED_CONFIG_H_ */
