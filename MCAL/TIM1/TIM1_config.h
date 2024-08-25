/*
 * TIM1_config.h
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef MCAL_TIM1_TIM1_CONFIG_H_
#define MCAL_TIM1_TIM1_CONFIG_H_

/* Mode Configuration */
#define TIM1_PWM_TOG_ON_COMPARE_MATCH	0b01
#define TIM1_PWM_CLR_ON_COMPARE_MATCH	0b10
#define TIM1_PWM_SET_ON_COMPARE_MATCH	0b11


#define TIM1_PWM_OC1A_MODE	TIM1_PWM_CLR_ON_COMPARE_MATCH
#define TIM1_PWM_OC1B_MODE	TIM1_PWM_SET_ON_COMPARE_MATCH

#endif /* MCAL_TIM1_TIM1_CONFIG_H_ */
