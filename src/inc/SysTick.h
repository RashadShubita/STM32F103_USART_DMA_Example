/*
 * SysTick.h
 *
 *  Created on: Nov 13, 2018
 *      Author: Rashad Shubita
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

/* Includes */
#include "stm32f10x.h"


extern volatile uint32_t SysTickCounter;

/**
 * @brief   Return current SysTick counter
 * @note
 * @param   None
 * @retval  SysTickCounter
 */
uint32_t SysTick_GetCurrentTick(void);

/**
 * @brief   Delay function based on SysTick
 * @note    SysTick will be update with IRQ callback
 * @param   Waiting time in milliseconds
 * @retval  None
 */
void SysTick_Delay(uint32_t wait_time_ms);

/**
 * @brief   SysTick initial configuration
 * @note
 * @param   None
 * @retval  None
 */
void SysTick_Init(void);

#endif /* INC_SYSTICK_H_ */
