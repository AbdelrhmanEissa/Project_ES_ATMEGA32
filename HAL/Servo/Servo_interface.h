/*
 * Servo_interface.h
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef SERVO_SERVO_INTERFACE_H_
#define SERVO_SERVO_INTERFACE_H_

#define SERVO1	0
#define SERVO2	1

void Servo_Init(void);
void Servo_SetAngle(u8 servo, s8 angle);

#endif /* SERVO_SERVO_INTERFACE_H_ */
