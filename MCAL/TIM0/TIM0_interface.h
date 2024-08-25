/*
 * TIM0_interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef MCAL_TIM0_TIM0_INTERFACE_H_
#define MCAL_TIM0_TIM0_INTERFACE_H_

void TIM0_Init(void);
void TIM0_SetValueUS(u32 us);
void TIM0_Disable(void);
void TIM0_SetOVFCallback(void (* ptr)(void));
void TIM0_SetCTCCallback(void (* ptr)(void));

#endif /* MCAL_TIM0_TIM0_INTERFACE_H_ */
