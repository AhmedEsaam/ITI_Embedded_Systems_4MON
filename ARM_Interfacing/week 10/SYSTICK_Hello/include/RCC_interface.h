/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RCC_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 1, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 1, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

// Buses .......................................
#define         RCC_AHB1                   0
#define         RCC_AHB2                   1
#define         RCC_APB1                   2
#define         RCC_APB2                   3
    
// System Clock Selection ......................
#define         RCC_SYS_CLK_HSI            0b00 
#define         RCC_SYS_CLK_HSE            0b01 
#define         RCC_SYS_CLK_PLL            0b10

// PLL Clock Source ............................
#define         RCC_PLL_CLK_HSI            0 
#define         RCC_PLL_CLK_HSE            1 

// Peripherals .................................
// AHB1
#define         RCC_AHB1_GPIOA             0
#define         RCC_AHB1_GPIOB             1
#define         RCC_AHB1_GPIOC             2
#define         RCC_AHB1_CRC               12
#define         RCC_AHB1_DMA1              21
#define         RCC_AHB1_DMA2              22
// APB1
#define         RCC_APB1_TIM2              0
#define         RCC_APB1_TIM3              1
#define         RCC_APB1_TIM4              2
#define         RCC_APB1_TIM5              3
#define         RCC_APB1_WWDG              11
#define         RCC_APB1_SPI2              12
#define         RCC_APB1_SPI3              13
#define         RCC_APB1_USART2            17
#define         RCC_APB1_I2C1              21
#define         RCC_APB1_I2C2              22
#define         RCC_APB1_I2C3              23
#define         RCC_APB1_PWR               28
// APB2
#define         RCC_APB2_TIM1              0
#define         RCC_APB2_USART1            4
#define         RCC_APB2_USART6            5
#define         RCC_APB2_ADC1              8
#define         RCC_APB2_SDIO              11
#define         RCC_APB2_SPI1              12
#define         RCC_APB2_SPI4              13
#define         RCC_APB2_SYSCFG            14
#define         RCC_APB2_TIM9              16
#define         RCC_APB2_TIM10             17
#define         RCC_APB2_TIM11             18


void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID);
void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID);

#endif /* RCC_INTERFACE_H */
