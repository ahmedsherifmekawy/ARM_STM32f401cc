/*
 * Switch.c
 *
 *  Created on: Apr 9, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Gpio.h"
#include "Switch.h"
#include "Switch_cfg.h"

extern SwitchCfg_t SwitchList [SWITCHES_NUMBER];

static u8  Status[SWITCHES_NUMBER];


void Swicth_vidInit()
{
	GpioPinCfg_t Loc_strGpioCfg;
	u8 Loc_u8Idx ;
	for(Loc_u8Idx = SWITCH_ONE ; Loc_u8Idx < SWITCHES_NUMBER ; Loc_u8Idx++)
	{
		Loc_strGpioCfg.Mode = SwitchList[Loc_u8Idx].Mode;
		Loc_strGpioCfg.Port = SwitchList[Loc_u8Idx].Port;
		Loc_strGpioCfg.Pin = SwitchList[Loc_u8Idx].Pin;

		Gpio_enuInitPin(&Loc_strGpioCfg);
	}
}

void Switch_vidTask()
{
	static u32 Loc_u32Counter[SWITCHES_NUMBER];
	static u8 Loc_u8Prev[SWITCHES_NUMBER];
	u8 Loc_u8Current[SWITCHES_NUMBER];
	u8 Loc_u8Idx ;

	for(Loc_u8Idx = SWITCH_ONE ; Loc_u8Idx < SWITCHES_NUMBER ; Loc_u8Idx++)
	{
		Gpio_enuGetPinValue( SwitchList[Loc_u8Idx].Port , SwitchList[Loc_u8Idx].Pin , &Loc_u8Current[Loc_u8Idx]);
		if( Loc_u8Current[Loc_u8Idx] == Loc_u8Prev[Loc_u8Idx])
		{
			Loc_u32Counter[Loc_u8Idx] ++;
		}
		else
		{
			Loc_u32Counter[Loc_u8Idx] = 0;
		}

		if(Loc_u32Counter[Loc_u8Idx] == SWITCH_NUM_OF_CHECKS)
		{
			Status[Loc_u8Idx] = Loc_u8Current[Loc_u8Idx];
			Loc_u32Counter[Loc_u8Idx] = 0;
		}

		Loc_u8Prev[Loc_u8Idx] = Loc_u8Current[Loc_u8Idx] ;
	}


}
Switch_tenuErrorStatus Switch_enuGetStatus(pu8 Add_pu8SwitchStatus , u32 Copy_SwitchNumber)
{
	Switch_tenuErrorStatus Loc_enuError = SwitchOk;
	if(Add_pu8SwitchStatus == NULL)
	{
		Loc_enuError = SwitchOk;
	}
	else if(Copy_SwitchNumber >= SWITCHES_NUMBER)
	{
		Loc_enuError = SwitchOk;
	}
	else
	{
		if(SwitchList [Copy_SwitchNumber ].Mode == GPIO_u32MODE_INPUT_PU)
		{
			SwitchList [Copy_SwitchNumber ].PullState = SWITCH_u8PULL_UP ;
		}
		else if(SwitchList [Copy_SwitchNumber ].Mode == GPIO_u32MODE_INPUT_PD)
		{
			SwitchList [Copy_SwitchNumber ].PullState = SWITCH_u8PULL_DOWN ;
		}

		*Add_pu8SwitchStatus = ( Status[Copy_SwitchNumber] ^ SwitchList [Copy_SwitchNumber ].PullState );
	}
	return Loc_enuError;
}

