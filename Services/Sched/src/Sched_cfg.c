/*
 * Sched_cfg.c
 *
 *  Created on: Apr 3, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Sched.h"
#include "Sched_cfg.h"
#include "Tasks.h"
#include "Switch.h"

const Runnable_t RunnableList[ SCHED_u32NUM_OF_TASKS ] = {

		[1] = {
				.cbf =task1,
				.CyclicTime = 1
			},
		[0] = {
				.cbf =Switch_vidTask,
				.CyclicTime = 5
		}
};
