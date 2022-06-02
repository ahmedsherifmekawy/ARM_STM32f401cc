/*
 * Led_cfg.c
 *
 *  Created on: Mar 26, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "Gpio.h"
#include "Led.h"
#include "Led_cfg.h"


 Ledcfg_t Leds[NUM_OF_LEDS] = {

	[LED_STOP] = {

				.Port = GPIOC_BASE_ADDRESS,
				.Pin = GPIO_u32PIN_13,
				.ActiveState = LED_u8ACTIVE_STATE_HIGH,
				.Otype = LED_u8OTYPE_PP
		},

		[LED_START] = {

				.Port = GPIOA_BASE_ADDRESS,
				.Pin = GPIO_u32PIN_8,
				.ActiveState = LED_u8ACTIVE_STATE_HIGH,
				.Otype = LED_u8OTYPE_PP
		},

		[LED_RUN] = {

				.Port = GPIOA_BASE_ADDRESS,
				.Pin = GPIO_u32PIN_2,
				.ActiveState = LED_u8ACTIVE_STATE_HIGH,
				.Otype = LED_u8OTYPE_PP
		}
};
