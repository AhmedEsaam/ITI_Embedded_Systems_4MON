/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LED_program.c
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

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


void LED_voidInit(LED_t* Copy_pLED_t_Obj)
{
	MDIO_voidSetPinDir(Copy_pLED_t_Obj->LED_u8PORT, Copy_pLED_t_Obj->LED_u8PIN, OUTPUT);
}
void LED_voidTurnOn(LED_t* Copy_pLED_t_Obj)
{
	MDIO_voidSetPinValue(Copy_pLED_t_Obj->LED_u8PORT, Copy_pLED_t_Obj->LED_u8PIN, HIGH);
}
void LED_voidTurnOff(LED_t* Copy_pLED_t_Obj)
{
	MDIO_voidSetPinValue(Copy_pLED_t_Obj->LED_u8PORT, Copy_pLED_t_Obj->LED_u8PIN, LOW);
}
void LED_voidToggle(LED_t* Copy_pLED_t_Obj)
{
	MDIO_voidTogglePinValue(Copy_pLED_t_Obj->LED_u8PORT, Copy_pLED_t_Obj->LED_u8PIN);
}



