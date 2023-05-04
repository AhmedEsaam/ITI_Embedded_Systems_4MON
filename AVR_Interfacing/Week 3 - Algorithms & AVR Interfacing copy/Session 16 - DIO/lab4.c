/*
 * ----------------------------------------------------------------------------------
 * Filename     :	main.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 25, 2023
 * Description	:	Apply LED animation -> LEDs blink sequentially
 * Version      :	v1.1
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 22, 2023		Ahmed Essam El-Mogy		Adding Main Algorithm
 * v1.1		    MAR 25, 2023		Ahmed Essam El-Mogy		Editing Naming Conventions
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
	MDIO_voidSetPortDir(DIO_PORT_A, OUTPUT);
	u8 Local_u8PinNumber;
	Local_u8PinNumber = PIN0;
	while(1)
	{
		MDIO_ClrPortValue(DIO_PORT_A);
		MDIO_voidTogglePinValue(DIO_PORT_A, Local_u8PinNumber);
		Local_u8PinNumber = (Local_u8PinNumber + 1) % 8;
		_delay_ms(500);	// Wait for 0.5 Sec
	}
}
