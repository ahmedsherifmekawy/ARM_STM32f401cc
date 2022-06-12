/*
 * Lin.c
 *
 *  Created on: May 16, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Uart.h"
#include "Lin.h"
#include "Lin_cfg.h"


extern Lin_tstrInfo Lin_Info [ LIN_u8TIME_SLOTS ];
static u8 Tick_Time = LIN_u8START_TIME;

void Lin_vidCalculateParity(u8 ID, pu8 PID);

u8 SendHeaderFlag = 0;
u8 ReceiveHeaderFlag = 0;
u8 SendDataFlag = 0;
u8 ReceiveDataFlag = 0;

void Notify_SendHeader(void)
{
	SendHeaderFlag = 1;
}

void Notify_ReceiveHeader(void)
{
	ReceiveHeaderFlag = 1;
}

void Notify_SendData(void)
{
	SendDataFlag = 1;
}

void Notify_ReceiveData(void)
{
	ReceiveDataFlag = 1;
}


void Lin_enuMasterTask( void )
{
	static Lin_tenuState Loc_enuMasterState = SendHeader;
	static u8 Loc_u8Data[3];
	static UartCfg_t Loc_enuUartCfg = {
			.BusNumber = UART1 ,
			.BaudRate = 9600
	};
	u8 Loc_u8PID;



	switch( Loc_enuMasterState )
	{
		case Idle:
		{
			if( Tick_Time < LIN_u8TIME_SLOTS)
				Loc_enuMasterState = SendHeader;
			break;
		}
		case SendHeader:
		{
			Uart_enuTxRegCbf(Notify_SendHeader);
			Uart_vidSendBreak( &Loc_enuUartCfg );
			Lin_vidCalculateParity( Lin_Info [Tick_Time].ID ,&Loc_u8PID);
			Loc_enuUartCfg.State.TxBusy = 0;
			Loc_enuUartCfg.State.RxBusy = 1;
			Loc_u8Data[0] = LIN_u8SYNC_BYTE;
			Loc_u8Data[1] = LIN_u8DEL;
			Loc_u8Data[2] = Loc_u8PID;
			Loc_enuUartCfg.TxBuffer.Data = Loc_u8Data;
			Loc_enuUartCfg.TxBuffer.Size = 3;
			Loc_enuUartCfg.TxBuffer.Used = 0;
			Uart_enuSendBuffer( &Loc_enuUartCfg );

			if( SendHeaderFlag == 1 )
			{
				Loc_enuMasterState = Idle;
				SendHeaderFlag = 0;
			}
			break;
		}
	}
}

void Lin_enuSlaveTask( void )
{
	static Lin_tenuState SlaveState = ReceiveHeader;
	static UartCfg_t Loc_enuUartCfg = {
			.BusNumber = UART1 ,
			.BaudRate = 9600
	};
	u8 Loc_u8BreakState;
	u8 Loc_Flag = 0;
	switch( SlaveState )
	{

		case ReceiveHeader:
		{
			Uart_enuRxRegCbf(Notify_ReceiveHeader);
			Loc_enuUartCfg.State.TxBusy = 1;
			Loc_enuUartCfg.State.RxBusy = 0;
			Loc_enuUartCfg.RxBuffer -> Size = 5;
			Loc_enuUartCfg.RxBuffer -> Used = 0;
			Uart_enuReceiveBuffer( &Loc_enuUartCfg );
			Uart_vidDetectBreak( &Loc_enuUartCfg , &Loc_u8BreakState );
			if(Loc_u8BreakState == 1 && ReceiveHeaderFlag == 1)
			{
				SlaveState = Response;
				ReceiveHeaderFlag = 0;
			}
			break;
		}

		case Response:
		{

			if( Lin_Info[Tick_Time].Sender == LIN_u8MY_NUMBER )
			{
				Uart_enuTxRegCbf(Notify_SendData);
				Loc_enuUartCfg.State.TxBusy = 0;
				Loc_enuUartCfg.State.RxBusy = 1;
				Loc_enuUartCfg.TxBuffer = Lin_Info[Tick_Time].Data;
				Uart_enuSendBuffer( &Loc_enuUartCfg );
				if(ReceiveDataFlag == 1)
				{
					SendDataFlag = 0;
					Loc_Flag = 1;
				}
			}
			else if( Lin_Info[Tick_Time].Receiver == LIN_u8MY_NUMBER )
			{
				Uart_enuRxRegCbf(Notify_ReceiveData);
				Loc_enuUartCfg.State.TxBusy = 1;
				Loc_enuUartCfg.State.RxBusy = 0;
				Uart_enuReceiveBuffer( &Loc_enuUartCfg ); // problem ( i don't know the size of data to receive )
				if(ReceiveDataFlag == 1)
				{
					ReceiveDataFlag = 0;
					Loc_Flag = 1;
				}
			}
			if(Loc_Flag == 1)
			{
				SlaveState = ReceiveHeader;
				Tick_Time++;
			}
			break;
		}
	}
}

void Lin_vidCalculateParity(u8 ID, pu8 PID)
{

}
