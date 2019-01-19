/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 9.0.0   2018-06-29

The MIT License (MIT)
Copyright (c) 2018 STMicroelectronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************************
*/

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
    USART_Init(USART1, Yes, Yes, Yes, 8000000);
    /* Init. for USART1_TX */
    DMA_Init(1,DMA1_Channel4, (const uint32_t *)&USART1->DR,(const uint32_t *)tempAddr,128,DMA_PERIPHERAL_DATA_8BIT, DMA_MEMORY_DATA_8BIT, DMA_PRIORITY_VERY_HIGH
    		,DMA_PERIPHERAL_INCREMENT_D,DMA_MEMORY_INCREMENT_E,DMA_CIRCULAR_MODE_D,DMA_M2M_D,DMA_READ_FROM_MEMORY);

    /* Init. for USART1_RX */
    DMA_Init(1,DMA1_Channel5, (const uint32_t *)&USART1->DR,(const uint32_t *)RxDMABuffer,128,DMA_PERIPHERAL_DATA_8BIT, DMA_MEMORY_DATA_8BIT, DMA_PRIORITY_VERY_HIGH
    		,DMA_PERIPHERAL_INCREMENT_D,DMA_MEMORY_INCREMENT_E,DMA_CIRCULAR_MODE_D,DMA_M2M_D,DMA_READ_FROM_PERIPHERAL);


    __enable_irq();
    USART_Enable(USART1);
    DMA_ChannelEnable(DMA1_Channel5,1,5);
 while(1)
 {
	 USART1_Process();
 }

}


