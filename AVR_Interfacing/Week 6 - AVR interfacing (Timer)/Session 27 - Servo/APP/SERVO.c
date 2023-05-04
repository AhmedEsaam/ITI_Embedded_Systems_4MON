// /*
//  * ----------------------------------------------------------------------------------
//  * Filename     :	LED_BLINK.c
//  *
//  * Author       :	Ahmed Essam El-Mogy
//  * Created on   :	APR 10, 2023
//  * Version      :	v1.0
//  * C Standard   :	C99
//  * Compiler     :	AVR GCC
//  * ----------------------------------------------------------------------------------
//  *
//  * ----------------------------------------------------------------------------------
//  * Version		Date 		        Author			        Description
//  * v1.0		    APR 10, 2023		Ahmed Essam El-Mogy		Initial Creation
//  * ----------------------------------------------------------------------------------
//  */

// #include "../LIB/STD_TYPES.h"

// #include "util/delay.h"

// #include "../MCAL/DIO/DIO_interface.h"
// #include "../MCAL/ADC/ADC_interface.h"
// #include "../MCAL/Timer/Timer_interface.h"

// #include "../HAL/LED/LED_interface.h"

// void main(void)
// {
// 	TIMER1_voidInit();
// 	MDIO_voidSetPinDir(DIO_PORT_D, PIN5, OUTPUT);
// 	TIMER1_coidSetICR1Value(20000);
// 	while(1)
// 	{
// 		TIMER1_coidSetOCR1AValue(1000);

// 	}
// }
