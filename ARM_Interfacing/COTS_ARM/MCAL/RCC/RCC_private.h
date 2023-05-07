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

#define     RCC_BASE_ADDRESS            0x40023800

#define     RCC                         ((volatile RCC_t *)RCC_BASE_ADDRESS)


/*---------------------------- Clock ----------------------------*/

// RCC clock control register (RCC_CR)
// HSI
#define     CR_HSION                    0  
#define     CR_HSIRDY                   1  
#define     CR_HSITRIM_BIT_MASK         0xffffff07  
#define     CR_HSICAL_BIT_MASK          0xffff00ff
// HSE  
#define     CR_HSEON                    16  
#define     CR_HSERDY                   17  
#define     CR_HSEBYP                   18
#define     CR_CSSON                    19
// PLL
#define     CR_PLLON                    24  
#define     CR_PLLRDY                   25  
#define     CR_PLLI2SON                 26  
#define     CR_PLLI2SRDY                27

// RCC PLL configuration register (RCC_PLLCFGR)
#define     PLLCFGR_PLLM_BIT_MASK       0xffffffc0
#define     PLLCFGR_PLLN_BIT_MASK       0xffff803f
#define     PLLCFGR_PLLP_BIT_MASK       0xfffcffff
#define     PLLCFGR_PLLSRC              22
#define     PLLCFGR_PLLQ_BIT_MASK       0xf0ffffff

// RCC clock configuration register (RCC_CFGR)
#define     CFGR_SW_BIT_MASK            0xfffffffc
#define     CFGR_SWS_BIT_MASK           0xfffffff3
#define     CFGR_HPRE_BIT_MASK          0xffffff0f
#define     CFGR_PPRE1_BIT_MASK         0xffffe3ff
#define     CFGR_PPRE2_BIT_MASK         0xffff1fff
#define     CFGR_RTCPRE_BIT_MASK        0xffe0ffff
#define     CFGR_MCO1_BIT_MASK          0xff9fffff
#define     CFGR_MCO1_PRE_BIT_MASK      0xf8ffffff
#define     CFGR_MCO2_BIT_MASK          0x3fffffff
#define     CFGR_MCO2_PRE_BIT_MASK      0xc7ffffff
#define     CFGR_I2SSCR                 23

// APB high-speed prescaler (APB1 and APB2)
#define     APB1_2_DIVIDE_BY_2          0b100
#define     APB1_2_DIVIDE_BY_4          0b101
#define     APB1_2_DIVIDE_BY_8          0b110
#define     APB1_2_DIVIDE_BY_16         0b111

// AHB prescaler
#define     SYSCLOCK_DIVIDE_BY_1        0b0000
#define     SYSCLOCK_DIVIDE_BY_2        0b1000
#define     SYSCLOCK_DIVIDE_BY_4        0b1001
#define     SYSCLOCK_DIVIDE_BY_8        0b1010
#define     SYSCLOCK_DIVIDE_BY_16       0b1011

// RCC clock interrupt register (RCC_CIR)
// Ready Interrupt Falgs
#define     CIR_LSIRDYF                 0
#define     CIR_LSERDYF                 1
#define     CIR_HSIRDYF                 2
#define     CIR_HSERDYF                 3
#define     CIR_PLLRDYF                 4
#define     CIR_PLLI2SRDYF              5
// Ready Interrupt Enable
#define     CIR_LSIRDYIE                8
#define     CIR_LSERDYIE                9
#define     CIR_HSIRDYIE                10
#define     CIR_HSERDYIE                11
#define     CIR_PLLRDYIE                12
#define     CIR_PLLI2SRDYIE             13
// Ready Interrupt Clear
#define     CIR_LSIRDYC                 16
#define     CIR_LSERDYC                 17
#define     CIR_HSIRDYC                 18
#define     CIR_HSERDYC                 19
#define     CIR_PLLRDYC                 20
#define     CIR_PLLI2SRDYC              21
// Clock Security System Interrupt Flag
#define     CIR_CSSF                    7
// Clock security system interrupt clear
#define     CIR_CSSC                    23



/*----------------------------- AHB1 ----------------------------*/

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