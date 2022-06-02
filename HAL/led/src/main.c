


#include "Std_types.h"

#include "Led.h"
#include "Led_cfg.h"
#include "RCC.h"
#include "Gpio.h"


int main()
{
	Rcc_enuSelectSysClk(RCC_u8HSI);
	Rcc_vidEnablePeripheralClk(RCC_u32PERIPHERAL_AHB1_GPIOC);
	Led_enuInit();
	while (1)
	{
		Led_enuSetStatus( LED_STOP , LED_u8STATE_OFF );
	}
}
