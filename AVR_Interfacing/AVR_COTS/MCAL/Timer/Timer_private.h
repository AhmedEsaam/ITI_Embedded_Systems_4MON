/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Timer_private.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 9, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 9, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

// Clock Selection
#define     DIVISION_FACTOR_8           0b00000010
#define     DIVISION_FACTOR_32          0b00000101
#define     DIVISION_FACTOR_64          0b00000110
#define     DIVISION_FACTOR_128         0b00000111

#define     CLK_SEL_BIT_MASK            0b11111000


/*------------------------------------------ Timer0 Registers ------------------------------------------*/
#define TCCR0               (*((volatile u8*) 0x53))    // Timer/Counter Control Register
// Clock Select Bit 
#define TCCR0_CS00          0
#define TCCR0_CS01          1
#define TCCR0_CS02          2
// Mode
#define TCCR0_WGM00         6
#define TCCR0_WGM01         3

#define TCNT0               (*((volatile u8*) 0x52))    // Timer/Counter Register
#define OCR0                (*((volatile u8*) 0x5C))    // Output Compare Register

#define TIMSK               (*((volatile u8*) 0x59))    // Timer/Counter Interrupt Mask Register (Interrupt Enable)
#define TIMSK_TOIE0         0
#define TIMSK_OCIE0         1

#define TIFR                (*((volatile u8*) 0x58))    // Timer/Counter Interrupt Flag Register
#define TIFR_TOV0           0
#define TIFR_OCF0           1


#endif /* TIMER_PRIVATE_H */