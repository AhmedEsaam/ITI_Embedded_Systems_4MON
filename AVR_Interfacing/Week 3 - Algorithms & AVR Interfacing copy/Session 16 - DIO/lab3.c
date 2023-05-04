/*
 * ----------------------------------------------------------------------------------
 * Filename     :	main.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 22, 2023
 * Description	:	Blink a LED every 1 second
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 */

#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

void main(void)
{
	DIO_SetPinDirection(PORT_A, PIN0, OUTPUT);

	while(1)
	{
		DIO_TogglePin(PORT_A, PIN0);
		_delay_ms(1000);	// Wait for 1 Sec
	}
}
