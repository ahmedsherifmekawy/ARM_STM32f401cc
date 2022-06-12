/*
 * Uart.c
 *
 *  Created on: Apr 24, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Uart.h"


typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}Uart_t;

static UartCfg_t * Uart_Tx ;
static UartCfg_t * Uart_Rx ;
static AppCbf_t Tx1_Cbf ;
static AppCbf_t Rx1_Cbf ;

Uart_tenuErrorStatus Uart_enuTxRegCbf(AppCbf_t Cbf)
{
	Uart_tenuErrorStatus Loc_enuError = UARTOk;
	if(Cbf)
		Tx1_Cbf = Cbf;
	else
		Loc_enuError = UARTNok;
	return Loc_enuError;
}

Uart_tenuErrorStatus Uart_enuRxRegCbf(AppCbf_t Cbf)
{
	Uart_tenuErrorStatus Loc_enuError = UARTOk;
	if(Cbf)
		Rx1_Cbf = Cbf;
	else
		Loc_enuError = UARTNok;
	return Loc_enuError;
}


Uart_tenuErrorStatus Uart_enuSendBuffer( UartCfg_t * Add_strUartCfg )
{
	Uart_tenuErrorStatus Loc_enuError;
	u32 Loc_u32Reg;

	Uart_Tx = Add_strUartCfg ;
	Loc_u32Reg = ( ( Uart_t * const ) Uart_Tx -> BusNumber ) -> CR1 ;

    if(Add_strUartCfg == NULL)
	{
		Loc_enuError = UARTNok;
	}
	else
	{
		if( Uart_Tx -> State.TxBusy == 0 )
		{
			Uart_Tx -> State.TxBusy = 1 ;
			Uart_Tx -> TxBuffer.Used = 1 ;
			Loc_u32Reg |= ( UART_u32CR1_TCIE | UART_u32CR1_TE | UART_u32CR1_UE );
			( ( Uart_t * const ) Uart_Tx -> BusNumber ) -> CR1 = Loc_u32Reg ;
			( ( Uart_t * const ) Uart_Tx -> BusNumber ) -> BRR = ( Uart_Tx -> BaudRate << UART_u8BAUDRATE_SHIFT ); ////// problem //////
			( ( Uart_t * const ) Uart_Tx -> BusNumber ) -> DR = Uart_Tx -> TxBuffer.Data [0] ;
		}
	}

	return Loc_enuError;
}

Uart_tenuErrorStatus Uart_enuReceiveBuffer( UartCfg_t * Add_strUartCfg )
{
	Uart_tenuErrorStatus Loc_enuError;
	u32 Loc_u32Reg ;
	Uart_Rx = Add_strUartCfg;
	Loc_u32Reg = ( ( Uart_t * const ) Uart_Rx -> BusNumber ) -> CR1 ;
	if(Add_strUartCfg == NULL)
	{
		Loc_enuError = UARTNok;
	}
	else
	{
		if( Uart_Rx -> State.RxBusy == 0 )
		{
			Loc_u32Reg &= ~UART_u32SR_ORE;
			Uart_Rx -> State.RxBusy = 1 ;
			Uart_Rx -> RxBuffer -> Used = 1 ;
			Loc_u32Reg |= ( UART_u32CR1_RXNEIE | UART_u32CR1_RE | UART_u32CR1_UE );
			( ( Uart_t * const ) Uart_Rx -> BusNumber ) -> CR1 = Loc_u32Reg;
			( ( Uart_t * const ) Uart_Rx -> BusNumber ) -> BRR = ( Uart_Rx -> BaudRate << UART_u8BAUDRATE_SHIFT );
			Uart_Rx -> RxBuffer -> Data[0] = ( ( Uart_t * const ) Uart_Rx -> BusNumber ) -> DR ;
		}
	}
	return Loc_enuError;
}

Uart_tenuErrorStatus Uart_vidSendBreak( UartCfg_t * Add_strUartCfg )
{
	Uart_tenuErrorStatus Loc_enuError = UARTOk;
	u32 Loc_u32Reg;

	if(Add_strUartCfg == NULL)
	{
		Loc_enuError = UARTNok;
	}
	else
	{
		////////// cfg Baudrate ///////////////////
		Loc_u32Reg = ( ( Uart_t * const ) Add_strUartCfg -> BusNumber ) -> CR1 ;
		Loc_u32Reg |= UART_u32CR1_SBK ;
		( ( Uart_t * const ) Add_strUartCfg -> BusNumber ) -> CR1  = Loc_u32Reg ;
	}

	return Loc_enuError;
}

void Uart_vidDetectBreak( UartCfg_t * Add_strUartCfg, pu8 Add_Break )
{
	u32 Loc_u32Reg = ( ( Uart_t * const ) Add_strUartCfg -> BusNumber ) -> SR ;
	if( (Loc_u32Reg & UART_u32SR_LBD) == UART_u32SR_LBD )
	{
		*Add_Break = 1;
		Loc_u32Reg &= ~UART_u32SR_LBD;
		( ( Uart_t * const ) Add_strUartCfg -> BusNumber ) -> SR = Loc_u32Reg ;
	}
	else
	{
		*Add_Break = 0;
	}
}


void USART1_IRQHandler(void)
{
	u32 Loc_u32Reg = ( ( Uart_t * const ) Uart_Tx -> BusNumber ) -> CR1 ;

	if( ( ( ( ( Uart_t * const ) UART1 ) -> SR ) & UART_u32SR_TC ) == UART_u32SR_TC )
	{
		if( Uart_Tx -> TxBuffer.Used == Uart_Tx -> TxBuffer.Size )
		{
			Loc_u32Reg &= ~UART_u32CR1_TCIE;
			( ( Uart_t * const ) Uart_Tx -> BusNumber ) -> CR1 = Loc_u32Reg ;
			Uart_Tx ->State.TxBusy = 0;
			Tx1_Cbf();
		}
		else
		{
			( ( Uart_t * const ) UART1 ) -> DR = Uart_Tx -> TxBuffer.Data [ Uart_Tx -> TxBuffer.Used ] ;
			Uart_Tx -> TxBuffer.Used ++ ;
		}
	}

	if( ( ( ( ( ( Uart_t * const ) UART1 ) -> SR ) & UART_u32SR_RXNE ) == UART_u32SR_RXNE ) && ( Uart_Rx -> State.RxBusy == 1 ) )
	{
		Uart_Rx -> RxBuffer -> Data [ Uart_Rx -> RxBuffer -> Used ] = ( ( Uart_t * const ) UART1 ) -> DR ;
		Uart_Rx -> RxBuffer -> Used ++;

		if( Uart_Rx -> RxBuffer -> Used == Uart_Rx -> RxBuffer -> Size )
		{
			Loc_u32Reg &= ~UART_u32CR1_RXNEIE;
			Uart_Rx -> State.RxBusy = 0;
			Rx1_Cbf();
		}
	}

}

/*
void USART2_IRQHandler(void)
{
	if( ( ( ( Uart_t * const ) UART2 ) ->SR ) & UART_u32SR_TC == UART_u32SR_TC )
	{
		if( txBuffer -> Used == txBuffer->Size )
		{
			txBusy = 0;
			Tx2_Cbf();
		}
		else
		{
			( ( Uart_t * const ) UART2 ) -> DR = txBuffer -> Data[txBuffer -> Used] ;
			txBuffer -> Used ++ ;
		}
	}
}
void USART6_IRQHandler(void)
{
	if( ( ( ( Uart_t * const ) UART6 ) ->SR ) & UART_u32SR_TC == UART_u32SR_TC )
	{
		if( txBuffer -> Used == txBuffer->Size )
		{
			txBusy = 0;
			Tx6_Cbf();
		}
		else
		{
			( ( Uart_t * const ) UART6 ) -> DR = txBuffer -> Data[txBuffer -> Used] ;
			txBuffer -> Used ++ ;
		}
	}
}
*/
