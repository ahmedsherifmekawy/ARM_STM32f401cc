/*
 * LCD.h
 *
 *  Created on: Apr 11, 2022
 *      Author: WINDOWS
 */

#ifndef LCD_H_
#define LCD_H_

typedef struct{
	u32 Port;
	u32 Pin;
	u8 ActiveState;
}LCD_PinCfg;

#define    LCD_u8RW_PIN               8
#define    LCD_u8EN_PIN               9
#define    LCD_u8RS_PIN               10

#define    LCD_u8NUMBER_OF_PINS       11

#define   LCD_u8RW_READ               1
#define   LCD_u8RW_WRITE			  0

#define   LCD_u8RS_COMMAND            0
#define   LCD_u8RS_DATA	              1

#define   LCD_u8EN_HIGH	              1
#define   LCD_u8ENABLE_LOW            0

void  LCD_vidInit();
void  LCD_vidDisplayString( Buffer_t * Add_strString );
void  LCD_vidSendCommand(u8 Copy_u8Command);
void  LCD_vidSched();


#endif /* LCD_H_ */
