/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Assignment_2_LED_String_Animations.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 25, 2023
 * Description	:	LED String 8 Different Animations By Dip Switch 
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
	u8 Local_u8DipSwitchValue;
	u8 Local_u8LEDStringValue;
	u8 Local_u8LEDStringRightNibble;
	u8 Local_u8LEDStringLeftNibble;
	u8 Local_u8PingPongFlag = 'L'; /* Shift Left */
	u8 Local_u8ConvergingDiverging = 'C'; /* First Converging */
	u8 Local_u8SnakeValue = 0;
	u8 Local_u8SnakeCounter = 0;
	/* String Of 8 LEDs */
	MDIO_voidSetPortDir(DIO_PORT_A, OUTPUT);
	/* 3-Way Dip Switch As Input */
	MDIO_voidSetPinDir(DIO_PORT_D, PIN0, INPUT_PULLUP);
	MDIO_voidSetPinDir(DIO_PORT_D, PIN1, INPUT_PULLUP);
	MDIO_voidSetPinDir(DIO_PORT_D, PIN2, INPUT_PULLUP);

	while(1)
	{
		MDIO_voidGetPortValue(DIO_PORT_D, &Local_u8DipSwitchValue);
		switch (Local_u8DipSwitchValue & 0x07)
		{
		case 0:
			/* Flashing Every 500 ms */
			MDIO_voidTogglePortValue(DIO_PORT_A);
			_delay_ms(500);
			break;

		case 1:
			/* Shifting Left Every 250 ms */
			if(Local_u8LEDStringValue == 0)
			{
				Local_u8LEDStringValue = 1;
			}
			MDIO_voidSetPortValue(DIO_PORT_A, ~Local_u8LEDStringValue);
			Local_u8LEDStringValue = Local_u8LEDStringValue << 1;
			
			_delay_ms(250);
			break;

		case 2:
			/* Shifting Right Every 250 ms */
			if(Local_u8LEDStringValue == 0)
			{
				Local_u8LEDStringValue = 128;
			}
			MDIO_voidSetPortValue(DIO_PORT_A, ~Local_u8LEDStringValue);
			Local_u8LEDStringValue = Local_u8LEDStringValue >> 1;
			
			_delay_ms(250);
			break;

		case 3:
			/* 2-LEDs Converging every 300 ms */
			if(Local_u8LEDStringRightNibble > 15 || Local_u8LEDStringRightNibble == 0)
			{
				Local_u8LEDStringRightNibble = 1;
			}
			if(Local_u8LEDStringLeftNibble < 16 || Local_u8LEDStringLeftNibble == 0)
			{
				Local_u8LEDStringLeftNibble = 128;
			}
			Local_u8LEDStringValue = (Local_u8LEDStringRightNibble & 0x0F) | (Local_u8LEDStringLeftNibble & 0xF0);
			MDIO_voidSetPortValue(DIO_PORT_A, ~Local_u8LEDStringValue);
			Local_u8LEDStringRightNibble = (Local_u8LEDStringRightNibble << 1);
			Local_u8LEDStringLeftNibble = (Local_u8LEDStringLeftNibble >> 1);
			_delay_ms(300);
			break;

		case 4:
			/* 2-LEDs Diverging every 300 ms */
			if(Local_u8LEDStringRightNibble == 0)
			{
				Local_u8LEDStringRightNibble = 8;
			}
			if(Local_u8LEDStringLeftNibble == 0)
			{
				Local_u8LEDStringLeftNibble = 16;
			}
			Local_u8LEDStringValue = (Local_u8LEDStringRightNibble & 0x0F) | (Local_u8LEDStringLeftNibble & 0xF0);
			MDIO_voidSetPortValue(DIO_PORT_A, ~Local_u8LEDStringValue);
			Local_u8LEDStringRightNibble = (Local_u8LEDStringRightNibble >> 1);
			Local_u8LEDStringLeftNibble = (Local_u8LEDStringLeftNibble << 1);
			_delay_ms(300);
			break;
		
		case 5:
			/* Ping Pong Effect Every 250 ms */
			switch (Local_u8PingPongFlag)
			{
			case 'L':
				if(Local_u8LEDStringValue == 0)
				{
					Local_u8LEDStringValue = 1;
				}
				MDIO_voidSetPortValue(DIO_PORT_A, ~Local_u8LEDStringValue);
				Local_u8LEDStringValue = Local_u8LEDStringValue << 1;
				if(Local_u8LEDStringValue == 128)
				{
					Local_u8PingPongFlag = 'R'; /* Shift Right */
				}
				break;
			case 'R':
				if(Local_u8LEDStringValue == 0)
				{
					Local_u8LEDStringValue = 128;
				}
				MDIO_voidSetPortValue(DIO_PORT_A, ~Local_u8LEDStringValue);
				Local_u8LEDStringValue = Local_u8LEDStringValue >> 1;
				if(Local_u8LEDStringValue == 1)
				{
					Local_u8PingPongFlag = 'L'; /* Shift Left */
				}
				break;
			
			default:
				break;
			}
			_delay_ms(250);
			break;

		case 6:
			/* Incrementing (Snake effect) every 300 ms */
			if(Local_u8LEDStringValue == 0)
			{
				Local_u8SnakeValue |= (1<<Local_u8SnakeCounter); // Increment Snake Length
				Local_u8LEDStringValue = Local_u8SnakeValue;
				Local_u8SnakeCounter++;
			}
			MDIO_voidSetPortValue(DIO_PORT_A, ~Local_u8LEDStringValue);
			Local_u8LEDStringValue = Local_u8LEDStringValue << 1;
			
			_delay_ms(250);
			break;

		case 7:
			switch (Local_u8ConvergingDiverging)
			{
			case 'C':
				/* 2-LEDs Converging/Diverging every 300 ms */
				if(Local_u8LEDStringRightNibble > 15 || Local_u8LEDStringRightNibble == 0)
				{
					Local_u8LEDStringRightNibble = 1;
				}
				if(Local_u8LEDStringLeftNibble < 16 || Local_u8LEDStringLeftNibble == 0)
				{
					Local_u8LEDStringLeftNibble = 128;
				}
				Local_u8LEDStringValue = (Local_u8LEDStringRightNibble & 0x0F) | (Local_u8LEDStringLeftNibble & 0xF0);
				MDIO_voidSetPortValue(DIO_PORT_A, ~Local_u8LEDStringValue);
				Local_u8LEDStringRightNibble = (Local_u8LEDStringRightNibble << 1);
				Local_u8LEDStringLeftNibble = (Local_u8LEDStringLeftNibble >> 1);
				if(Local_u8LEDStringRightNibble == 8)
				{
					Local_u8ConvergingDiverging = 'D'; /* Diverging */
				}
				break;

			case 'D':
				/* 2-LEDs Diverging every 300 ms */
				if(Local_u8LEDStringRightNibble == 0)
				{
					Local_u8LEDStringRightNibble = 8;
				}
				if(Local_u8LEDStringLeftNibble == 0)
				{
					Local_u8LEDStringLeftNibble = 16;
				}
				Local_u8LEDStringValue = (Local_u8LEDStringRightNibble & 0x0F) | (Local_u8LEDStringLeftNibble & 0xF0);
				MDIO_voidSetPortValue(DIO_PORT_A, ~Local_u8LEDStringValue);
				Local_u8LEDStringRightNibble = (Local_u8LEDStringRightNibble >> 1);
				Local_u8LEDStringLeftNibble = (Local_u8LEDStringLeftNibble << 1);
				if(Local_u8LEDStringRightNibble == 1)
				{
					Local_u8ConvergingDiverging = 'C'; /* Converging */
				}
				break;

			default:
				break;
			}
			
			_delay_ms(300);
			break;

		default:
			break;
		}
		
	}
}
