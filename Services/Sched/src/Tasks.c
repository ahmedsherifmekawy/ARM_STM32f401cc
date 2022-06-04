/*
 * Tasks.c
 *
 *  Created on: May 9, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "Tasks.h"
#include "Led.h"
#include "Switch.h"


void task1(void)
{
	u8 f;
	Switch_enuGetStatus( &f , 0 );
	if( f == SWITCH_u8STATE_PRESSED )
	{
		 Led_enuSetStatus( 0 , LED_u8STATE_ON );
	}
	else
	{
		 Led_enuSetStatus( 0 , LED_u8STATE_OFF );
	}
}
