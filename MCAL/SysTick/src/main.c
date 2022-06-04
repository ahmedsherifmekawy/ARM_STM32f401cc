


#include "Std_types.h"
#include "Bit_utils.h"
#include "Systick.h"
#include "Systick_cfg.h"
#include "RCC.h"
#include "Gpio.h"

GpioPinCfg_t Pin = {
		.Mode = GPIO_u32MODE_OUTPUT_PP,
		.Speed = GPIO_u8SPEED_VERY_HIGH,
		.Pin = GPIO_u32PIN_13,
		.Port = GPIOC_BASE_ADDRESS
	};

void toggle()
{
	static u8 f=0;

	if(f == 0)
	{
		Gpio_enuSetPinValuestruct(&Pin,1);
		f=1;
	}

	else
	{
		Gpio_enuSetPinValuestruct(&Pin,0);
		f=0;
	}
}
int main()
{
	Rcc_enuSelectSysClk(RCC_u8HSI);
	Rcc_vidEnablePeripheralClk(RCC_u32PERIPHERAL_AHB1_GPIOC);
	Gpio_enuInitPin(&Pin);

	Systick_vidInit();
	Systick_enuSetTicTime_ms(1000);
	Systick_enuRegisterCbf(toggle);
	Systick_vidStart();
	while (1);
}
