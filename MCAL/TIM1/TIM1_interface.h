/*
 * TIM1_interface.h
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef MCAL_TIM1_TIM1_INTERFACE_H_
#define MCAL_TIM1_TIM1_INTERFACE_H_

#define PWM_OCR1A		0
#define PWM_OCR1B		1

#define ICU_EDGE_RISING			0
#define ICU_EDGE_FALLING		1

void TIM1_voidInit(void);
u16 TIM1_GetCounterValueUs(void);
void TIM1_ClearCounterValue(void);
void TIM1_voidFPWMInit(u16 period_us);
void TIM1_setDutyCycle(u8 channel, u16 value_us);

void TIM1_voidICUInit(void);
void TIM1_SetEdge(u8 edge);
u16 TIM1_GetICRValue(void);
void TIM1_setCallback(void (* ptr)(void));

#endif /* MCAL_TIM1_TIM1_INTERFACE_H_ */
