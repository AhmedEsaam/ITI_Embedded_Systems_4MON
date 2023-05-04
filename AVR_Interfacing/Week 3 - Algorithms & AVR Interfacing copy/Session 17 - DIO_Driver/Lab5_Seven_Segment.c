/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Lab5_Seven_Segment.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 25, 2023
 * Description	:	Display 0 -> 9 On A Seven-Segment
 * Version      :	v1.1
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 22, 2023		Ahmed Essam El-Mogy		Adding Main Algorithm
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
	MDIO_voidSetPortDir(DIO_PORT_D, OUTPUT);

	u8 Local_u8SevenSegmentValues[10] =
	{
		0b01111110, //0
		0b00110000, //1
		0b01101101, //2
		0b01111001, //3
		0b00110011, //4
		0b01011011, //5
		0b01011111, //6
		0b01110000, //7
		0b01111111, //8
		0b01111011  //9
	};
	while(1)
	{
		u8 Local_u8Counter;
		for(Local_u8Counter = 0; Local_u8Counter < 10; Local_u8Counter++)
		{
			MDIO_voidSetPortValue(DIO_PORT_D, Local_u8SevenSegmentValues[Local_u8Counter]);
			_delay_ms(1000);
		}

	}
}
