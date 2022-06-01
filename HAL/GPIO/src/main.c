
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "Std_types.h"
#include "RCC.h"
#include "Gpio.h"

int main(void)
{
	GpioPinCfg_t x[2];

	Rcc_enuControl_Clk(RCC_u8HSI , RCC_u32HSE_ON);
	Rcc_enuSelectSysClk(RCC_u8HSI);

	Rcc_vidEnablePeripheralClk( RCC_u32PERIPHERAL_AHB1_GPIOA );
	Rcc_vidEnablePeripheralClk( RCC_u32PERIPHERAL_AHB1_GPIOB );
	Rcc_vidEnablePeripheralClk( RCC_u32PERIPHERAL_AHB1_GPIOC );

	x[0].Mode = GPIO_u32MODE_OUTPUT_PP ;
	x[0].Pin = GPIO_u32PIN_0 ;
	x[0].Port = GPIOA_BASE_ADDRESS ;
	x[0].Speed = GPIO_u8SPEED_VERY_HIGH ;

	Gpio_enuInitPin( &x[0] );

	Gpio_enuSetPinValue( x[0].Port , x[0].Pin , 0);
	Gpio_enuSetPinValue( x[0].Port , x[0].Pin , 1);
    while (1)
    {
    	Gpio_enuSetPinValue( x[0].Port , x[0].Pin , 1);
    }

}

