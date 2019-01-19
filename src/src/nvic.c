/*
 * NVIC.c
 *
 *  Created on: Nov 20, 2018
 *      Author: shubi
 */

/* Includes */
#include "nvic.h"


/**
 * @brief   NVIC IRQs initialization function
 * @note
 * @param   None
 * @retval  None
 */
void NVIC_Init(void)
{
	  /* Set priority group to 3
	   * bits[3:0] are the sub-priority,
	   * bits[7:4] are the pre-empt priority */

	  NVIC_SetPriorityGrouping(3);

	  /* Set priority levels */
	  NVIC_SetPriority(EXTI0_IRQn, 1);
	  NVIC_SetPriority(DMA1_Channel3_IRQn, 1);
	  NVIC_SetPriority(DMA1_Channel4_IRQn, 1);
	  NVIC_SetPriority(DMA1_Channel5_IRQn, 1);
	  NVIC_SetPriority(USART1_IRQn,1);

	  /* Enable interrupts at NVIC */
	  NVIC_EnableIRQ(EXTI0_IRQn);
	  NVIC_EnableIRQ(DMA1_Channel3_IRQn);
	  NVIC_EnableIRQ(DMA1_Channel4_IRQn);
	  NVIC_EnableIRQ(DMA1_Channel5_IRQn);
	  NVIC_EnableIRQ(USART1_IRQn);


}
