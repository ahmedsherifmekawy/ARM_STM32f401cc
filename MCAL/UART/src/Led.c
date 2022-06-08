/*
 * Led.c
 *
 *  Created on: Mar 26, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "Gpio.h"
#include "Led.h"
#include "Led_cfg.h"


extern Ledcfg_t Leds[NUM_OF_LEDS];

extern Led_enuResult Led_enuInit()
{
	Led_enuResult Loc_enuErrorStatus = LedOk ;
	Gpio_enuErrorStatus GpioError = Ok;
	GpioPinCfg_t Loc_enuLedCfg ;
	u8 idx ;

	for(idx = LED_u8ZERO ; idx < NUM_OF_LEDS ; idx ++)
	{

		Loc_enuLedCfg.Pin = Leds[idx].Pin ;

		if( Leds[idx].Otype == LED_u8OTYPE_PP )
		{
			Loc_enuLedCfg.Mode = GPIO_u32MODE_OUTPUT_PP;
		}
		else
		{
			Loc_enuLedCfg.Mode = GPIO_u32MODE_OUTPUT_OD;
		}

		Loc_enuLedCfg.Port = Leds[idx].Port;

		Gpio_enuInitPin(&Loc_enuLedCfg);
	}

	if(GpioError == Nok)
	{
		Loc_enuErrorStatus = LedNok ;
	}

	return Loc_enuErrorStatus;
}
extern Led_enuResult Led_enuSetStatus(u8 Copy_u8LedNumber ,u8 Copy_u8LedState )
{
	Led_enuResult Loc_enuErrorStatus = LedOk ;
	Gpio_enuErrorStatus GpioError = Ok;

	u8 Loc_u8PinValue = Leds[Copy_u8LedNumber].ActiveState ^ Copy_u8LedState;

	GpioError = Gpio_enuSetPinValue( Leds[Copy_u8LedNumber].Port , Leds[Copy_u8LedNumber].Pin , Loc_u8PinValue );

	if(GpioError == Nok)
	{
		Loc_enuErrorStatus = LedNok ;
	}

	return Loc_enuErrorStatus;
}


