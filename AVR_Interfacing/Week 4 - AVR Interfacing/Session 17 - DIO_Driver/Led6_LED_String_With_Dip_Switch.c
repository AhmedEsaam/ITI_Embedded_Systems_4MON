/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Led6_LED_String_With_Dip_Switch.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 25, 2023
 * Description	:	LED String With Dip Switch
 * Version      :	v1.1
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 25, 2023		Ahmed Essam El-Mogy		Adding Main Algorithm
 * ----------------------------------------------------------------------------------
 */

/* Libraries */
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/* Lower Layers */
#include "../MCAL/DIO/DIO_interface.h"

void main(void)
{
	MDIO_voidSetPortDir(DIO_PORT_A, OUTPUT); /* LEDs */
	MDIO_voidSetPinDir(DIO_PORT_D, PIN0, INPUT_PULLUP); /* Dip Switch */
	
	while(1)
	{
		u8 Local_u8PinValue;
		MDIO_voidGetPinValue(DIO_PORT_D, PIN0, &Local_u8PinValue);
		if(Local_u8PinValue == HIGH)
		{
			MDIO_voidTogglePortValue(DIO_PORT_A);
			_delay_ms(500);
		}
		else if(Local_u8PinValue == LOW)
		{
			MDIO_voidClrPortValue(DIO_PORT_A);
		}
	}
}
