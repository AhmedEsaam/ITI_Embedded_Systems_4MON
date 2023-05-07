/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RCC_program.c
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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void MRCC_voidInit(void)
{
    #if     CPU_CLK_SOURCE == RCC_SYS_CLK_HSI
        /* Enable HSI */
        SET_BIT(RCC->CR, CR_HSION);
        /* Select HSI As System Clock (CPU Clk Source)*/
        (RCC->CFGR) &= CFGR_SW_BIT_MASK;
        (RCC->CFGR) |= RCC_SYS_CLK_HSI;
    #elif   CPU_CLK_SOURCE == RCC_SYS_CLK_HSE
        /* Enable HSE */
        SET_BIT(RCC->CR, CR_HSION);
        /* Select HSE As System Clock (CPU Clk Source)*/
        (RCC->CFGR) &= CFGR_SW_BIT_MASK;
        (RCC->CFGR) |= RCC_SYS_CLK_HSE;
    #elif   CPU_CLK_SOURCE == RCC_SYS_CLK_PLL
        #if PLL_SOURCE == RCC_PLL_CLK_HSI
            /* Enable HSI */
            SET_BIT(RCC->CR, CR_HSION);
            /* Select HSI As PLL Source */
            CLR_BIT(RCC->PLLCFGR, PLLCFGR_PLLSRC);
            /* Enable PLL */
            SET_BIT(RCC->CR, CR_PLLON);
            /* Select PLL As System Clock (CPU Clk Source) */
            (RCC->CFGR) &= CFGR_SW_BIT_MASK;
            (RCC->CFGR) |= RCC_SYS_CLK_PLL;
        #elif PLL_SOURCE == RCC_PLL_CLK_HSE
            /* Enable HSE */
            SET_BIT(RCC->CR, CR_HSEON);
            /* Select HSE As PLL Source */
            SET_BIT(RCC->PLLCFGR, PLLCFGR_PLLSRC);
            /* Enable PLL */
            SET_BIT(RCC->CR, CR_PLLON);
            /* Select PLL As System Clock (CPU Clk Source) */
            (RCC->CFGR) &= CFGR_SW_BIT_MASK;
            (RCC->CFGR) |= RCC_SYS_CLK_PLL;
        #else
            #error "RCC PLL_SOURCE Configuration Error"AHB1ENR_CRC_EN
        #endif 
    #else
        #error "CPU_CLK_SOURCE Configuration Error"
    #endif

    /* Set AHB Prescaler */
    (RCC->CFGR) |= (AHB_PRESCALER << 4);

    // APB1, APB2 Prescaler ...

}

void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
    case RCC_AHB1:
        SET_BIT(RCC->AHB1ENR, Copy_u8PeripheralID); 
    break;
    case RCC_AHB2:
        SET_BIT(RCC->AHB2ENR, Copy_u8PeripheralID); 
    break;
    case RCC_APB1:
        SET_BIT(RCC->APB1ENR, Copy_u8PeripheralID); 
    break;
    case RCC_APB2:
        SET_BIT(RCC->APB2ENR, Copy_u8PeripheralID); 
    break;
    default:
        /* Return Error */
    break;
    }
}

void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID)
{
switch (Copy_u8PeripheralBus)
    {
    case RCC_AHB1:
        CLR_BIT(RCC->AHB1ENR, Copy_u8PeripheralID); 
    break;
    case RCC_AHB2:
        CLR_BIT(RCC->AHB2ENR, Copy_u8PeripheralID); 
    break;
    case RCC_APB1:
        CLR_BIT(RCC->APB1ENR, Copy_u8PeripheralID); 
    break;
    case RCC_APB2:
        CLR_BIT(RCC->APB2ENR, Copy_u8PeripheralID); 
    break;
    default:
        /* Return Error */
    break;
    }
}
