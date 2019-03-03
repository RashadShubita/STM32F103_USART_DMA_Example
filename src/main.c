/*******************************************************************************
 * @file    main.c
 * @author  Rashad Shubita
 * @email   shubitarashad@gmail.com
 * @date    03.03.2019
 *
 * @brief   main application called after startup
 * @note
 *
@verbatim
Copyright (C) 2019, Rashad Shubita

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "nvic.h"
#include "SysTick.h"
#include "gpio.h"
#include "usart.h"
#include "dma.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
char tempAddr[20]="temp address";

extern char RxDMABuffer[128];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
	SysTick_Init();
    GPIO_OnBoard_Init_LED();
    NVIC_Init();

    USART1_Init(Cal_USART_BRR_Val(115200,8000000) );
    /* Init. for USART1_TX */
    USART1_TX_DMA_Config();
    /* Init. for USART1_RX */
    USART1_RX_DMA_Config();

     __enable_irq();
    USART_Enable(USART1);
    DMA_ChannelEnable(DMA1_Channel5,1,5);

 while(1)
 {
	 USART1_Process();
 }

}


