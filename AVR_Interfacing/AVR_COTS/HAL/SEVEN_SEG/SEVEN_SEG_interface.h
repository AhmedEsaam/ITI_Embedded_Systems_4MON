/*
 * ----------------------------------------------------------------------------------
 * Filename     :	SEVEN_SEG_interface.c
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

#ifndef SEVEN_SEG_INTERFACE_H
#define SEVEN_SEG_INTERFACE_H

typedef struct 
{
	u8 SEVEN_SEG_u8PORT;
	u8 SEVEN_SEG_u8CONNECTION;
}SEVEN_SEG_t;

/* Connection Types */
#define COMMON_ANODE		0
#define COMMON_CATHODE		1

void SEVEN_SEG_voidInit(SEVEN_SEG_t* Copy_pSEVEN_SEG_t_Obj);
void SEVEN_SEG_voidSendDigit(SEVEN_SEG_t* Copy_pSEVEN_SEG_t_Obj, u8 Copy_u8Digit);
void SEVEN_SEG_voidClrDisplay(SEVEN_SEG_t* Copy_pSEVEN_SEG_t_Obj);
void SEVEN_SEG_voidSendCustomCharacter(SEVEN_SEG_t* Copy_pSEVEN_SEG_t_Obj, u8 Copy_u8CustomCharacter);

#endif /* SEVEN_SEG_INTERFACE_H */
