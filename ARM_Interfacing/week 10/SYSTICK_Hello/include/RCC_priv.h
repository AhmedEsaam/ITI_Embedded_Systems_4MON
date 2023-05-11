#ifndef RCC_PRIV_H
#define RCC_PRIV_H

//#define RCC_BASE_ADD       *((u32*)0x40023800)

#define RCC_CR               *((u32*)0x40023800)
#define RCC_PLLCFGR          *((u32*)0x40023804)
#define RCC_CFGR             *((u32*)0x40023808)
#define RCC_CIR              *((u32*)0x40023812)
#define RCC_AHB1RSTR         *((u32*)0x40023816)
#define RCC_AHB2RSTR         *((u32*)0x40023820)
#define RCC_APB1RSTR         *((u32*)0x40023824)
#define RCC_APB2RSTR         *((u32*)0x40023828)
#define RCC_AHB1ENR           *((u32*)0x40023832)
#define RCC_AHB2ENR           *((u32*)0x40023836)
#define RCC_APB1ENR          *((u32*)0x40023840)
#define RCC_APB2ENR          *((u32*)0x40023844)
#define RCC_AHB1LPENR        *((u32*)0x40023848)
#define RCC_AHB2LPENR         *((u32*)0x40023852)
#define RCC_APB1LPENR         *((u32*)0x40023856)
#define RCC_APB2LPENR		   *((u32*)0x40023860)
#define RCC_BDCR             *((u32*)0x40023864)
#define RCC_CSR              *((u32*)0x40023868)
#define RCC_SSCGR           *((u32*)0x40023872)
#define RCC_PLLI2SCFGR      *((u32*)0x40023876)
#define RCC_DCKCFGR			*((u32*)0x40023880)

#define  RCC_HSE_RC             0
#define  RCC_HSE_CRYSTAL        1
#define  RCC_HSI                2
#define  RCC_PLL                3

#define  PLL_HSE                0
#define  PLL_HSI                1

/*Prescaler for AHB System Clock*/
#define system_clock_not_divided                0000
#define system_clock_divided_by_2               1000
#define system_clock_divided_by_4               1001
#define system_clock_divided_by_8               1010
#define system_clock_divided_by_16              1011
#define system_clock_divided_by_64              1100
#define system_clock_divided_by_128             1101
#define system_clock_divided_by_256             1110
#define system_clock_divided_by_512             1111

/*Prescaler for APB1 System Clock*/
#define AHB_clock_not_divided      000
#define AHB_clock_divided_by_2     100
#define AHB_clock_divided_by_4     101
#define AHB_clock_divided_by_8     110
#define AHB_clock_divided_by_16    111

#endif // RCC_PRIV_H
