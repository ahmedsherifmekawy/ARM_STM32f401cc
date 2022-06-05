/*
 * Sched_cfg.c
 *
 *  Created on: Apr 3, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Sched.h"
#include "Sched_cfg.h"
#include "LCD.h"

const Runnable_t RunnableList[ SCHED_u32NUM_OF_TASKS ] = {

		[0] ={
				.cbf = LCD_vidSched ,
				.CyclicTime = 2
		     }
};
