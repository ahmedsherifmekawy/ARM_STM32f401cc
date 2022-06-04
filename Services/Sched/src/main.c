


#include "Std_types.h"
#include "Bit_utils.h"
#include "Sched.h"
#include "Sched_cfg.h"
#include "RCC.h"
#include "Led.h"
#include "Switch.h"



int main()
{
	Rcc_enuSelectSysClk(RCC_u8HSI);
	Rcc_vidEnablePeripheralClk(RCC_u32PERIPHERAL_AHB1_GPIOA);
	Swicth_vidInit();
	Led_enuInit();
	Sched_vidInit();
	Sched_vidStart();
}
