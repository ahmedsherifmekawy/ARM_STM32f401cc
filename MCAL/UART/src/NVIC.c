/*
 * NVIC.c
 *
 *  Created on: Apr 3, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "NVIC.h"


typedef struct{
	volatile u32 ISER [8];            //iser0  -> iser[0]
	volatile u32 reserved0[24];
	volatile u32 ICER [8];
	volatile u32 reserved1[24];
	volatile u32 ISPR [8];
	volatile u32 reserved2[24];
	volatile u32 ICPR [8];
	volatile u32 reserved3[24];
	volatile u32 IABR [8];
	volatile u32 reserved4[56];
	volatile u8 IPR [240];
}NVIC_t;




//#define 	NVIC_ICER_BASE_ADDRESS	(*(volatile u32 * const)0xE000E180)
//#define 	NVIC_ISPR_BASE_ADDRESS	(*(volatile u32 * const)0XE000E200)
//#define 	NVIC_ICPR_BASE_ADDRESS	(*(volatile u32 * const)0XE000E280)
//#define 	NVIC_IABR_BASE_ADDRESS	(*(volatile u32 * const)0xE000E300)
//#define 	NVIC_IPR_BASE_ADDRESS	(*(volatile u32 * const)0xE000E400)
//#define 	NVIC_STIR_BASE_ADDRESS	(*(volatile u32 * const)0xE000EF00)
//
//#define 	SCB_AIRCR_BASE_ADDRESS	(*(volatile u32 * const)0xE000ED0C)



//static u32 ( *  ISER )[8]  =  arr;
//static u32 ( * const ICER ) [8] = ( u32 * const ) 0xE000E180;
//static u32 ( * const ISPR ) [8] = ( u32 * const ) 0XE000E200;
//static u32 ( * const ICPR ) [8] = ( u32 * const ) 0XE000E280;
//static u32 ( * const IABR ) [8] = ( u32 * const ) 0xE000E300;
//static u8 ( * const IPR ) [60][4] = ( u8 * const ) 0xE000E400;




#define 	NVIC_BASE_ADDRESS	    ((u32)0xE000E100)
static      u8 ( * const AIRCR ) = ( u8 * const ) 0xE000ED0C;

NVIC_tenuError NVIC_enuEnableIRQ(u32  Copy_u32IRQn)
{
	NVIC_tenuError Loc_enuError = NVIC_Ok;
	u8 Loc_u8IRQReg = Copy_u32IRQn / 32 ;
	u8 Loc_u8IRQBit = Copy_u32IRQn % 32 ;

	if( Copy_u32IRQn > 239 )
	{
		Loc_enuError = NVIC_Nok;
	}
	else
	{
		( ( NVIC_t * const ) NVIC_BASE_ADDRESS ) -> ISER [ Loc_u8IRQReg ] = ( (u32)1 << Loc_u8IRQBit ) ;
	}

	return Loc_enuError;
}
NVIC_tenuError NVIC_enuDisableIRQ(u32  Copy_u32IRQn)
{
	NVIC_tenuError Loc_enuError = NVIC_Ok;
	u8 Loc_u8IRQReg = Copy_u32IRQn / 32 ;
	u8 Loc_u8IRQBit = Copy_u32IRQn % 32 ;
	if( Copy_u32IRQn > 239 )
	{
		Loc_enuError = NVIC_Nok;
	}
	else
	{
		( ( NVIC_t * const ) NVIC_BASE_ADDRESS ) -> ICER [ Loc_u8IRQReg ] = ( (u32)1 << Loc_u8IRQBit ) ;
	}

	return Loc_enuError;
}
NVIC_tenuError NVIC_enuSetPendingIRQ(u32  Copy_u32IRQn)
{
	NVIC_tenuError Loc_enuError = NVIC_Ok;
	u8 Loc_u8IRQReg = Copy_u32IRQn / 32 ;
	u8 Loc_u8IRQBit = Copy_u32IRQn % 32 ;
	if( Copy_u32IRQn > 239 )
	{
		Loc_enuError = NVIC_Nok;
	}
	else
	{
		( ( NVIC_t * const ) NVIC_BASE_ADDRESS ) -> ISPR [ Loc_u8IRQReg ] = ( (u32)1 << Loc_u8IRQBit ) ;
	}

	return Loc_enuError;
}
NVIC_tenuError NVIC_enuClearPendingIRQ(u32  Copy_u32IRQn)
{
	NVIC_tenuError Loc_enuError = NVIC_Ok;
	u8 Loc_u8IRQReg = Copy_u32IRQn / 32 ;
	u8 Loc_u8IRQBit = Copy_u32IRQn % 32 ;
	if( Copy_u32IRQn > 239 )
	{
		Loc_enuError = NVIC_Nok;
	}
	else
	{
		( ( NVIC_t * const ) NVIC_BASE_ADDRESS ) -> ICPR [ Loc_u8IRQReg ] = ( (u32)1 << Loc_u8IRQBit ) ;
	}

	return Loc_enuError;
}
NVIC_tenuError NVIC_enuGetActiveStateIRQ(u32  Copy_u32IRQn , u32 * Add_pu32ActiveStatus )
{
	NVIC_tenuError Loc_enuError = NVIC_Ok;
	u8 Loc_u8IRQReg = Copy_u32IRQn / 32 ;
	u8 Loc_u8IRQBit = Copy_u32IRQn % 32 ;
	if( Copy_u32IRQn > 239 )
	{
		Loc_enuError = NVIC_Nok;
	}
	else if(Add_pu32ActiveStatus == NULL)
	{
		Loc_enuError = NVIC_Nok;
	}
	else
	{
		*Add_pu32ActiveStatus = ( ( ( ( ( NVIC_t * const ) NVIC_BASE_ADDRESS ) -> IABR [ Loc_u8IRQReg ] ) >> Loc_u8IRQBit ) & (u32) 1 );
	}
	return Loc_enuError;
}
NVIC_tenuError NVIC_enuSetPriority(u32  Copy_u32IRQn, u8 Copy_u8Priority)
{
	NVIC_tenuError Loc_enuError = NVIC_Ok;

	if( Copy_u32IRQn > 239 )
	{
		Loc_enuError = NVIC_Nok;
	}
	else if(Copy_u8Priority > 239)
	{
		Loc_enuError = NVIC_Nok;
	}
	else
	{
		( ( NVIC_t * const ) NVIC_BASE_ADDRESS ) -> IPR [ Copy_u32IRQn ] = ( Copy_u8Priority << NVIC_u8IPR_NOT_IMPLEMENTED );
	}
	return Loc_enuError;
}
NVIC_tenuError NVIC_enuSetPriGroup(u32  Copy_u32IRQn, u32 Copy_u32PriGroup)
{
	NVIC_tenuError Loc_enuError = NVIC_Ok;
	u32 Loc_u32Reg = *AIRCR;
	if( Copy_u32IRQn > 239 )
	{
		Loc_enuError = NVIC_Nok;
	}
	else
	{
		Loc_u32Reg &= ~ Copy_u32PriGroup;
		*AIRCR = Loc_u32Reg | Copy_u32PriGroup ;
	}

	return 	Loc_enuError;
}
NVIC_tenuError NVIC_enuEncodePriority(u32  Copy_u32IRQn, u32 * Add_u32Priority)
{

}




