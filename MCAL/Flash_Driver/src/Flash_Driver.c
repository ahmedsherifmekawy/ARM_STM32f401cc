/*
 * Flash_Driver.c
 *
 *  Created on: May 14, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "Flash_Driver.h"
#include "Flash_Driver_prv.h"


FD_tenuErrorStatus FD_Init()
{
	FD_tenuErrorStatus Loc_enuError = FDOk;

	u32 Loc_u32Reg;

	FD -> KEYR = FD_KEY1;
	FD -> KEYR = FD_KEY2;

	Loc_u32Reg = FD -> CR;
	Loc_u32Reg &= ~FD_CR_PSIZE_MSK;
	Loc_u32Reg |= ( FD_CR_PSIZE_MSK & FD_CR_PSIZE_32 );
	FD -> CR = Loc_u32Reg;


	return Loc_enuError;
}
FD_tenuErrorStatus FD_EraseSector(u32 Copy_enuSectorNumber )
{
	FD_tenuErrorStatus Loc_enuError = FDOk;

	if( Copy_enuSectorNumber > FD_USR_CFG_SECTOR )
	{
		Loc_enuError = FDNok;
	}
	else
	{
		while( FD_SR_BSY_MSK & ( FD -> SR ) );

		u32 Loc_u32Reg = FD -> CR;
		Loc_u32Reg &= ~FD_CR_SNB_MSK;
		Loc_u32Reg |= ( FD_CR_SNB_MSK & Copy_enuSectorNumber );

		Loc_u32Reg |= FD_CR_SER_MSK;
		FD -> CR = Loc_u32Reg;

		Loc_u32Reg |= FD_CR_STRT_MSK;
		FD -> CR = Loc_u32Reg;

		while( FD_SR_BSY_MSK & ( FD -> SR ) );
	}

	return Loc_enuError;
}
FD_tenuErrorStatus FD_ProgramPage( u32 Copy_u32PageAddress , u32 Copy_u32PageData)
{
	FD_tenuErrorStatus Loc_enuError = FDOk;

	if( Copy_u32PageAddress % 32 != 0 )
	{
		Loc_enuError = FDNok;
	}
	else
	{
		while( FD_SR_BSY_MSK & ( FD -> SR ) );

		u32 Loc_u32Reg = FD -> CR;
		Loc_u32Reg |= FD_CR_PG_MSK;
		FD -> CR = Loc_u32Reg;

		*( ( volatile pu32)Copy_u32PageAddress ) = Copy_u32PageData;

		while( FD_SR_BSY_MSK & ( FD -> SR ) );
	}

	return Loc_enuError;
}
void FD_MassErase()
{
	while( FD_SR_BSY_MSK & ( FD -> SR ) );

	u32 Loc_u32Reg = FD -> CR;
	Loc_u32Reg |= FD_CR_MER_MSK;
	FD -> CR = Loc_u32Reg;

	Loc_u32Reg |= FD_CR_STRT_MSK;
	FD -> CR = Loc_u32Reg;

	while( FD_SR_BSY_MSK & ( FD -> SR ) );
}
void FD_LockCR()
{
	while( FD_SR_BSY_MSK & ( FD -> SR ) );

	u32 Loc_u32Reg = FD -> CR;
	Loc_u32Reg |= FD_CR_MER_MSK;
	FD -> CR = Loc_u32Reg;

	while( FD_SR_BSY_MSK & ( FD -> SR ) );
}
