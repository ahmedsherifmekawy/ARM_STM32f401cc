/*
 * Gpio.c
 *
 *  Created on: Mar 15, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Gpio.h"


typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
}Gpio_t;



/*
 *
 *
static Gpio_t * const Gpio_A = ( Gpio_t * const ) GPIOA_BASE_ADDRESS;
static Gpio_t * const Gpio_B = ( Gpio_t * const ) GPIOB_BASE_ADDRESS;
static Gpio_t * const Gpio_C = ( Gpio_t * const ) GPIOC_BASE_ADDRESS;
static Gpio_t * const Gpio_D = ( Gpio_t * const ) GPIOD_BASE_ADDRESS;
static Gpio_t * const Gpio_E = ( Gpio_t * const ) GPIOE_BASE_ADDRESS;
static Gpio_t * const Gpio_H = ( Gpio_t * const ) GPIOH_BASE_ADDRESS;

*
*/


/////////////////////////////////////////////////////////////////////////////////////////


Gpio_enuErrorStatus Gpio_enuInitPin( GpioPinCfg_t * Add_strPinCfg )
{

	Gpio_enuErrorStatus Gpio_InitError = Ok;
	u32 Loc_u32Reg ;
	u8 Gpio_u8PinNumber =  GPIO_u8ZERO ;
	if( Add_strPinCfg == NULL )
	{
		Gpio_InitError = Nok;
	}
	else
	{
		while( ( Gpio_u8PinNumber < GPIO_u8NUMBER_OF_PINS ) && (Add_strPinCfg -> Pin  != ( GPIO_u32PIN_MSK << Gpio_u8PinNumber ) ) )
		{
			Gpio_u8PinNumber++;
		}

		/* MODER */
		Loc_u32Reg = ( ( Gpio_t * const ) ( Add_strPinCfg -> Port ) ) -> MODER ;
		Loc_u32Reg |= ( GPIO_u32MODER_MSK << ( Gpio_u8PinNumber * GPIO_u8DOUBLE_SHIFT ) );
		Loc_u32Reg &= ( ( ~GPIO_u32MODER_MSK | Add_strPinCfg -> Mode ) << ( Gpio_u8PinNumber * GPIO_u8DOUBLE_SHIFT ) );
		( ( Gpio_t * const ) ( Add_strPinCfg -> Port) ) -> MODER = Loc_u32Reg ;

		/* OTYPER */
		Loc_u32Reg = ( ( Gpio_t * const ) ( Add_strPinCfg -> Port ) ) -> OTYPER ;
		Loc_u32Reg |= ( ( GPIO_u32OTYPER_MSK >> GPIO_u8OTYPER_SHIFT ) << Gpio_u8PinNumber  );
		Loc_u32Reg &= ( ( ( ~GPIO_u32OTYPER_MSK | Add_strPinCfg -> Mode ) >> GPIO_u8OTYPER_SHIFT ) << Gpio_u8PinNumber );
		( ( Gpio_t * const ) ( Add_strPinCfg -> Port) ) -> OTYPER = Loc_u32Reg ;


		/* PUPDR */
		Loc_u32Reg = ( ( Gpio_t * const ) ( Add_strPinCfg -> Port ) ) -> PUPDR ;
		Loc_u32Reg |= ( ( GPIO_u32PUPDR_MSK >> GPIO_u8PUPDR_SHIFT ) << (Gpio_u8PinNumber * GPIO_u8DOUBLE_SHIFT )  );
		Loc_u32Reg &= ( ( ( ~GPIO_u32PUPDR_MSK | Add_strPinCfg -> Mode ) >> GPIO_u8PUPDR_SHIFT ) << (Gpio_u8PinNumber * GPIO_u8DOUBLE_SHIFT ) );
		( ( Gpio_t * const ) ( Add_strPinCfg -> Port) ) -> PUPDR = Loc_u32Reg ;


		/* OSPEEDR */
		Loc_u32Reg = ( ( Gpio_t * const ) ( Add_strPinCfg -> Port ) ) -> OSPEEDR ;
		Loc_u32Reg |= ( GPIO_u32OSPEEDR_MSK << ( Gpio_u8PinNumber * GPIO_u8DOUBLE_SHIFT ) );
		Loc_u32Reg &= ( ( ~GPIO_u32OSPEEDR_MSK | Add_strPinCfg -> Speed ) << ( Gpio_u8PinNumber * GPIO_u8DOUBLE_SHIFT ) );
		( ( Gpio_t * const ) ( Add_strPinCfg -> Port) ) -> OSPEEDR = Loc_u32Reg ;

	}

	return Gpio_InitError;
}

Gpio_enuErrorStatus Gpio_enuSetPinValuestruct( GpioPinCfg_t * Add_strPinCfg ,u8 Copy_u8PinValue )
{
	Gpio_enuErrorStatus Gpio_SetError = Ok;
	if( Add_strPinCfg == NULL )
	{
		Gpio_SetError = Nok;
	}
	else if( Copy_u8PinValue > GPIO_u8PIN_HIGH)
	{
		Gpio_SetError = Nok;
	}
	else
	{
		if( Copy_u8PinValue == GPIO_u8PIN_HIGH )
		{
			( ( Gpio_t * const ) ( Add_strPinCfg -> Port) ) -> BSRR = Add_strPinCfg -> Pin ;
		}
		else
		{
			( ( Gpio_t * const ) ( Add_strPinCfg -> Port) ) -> BSRR =  ( ( Add_strPinCfg -> Pin ) << 16 );
		}
	}

	return Gpio_SetError;
}

Gpio_enuErrorStatus Gpio_enuSetPinValue( u32 Copy_u32Port , u32 Copy_u32Pin , u8 Copy_u8PinValue )
{
	Gpio_enuErrorStatus Gpio_SetError = Ok;
	if( Copy_u32Port > GPIOH_BASE_ADDRESS || Copy_u32Port < GPIOA_BASE_ADDRESS )
	{
		Gpio_SetError = Nok;
	}
	else if( Copy_u32Pin > GPIO_u32PIN_15 )
	{
		Gpio_SetError = Nok;
	}
	else if( Copy_u8PinValue > GPIO_u8PIN_HIGH )
	{
		Gpio_SetError = Nok;
	}
	else
	{
		if( Copy_u8PinValue == GPIO_u8PIN_HIGH )
		{
			( ( Gpio_t * const ) Copy_u32Port ) -> BSRR = Copy_u32Pin ;
		}
		else
		{
			( ( Gpio_t * const ) Copy_u32Port ) -> BSRR = ( Copy_u32Pin << 16 ) ;
		}
	}

	return Gpio_SetError;
}

Gpio_enuErrorStatus Gpio_enuGetPinValue( u32 Copy_u32Port , u32 Copy_u32Pin , pu16 Add_pu16PinValue )
{

	Gpio_enuErrorStatus Gpio_GetError = Ok;
	u32 Gpio_u8PinNumber = GPIO_u8ZERO ;

	if( Copy_u32Port > GPIOH_BASE_ADDRESS || Copy_u32Port < GPIOA_BASE_ADDRESS )
	{
		Gpio_GetError = Nok;
	}
	else if( Copy_u32Pin > GPIO_u32PIN_15 )
	{
		Gpio_GetError = Nok;
	}
	else if( Add_pu16PinValue == NULL )
	{
		Gpio_GetError = Nok;
	}
	else
	{
		while( ( Gpio_u8PinNumber<GPIO_u8NUMBER_OF_PINS ) && ( Copy_u32Pin  == (GPIO_u32PIN_MSK << Gpio_u8PinNumber ) ) )
		{
			Gpio_u8PinNumber++;
		}
		*Add_pu16PinValue = ( ( ( ( Gpio_t * const ) Copy_u32Port ) -> IDR ) & Copy_u32Pin ) >> Gpio_u8PinNumber ;
	}
	return Gpio_GetError;
}






