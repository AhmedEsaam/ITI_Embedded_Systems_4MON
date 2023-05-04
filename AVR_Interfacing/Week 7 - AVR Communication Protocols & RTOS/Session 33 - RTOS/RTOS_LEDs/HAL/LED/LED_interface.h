/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LED_interface.c
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

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef struct 
{
	u8 LED_u8PORT;
	u8 LED_u8PIN;
}LED_t;

void LED_voidInit(LED_t* Copy_pLED_t_Obj);
void LED_voidTurnOn(LED_t* Copy_pLED_t_Obj);
void LED_voidTurnOff(LED_t* Copy_pLED_t_Obj);
void LED_voidToggle(LED_t* Copy_pLED_t_Obj);

#endif /* LED_INTERFACE_H */
