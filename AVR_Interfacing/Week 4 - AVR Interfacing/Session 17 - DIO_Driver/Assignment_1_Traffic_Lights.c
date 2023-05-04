/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Assignment_1_Traffic_Lights.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 25, 2023
 * Description	:	Traffic Lights With Seven-Segment Counter Displays
 * Version      :	v1.0
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
	/* Two Seven Segment Display Pins (Common Anode)*/
	MDIO_voidSetPortDir(DIO_PORT_C, OUTPUT);
	MDIO_voidSetPortDir(DIO_PORT_D, OUTPUT);

	/* Traffic Lights */
	MDIO_voidSetPinDir(DIO_PORT_A, PIN0, OUTPUT); 	/* Red Light */
	MDIO_voidSetPinDir(DIO_PORT_A, PIN1, OUTPUT); 	/* Yellow Light */
	MDIO_voidSetPinDir(DIO_PORT_A, PIN2, OUTPUT); 	/* Green Light */

	u8 Local_u8SevenSegmentValues[10] =
	{
		0b01000000, //0
		0b01111001, //1
		0b00100100, //2
		0b00110000, //3
		0b00011001, //4
		0b00010010, //5
		0b00000010, //6
		0b01111000, //7
		0b00000000, //8
		0b00010000, //9
	};

	u8 Local_u8DownCounter = 10;	/* 10 Seconds */
	u8 Local_u8TrafficLight = 'G'; 	/* Start With Green Light */
	
	while(1)
	{
		MDIO_voidClrPortValue(DIO_PORT_A);
		MDIO_voidSetPortValue(DIO_PORT_C, Local_u8SevenSegmentValues[Local_u8DownCounter/10]);
		MDIO_voidSetPortValue(DIO_PORT_D, Local_u8SevenSegmentValues[Local_u8DownCounter%10]);
		Local_u8DownCounter--;

		switch (Local_u8TrafficLight)
		{
		case 'G':
			MDIO_voidSetPinValue(DIO_PORT_A, PIN0, HIGH);
			if(Local_u8DownCounter == 0)
			{
				Local_u8TrafficLight = 'Y';
				Local_u8DownCounter = 5;
			}
			break;
		case 'Y':
			MDIO_voidSetPinValue(DIO_PORT_A, PIN1, HIGH);
			if(Local_u8DownCounter == 0)
			{
				Local_u8TrafficLight = 'R';
				Local_u8DownCounter = 10;
			}
			break;
		case 'R':
			MDIO_voidSetPinValue(DIO_PORT_A, PIN2, HIGH);
			if(Local_u8DownCounter == 0)
			{
				Local_u8TrafficLight = 'G';
				Local_u8DownCounter = 10;
			}
			break;
		
		default:
			break;
		}

		_delay_ms(1000);
	}
}
