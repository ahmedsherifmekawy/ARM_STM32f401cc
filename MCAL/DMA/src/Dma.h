/*
 * Dma.h
 *
 *  Created on: Apr 29, 2022
 *      Author: WINDOWS
 */

#ifndef DMA_H_
#define DMA_H_

typedef enum{
	DmaOk,
	DmaNok
}Dma_tenuErrorStatus;

typedef struct{
	u8 StreamNumber;
	u32 DMA_Number;
	u32 Channel;
	u32 Direction;
	u32 MemoryAddress[2]; // memory 0 & memory 1
	u32 PeriAddress;
	u32 CopiesNumber;
	u32 Mode;  // Double buffer or not
	u32 Priority;
	u32 PeriOffsetIncrement;
	u32 MemoryDataSize;
	u32 PeriDataSize;
	u32 MemoryIncrementMode;
	u32 PeriIncrementMode;
	u32 CircularMode;
	u32 PeriFlowCtrl;
	u32 TC_Int;
	u32 HTC_Int;
	u32 TrasError_Int;
	u32 DirModeError_Int;
}Dma_tenuCfg;


#define   DMA1                                        (u32)0x40026400
#define   DMA2                                        (u32)0x40026400


#define   DMA_u32SCR_CHSEL_0                          (u32)0x0
#define   DMA_u32SCR_CHSEL_1                          (u32)0x2000000
#define   DMA_u32SCR_CHSEL_2                          (u32)0x4000000
#define   DMA_u32SCR_CHSEL_3                          (u32)0x6000000
#define   DMA_u32SCR_CHSEL_4                          (u32)0x8000000
#define   DMA_u32SCR_CHSEL_5                          (u32)0xA000000
#define   DMA_u32SCR_CHSEL_6                          (u32)0xC000000
#define   DMA_u32SCR_CHSEL_7                          (u32)0xE000000


#define   DMA_u32SCR_MBURST_1                         (u32)0x0
#define   DMA_u32SCR_MBURST_4                         (u32)0x800000
#define   DMA_u32SCR_MBURST_8                         (u32)0x1000000
#define   DMA_u32SCR_MBURST_16                        (u32)0x1800000

#define   DMA_u32SCR_PBURST_1                         (u32)0x0
#define   DMA_u32SCR_PBURST_4                         (u32)0x200000
#define   DMA_u32SCR_PBURST_8                         (u32)0x400000
#define   DMA_u32SCR_PBURST_16                        (u32)0x600000


#define   DMA_u32SCR_CT_MEM0                          (u32)0x0
#define   DMA_u32SCR_CT_MEM1                          (u32)0x80000


#define   DMA_u32SCR_DBM_ON                           (u32)0x40000
#define   DMA_u32SCR_DBM_OFF                          (u32)0x0


#define   DMA_u32SCR_PL_LOW                           (u32)0x0
#define   DMA_u32SCR_PL_MID                           (u32)0x10000
#define   DMA_u32SCR_PL_HIGH                          (u32)0x20000
#define   DMA_u32SCR_PL_VERY_HIGH                     (u32)0x30000


#define   DMA_u32SCR_PINCOS_PSIZE                     (u32)0x0
#define   DMA_u32SCR_PINCOS_4                         (u32)0x8000


#define   DMA_u32SCR_MSIZE_BYTE                       (u32)0x0
#define   DMA_u32SCR_MSIZE_HALF_WORD                  (u32)0x2000
#define   DMA_u32SCR_MSIZE_WORD                       (u32)0x4000


#define   DMA_u32SCR_PSIZE_BYTE                       (u32)0x0
#define   DMA_u32SCR_PSIZE_HALF_WORD                  (u32)0x800
#define   DMA_u32SCR_PSIZE_WORD                       (u32)0x1000


#define   DMA_u32SCR_MINC_FIXED                       (u32)0x0
#define   DMA_u32SCR_MINC_MSIZE                       (u32)0x400


#define   DMA_u32SCR_PINC_FIXED                       (u32)0x0
#define   DMA_u32SCR_PINC_PSIZE                       (u32)0x200


#define   DMA_u32SCR_CIRC_EN                          (u32)0x100
#define   DMA_u32SCR_CIRC_DIS                         (u32)0x0


#define   DMA_u32SCR_DIR_PTM                          (u32)0x0
#define   DMA_u32SCR_DIR_MTP                          (u32)0x40
#define   DMA_u32SCR_DIR_MTM                          (u32)0x80


#define   DMA_u32SCR_PFCTRL_DMA                       (u32)0x0
#define   DMA_u32SCR_PFCTRL_PERI                      (u32)0x20

#define   DMA_u32SCR_TCIE_EN                          (u32)0x10
#define   DMA_u32SCR_TCIE_DIS                         (u32)0x0

#define   DMA_u32SCR_HTIE_EN                          (u32)0x8
#define   DMA_u32SCR_HTIE_DIS                         (u32)0x0

#define   DMA_u32SCR_TEIE_EN                          (u32)0x4
#define   DMA_u32SCR_TEIE_DIS                         (u32)0x0

#define   DMA_u32SCR_DMEIE_EN                         (u32)0x2
#define   DMA_u32SCR_DMEIE_DIS                        (u32)0x0

#define   DMA_u32SCR_EN                               (u32)0x1
#define   DMA_u32SCR_DIS                              (u32)0x0


Dma_tenuErrorStatus Dma_enuInit( Dma_tenuCfg * Add_penuDmaCfg );
void Dma_vidStart(void);


#endif /* DMA_H_ */
