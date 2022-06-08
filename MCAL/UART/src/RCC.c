/*
 * RCC.c
 *
 *  Created on: Mar 12, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "RCC.h"

/////////////////////////////////////////////////////////////////////////////////////////


#define 	RCC_BASE_ADD	(*(volatile u32 *const)0x40023800)
#define 	CR 				(*(volatile u32 *const)0x40023800)
#define 	PLLCFGR 		(*(volatile u32 *const)0x40023804)
#define 	CFGR 			(*(volatile u32 *const)0x40023808)
#define  	CIR 			(*(volatile u32 *const)0x4002380C)
#define 	AHB1ENR		    (*(volatile u32 *const)0x40023830)
#define 	APB1ENR		    (*(volatile u32 *const)0x40023840)
#define 	APB2ENR		    (*(volatile u32 *const)0x40023844)




///////////////////////////////////////////////////////////////////////////////////////


RCC_enuErrorStatus Rcc_enuSelectSysClk( u8 Copy_u8ClkMode )
{
	RCC_enuErrorStatus Loc_enuSelectStatus = SelectClkOk ;
	u32 Loc_u32Reg = CFGR ;
	u32 Loc_u32ReadSWS ;
	Loc_enuSelectStatus = Rcc_enuControl_Clk( Copy_u8ClkMode , RCC_u8CLK_ON );

	if( Loc_enuSelectStatus == ControlClkNok )
	{
		Loc_enuSelectStatus = SelectClkNok;
	}
	else
	{
		switch(Copy_u8ClkMode)
		{
			case RCC_u8HSI:
			{
				Loc_u32Reg |= RCC_u32SW_MASK;
				Loc_u32Reg &= RCC_u32SWS_HSI | ~RCC_u32SW_MASK ;
				CFGR = Loc_u32Reg ;
				Loc_u32ReadSWS = CFGR & RCC_u32SWS_MASK ;
				if( Loc_u32ReadSWS != RCC_u32SWS_HSI )
				{
					Loc_enuSelectStatus = SelectClkNok;
				}
				break;
			}

			case RCC_u8HSE:
			{
				Loc_u32Reg |= RCC_u32SW_MASK;
				Loc_u32Reg &= RCC_u32SW_HSE | ~RCC_u32SW_MASK ;
				CFGR = Loc_u32Reg ;
				Loc_u32ReadSWS = CFGR & RCC_u32SWS_MASK ;
				if( Loc_u32ReadSWS != RCC_u32SWS_HSE )
				{
					Loc_enuSelectStatus = SelectClkNok;
				}
				break;
			}

			case RCC_u8PLL:
			{
				Loc_u32Reg |= RCC_u32SW_MASK;
				Loc_u32Reg &= RCC_u32SW_PLL | ~RCC_u32SW_MASK ;
				CFGR = Loc_u32Reg ;
				Loc_u32ReadSWS = CFGR & RCC_u32SWS_MASK ;
				if( Loc_u32ReadSWS != RCC_u32SWS_PLL )
				{
					Loc_enuSelectStatus = SelectClkNok;
				}
				break;
			}

		}
	}

	return Loc_enuSelectStatus;
}


RCC_enuErrorStatus Rcc_enuControl_Clk( u8 Copy_u8ClkMode , u32 Copy_u32ClkCtrl )
{
	RCC_enuErrorStatus CtrlStatus = ControlClkNok ;
	u8 Loc_u8TimeOut = 50 ;
	u32 Loc_u32Reg = CR ;
	switch(Copy_u8ClkMode)
	{
		case RCC_u8HSI:
		{
			if( Copy_u32ClkCtrl == RCC_u32HSI_ON )
			{
				Loc_u32Reg &= ~RCC_u32HSI_ON;
				CR = Loc_u32Reg | RCC_u32HSI_ON;

				while( Loc_u8TimeOut && !Rcc_u8GetClkStatus( Copy_u8ClkMode ) )
				{
					Loc_u8TimeOut--;
				}

				if( Rcc_u8GetClkStatus( Copy_u8ClkMode ) )
				{
					CtrlStatus = ControlClkOk;
				}
			}
			else
			{
				CR &= ~RCC_u32HSI_ON;
				CtrlStatus = ControlClkOk;
			}

			break;
		}
		case RCC_u8HSE:
		{
			if( Copy_u32ClkCtrl == RCC_u32HSE_ON )
			{
				Loc_u32Reg &= ~RCC_u32HSE_ON;
				CR = Loc_u32Reg | RCC_u32HSE_ON;

				while( Loc_u8TimeOut && !Rcc_u8GetClkStatus( Copy_u8ClkMode ) )
				{
					Loc_u8TimeOut--;
				}

				if( Rcc_u8GetClkStatus( Copy_u8ClkMode ) )
				{
					CtrlStatus = ControlClkOk;
				}
			}
			else
			{
				CR &= ~RCC_u32HSE_ON;
				CtrlStatus = ControlClkOk;
			}
			break;
		}
		case RCC_u8PLL:
		{
			if( Copy_u32ClkCtrl == RCC_u32PLL_ON )
			{
				Loc_u32Reg &= ~RCC_u32PLL_ON;
				CR = Loc_u32Reg | RCC_u32PLL_ON;

				while( Loc_u8TimeOut && !Rcc_u8GetClkStatus( Copy_u8ClkMode ) )
				{
					Loc_u8TimeOut--;
				}

				if( Rcc_u8GetClkStatus( Copy_u8ClkMode ) )
				{
					CtrlStatus = ControlClkOk;
				}
			}
			else
			{
				CR &= ~RCC_u32PLL_ON;
				CtrlStatus = ControlClkOk;
			}
			break;
		}
	}
	return CtrlStatus;
}




u8 Rcc_u8GetClkStatus( u8 Copy_u8ClkMode )
{
	u8 clkStatus = RCC_u8CLK_NOTRDY;
	u32 Loc_u32Reg = CR;

	switch(Copy_u8ClkMode)
	{
		case RCC_u8HSI:
		{
			Loc_u32Reg = RCC_u32HSI_RDY_MASK & CR;
			if( Loc_u32Reg == RCC_u32HSI_RDY_MASK )
			{
				clkStatus = RCC_u8CLK_RDY;
			}
			break;
		}
		case RCC_u8HSE:
		{
			Loc_u32Reg = RCC_u32HSE_RDY_MASK & CR;
			if( Loc_u32Reg == RCC_u32HSE_RDY_MASK )
			{
				clkStatus = RCC_u8CLK_RDY;
			}
			break;
		}
		case RCC_u8PLL:
		{
			Loc_u32Reg = RCC_u32PLL_RDY_MASK & CR;
			if( Loc_u32Reg == RCC_u32PLL_RDY_MASK )
			{
				clkStatus = RCC_u8CLK_RDY;
			}
			break;
		}
	}
	return clkStatus;
}




RCC_enuErrorStatus Rcc_enuConfigurePll(u8 Copy_u8M ,u16 Copy_u16N ,u32 Copy_u32Q ,u32 Copy_u32P , u32 Copy_u32SrcClk)
{
	RCC_enuErrorStatus CfgPllStatus = PllCfgOk;
	u32 Loc_u32Reg = PLLCFGR;
	if( Copy_u8M < RCC_u8PLL_M_MIN || Copy_u8M > RCC_u8PLL_M_MAX )
	{
		CfgPllStatus = PllCfgNok;
	}
	if( Copy_u16N < RCC_u8PLL_N_MIN || Copy_u16N > RCC_u8PLL_N_MAX )
	{
		CfgPllStatus = PllCfgNok;
	}
	if( Copy_u32Q < RCC_u32PLL_Q_CFG_2 || Copy_u32Q > RCC_u32PLL_Q_CFG_15 )
	{
		CfgPllStatus = PllCfgNok;
	}
	if( Copy_u32P > RCC_u32PLL_P_CFG_8 )
	{
		CfgPllStatus = PllCfgNok;
	}
	if( ( Copy_u32SrcClk != RCC_u32PLL_SRC_HSI ) && ( Copy_u32SrcClk != RCC_u32PLL_SRC_HSE ) )
	{
		CfgPllStatus = PllCfgNok;
	}

	Loc_u32Reg &= ~( RCC_u32PLL_N_MASK | RCC_u32PLL_M_MASK | Copy_u32Q | Copy_u32P | Copy_u32SrcClk );
	PLLCFGR = Loc_u32Reg | ( RCC_u32PLL_N_MASK | RCC_u32PLL_M_MASK | Copy_u32Q | Copy_u32P | Copy_u32SrcClk );

	return CfgPllStatus;
}




RCC_enuErrorStatus Rcc_enuControlBusPrescaller( u32 Copy_u32BusMode , u32 Copy_u32PrescallerValue )
{
	RCC_enuErrorStatus CtrlPrescallerStaus = ControlPrescallerOk;
	u32 Loc_u32Reg = CFGR;

	switch( Copy_u32BusMode )
	{
		case RCC_u32AHB1_MASK:
		{
			if( Copy_u32PrescallerValue > RCC_u32AHB1_PRE_512 || Copy_u32PrescallerValue < RCC_u32AHB1_PRE_NOTDEVIDED )
			{
				CtrlPrescallerStaus = ControlPrescallerNok;
			}
			else
			{
				Loc_u32Reg &= ~Copy_u32PrescallerValue;
				CFGR = Loc_u32Reg | Copy_u32PrescallerValue;
			}
			break;
		}
		case RCC_u32APB1_MASK:
		{
			if( Copy_u32PrescallerValue > RCC_u32APB1_PRE_16 || Copy_u32PrescallerValue < RCC_u32APB1_PRE_NOTDEVIDED )
			{
				CtrlPrescallerStaus = ControlPrescallerNok;
			}
			else
			{
				Loc_u32Reg &= ~Copy_u32PrescallerValue;
				CFGR = Loc_u32Reg | Copy_u32PrescallerValue;
			}
			break;
		}
		case RCC_u32APB2_MASK:
		{
			if( Copy_u32PrescallerValue > RCC_u32APB2_PRE_16 || Copy_u32PrescallerValue < RCC_u32APB2_PRE_NOTDEVIDED )
			{
				CtrlPrescallerStaus = ControlPrescallerNok;
			}
			else
			{
				Loc_u32Reg &= ~Copy_u32PrescallerValue;
				CFGR = Loc_u32Reg | Copy_u32PrescallerValue;
			}
			break;
		}
		default:
		{
			CtrlPrescallerStaus = ControlPrescallerNok;
		}
	}

	return CtrlPrescallerStaus;
}



void Rcc_vidEnablePeripheralClk( u32 Copy_u8PeripheralName )
{
	u32 readBus = Copy_u8PeripheralName & RCC_u32BUS_MASK ;
	u32 Loc_u32Reg;
	switch( readBus )
	{
		case RCC_u32AHB1_MASK:
		{
			Loc_u32Reg = AHB1ENR;
			Loc_u32Reg &= ~Copy_u8PeripheralName;
			AHB1ENR = Loc_u32Reg | Copy_u8PeripheralName ;
			break;
		}

		case RCC_u32APB1_MASK:
		{
			Loc_u32Reg = APB1ENR;
			Loc_u32Reg &= ~Copy_u8PeripheralName;
			APB1ENR = Loc_u32Reg | Copy_u8PeripheralName ;
			break;
		}

		case RCC_u32APB2_MASK:
		{
			Loc_u32Reg = APB2ENR;
			Loc_u32Reg &= ~Copy_u8PeripheralName;
			APB2ENR = Loc_u32Reg | Copy_u8PeripheralName ;
			break;
		}

	}

}
