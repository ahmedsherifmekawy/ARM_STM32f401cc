/*
 * LCD_cfg.c
 *
 *  Created on: Apr 11, 2022
 *      Author: WINDOWS
 */




#include "Std_types.h"
#include "Gpio.h"
#include "LCD.h"
#include "LCD_cfg.h"

LCD_PinCfg PinList[ LCD_u8NUMBER_OF_PINS ]  = {

			[0]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_0,
				},

			[1]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_1,
			    },

			[2]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_2,
				},

			[3]={
					.Port = GPIOA_BASE_ADDRESS,
		    		.Pin = GPIO_u32PIN_3,
		        },
			[4]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_4,
				},
			[5]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_5,
				},
			[6]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_6,
				},
			[7]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_7,
				},
			[LCD_u8RW_PIN]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_8,
					},
			[LCD_u8EN_PIN]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_9,
				},

			[LCD_u8RS_PIN]={
					.Port = GPIOA_BASE_ADDRESS,
					.Pin = GPIO_u32PIN_10,
				},
};

