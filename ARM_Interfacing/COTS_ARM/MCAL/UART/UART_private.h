/*
 * ----------------------------------------------------------------------------------
 * Filename		:	UART_private.h
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	JUN 6, 2023
 * Version		:	v1.0
 * C Standard	:	C99
 * Compiler		:	GNU ARM GCC
 * Controller	:	STM32F401CCU6 (32-bit Architecture)
 * Layer		:	MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version 		Date 				Author 						Describtion
 * v1.0 		JUN 6, 2023 		Ahmed Essam El-Mogy 		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

typedef struct
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GTPR;
}UART_t;

#define     UART_BASE_ADDRESS        0x40011000 

#define     UART                     ((volatile UART_t *)UART_BASE_ADDRESS)

// UART Status Register (SR)
#define     PE                       0
#define     FE                       1
#define     NF                       2
#define     ORE                      3
#define     IDLE                     4
#define     RXNE                     5
#define     TC                       6
#define     TXE                      7
#define     LBD                      8
#define     CTS                      9
         
// UART Baud Rate Register (BRR)
#define     DIV_Fraction_MASK        0xf
#define     DIV_Mantissa_MASK        0xfff0
#define     DIV_Mantissa_LOCATION    4
         
// UART Control Register 1 (CR1)
#define     SBK                      0
#define     RWU                      1
#define     RE                       2
#define     TE                       3
#define     IDLEIE                   4
#define     RXNEIE                   5
#define     TCIE                     6
#define     TXEIE                    7
#define     PEIE                     8
#define     PS                       9
#define     PCE                      10
#define     WAKE                     11
#define     M                        12
#define     UE                       13
#define     OVER8                    15
         
         
// UART Control Register 2 (CR2)
#define     ADD_MASK                 0xf
#define     LBDL                     5
#define     LBDIE                    6
#define     LBCL                     8
#define     CPHA                     9
#define     CPOL                     10
#define     CLKEN                    11
#define     STOP_MASK                0x3000          
#define     STOP_LOCATION            12          
#define     LINEN                    14
         
// UART Control Register 3 (CR3)
#define     EIE                      0
#define     IREN                     1
#define     URLP                     2
#define     HDSEL                    3
#define     NACK                     4
#define     SCEN                     5
#define     DMAR                     6
#define     DMAT                     7
#define     RTSE                     8
#define     CTSE                     9
#define     CTSIE                    10
#define     ONEBIT                   11
         
// UART Guard Time and Prescaler Register (GTPR)
#define     PSC_MASK                 0xf
#define     GT_MASK                  0xfff0


#endif /* UART_PRIVATE_H_ */