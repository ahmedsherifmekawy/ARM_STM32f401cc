/*
 * Uart.h
 *
 *  Created on: Apr 24, 2022
 *      Author: WINDOWS
 */

#ifndef UART_H_
#define UART_H_

typedef enum{
	UARTOk,
	UARTNok
}Uart_tenuErrorStatus;

typedef struct{
	u32 BusNumber;
	u16 BaudRate;
	Buffer_t * RxBuffer;
	Buffer_t TxBuffer;
	struct{
			u8 TxBusy;
			u8 RxBusy;
		  }State;
}UartCfg_t;

typedef void (*AppCbf_t)(void);

#define UART1                           (u32)0x40011000
#define UART2                           (u32)0x40004400
#define UART6                           (u32)0x40011400

#define UART_u32SR_TC                   (u32)0x40
#define UART_u32SR_RXNE                 (u32)0x20
#define UART_u32SR_ORE                  (u32)0x8
#define UART_u32SR_LBD                  (u32)0x100

#define UART_u32CR1_OVER8               (u32)0x8000
#define UART_u32CR1_UE                  (u32)0x2000
#define UART_u32CR1_M                   (u32)0x1000
#define UART_u32CR1_WAKE                (u32)0x800
#define UART_u32CR1_PCE                 (u32)0x400
#define UART_u32CR1_PS                  (u32)0x200
#define UART_u32CR1_PEIE                (u32)0x100
#define UART_u32CR1_TXEIE               (u32)0x80
#define UART_u32CR1_TCIE                (u32)0x40
#define UART_u32CR1_RXNEIE              (u32)0x20
#define UART_u32CR1_IDLEIE              (u32)0x10
#define UART_u32CR1_TE                  (u32)0x8
#define UART_u32CR1_RE                  (u32)0x4
#define UART_u32CR1_RWU                 (u32)0x2
#define UART_u32CR1_SBK                 (u32)0x1



#define UART_u32CR2_LINEN               (u32)0x4000
#define UART_u32CR2_CLKEN               (u32)0x800
#define UART_u32CR2_CPOL                (u32)0x400
#define UART_u32CR2_CPHA                (u32)0x200
#define UART_u32CR2_LBCL                (u32)0x100
#define UART_u32CR2_LBDIE               (u32)0x40
#define UART_u32CR2_LBDL                (u32)0x20

#define UART_u32CR2_STOP_MASK           (u32)0x3000

#define UART_u32CR2_STOP_1BIT           (u32)0x0
#define UART_u32CR2_STOP_HALF_BIT       (u32)0x1000
#define UART_u32CR2_STOP_2BITS          (u32)0x2000

#define UART_u32CR2_ADD_MASK            (u32)0xF




#define UART_u32CR3_ONEBIT              (u32)0x800
#define UART_u32CR3_CTSIE               (u32)0x400
#define UART_u32CR3_CTSE                (u32)0x200
#define UART_u32CR3_RTSE                (u32)0x100
#define UART_u32CR3_DMAT                (u32)0x80
#define UART_u32CR3_DMAR                (u32)0x40
#define UART_u32CR3_SCEN                (u32)0x20
#define UART_u32CR3_NACK                (u32)0x10
#define UART_u32CR3_HDSEL               (u32)0x8
#define UART_u32CR3_IRLP                (u32)0x4
#define UART_u32CR3_IREN                (u32)0x2
#define UART_u32CR3_EIE                 (u32)0x1

#define UART_u8BAUDRATE_SHIFT           (u8)4


#define UART_u8BREAK_DETECTED           (u8)1
#define UART_u8BREAK_NOT_DETECTED       (u8)0

Uart_tenuErrorStatus Uart_enuTxRegCbf(AppCbf_t Cbf);
Uart_tenuErrorStatus Uart_enuRxRegCbf(AppCbf_t Cbf);
Uart_tenuErrorStatus Uart_enuSendBuffer( UartCfg_t * Add_strUartCfg );
Uart_tenuErrorStatus Uart_enuReceiveBuffer( UartCfg_t * Add_strUartCfg );
Uart_tenuErrorStatus Uart_vidSendBreak( UartCfg_t * Add_strUartCfg );
void Uart_vidDetectBreak( UartCfg_t * Add_strUartCfg, pu8 Add_Break );

#endif /* UART_H_ */
