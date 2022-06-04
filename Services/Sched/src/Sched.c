/*
 * Sched.c
 *
 *  Created on: Apr 3, 2022
 *      Author: WINDOWS
 */



#include "Std_types.h"
#include "Systick.h"
#include "Sched.h"
#include "Sched_cfg.h"


extern Runnable_t RunnableList[SCHED_u32NUM_OF_TASKS];

static void Sched()
{
	static u32 Loc_u32Time_ms; // 0      // 1     // 2   // 4  // 6  // 8
	u32 Loc_u32Idx ;

	for( Loc_u32Idx = SCHED_u32FIRST_TASK ; Loc_u32Idx < SCHED_u32NUM_OF_TASKS ; Loc_u32Idx++ )
	{
		if(Loc_u32Time_ms % RunnableList[Loc_u32Idx]  . CyclicTime == 0 )
		{
			RunnableList[Loc_u32Idx] . cbf();
		}
	}
	Loc_u32Time_ms += SCHED_u32TICK_TIME ;
}


void Sched_vidInit()
{
	Systick_vidInit();
	Systick_enuSetTicTime_ms( SCHED_u32TICK_TIME );
	Systick_enuRegisterCbf(Sched);
}


void Sched_vidStart()
{
	Systick_vidStart();

	while(1);

}

