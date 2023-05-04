/*
 * ----------------------------------------------------------------------------------
 * Filename     :	GIE_private.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 28, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 28, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef GIE_PRIVATE_H
#define GIE_PRIVATE_H

#define SREG            *((volatile u8*) 0x5F)

#define SREG_BIT7       7    /* Global Interrupt */


#endif /* GIE_PRIVATE_H */