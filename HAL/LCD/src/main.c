


#include "Std_types.h"
#include "RCC.h"
#include "Gpio.h"
#include "Sched.h"
#include "Sched_cfg.h"
#include "LCD.h"
#include "LCD_cfg.h"



int main()
{
	Buffer_t String;
	String.Data ="Ahmed";
	String.Size = 6;
	Sched_vidInit();
	Sched_vidStart();

	LCD_vidInit();
	LCD_vidDisplayString(&String);

	return 0;
}
