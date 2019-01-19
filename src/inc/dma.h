/*
 * dma.h
 *
 *  Created on: Dec 11, 2018
 *      Author: shubi
 */

/* Define to prevent recursive inclusion */
#ifndef INC_DMA_H_
#define INC_DMA_H_

#include "stm32f10x.h"

#define DMA_PERIPHERAL_DATA_8BIT        0
#define DMA_PERIPHERAL_DATA_16BIT       (0x0100)
#define DMA_PERIPHERAL_DATA_32BIT       (0x0200)
#define DMA_MEMORY_DATA_8BIT            0
#define DMA_MEMORY_DATA_16BIT           DMA_CCR1_MSIZE_0
#define DMA_MEMORY_DATA_32BIT            ((uint16_t)0x0800)
#define DMA_PRIORITY_LOW                0
#define DMA_PRIORITY_MEDIUM             DMA_CCR1_PL_0
#define DMA_PRIORITY_HIGH               DMA_CCR1_PL_1
#define DMA_PRIORITY_VERY_HIGH          DMA_CCR1_PL
#define DMA_PERIPHERAL_INCREMENT_E      1
#define DMA_PERIPHERAL_INCREMENT_D      0
#define DMA_MEMORY_INCREMENT_E          1
#define DMA_MEMORY_INCREMENT_D          0
#define DMA_CIRCULAR_MODE_E             1
#define DMA_CIRCULAR_MODE_D             0
#define DMA_READ_FROM_PERIPHERAL        0
#define DMA_READ_FROM_MEMORY            1
#define DMA_M2M_D                       0
#define DMA_M2M_E                       1


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
 * @retval  None
 */
void DMA_Init(uint8_t DMA_Num, DMA_Channel_TypeDef * DMA_Channel, const uint32_t * Peripheral_Adr, const uint32_t * Memory_Adr,const uint32_t Size,
	    	const uint32_t Psize, const uint32_t Msize, const uint32_t Prio, const uint32_t P_inc, const uint32_t M_inc, const uint8_t Circular_M,
		    const uint8_t M2M, const uint8_t Dir );

/**
 * @brief   Enable DMA
 * @note
 * @param   DMAx_Channely   where: x= 1 or 2 , y= 1 ..7 for DMA1 and 1 ..5 for DMA2
 * @retval  None
 */
void DMA_ChannelEnable(DMA_Channel_TypeDef *DMA_Channel,uint8_t DMA_Num, uint8_t Ch_Num);

/**
 * @brief   Disable DMA
 * @note
 * @param   DMAx_Channely   where: x= 1 or 2 , y= 1 ..7 for DMA1 and 1 ..5 for DMA2
 * @retval  None
 */
void DMA_ChannelDisable(DMA_Channel_TypeDef *DMA_Channel);


#endif /* INC_DMA_H_ */
