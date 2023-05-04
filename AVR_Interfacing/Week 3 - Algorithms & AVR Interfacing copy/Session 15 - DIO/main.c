/*
 * ----------------------------------------------------------------------------------
 * Filename     :	main.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 21, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 */

#include <avr/io.h>
#include <util/delay.h>


void main(void)
{
	// Pin 4 - PortA -> Output, 5v
	DDRA = 0b00010000;	// Pin 4 Output Pin

	while(1)
	{
		PORTA = 0b00010000;	// Pin 4 High (5v)
		_delay_ms(1000);	// Wait for 1 Sec
		PORTA = 0b00000000;	// Pin 4 Low  (0v)
		_delay_ms(1000);	// Wait for 1 Sec
	}
}
