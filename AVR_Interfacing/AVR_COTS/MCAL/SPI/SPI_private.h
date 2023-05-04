/*
 * ----------------------------------------------------------------------------------
 * Filename     :	SPI_private.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 17, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		    Author		    	    Description
 * v1.2		    APR 17, 2023	Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPDR             (*((volatile u8*) 0x2F))      // USART Control and Status Register A   

#define SPSR             (*((volatile u8*) 0x2E))      // USART Control and Status Register B    

#define SPSR_SPI2X       0                             // Transmit Data Bit 8
#define SPSR_WCOL        6                             // Receive Data Bit 8
#define SPSR_SPIF        7                             // Character Size

#define SPCR             (*((volatile u8*) 0x2D))      // USART Control and Status Register C  (Byte Accessable)  

#define SPCR_SPR0        0                             // Clock Polarity (Synchronous Mode)
#define SPCR_SPR1        1                             // Character Size Bit 0
#define SPCR_CPHA        2                             // Character Size Bit 1
#define SPCR_CPOL        3                             // Stop Bit Select
#define SPCR_MSTR        4                             // Parity Mode Bit 0
#define SPCR_DORD        5                             // Parity Mode Bit 1
#define SPCR_SPE         6                             // USART Mode Select
#define SPCR_SPIE        7                             // Register Select (1: SPCR, 0: UBRRH)


#endif /* SPI_PRIVATE_H */