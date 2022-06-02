/*
 * Led.h
 *
 *  Created on: Mar 26, 2022
 *      Author: WINDOWS
 */

#ifndef LED_H_
#define LED_H_


typedef enum{
	LedOk,
	LedNok
}Led_enuResult;

typedef struct{

	u32 Port;
	u32 Pin;
	u8 ActiveState;
	u8 Otype;

}Ledcfg_t;

#define LED_u8STATE_ON             0
#define LED_u8STATE_OFF            1

#define LED_u8ZERO                 0

#define LED_u8ACTIVE_STATE_HIGH      1
#define LED_u8ACTIVE_STATE_LOW       0

#define LED_u8OTYPE_PP               0
#define LED_u8OTYPE_OD               1


extern Led_enuResult Led_enuInit();
extern Led_enuResult Led_enuSetStatus(u8 Copy_u8LedNumber ,u8 Copy_u8LedState );

#endif /* LED_H_ */
