/*
 * Switch.h
 *
 *  Created on: Apr 9, 2022
 *      Author: WINDOWS
 */

#ifndef SWITCH_H_
#define SWITCH_H_


typedef enum{
	SwitchOk,
	SwitchNok
}Switch_tenuErrorStatus;

typedef struct{
	u32 Port;
	u32 Pin;
	u32 Mode;
	u8 PullState;
}SwitchCfg_t;


#define    SWITCH_u8STATE_PRESSED         1
#define    SWITCH_u8STATE_RELEASED        0

#define    SWITCH_u8PULL_UP               1
#define    SWITCH_u8PULL_DOWN             0

#define    SWITCH_NUM_OF_CHECKS           5

void Swicth_vidInit();
void Switch_vidTask();
Switch_tenuErrorStatus Switch_enuGetStatus(pu8 Add_pu8SwitchStatus , u32 Copy_SwitchNumber);


#endif /* SWITCH_H_ */
