/*
 * Dma_prv.h
 *
 *  Created on: May 3, 2022
 *      Author: WINDOWS
 */

#ifndef DMA_PRV_H_
#define DMA_PRV_H_


typedef struct{
	u32 SCR;
	u32 SNDTR;
	u32 SPAR;
	u32 SMAR[2];
	u32 SFCR;
}DmaCfgReg_t;

typedef struct{
	u32 LISR;
	u32 HISR;
	u32 LIFCR;
	u32 HIFCR;
	DmaCfgReg_t Stream[7];
}Dma_t;

#define   DMA_u32SCR_CHSEL_MASK                                (u32)0xE000000
#define   DMA_u32SCR_MBURST_MASK                               (u32)0x1800000
#define   DMA_u32SCR_PBURST_MASK                               (u32)0x600000
#define   DMA_u32SCR_CT_MASK                                   (u32)0x80000
#define   DMA_u32SCR_DBM_MASK                                  (u32)0x40000
#define   DMA_u32SCR_PL_MASK                                   (u32)0x30000
#define   DMA_u32SCR_PINCOS_MASK                               (u32)0x8000
#define   DMA_u32SCR_MSIZE_MASK                                (u32)0x6000
#define   DMA_u32SCR_PSIZE_MASK                                (u32)0x1800
#define   DMA_u32SCR_MINC_MASK                                 (u32)0x400
#define   DMA_u32SCR_PINC_MASK                                 (u32)0x200
#define   DMA_u32SCR_CIRC_MASK                                 (u32)0x100
#define   DMA_u32SCR_DIR_MASK                                  (u32)0xC0
#define   DMA_u32SCR_PFCTRL_MASK                               (u32)0x20
#define   DMA_u32SCR_TCIE_MASK                                 (u32)0x10
#define   DMA_u32SCR_HTIE_MASK                                 (u32)0x8
#define   DMA_u32SCR_TEIE_MASK                                 (u32)0x4
#define   DMA_u32SCR_DMEIE_MASK                                (u32)0x2
#define   DMA_u32SCR_EN_MASK                                   (u32)0x1

#define   DMA_HIGH_BIT_SAFE_MASK                               (u32)0xFFFF



#endif /* DMA_PRV_H_ */
