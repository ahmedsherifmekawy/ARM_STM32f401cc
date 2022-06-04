/*
 * Switch_cfg.c
 *
 *  Created on: Apr 9, 2022
 *      Author: WINDOWS
 */



#include "Std_types.h"
#include "Gpio.h"
#include "Switch.h"
#include "Switch_cfg.h"

SwitchCfg_t SwitchList [SWITCHES_NUMBER] = {
		[SWITCH_ONE] =
		{
			.Mode = GPIO_u32MODE_INPUT_PU,
			.Port = GPIOA_BASE_ADDRESS,
			.Pin = GPIO_u32PIN_0,
			.PullState = SWITCH_u8PULL_UP
		},
		[SWITCH_TWO] =
		{
			.Mode = GPIO_u32MODE_INPUT_PU,
			.Port = GPIOA_BASE_ADDRESS,
			.Pin = GPIO_u32PIN_2,
			.PullState = SWITCH_u8PULL_UP
		},

};

