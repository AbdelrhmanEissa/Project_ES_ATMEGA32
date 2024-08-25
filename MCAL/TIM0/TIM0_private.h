/*
 * TIM0_private.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef MCAL_TIM0_TIM0_PRIVATE_H_
#define MCAL_TIM0_TIM0_PRIVATE_H_


#define TCCR0_Register	 	*((volatile u8 *) 0x53)
#define TCNT0_Register	 	*((volatile u8 *) 0x52)
#define OCR0_Register	 	*((volatile u8 *) 0x5C)
#define TIMSK_Register	 	*((volatile u8 *) 0x59)
#define TIFR_Register	 	*((volatile u8 *) 0x58)


/* TCCR0 register bits */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/* TIMSK register bits */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR register bits */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/* SFIOR register bits */
#define ADTS2   7
#define ADTS1   6
#define ADTS0   5
/* bit 4 reserved */
#define ACME    3
#define PUD     2
#define PSR2    1
#define PSR10   0

void __vector_10(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));


#endif /* MCAL_TIM0_TIM0_PRIVATE_H_ */
