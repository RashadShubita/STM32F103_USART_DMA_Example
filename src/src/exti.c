/*
 * EXTI.c
 *
 *  Created on: Nov 20, 2018
 *      Author: shubi
 */


#include "exti.h"
#include "stm32f10x.h"

void EXTI_Init_PB(void)
{

 /* --------------- EXTI initialization and connect the External line to the GPIO --------------- */
 /* Enable AFIO_EXTICR clock */
    RCC-> APB2ENR |= RCC_APB2ENR_AFIOEN;

 /* MAP the PA0 to EXTI0  */
    AFIO-> EXTICR[0] |= AFIO_EXTICR1_EXTI0_PA ;

 /* Rising trigger selection ( 1 = trigger enable) */
	EXTI-> RTSR |= EXTI_RTSR_TR0  ;

 /* Falling trigger selection ( 0 = trigger disable) */
	EXTI-> FTSR &= ~EXTI_FTSR_TR0  ;

 /* Interrupt Mask Register ( 1 = not masked [enable], 0=masked) */
    EXTI-> IMR |= EXTI_IMR_MR0 ;

 /* Enable event line */
    EXTI -> EMR |= EXTI_EMR_MR0;

 /* Clear pending if any */
	EXTI->PR |= EXTI_PR_PR0;

}
