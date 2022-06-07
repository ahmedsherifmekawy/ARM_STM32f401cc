

#include "Std_types.h"
#include "NVIC.h"

int main(void)
{
	u32 Active;

	NVIC_enuEnableIRQ(37);
	NVIC_enuDisableIRQ(37);
	NVIC_enuSetPendingIRQ(37);
	NVIC_enuClearPendingIRQ(37);
	NVIC_enuGetActiveStateIRQ( 37, &Active );
	NVIC_enuSetPriority(239, 6);

	while (1)
	{

	}
}
