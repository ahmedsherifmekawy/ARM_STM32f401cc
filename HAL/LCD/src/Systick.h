/*
 * Systick.h
 *
 *  Created on: Apr 2, 2022
 *      Author: WINDOWS
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_


typedef enum{
	SystickOk,
	SystickNok
}Systick_tenuErrorStatus;

typedef void (*SystickCbf_t)(void);



#define   	SYSTICK_u32SRC_CLK_MASK                (u32)0x4
#define   	SYSTICK_u32ENABLE_MASK                 (u32)0x1
#define     SYSTICK_u32TICKINT_MASK                (u32)0x2

#define     SYSTICK_u8CLK_PROC_DIV_EIGHT           0
#define     SYSTICK_u8CLK_PROC                     1

#define     SYSTICK_MAX                            1000
#define     SYS_FREQUENCY                          16000000

void Systick_vidInit();
Systick_tenuErrorStatus Systick_enuSetTicTime_ms(u32 Copy_u8time);
Systick_tenuErrorStatus Systick_enuRegisterCbf(SystickCbf_t Copy_Cbf);
void Systick_vidStart();




#endif /* SYSTICK_H_ */
