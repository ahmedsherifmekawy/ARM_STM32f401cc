

#include "Std_types.h"
#include "RCC.h"
#include "Gpio.h"
#include "Uart.h"
#include "Led.h"
#include "Led_cfg.h"

void ReceiveNotify(void)
{
	GpioPinCfg_t Loc_strPinCfg = {
				.Mode = GPIO_u32MODE_OUTPUT ,
				.Speed = GPIO_u8SPEED_VERY_HIGH,
				.Pin = GPIO_u32PIN_0,
				.Port = GPIOA_BASE_ADDRESS
		};
	Gpio_enuInitPin( &Loc_strPinCfg );
	Led_enuSetStatus( 1 ,LED_u8STATE_ON );
}

void SendNotify(void)
{
	GpioPinCfg_t Loc_strPinCfg = {
				.Mode = GPIO_u32MODE_OUTPUT ,
				.Speed = GPIO_u8SPEED_VERY_HIGH,
				.Pin = GPIO_u32PIN_1,
				.Port = GPIOA_BASE_ADDRESS
		};
	Gpio_enuInitPin( &Loc_strPinCfg );
	Led_enuSetStatus( 0 ,LED_u8STATE_ON );
}

int main(void)
{
	GpioPinCfg_t Loc_strPinCfg = {
			.Mode = GPIO_u32MODE_AF ,
			.Speed = GPIO_u8SPEED_VERY_HIGH,
			.Pin = GPIO_u32PIN_9,
			.Port = GPIOA_BASE_ADDRESS
	};

	u8 DataArray[5]={1,2,3,4,5};

	UartCfg_t Loc_strUartCfg = {
			.BusNumber = UART1 ,
			.BaudRate = 9600 ,
//			.RxBuffer ={
//					.Data = DataArray ,
//					.Size = 5 ,
//					.Used = 0
//						},
			.TxBuffer = {
					.Data = DataArray ,
					.Size = 5 ,
					.Used = 0
						},
			.State.TxBusy = 0,
			.State.RxBusy = 0
	};
	Loc_strUartCfg.RxBuffer->Used=0;
	Loc_strUartCfg.RxBuffer->Size=5;

	Rcc_enuSelectSysClk( RCC_u8HSI );
	Rcc_vidEnablePeripheralClk( RCC_u32PERIPHERAL_APB2_USART1 );
	Rcc_vidEnablePeripheralClk( RCC_u32PERIPHERAL_AHB1_GPIOA );
	Gpio_enuInitPin( &Loc_strPinCfg );
	Led_enuInit();
	Loc_strPinCfg.Pin = GPIO_u32PIN_10;
	Gpio_enuInitPin( &Loc_strPinCfg );
	NVIC_enuEnableIRQ( 37 );
	Gpio_enuSetAlternative( GPIOA_BASE_ADDRESS , 9 , 0b0111 );
	Gpio_enuSetAlternative( GPIOA_BASE_ADDRESS , 10 , 0b0111 );

	Uart_enuTxRegCbf(SendNotify);
	Uart_enuRxRegCbf(ReceiveNotify);
	Uart_enuSendBuffer( &Loc_strUartCfg );
	Uart_enuReceiveBuffer( &Loc_strUartCfg );

	while (1)
    {
		Uart_enuReceiveBuffer( &Loc_strUartCfg );
    }
	return 0;
}
