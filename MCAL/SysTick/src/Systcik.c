/*
 * Systcik.c
 *
 *  Created on: Apr 2, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Systick.h"
#include "Systick_cfg.h"

#define   SYSTICK_BASE_ADDRESS           (u32)(0xE000E010)

typedef struct{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;
}Systick_t;


static SystickCbf_t AppCbf;
static Systick_t * const Systick = ( Systick_t * const ) SYSTICK_BASE_ADDRESS;

void SysTick_Handler()
{
	if(AppCbf)
		AppCbf();
}

void Systick_vidInit()
{
	u32 Loc_u32reg;

	Loc_u32reg = Systick -> STK_CTRL ;
	Loc_u32reg &= ~(SYSTICK_u32TICKINT_MASK );
	Loc_u32reg |= SYSTICK_u32TICKINT_MASK;
	Loc_u32reg &= ~(SYSTICK_u32SRC_CLK_MASK );
	if ( SOURCE_CLK == SYSTICK_u8CLK_PROC )
		 Loc_u32reg |= SYSTICK_u32SRC_CLK_MASK ;
	Systick -> STK_CTRL = Loc_u32reg;
}

Systick_tenuErrorStatus Systick_enuSetTicTime_ms(u32 Copy_u32TimeMs)
{
	Systick_tenuErrorStatus Loc_enuError = SystickOk;

	if(Copy_u32TimeMs > SYSTICK_MAX )
	{
		Loc_enuError = SystickNok;
	}
	else
	{
		Systick -> STK_LOAD = Copy_u32TimeMs*(SYS_FREQUENCY/1000) ;
	}

	return Loc_enuError;
}

Systick_tenuErrorStatus Systick_enuRegisterCbf(SystickCbf_t Copy_Cbf)
{
	Systick_tenuErrorStatus Loc_enuError = SystickOk;

	if(Copy_Cbf)
		AppCbf = Copy_Cbf;
	else
		Loc_enuError = SystickNok;

	return Loc_enuError;
}

void Systick_vidStart()
{
	u32 Loc_u32reg;

	Loc_u32reg = Systick -> STK_CTRL ;

	Loc_u32reg &= ~SYSTICK_u32ENABLE_MASK ;
	Systick -> STK_CTRL = Loc_u32reg | SYSTICK_u32ENABLE_MASK ;
}
