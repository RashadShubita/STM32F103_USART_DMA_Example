/*
 * GPIO.c
 *
 *  Created on: Nov 13, 2018
 *      Author: Rashad Shubita
 */

/* Includes */
#include "gpio.h"

/**
 * @brief   LED initialization function
 * @note    Yellow_LED -> PC13
 * @param   None
 * @retval  None
 */
void GPIO_OnBoard_Init_LED(void)
{
 /* Enable clock for GPIOC */
    RCC ->APB2ENR |= RCC_APB2ENR_IOPCEN;
 /* Configure PC.13 in output mode, max speed 2 MHz. */
    GPIOC ->CRH &= ~GPIO_CRH_MODE13;
    GPIOC ->CRH |=  GPIO_CRH_MODE13_1;
 /* Configure PC.13 as  general purpose output push-pull */
    GPIOC ->CRH  &= ~GPIO_CRH_CNF13;
 /* Led OFF */
    GPIOC ->ODR  |= GPIO_ODR_ODR13;

}

/**
 * @brief   Push button initialization function
 * @note    Push button connected to PA0
 * @param   None
 * @retval  None
 */
void GPIO_Init_PB(void)
{
	RCC -> APB2ENR |=  RCC_APB2ENR_IOPAEN;  //Enable Clock for GPIOA
	GPIOA -> CRL   &= ~GPIO_CRL_MODE0;      //Input mode (reset state)
	GPIOA -> CRL   &= ~GPIO_CRL_CNF0_0;     //Input with pull-up / pull-down
	GPIOA -> CRL   |=  GPIO_CRL_CNF0_1;     //
	GPIOA ->ODR    &= ~GPIO_ODR_ODR0;       //active pull-down resistor
}

/**
 * @brief   USART1 GPIO initialization function
 * @note    PA9  -> USART1_TX
 *          PA10 -> USART1_RX
 *          PA11 -> USART1_CTS
 *          PA12 -> USART1_RTS
 *          "Table 5. Medium-density STM32F103xx pin definitions" in Datasheet
 *          "Table 24. USARTs" in Reference manual
 * @param   HFC if = 0 -> Init. CTS & RTS pins
 * @retval  None
 */
void GPIO_USART1_Init(uint8_t HFC)
{
 /* GPIOA clock enable */
  	RCC ->APB2ENR   |= RCC_APB2ENR_IOPAEN;

 /* PA9 TX: Output mode, max speed 2 MHz. */
	GPIOA ->CRH     &= ~GPIO_CRH_MODE9;
	GPIOA ->CRH     |=  GPIO_CRH_MODE9_1;

 /* PA9 TX: Alternate function output Push-pull */
  	GPIOA ->CRH     &= ~GPIO_CRH_CNF9;
    GPIOA ->CRH     |=  GPIO_CRH_CNF9_1;

 /* PA10 RX: Floating input */
  	GPIOA ->CRH     &= ~GPIO_CRH_CNF10;
    GPIOA ->CRH     |=  GPIO_CRH_CNF10_0;

 /* PA10 RX: Input mode */
  	GPIOA ->CRH     &= ~GPIO_CRH_MODE10;
 if(HFC == 1)
 {
 /* PA11 CTS: Floating input */
    GPIOA ->CRH     &= ~GPIO_CRH_CNF11;
  	GPIOA ->CRH     |=  GPIO_CRH_CNF11_0;

 /* PA11 CTS: Input mode */
  	GPIOA ->CRH     &= ~GPIO_CRH_MODE11;

 /* PA12 RTS: Output mode, max speed 2 MHz. */
  	GPIOA ->CRH     &= ~GPIO_CRH_MODE12;
  	GPIOA ->CRH     |=  GPIO_CRH_MODE12_1;

 /* PA12 RTS: Alternate function output Push-pull */
  	GPIOA ->CRH     &= ~GPIO_CRH_CNF12;
  	GPIOA ->CRH     |=  GPIO_CRH_CNF12_1;
 }


}

/**
 * @brief   USART2 GPIO initialization function
 * @note    PB10 -> USART1_TX, PB11 -> USART1_RX
 * @param   None
 * @retval  None
 */
void GPIO_USART2_Init(void)
{
 /* GPIOA clock enable */
  	RCC ->APB2ENR   |= RCC_APB2ENR_IOPBEN;

 /* PB10 TX: Output mode, max speed 2 MHz. */
	GPIOB ->CRH     &= ~GPIO_CRH_MODE10;
	GPIOB ->CRH     |=  GPIO_CRH_MODE10_1;

 /* PB10 TX: Alternate function output Push-pull */
	GPIOB ->CRH     &= ~GPIO_CRH_CNF10;
	GPIOB ->CRH     |=  GPIO_CRH_CNF10_1;

 /* PB11 RX: Floating input */
	GPIOB ->CRH     &= ~GPIO_CRH_CNF11;
	GPIOB ->CRH     |=  GPIO_CRH_CNF11_0;

 /* PB11 RX: Input mode */
	GPIOB ->CRH     &= ~GPIO_CRH_MODE11;

}

