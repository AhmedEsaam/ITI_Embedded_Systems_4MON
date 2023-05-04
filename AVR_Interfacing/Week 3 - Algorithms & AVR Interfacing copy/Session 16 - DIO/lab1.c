/*
 * ----------------------------------------------------------------------------------
 * Filename     :	main.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 22, 2023
 * Description	:	Write a code to turn on LED on Pin A0
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
	DIO_SetPinValue(PORT_A, PIN0, HIGH);
}
