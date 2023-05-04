/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RCC_private.h
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
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

typedef struct
{
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Reserved8;
    volatile u32 DCKCFGR;
}RCC_t;

#define     RCC         (volatile RCC_t *) 0x40023800


/*------------------------------ AHB1 ----------------------------*/

// RCC AHB1 peripheral reset register (RCC_AHB1RSTR)
#define     AHB1RSTR_GPIOA_RST          0  
#define     AHB1RSTR_GPIOB_RST          1  
#define     AHB1RSTR_GPIOC_RST          2  
#define     AHB1RSTR_GPIOD_RST          3  
#define     AHB1RSTR_GPIOE_RST          4  
#define     AHB1RSTR_GPIOH_RST          7
#define     AHB1RSTR_CRC_RST            12
#define     AHB1RSTR_DMA1_RST           21
#define     AHB1RSTR_DMA2_RST           22

// RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
#define     AHB1ENR_GPIOA_EN            0  
#define     AHB1ENR_GPIOB_EN            1  
#define     AHB1ENR_GPIOC_EN            2  
#define     AHB1ENR_GPIOD_EN            3  
#define     AHB1ENR_GPIOE_EN            4  
#define     AHB1ENR_GPIOH_EN            7
#define     AHB1ENR_CRC_EN              12
#define     AHB1ENR_DMA1_EN             21
#define     AHB1ENR_DMA2_EN             22

// RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)
#define     AHB1LPENR_GPIOA_LPEN        0  
#define     AHB1LPENR_GPIOB_LPEN        1  
#define     AHB1LPENR_GPIOC_LPEN        2  
#define     AHB1LPENR_GPIOD_LPEN        3  
#define     AHB1LPENR_GPIOE_LPEN        4  
#define     AHB1LPENR_GPIOH_LPEN        7
#define     AHB1LPENR_CRC_LPEN          12
#define     AHB1LPENR_FLITF_LPEN        15
#define     AHB1LPENR_SRAM1_LPEN        16
#define     AHB1LPENR_DMA1_LPEN         21
#define     AHB1LPENR_DMA2_LPEN         22


#endif /* RCC_PRIVATE_H */
