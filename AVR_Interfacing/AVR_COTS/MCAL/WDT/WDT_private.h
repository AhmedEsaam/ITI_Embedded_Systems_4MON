/*
 * ----------------------------------------------------------------------------------
 * Filename     :	WDT_private.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 12, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		    Author		    	    Description
 * v1.2		    APR 12, 2023	Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

// #define SLEEP_16_3_MS       0b000
/*------------------------------------- WDT Register --------------------------------------*/

#define WDTCR               (*((volatile u8*) 0x41))    // WatchDog Timer Counter Register
#define WDTCR_WDP0          0                           // WatchDog Timer Prescaler Bit 0
#define WDTCR_WDP1          1                           // WatchDog Timer Prescaler Bit 1
#define WDTCR_WDP2          2                           // WatchDog Timer Prescaler Bit 2
#define WDTCR_WDE           3                           // WatchDog Timer Enable Bit
#define WDTCR_WDTOE         4                           // WatchDog Timer Turn-Off Enable Bit

#endif /* WDT_PRIVATE_H */