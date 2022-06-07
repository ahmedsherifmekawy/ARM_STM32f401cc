/*
 * NVIC.h
 *
 *  Created on: Apr 3, 2022
 *      Author: WINDOWS
 */

#ifndef NVIC_H_
#define NVIC_H_


typedef enum {
	NVIC_Ok,
	NVIC_Nok
}NVIC_tenuError;



#define SCB_u32AIRCR_PRIGROUP_SUB_PRI_NONE            (u32)0x000
#define SCB_u32AIRCR_PRIGROUP_SUB_PRI_2               (u32)0x400
#define SCB_u32AIRCR_PRIGROUP_SUB_PRI_4               (u32)0x500
#define SCB_u32AIRCR_PRIGROUP_SUB_PRI_8               (u32)0x600
#define SCB_u32AIRCR_PRIGROUP_SUB_PRI_16              (u32)0x700

#define NVIC_u8IPR_NOT_IMPLEMENTED                    4

NVIC_tenuError NVIC_enuEnableIRQ(u32  Copy_enuIRQn);
NVIC_tenuError NVIC_enuDisableIRQ(u32  Copy_enuIRQn);
NVIC_tenuError NVIC_enuSetPendingIRQ(u32  Copy_enuIRQn);
NVIC_tenuError NVIC_enuClearPendingIRQ(u32  Copy_enuIRQn);
NVIC_tenuError NVIC_enuGetActiveStateIRQ(u32  Copy_enuIRQn , u32 * Add_pu32ActiveStatus );
NVIC_tenuError NVIC_enuSetPriority(u32  Copy_enuIRQn, u8 Copy_u8Priority);
NVIC_tenuError NVIC_enuSetPriGroup(u32  Copy_enuIRQn, u32 Copy_u32PriGroup);

NVIC_tenuError NVIC_enuEncodePriority(); //prigroup //pre //sub   ->>>> overall priority





#endif /* NVIC_H_ */
