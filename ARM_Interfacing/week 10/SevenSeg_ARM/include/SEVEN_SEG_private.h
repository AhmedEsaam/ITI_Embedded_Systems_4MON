/*
 * ----------------------------------------------------------------------------------
 * Filename     :	SEVEN_SEG_private.c
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

#ifndef SEVEN_SEG_PRIVATE_H
#define SEVEN_SEG_PRIVATE_H

/* Numbers Display Configuration for The 7 Segment Display (Common Anode)*/
#define NUM_0_COM_ANDOE     0x40
#define NUM_1_COM_ANDOE     0x79
#define NUM_2_COM_ANDOE     0x24
#define NUM_3_COM_ANDOE     0x30
#define NUM_4_COM_ANDOE     0x19
#define NUM_5_COM_ANDOE     0x12
#define NUM_6_COM_ANDOE     0x02
#define NUM_7_COM_ANDOE     0x78
#define NUM_8_COM_ANDOE     0x00
#define NUM_9_COM_ANDOE     0x10

#define ALL_OFF_COM_ANODE   0xFF

/* Numbers Display Configuration for The 7 Segment Display (Common Cathode)*/
#define NUM_1_COM_CATHODE   0x06
#define NUM_2_COM_CATHODE   0x5B
#define NUM_0_COM_CATHODE   0x3F
#define NUM_3_COM_CATHODE   0x4F
#define NUM_4_COM_CATHODE   0x66
#define NUM_5_COM_CATHODE   0x6D
#define NUM_6_COM_CATHODE   0x7D
#define NUM_7_COM_CATHODE   0x27
#define NUM_8_COM_CATHODE   0x7F
#define NUM_9_COM_CATHODE   0x6F



#endif /* SEVEN_SEG_PRIVATE_H */
