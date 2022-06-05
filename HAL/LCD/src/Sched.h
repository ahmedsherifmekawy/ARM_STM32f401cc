/*
 * Sched.h
 *
 *  Created on: Apr 3, 2022
 *      Author: WINDOWS
 */

#ifndef SCHED_H_
#define SCHED_H_

typedef struct{
	void(* cbf)(void);
	u32 CyclicTime;
}Runnable_t;


#define   SCHED_u32FIRST_TASK      0




void Sched_vidInit(void);
void Sched_vidStart(void);


#endif /* SCHED_H_ */
