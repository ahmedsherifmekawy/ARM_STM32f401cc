/*
 * Gpio.h
 *
 *  Created on: Mar 15, 2022
 *      Author: WINDOWS
 */



typedef enum{
	Ok,
	Nok
}Gpio_enuErrorStatus;

typedef struct{
	u32 Mode;
	u8 Speed;
	u32 Pin;
	u32 Port;
}GpioPinCfg_t;

////////////////////////////////////////////////////////////


#define  GPIOA_BASE_ADDRESS    (u32)0X40020000
#define  GPIOB_BASE_ADDRESS    (u32)0X40020400
#define  GPIOC_BASE_ADDRESS    (u32)0X40020800
#define  GPIOD_BASE_ADDRESS    (u32)0X40020C00
#define  GPIOE_BASE_ADDRESS    (u32)0X40021000
#define  GPIOH_BASE_ADDRESS    (u32)0X40021C00


#define GPIO_u32PIN_0           (u32)0x1
#define GPIO_u32PIN_1           (u32)0x2
#define GPIO_u32PIN_2           (u32)0x4
#define GPIO_u32PIN_3           (u32)0x8
#define GPIO_u32PIN_4           (u32)0x10
#define GPIO_u32PIN_5           (u32)0x20
#define GPIO_u32PIN_6           (u32)0x40
#define GPIO_u32PIN_7           (u32)0x80
#define GPIO_u32PIN_8           (u32)0x100
#define GPIO_u32PIN_9           (u32)0x200
#define GPIO_u32PIN_10          (u32)0x400
#define GPIO_u32PIN_11          (u32)0x800
#define GPIO_u32PIN_12          (u32)0x1000
#define GPIO_u32PIN_13          (u32)0x2000
#define GPIO_u32PIN_14          (u32)0x4000
#define GPIO_u32PIN_15          (u32)0x8000

#define GPIO_u8BRR_SHIFT       (u8)16

#define GPIO_u8PIN_HIGH        (u8)1
#define GPIO_u8PIN_LOW         (u8)0


#define GPIO_u32PIN_MSK        (u32)0x01
#define GPIO_u32MODER_MSK      (u32)0x03
#define GPIO_u32OTYPER_MSK     (u32)0x04
#define GPIO_u32PUPDR_MSK      (u32)0x18
#define GPIO_u32OSPEEDR_MSK    (u32)0x03

#define GPIO_u32AF_MSK         (u32)0x0F

#define GPIO_u8OTYPER_SHIFT     (u8)2
#define GPIO_u8PUPDR_SHIFT      (u8)3

#define GPIO_u8DOUBLE_SHIFT     (u8)2

#define GPIO_u32MODE_INPUT      (u32)0x0
#define GPIO_u32MODE_OUTPUT     (u32)0x1
#define GPIO_u32MODE_AF         (u32)0x2
#define GPIO_u32MODE_ANALOG     (u32)0x3

#define GPIO_u32MODE_INPUT_FLOAT   (u32)0x0
#define GPIO_u32MODE_INPUT_PU      (u32)0x8
#define GPIO_u32MODE_INPUT_PD      (u32)0x10

#define GPIO_u32MODE_OUTPUT_PP     (u32)0x1
#define GPIO_u32MODE_OUTPUT_OD     (u32)0x5

#define GPIO_u32MODE_AF_PP         (u32)0x2
#define GPIO_u32MODE_AF_OD         (u32)0x6
#define GPIO_u32MODE_AF_FLOAT      (u32)0x2
#define GPIO_u32MODE_AF_PU         (u32)0xA
#define GPIO_u32MODE_AF_PD         (u32)0x12


#define GPIO_u8SPEED_LOW	       (u8)0x0
#define GPIO_u8SPEED_MEDIUM	       (u8)0x1
#define GPIO_u8SPEED_HIGH	       (u8)0x2
#define GPIO_u8SPEED_VERY_HIGH     (u8)0x3


#define GPIO_u8ZERO                (u8)0
#define GPIO_u8NUMBER_OF_PINS      (u8)16

///////////////////////////////////////////////////////////

Gpio_enuErrorStatus Gpio_enuInitPin( GpioPinCfg_t * Add_strPinCfg );

Gpio_enuErrorStatus Gpio_enuSetPinValuestruct( GpioPinCfg_t * Add_strPinCfg ,u8 Copy_u8PinValue );

Gpio_enuErrorStatus Gpio_enuSetPinValue( u32 Copy_u32Port , u32 Copy_u32Pin , u8 Copy_u8PinValue );

Gpio_enuErrorStatus Gpio_enuGetPinValue( u32 Copy_u32Port , u32 Copy_u32Pin , pu16 Add_pu16PinValue );

Gpio_enuErrorStatus Gpio_enuSetAlternative( u32 Copy_u32Port , u8 Copy_u8AF_Number , u8 Copy_u8AF_Value );




