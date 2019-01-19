/*
 * dma.c
 *
 *  Created on: Dec 11, 2018
 *      Author: shubi
 */

#include "dma.h"

/**
 * @brief   DMA initialization function
 * @note    Basic initialization
 *
 * @param   DMA_Num:        1 or 2
 *          DMA_Channel:    DMAx_Channely   where: x= 1 or 2 , y= 1 ..7 for DMA1 and 1 ..5 for DMA2
 *          Peripheral_Adr: peripheral address
 *          Memory_Adr:     memory address
 *          Size:           Buffer size(no. of data to transfer)
 *          Psize:          DMA_PERIPHERAL_DATA_8BIT
 *                          DMA_PERIPHERAL_DATA_16BIT
 *                          DMA_PERIPHERAL_DATA_32BIT
 *          Msize:          DMA_MEMORY_DATA_8BIT
 *                          DMA_MEMORY_DATA_16BIT
 *                          DMA_MEMORY_DATA_32BIT
 *          Prio:           DMA_PRIORITY_LOW
 *                          DMA_PRIORITY_MEDIUM
 *                          DMA_PRIORITY_HIGH
 *                          DMA_PRIORITY_VERY_HIGH
 *          P_inc:          DMA_PERIPHERAL_INCREMENT_E
 *                          DMA_PERIPHERAL_INCREMENT_D
 *          M_inc:          DMA_MEMORY_INCREMENT_E
 *                          DMA_MEMORY_INCREMENT_D
 *          Circular_M:     DMA_CIRCULAR_MODE_E
 *                          DMA_CIRCULAR_MODE_D
 *          M2M:            DMA_M2M_E
 *                          DMA_M2M_D
 *
 * @retval  None
 */
void DMA_Init(uint8_t DMA_Num, DMA_Channel_TypeDef * DMA_Channel, const uint32_t * Peripheral_Adr, const uint32_t * Memory_Adr,const uint32_t Size,
		      const uint32_t Psize, const uint32_t Msize, const uint32_t Prio, const uint32_t P_inc, const uint32_t M_inc, const uint8_t Circular_M,
		      const uint8_t M2M, const uint8_t Dir )
{
  /* Enable clock for DMA1 or DM2 */
	 if(DMA_Num == 1)
	     RCC ->AHBENR |= RCC_AHBENR_DMA1EN;
	 else if(DMA_Num == 2)
			 RCC ->AHBENR |= RCC_AHBENR_DMA1EN;

 /* disable channel, since this registers must not be written when the channel is enabled */
	 if(DMA_CCR1_EN == (DMA_CCR1_EN & DMA_Channel->CCR))
	  {
	    /* DMA 2 stream 5 is enabled, shall be disabled first */
		  DMA_ChannelDisable(DMA_Channel);

	    /* Wait until EN bit is cleared */
	  while(DMA_CCR1_EN == (DMA_CCR1_EN & DMA_Channel->CCR))
	    {
	      /* Do nothing until EN bit is cleared */
	    }
	  }
	  else
	  {
	    /* Do nothing, stream 5 is not enabled */
	  }

 /* Set address for peripheral */
	DMA_Channel ->CPAR   = (uint32_t)Peripheral_Adr;

 /* Set address for memory */
	DMA_Channel ->CMAR   = (uint32_t)Memory_Adr;

 /* Set no. of data to transfer */
	DMA_Channel ->CNDTR  = Size;

 /* Set Peripheral size, 00: 8-bits & 01: 16-bits & 10: 32-bits & 11: Reserved */
	DMA_Channel ->CCR   &= ~DMA_CCR1_PSIZE;
	if(Psize != 0)DMA_Channel ->CCR   |= Psize;

 /* Set Memory size, 00: 8-bits & 01: 16-bits & 10: 32-bits & 11: Reserved*/
	DMA_Channel ->CCR   &= ~DMA_CCR1_MSIZE;
	if(Msize != 0)DMA_Channel ->CCR   |= Msize;

 /* Set Channel priority, 00: Low & 01: Medium & 10: High & 11: Very high */
	DMA_Channel ->CCR   &= ~DMA_CCR1_PL;
	if(Prio != 0)DMA_Channel ->CCR   |= Prio;

 /* 1:Enable/0:Disable Peripheral increment mode */
	if(P_inc == 0)DMA_Channel ->CCR   &= ~DMA_CCR1_PINC;
	else DMA_Channel ->CCR   |= DMA_CCR1_PINC;

 /* 1:Enable/0:Disable memory increment mode */
	if(M_inc == 0)DMA_Channel ->CCR   &= ~DMA_CCR1_MINC;
	else DMA_Channel ->CCR   |= DMA_CCR1_MINC;

if(M2M == 0)
{
 /* Disable M2M Mode */
	DMA_Channel ->CCR   &= ~DMA_CCR1_MEM2MEM;
 /* 1:Enable/0:Disable Circular mode*/
	if(Circular_M == 0)DMA_Channel ->CCR   &= ~DMA_CCR1_CIRC;
	else DMA_Channel ->CCR   |= DMA_CCR1_CIRC;
}
else
{
 /* Enable M2M Mode */
	DMA_Channel ->CCR   |= DMA_CCR1_MEM2MEM;
}
 /* Data transfer direction, 0: Read from peripheral , 1: Read from memory*/
	if(Dir == 0)DMA_Channel ->CCR   &= ~DMA_CCR1_DIR;
	else DMA_Channel ->CCR   |= DMA_CCR1_DIR;

 /* Enable Transfer complete interrupt */
	DMA_Channel ->CCR   |= DMA_CCR1_TCIE;

	__ASM("NOP");
	__ASM("NOP");
	__ASM("NOP");
	__ASM("NOP");
}

/**
 * @brief   Enable DMA
 * @note
 * @param   DMAx_Channely   where: x= 1 or 2 , y= 1 ..7 for DMA1 and 1 ..5 for DMA2
 * @retval  None
 */
void DMA_ChannelEnable(DMA_Channel_TypeDef *DMA_Channel,uint8_t DMA_Num, uint8_t Ch_Num)
{
  /*Clears the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register */
	if(DMA_Num == 1)DMA1->IFCR |= (1 << (4*(Ch_Num-1)) );
	else DMA2->IFCR |= (1 << (4*(Ch_Num-1)) );
 /* Channel enable */
	DMA_Channel->CCR |=  DMA_CCR1_EN;
}

/**
 * @brief   Disable DMA
 * @note
 * @param   DMAx_Channely   where: x= 1 or 2 , y= 1 ..7 for DMA1 and 1 ..5 for DMA2
 * @retval  None
 */
void DMA_ChannelDisable(DMA_Channel_TypeDef *DMA_Channel){
  DMA_Channel->CCR &= ~DMA_CCR1_EN;
}
