/*
 * SysTick.c
 *
 * Created on: Nov 13, 2018
 * Author: Rashad Shubita
 */

/* Includes */
#include "SysTick.h"

volatile uint32_t SysTickCounter = 0;

/**
 * @brief   Return current SysTick counter
 * @note
 * @param   None
 * @retval  SysTickCounter
 */
uint32_t SysTick_GetCurrentTick(void)
{
  return(SysTickCounter);
}

/**
 * @brief   Delay function based on SysTick
 * @note    SysTick will be update with IRQ callback
 * @param   Waiting time in milliseconds
 * @retval  None
 */
void SysTick_Delay(uint32_t wait_time_ms)
{
  /* Store start tick */
  uint32_t startTick = SysTickCounter;

  /* Loop until timeout */
  while((SysTickCounter - startTick) < wait_time_ms)
  {

  }
}

/**
 * @brief   SysTick initial configuration
 * @note
 * @param   None
 * @retval  None
 */
void SysTick_Init(void)
{
  uint32_t returnCode;

  /* Update clock configuration */
  SystemCoreClockUpdate();

  /* Check clock configuration */
  if(SystemCoreClock != (uint32_t) 8000000)
  {
    /* Clock configuration is not OK */
    while(1)
    {

    }
  }
  else
  {
    /* Clock configuration is OK */
  }

  /* Configure SysTick to generate an interrupt every millisecond */
  returnCode = SysTick_Config(SystemCoreClock / 1000);

  /* Check return code for errors */
  if (returnCode != 0)
  {
    /* SysTick configuration failed */
    while(1)
    {

    }
  }
  else
  {
    /* Do nothing, SysTick configuration OK */
  }
  NVIC_SetPriority(SysTick_IRQn,  0);
}

