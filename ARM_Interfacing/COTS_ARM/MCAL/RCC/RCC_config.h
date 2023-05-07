/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RCC_config.h
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
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* options:
    SYS_CLK_HSI
    SYS_CLK_HSE
    SYS_CLK_PLL
*/
#define     CPU_CLK_SOURCE             RCC_SYS_CLK_HSI

/* options:
    PLL_CLK_HSI
    PLL_CLK_HSE
*/
#define     PLL_SOURCE                 RCC_PLL_CLK_HSI

/* options:
    SYSCLOCK_DIVIDE_BY_2
    SYSCLOCK_DIVIDE_BY_4
    SYSCLOCK_DIVIDE_BY_8
    SYSCLOCK_DIVIDE_BY_16
*/
#define     SYSCLOCK_PRESCALER         SYSCLOCK_DIVIDE_BY_2

/* options:
    APB1_2_DIVIDE_BY_2
    APB1_2_DIVIDE_BY_4
    APB1_2_DIVIDE_BY_8
    APB1_2_DIVIDE_BY_16
*/
#define     AHP_PRESCALER              APB1_2_DIVIDE_BY_2

#endif /* RCC_CONFIG_H */
