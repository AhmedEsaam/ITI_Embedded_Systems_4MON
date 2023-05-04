/*
 * ----------------------------------------------------------------------------------
 * Filename     :	UART_private.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 13, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		    Author		    	    Description
 * v1.2		    APR 13, 2023	Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


#define UDR               (*((volatile u8*) 0x2C))      // USART Data Register

#define UCSRA             (*((volatile u8*) 0x2B))      // USART Control and Status Register A   

#define UCSRA_MPCM        0                             // Multi-processor Communication Mod                            
#define UCSRA_U2X         1                             // Double the USART Transmission Speed
#define UCSRA_PE          2                             // Parity Error
#define UCSRA_DOR         3                             // Data OverRun
#define UCSRA_FE          4                             // Frame Error
#define UCSRA_UDRE        5                             // USART Data Register Empty
#define UCSRA_TXC         6                             // USART Transmit Complete
#define UCSRA_RXC         7                             // USART Receive Complete

#define UCSRB             (*((volatile u8*) 0x2A))      // USART Control and Status Register B    

#define UCSRB_TXBB        0                             // Transmit Data Bit 8
#define UCSRB_RXBB        1                             // Receive Data Bit 8
#define UCSRB_UCSZ2       2                             // Character Size
#define UCSRB_TXEN        3                             // Transmitter Enabl
#define UCSRB_RXEN        4                             // Receiver Enable
#define UCSRB_UDRIE       5                             // USART Data Register Empty Interrupt Enable
#define UCSRB_TXCIE       6                             // TX Complete Interrupt Enable
#define UCSRB_RXCIE       7                             // RX Complete Interrupt Enable

#define UCSRC             (*((volatile u8*) 0x40))      // USART Control and Status Register C  (Byte Accessable)  

#define UCSRC_UCPOL       0                             // Clock Polarity (Synchronous Mode)
#define UCSRC_UCSZ0       1                             // Character Size Bit 0
#define UCSRC_UCSZ1       2                             // Character Size Bit 1
#define UCSRC_USBS        3                             // Stop Bit Select
#define UCSRC_UPM0        4                             // Parity Mode Bit 0
#define UCSRC_UPM1        5                             // Parity Mode Bit 1
#define UCSRC_UMSEL       6                             // USART Mode Select
#define UCSRC_URSEL       7                             // Register Select (1: UCSRC, 0: UBRRH)

#define UBRRL             (*((volatile u8*) 0x29))      // USART Baud Rate Register Low      
#define UBRRH             (*((volatile u8*) 0x40))      // USART Baud Rate Register High      

#define UBRRH_URSEL       7                             // Register Select (1: UCSRC, 0: UBRRH)


#endif /* UART_PRIVATE_H */