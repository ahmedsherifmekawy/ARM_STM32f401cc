/*
 * RCC.h
 *
 *  Created on: Mar 12, 2022
 *      Author: WINDOWS
 */

#ifndef __RCC_H__
#define __RCC_H__

typedef enum{
	ControlClkOk,
	ControlClkNok,
	PllCfgOk,
	PllCfgNok,
	ControlPrescallerOk,
	ControlPrescallerNok,
	SelectClkOk,
	SelectClkNok
}RCC_enuErrorStatus;

/////////////////////////////////////////////////////////////////////////////////////////////


#define   RCC_u16CLK_VALUE                                25

#define	  RCC_u8HSI                                       0
#define	  RCC_u8HSE                                       1
#define	  RCC_u8PLL                                       2


#define   RCC_u8CLK_RDY                                   1
#define   RCC_u8CLK_NOTRDY                                0

#define   RCC_u8CLK_ON                                    1
#define   RCC_u8CLK_OFF                                   0

#define   RCC_u32HSI_RDY_MASK                             0x2
#define   RCC_u32HSE_RDY_MASK                             0x20000
#define   RCC_u32PLL_RDY_MASK                             0x2000000

#define   RCC_u32HSI_ON			                          0x1
#define   RCC_u32HSE_ON 		                          0x10000
#define   RCC_u32PLL_ON                                   0x1000000

// 0 0 MOST_BIT
#define   RCC_u32PERIPHERAL_AHB1_GPIOA                    0x1
#define   RCC_u32PERIPHERAL_AHB1_GPIOB		              0x2
#define   RCC_u32PERIPHERAL_AHB1_GPIOC                    0x4
#define   RCC_u32PERIPHERAL_AHB1_GPIOD				      0x8
#define   RCC_u32PERIPHERAL_AHB1_GPIOE	                  0x10
#define   RCC_u32PERIPHERAL_AHB1_GPIOH                    0x80
#define   RCC_u32PERIPHERAL_AHB1_CRC                      0x1000
#define   RCC_u32PERIPHERAL_AHB1_FLITF                    0x8000
#define   RCC_u32PERIPHERAL_AHB1_SRAM1                    0x10000
#define   RCC_u32PERIPHERAL_AHB1_DMA1                     0x200000
#define   RCC_u32PERIPHERAL_AHB1_DMA2                     0x400000

// 0 1 MOST_BIT
#define   RCC_u32PERIPHERAL_APB1_TIM2                     0x40000001
#define   RCC_u32PERIPHERAL_APB1_TIM3                     0x40000002
#define   RCC_u32PERIPHERAL_APB1_TIM4                     0x40000004
#define   RCC_u32PERIPHERAL_APB1_TIM5                     0x40000008
#define   RCC_u32PERIPHERAL_APB1_TIMWWDG                  0x40000800
#define   RCC_u32PERIPHERAL_APB1_SPI2                     0x40004000
#define   RCC_u32PERIPHERAL_APB1_SPI3                     0x40008000
#define   RCC_u32PERIPHERAL_APB1_USART2                   0x40020000
#define   RCC_u32PERIPHERAL_APB1_I2C1                     0x40200000
#define   RCC_u32PERIPHERAL_APB1_I2C2                     0x40400000
#define   RCC_u32PERIPHERAL_APB1_I2C3                     0x40800000
#define   RCC_u32PERIPHERAL_APB1_POWER                    0x50000000

// 1 0 MOST_BIT
#define   RCC_u32PERIPHERAL_APB2_TIM1                     0x80000001
#define   RCC_u32PERIPHERAL_APB2_USART1                   0x80000010
#define   RCC_u32PERIPHERAL_APB2_USART6                   0x80000020
#define   RCC_u32PERIPHERAL_APB2_ADC1                     0x80000100
#define   RCC_u32PERIPHERAL_APB2_SDIO                     0x80000800
#define   RCC_u32PERIPHERAL_APB2_SPI1                     0x80001000
#define   RCC_u32PERIPHERAL_APB2_SPI4                     0x80002000
#define   RCC_u32PERIPHERAL_APB2_SYSCFG                   0x80004000
#define   RCC_u32PERIPHERAL_APB2_TIM9                     0x80010000
#define   RCC_u32PERIPHERAL_APB2_TIM10                    0x80020000
#define   RCC_u32PERIPHERAL_APB2_TIM11                    0x80040000


#define   RCC_u32BUS_MASK                                 0xC0000000

#define   RCC_u32AHB1_MASK                                0x0
#define   RCC_u32APB1_MASK                                0x40000000
#define   RCC_u32APB2_MASK                                0x80000000


#define   RCC_u32PLL_Q_CFG_2                              0x2000000
#define   RCC_u32PLL_Q_CFG_3                              0x3000000
#define   RCC_u32PLL_Q_CFG_4                              0x4000000
#define   RCC_u32PLL_Q_CFG_5                              0x5000000
#define   RCC_u32PLL_Q_CFG_6                              0x6000000
#define   RCC_u32PLL_Q_CFG_7                              0x7000000
#define   RCC_u32PLL_Q_CFG_8                              0x8000000
#define   RCC_u32PLL_Q_CFG_9                              0x9000000
#define   RCC_u32PLL_Q_CFG_10                             0xA000000
#define   RCC_u32PLL_Q_CFG_11                             0xB000000
#define   RCC_u32PLL_Q_CFG_12                             0xC000000
#define   RCC_u32PLL_Q_CFG_13                             0xD000000
#define   RCC_u32PLL_Q_CFG_14                             0xE000000
#define   RCC_u32PLL_Q_CFG_15                             0xF000000


#define   RCC_u16PLL_N_INPUT                              5
#define   RCC_u8PLL_M_INPUT                               5

#define   RCC_u32PLL_N_MASK                               ( RCC_u16PLL_N_INPUT<<6 )
#define   RCC_u32PLL_M_MASK								  RCC_u8PLL_M_INPUT


#define   RCC_u32PLL_P_CFG_2                              0x0
#define   RCC_u32PLL_P_CFG_4                              0x10000
#define   RCC_u32PLL_P_CFG_6                              0x20000
#define   RCC_u32PLL_P_CFG_8                              0x30000



#define   RCC_u8PLL_M_MIN                                 2
#define   RCC_u8PLL_M_MAX                                 63


#define   RCC_u8PLL_N_MIN                                 2
#define   RCC_u8PLL_N_MAX                                 432

#define   RCC_u32PLL_SRC_HSI                              0x0
#define   RCC_u32PLL_SRC_HSE                              0x400000

#define   RCC_u32AHB1_PRE_NOTDEVIDED                       0x70
#define   RCC_u32AHB1_PRE_2                                0x80
#define   RCC_u32AHB1_PRE_4                                0x90
#define   RCC_u32AHB1_PRE_8                                0xA0
#define   RCC_u32AHB1_PRE_16                               0xB0
#define   RCC_u32AHB1_PRE_64                               0xC0
#define   RCC_u32AHB1_PRE_128                              0xD0
#define   RCC_u32AHB1_PRE_256                              0xE0
#define   RCC_u32AHB1_PRE_512                              0xF0


#define   RCC_u32APB1_PRE_NOTDEVIDED                       0xC00
#define   RCC_u32APB1_PRE_2                                0x1000
#define   RCC_u32APB1_PRE_4                                0x1400
#define   RCC_u32APB1_PRE_8                                0x1800
#define   RCC_u32APB1_PRE_16                               0x1C00


#define   RCC_u32APB2_PRE_NOTDEVIDED                       0x6000
#define   RCC_u32APB2_PRE_2                                0x8000
#define   RCC_u32APB2_PRE_4                                0xA000
#define   RCC_u32APB2_PRE_8                                0xC000
#define   RCC_u32APB2_PRE_16                               0xE000


#define   RCC_u32SW_HSI                                    0x0
#define   RCC_u32SW_HSE									   0x1
#define   RCC_u32SW_PLL									   0x2

#define   RCC_u32SW_MASK                                   0x3
#define   RCC_u32SWS_MASK                                  0xC

#define   RCC_u32SWS_HSI                                   0x0
#define   RCC_u32SWS_HSE                                   0x4
#define   RCC_u32SWS_PLL                                   0x8

//////////////////////////////////////////////////////////////////////////////////////////////

RCC_enuErrorStatus Rcc_enuSelectSysClk( u8 Copy_u8ClkMode );
RCC_enuErrorStatus Rcc_enuControl_Clk( u8 Copy_u8ClkMode , u32 Copy_u32ClkCtrl );
u8 Rcc_u8GetClkStatus( u8 Copy_u8ClkMode );
RCC_enuErrorStatus Rcc_enuConfigurePll(u8 Copy_u8M ,u16 Copy_u16N ,u32 Copy_u32Q ,u32 Copy_u32P , u32 Copy_u32SrcClk );
RCC_enuErrorStatus Rcc_enuControlBusPrescaller( u32 Copy_u32BusMode , u32 Copy_u32PrescallerValue );
void Rcc_vidEnablePeripheralClk( u32 Copy_u8PeripheralName );

#endif


