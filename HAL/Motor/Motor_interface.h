/*
 * Motor_interface.h
 *
 *  Created on: Jul 31, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef MOTOR_MOTOR_INTERFACE_H_
#define MOTOR_MOTOR_INTERFACE_H_

#define MOTOR_CW	0
#define MOTOR_CCW	1

void Motor_Init(void);
void Motor_SetDirection(u8 L_u8Direction);
void Motor_Stop(void);

#endif /* MOTOR_MOTOR_INTERFACE_H_ */
