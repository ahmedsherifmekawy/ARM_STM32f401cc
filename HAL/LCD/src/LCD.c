/*
 * LCD.c
 *
 *  Created on: Apr 11, 2022
 *      Author: WINDOWS
 */



#include "Std_types.h"
#include "Bit_utils.h"
#include "Gpio.h"
#include "LCD.h"
#include "LCD_cfg.h"


typedef enum{
	Pause,
	Start,
	FunctionSet,
	DisplayControl,
	DisplayClear,
	EntryModeSet,
	End
}LCD_tenuInitSequence;

typedef enum{
	Free,
	DisplayString,
	SendCommand
}LCD_tenuStates;


extern LCD_PinCfg PinList[ LCD_u8NUMBER_OF_PINS ] ;
static LCD_tenuInitSequence InitState = Pause;
static LCD_tenuStates Lcd_State = Free;

Buffer_t * Data_Buffer;
u8 Command;

void  LCD_vidInit()
{
	InitState = Start ;
}

void  LCD_vidDisplayString(Buffer_t * Add_strString)
{
	if(Lcd_State == Free)
	{
		Data_Buffer = Add_strString;
		Lcd_State = DisplayString;
		Add_strString -> Used = 0;
	}
}

void  LCD_vidSendCommand(u8 Copy_u8Command)
{
	if(Lcd_State == Free)
	{
		Command = Copy_u8Command;
		Lcd_State = SendCommand;
	}
}


void  LCD_vidSched()
{
	static u32 TimeMs;
	u8 Loc_u8Data = Data_Buffer -> Data;
	if( InitState != Pause && InitState != End )
	{
		switch(InitState)
		{
			case Start:
			{
				TimeMs++;
				if( TimeMs == 31 )
				{
					InitState = FunctionSet;
					TimeMs = 0;
				}
				break;
			}
			case FunctionSet:
			{
				TimeMs++;
				if(TimeMs == 1)
				{
					Gpio_enuSetPinValue( PinList[0].Port , PinList[0].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[1].Port , PinList[1].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[2].Port , PinList[2].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[3].Port , PinList[3].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[4].Port , PinList[4].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[5].Port , PinList[5].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[6].Port , PinList[6].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[7].Port , PinList[7].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[LCD_u8RW_PIN].Port , PinList[LCD_u8RW_PIN].Pin , LCD_u8RW_WRITE );
					Gpio_enuSetPinValue( PinList[LCD_u8RS_PIN].Port , PinList[LCD_u8RS_PIN].Pin , LCD_u8RS_COMMAND );
					Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , LCD_u8EN_HIGH );
				}
				else if(TimeMs == 2)
				{
					Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , GPIO_u8PIN_LOW );
					InitState = DisplayControl;
					TimeMs = 0;
				}
				break;
			}
			case DisplayControl:
			{
				TimeMs++;
				if(TimeMs == 1)
				{
					Gpio_enuSetPinValue( PinList[0].Port , PinList[0].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[1].Port , PinList[1].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[2].Port , PinList[2].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[3].Port , PinList[3].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[4].Port , PinList[4].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[5].Port , PinList[5].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[6].Port , PinList[6].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[7].Port , PinList[7].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[LCD_u8RW_PIN].Port , PinList[LCD_u8RW_PIN].Pin , LCD_u8RW_WRITE );
					Gpio_enuSetPinValue( PinList[LCD_u8RS_PIN].Port , PinList[LCD_u8RS_PIN].Pin , LCD_u8RS_COMMAND );
					Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , LCD_u8EN_HIGH );
				}
				else if(TimeMs == 2	)
				{
					Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , GPIO_u8PIN_LOW );
					InitState = DisplayClear;
					TimeMs = 0;
				}
				break;
			}
			case DisplayClear:
			{
				TimeMs++;
				if(TimeMs == 1)
				{
					Gpio_enuSetPinValue( PinList[0].Port , PinList[0].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[1].Port , PinList[1].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[2].Port , PinList[2].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[3].Port , PinList[3].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[4].Port , PinList[4].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[5].Port , PinList[5].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[6].Port , PinList[6].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[7].Port , PinList[7].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[LCD_u8RW_PIN].Port , PinList[LCD_u8RW_PIN].Pin , LCD_u8RW_WRITE );
					Gpio_enuSetPinValue( PinList[LCD_u8RS_PIN].Port , PinList[LCD_u8RS_PIN].Pin , LCD_u8RS_COMMAND );
					Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , LCD_u8EN_HIGH );
				}
				else if(TimeMs == 2)
				{
					Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , GPIO_u8PIN_LOW );
				}
				else if(TimeMs == 4)
				{
					InitState = EntryModeSet;
					TimeMs = 0;
				}
				break;
			}
			case EntryModeSet:
			{
				TimeMs++;
				if(TimeMs == 1)
				{
					Gpio_enuSetPinValue( PinList[0].Port , PinList[0].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[1].Port , PinList[1].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[2].Port , PinList[2].Pin , GPIO_u8PIN_HIGH );
					Gpio_enuSetPinValue( PinList[3].Port , PinList[3].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[4].Port , PinList[4].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[5].Port , PinList[5].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[6].Port , PinList[6].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[7].Port , PinList[7].Pin , GPIO_u8PIN_LOW );
					Gpio_enuSetPinValue( PinList[LCD_u8RW_PIN].Port , PinList[LCD_u8RW_PIN].Pin , LCD_u8RW_WRITE );
					Gpio_enuSetPinValue( PinList[LCD_u8RS_PIN].Port , PinList[LCD_u8RS_PIN].Pin , LCD_u8RS_COMMAND );
					Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , LCD_u8EN_HIGH );
				}
				else if(TimeMs == 2)
				{
					Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , GPIO_u8PIN_LOW );
					InitState = End;
					TimeMs = 0;
				}
				break;
			}
		}
	}
	else if( Lcd_State == DisplayString )
	{
		TimeMs++;

		if(TimeMs == 1)
		{
			if( Data_Buffer -> Used != Data_Buffer -> Used )
			{
				Gpio_enuSetPinValue( PinList[0].Port , PinList[0].Pin , GET_BIT(Loc_u8Data,0));
				Gpio_enuSetPinValue( PinList[1].Port , PinList[1].Pin , GET_BIT(Loc_u8Data,1));
				Gpio_enuSetPinValue( PinList[2].Port , PinList[2].Pin , GET_BIT(Loc_u8Data,2));
				Gpio_enuSetPinValue( PinList[3].Port , PinList[3].Pin , GET_BIT(Loc_u8Data,3));
				Gpio_enuSetPinValue( PinList[4].Port , PinList[4].Pin , GET_BIT(Loc_u8Data,4));
				Gpio_enuSetPinValue( PinList[5].Port , PinList[5].Pin , GET_BIT(Loc_u8Data,5));
				Gpio_enuSetPinValue( PinList[6].Port , PinList[6].Pin , GET_BIT(Loc_u8Data,6));
				Gpio_enuSetPinValue( PinList[7].Port , PinList[7].Pin , GET_BIT(Loc_u8Data,7));
				Gpio_enuSetPinValue( PinList[LCD_u8RW_PIN].Port , PinList[LCD_u8RW_PIN].Pin , LCD_u8RW_WRITE );
				Gpio_enuSetPinValue( PinList[LCD_u8RS_PIN].Port , PinList[LCD_u8RS_PIN].Pin , LCD_u8RS_DATA );
				Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , LCD_u8EN_HIGH );

				Data_Buffer -> Used ++;
			}
			else
			{
				Lcd_State = Free;
				TimeMs = 0;
			}
		}
		else if(TimeMs == 1)
		{
			Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , LCD_u8EN_HIGH );
		}
	}

	else if( Lcd_State == SendCommand )
	{
		TimeMs++;
		if(TimeMs == 1)
		{
			Gpio_enuSetPinValue( PinList[0].Port , PinList[0].Pin , GET_BIT(Command,0));
			Gpio_enuSetPinValue( PinList[1].Port , PinList[1].Pin , GET_BIT(Command,1));
			Gpio_enuSetPinValue( PinList[2].Port , PinList[2].Pin , GET_BIT(Command,2));
			Gpio_enuSetPinValue( PinList[3].Port , PinList[3].Pin , GET_BIT(Command,3));
			Gpio_enuSetPinValue( PinList[4].Port , PinList[4].Pin , GET_BIT(Command,4));
			Gpio_enuSetPinValue( PinList[5].Port , PinList[5].Pin , GET_BIT(Command,5));
			Gpio_enuSetPinValue( PinList[6].Port , PinList[6].Pin , GET_BIT(Command,6));
			Gpio_enuSetPinValue( PinList[7].Port , PinList[7].Pin , GET_BIT(Command,7));
			Gpio_enuSetPinValue( PinList[LCD_u8RW_PIN].Port , PinList[LCD_u8RW_PIN].Pin , LCD_u8RW_WRITE );
			Gpio_enuSetPinValue( PinList[LCD_u8RS_PIN].Port , PinList[LCD_u8RS_PIN].Pin , LCD_u8RS_COMMAND );
			Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , LCD_u8EN_HIGH );
		}
		else if(TimeMs == 1)
		{
			Gpio_enuSetPinValue( PinList[LCD_u8EN_PIN].Port , PinList[LCD_u8EN_PIN].Pin , LCD_u8EN_HIGH );
			Lcd_State = Free;
			TimeMs = 0;
		}
	}

}

