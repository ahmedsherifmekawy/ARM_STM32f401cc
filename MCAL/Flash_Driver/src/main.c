
#include "Std_types.h"
#include "Flash_Driver.h"


int main()
{

	FD_Init();

	FD_EraseSector( FD_SECTOR_1 );
	FD_ProgramPage( 0x08004000 , 0xFF00FF00);

	while (1)
    {

    }
	return 0;
}
