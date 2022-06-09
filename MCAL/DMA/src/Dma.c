/*
 * Dma.c
 *
 *  Created on: Apr 29, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "Dma.h"
#include "Dma_prv.h"


#define     DMA_CFG            ( ( ( Dma_t * const ) Add_penuDmaCfg ->DMA_Number ) -> Stream[ Add_penuDmaCfg -> StreamNumber ] )

//static Dma_t * const Dma1 = ( Dma_t * const ) DMA1;
//static Dma_t * const Dma2 = ( Dma_t * const ) DMA2;

u32 Dma_Number;
u8 Stream_Number;
Dma_tenuErrorStatus Dma_enuInit( Dma_tenuCfg * Add_penuDmaCfg )
{
	Dma_tenuErrorStatus Loc_enuError = DmaOk;
	u32 Loc_u32Reg;
	if( Add_penuDmaCfg == NULL )
	{
		Loc_enuError = DmaNok;
	}
	else
	{
		Dma_Number = Add_penuDmaCfg->DMA_Number;
		Stream_Number = Add_penuDmaCfg->StreamNumber;

		Loc_u32Reg = DMA_CFG.SCR;
		Loc_u32Reg |= DMA_u32SCR_CHSEL_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->Channel | ~DMA_u32SCR_CHSEL_MASK );

		Loc_u32Reg |= DMA_u32SCR_DIR_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->Direction | ~DMA_u32SCR_DIR_MASK );

		Loc_u32Reg |= DMA_u32SCR_DBM_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->Mode | ~DMA_u32SCR_DBM_MASK );

		Loc_u32Reg |= DMA_u32SCR_PL_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->Priority | ~DMA_u32SCR_PL_MASK );

		Loc_u32Reg |= DMA_u32SCR_PINCOS_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->PeriOffsetIncrement | ~DMA_u32SCR_PINCOS_MASK );

		Loc_u32Reg |= DMA_u32SCR_MSIZE_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->MemoryDataSize | ~DMA_u32SCR_MSIZE_MASK );

		Loc_u32Reg |= DMA_u32SCR_PSIZE_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->PeriDataSize | ~DMA_u32SCR_PSIZE_MASK );

		Loc_u32Reg |= DMA_u32SCR_MINC_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->MemoryIncrementMode | ~DMA_u32SCR_MINC_MASK );

		Loc_u32Reg |= DMA_u32SCR_PINC_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->PeriIncrementMode | ~DMA_u32SCR_PINC_MASK );

		Loc_u32Reg |= DMA_u32SCR_CIRC_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->CircularMode | ~DMA_u32SCR_CIRC_MASK );

		Loc_u32Reg |= DMA_u32SCR_PFCTRL_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->PeriFlowCtrl | ~DMA_u32SCR_PFCTRL_MASK );

		Loc_u32Reg |= DMA_u32SCR_TCIE_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->TC_Int | ~DMA_u32SCR_TCIE_MASK );

		Loc_u32Reg |= DMA_u32SCR_HTIE_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->HTC_Int | ~DMA_u32SCR_HTIE_MASK );

		Loc_u32Reg |= DMA_u32SCR_TEIE_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->TrasError_Int | ~DMA_u32SCR_TEIE_MASK );

		Loc_u32Reg |= DMA_u32SCR_DMEIE_MASK;
		Loc_u32Reg &= ( Add_penuDmaCfg->DirModeError_Int | ~DMA_u32SCR_DMEIE_MASK );

		DMA_CFG.SNDTR = Add_penuDmaCfg->CopiesNumber | DMA_HIGH_BIT_SAFE_MASK;

		DMA_CFG.SPAR = Add_penuDmaCfg->PeriAddress;

		DMA_CFG.SMAR[0] = Add_penuDmaCfg->MemoryAddress[0];
		DMA_CFG.SMAR[1] = Add_penuDmaCfg->MemoryAddress[1];


		while( ( DMA_CFG.SCR & DMA_u32SCR_EN ) == DMA_u32SCR_EN );   /// wait until en is free
		DMA_CFG.SCR = Loc_u32Reg;
	}
	return Loc_enuError;
}
void Dma_vidStart(void)
{
	u32 Loc_u32Reg;
	( ( ( Dma_t * const ) Dma_Number )-> LISR ) = 0;
	( ( ( Dma_t * const ) Dma_Number )-> HISR ) = 0;

	Loc_u32Reg = ( ( ( Dma_t * const ) Dma_Number ) -> Stream[ Stream_Number ] ).SCR;
	Loc_u32Reg |= DMA_u32SCR_EN_MASK;
	Loc_u32Reg &= ( DMA_u32SCR_EN | ~DMA_u32SCR_EN_MASK );
}
