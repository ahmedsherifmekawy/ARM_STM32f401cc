/*
 * Lin.h
 *
 *  Created on: May 16, 2022
 *      Author: WINDOWS
 */

#ifndef LIN_H_
#define LIN_H_


typedef enum{
	LinNok,
	LinOk
}Lin_tenuErrorStatus;

typedef enum{
	SendHeader,
	ReceiveHeader,
	Response,
	Idle
}Lin_tenuState;

typedef struct{
	u8 ID;
	Buffer_t Data;
	u8 Sender;
	u8 Receiver;
}Lin_tstrInfo;

typedef enum{
	Send,
	Receive,
	None
}Lin_tenuRole;


#define    LIN_u8SYNC_BYTE             (u8)0x55
#define    LIN_u8DEL                   (u8)0x1

void Lin_enuMasterTask( void );
void Lin_enuSlaveTask( void );

#endif /* LIN_H_ */
