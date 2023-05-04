/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DIO_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 22, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_SetPinDirection(u8 reg, u8 pin, u8 dir)
{
	switch (reg)
	{
		case PORT_A:
			switch (dir)
			{
				case INPUT:
					CLR_BIT(DDRA, pin);
					break;
				case OUTPUT:
					SET_BIT(DDRA, pin);
					break;
				default:
					break;
			}
			break;

		case PORT_B:
			switch (dir)
			{
				case INPUT:
					CLR_BIT(DDRB, pin);
					break;
				case OUTPUT:
					SET_BIT(DDRB, pin);
					break;
				default:
					break;
			}
			break;

		case PORT_C:
			switch (dir)
			{
				case INPUT:
					CLR_BIT(DDRC, pin);
					break;
				case OUTPUT:
					SET_BIT(DDRC, pin);
					break;
				default:
					break;
			}
			break;

		case PORT_D:
			switch (dir)
			{
				case INPUT:
					CLR_BIT(DDRD, pin);
					break;
				case OUTPUT:
					SET_BIT(DDRD, pin);
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}
}

void DIO_SetPinValue(u8 reg, u8 pin, u8 val)
{
	switch (reg)
	{
		case PORT_A:
			switch (val)
			{
				case LOW:
					CLR_BIT(PORTA, pin);
					break;
				case HIGH:
					SET_BIT(PORTA, pin);
					break;
				default:
					break;
			}
			break;

		case PORT_B:
			switch (val)
			{
				case LOW:
					CLR_BIT(PORTB, pin);
					break;
				case HIGH:
					SET_BIT(PORTB, pin);
					break;
				default:
					break;
			}
			break;

		case PORT_C:
			switch (val)
			{
				case LOW:
					CLR_BIT(PORTC, pin);
					break;
				case HIGH:
					SET_BIT(PORTC, pin);
					break;
				default:
					break;
			}
			break;

		case PORT_D:
			switch (val)
			{
				case LOW:
					CLR_BIT(PORTD, pin);
					break;
				case HIGH:
					SET_BIT(PORTD, pin);
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}
}


void DIO_TogglePin(u8 reg, u8 pin)
{
	switch (reg)
	{
		case PORT_A:
			TOG_BIT(PORTA, pin);
			break;
		case PORT_B:
			TOG_BIT(PORTB, pin);
			break;
		case PORT_C:
			TOG_BIT(PORTC, pin);
			break;
		case PORT_D:
			TOG_BIT(PORTD, pin);
			break;
		default:
			break;
	}
}

u8 DIO_GetPinValue(u8 reg, u8 pin)
{
	return GET_BIT(reg, pin);
}

void DIO_SetPortDir(u8 reg, u8 dir)
{
	switch (reg)
	{
		case PORT_A:
			switch (dir)
			{
				case INPUT:
					CLR_REG(DDRA);
					break;
				case OUTPUT:
					SET_REG(DDRA, 0xFF);
					break;
				default:
					break;
			}
			break;

		case PORT_B:
			switch (dir)
			{
				case INPUT:
					CLR_REG(DDRB);
					break;
				case OUTPUT:
					SET_REG(DDRB, 0xFF);
					break;
				default:
					break;
			}
			break;

		case PORT_C:
			switch (dir)
			{
				case INPUT:
					CLR_REG(DDRC);
					break;
				case OUTPUT:
					SET_REG(DDRC, 0xFF);
					break;
				default:
					break;
			}
			break;

		case PORT_D:
			switch (dir)
			{
				case INPUT:
					CLR_REG(DDRD);
					break;
				case OUTPUT:
					SET_REG(DDRD, 0xFF);
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}
}

void DIO_SetPortValue(u8 reg, u8 val)
{
	switch (reg)
	{
		case PORT_A:
			SET_REG(PORTA, val);
			break;
		case PORT_B:
			SET_REG(PORTB, val);
			break;
		case PORT_C:
			SET_REG(PORTC, val);
			break;
		case PORT_D:
			SET_REG(PORTD, val);
			break;
		default:
			break;
	}
}

void DIO_ClrPortValue(u8 reg)
{
	switch (reg)
	{
		case PORT_A:
			CLR_REG(PORTA);
			break;
		case PORT_B:
			CLR_REG(PORTB);
			break;
		case PORT_C:
			CLR_REG(PORTC);
			break;
		case PORT_D:
			CLR_REG(PORTD);
			break;
		default:
			break;
	}
}

void DIO_SetLowerNibbleDir(u8 reg, u8 dir)
{
	switch (reg)
	{
		case PORT_A:
			switch (dir)
			{
				case INPUT:
					DDRA &= 0xF0;
					break;
				case OUTPUT:
					DDRA |= 0x0F;
					break;
				default:
					break;
			}
			break;

		case PORT_B:
			switch (dir)
			{
				case INPUT:
					DDRB &= 0xF0;
					break;
				case OUTPUT:
					DDRB |= 0x0F;
					break;
				default:
					break;
			}
			break;

		case PORT_C:
			switch (dir)
			{
				case INPUT:
					DDRC &= 0xF0;
					break;
				case OUTPUT:
					DDRC |= 0x0F;
					break;
				default:
					break;
			}
			break;

		case PORT_D:
			switch (dir)
			{
				case INPUT:
					DDRD &= 0xF0;
					break;
				case OUTPUT:
					DDRD |= 0x0F;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}
}

void DIO_SetLowerNibbleValue(u8 reg, u8 val)
{
	switch (reg)
	{
		case PORT_A:
			PORTA |= (0x0F & val);
			break;
		case PORT_B:
			PORTB |= (0x0F & val);
			break;
		case PORT_C:
			PORTC |= (0x0F & val);
			break;
		case PORT_D:
			PORTD |= (0x0F & val);
			break;
		default:
			break;
	}
}

void DIO_SetHigherNibbleDir(u8 reg, u8 dir)
{
	switch (reg)
	{
		case PORT_A:
			switch (dir)
			{
				case INPUT:
					DDRA &= 0x0F;
					break;
				case OUTPUT:
					DDRA |= 0xF0;
					break;
				default:
					break;
			}
			break;

		case PORT_B:
			switch (dir)
			{
				case INPUT:
					DDRB &= 0x0F;
					break;
				case OUTPUT:
					DDRB |= 0xF0;
					break;
				default:
					break;
			}
			break;

		case PORT_C:
			switch (dir)
			{
				case INPUT:
					DDRC &= 0x0F;
					break;
				case OUTPUT:
					DDRC |= 0xF0;
					break;
				default:
					break;
			}
			break;

		case PORT_D:
			switch (dir)
			{
				case INPUT:
					DDRD &= 0x0F;
					break;
				case OUTPUT:
					DDRD |= 0xF0;
					break;
				default:
					break;
			}
			break;

		default:
			break;
	}
}
void DIO_SetHigherNibbleValue(u8 reg, u8 val)
{
	switch (reg)
	{
		case PORT_A:
			PORTA |= (0xF0 & val);
			break;
		case PORT_B:
			PORTB |= (0xF0 & val);
			break;
		case PORT_C:
			PORTC |= (0xF0 & val);
			break;
		case PORT_D:
			PORTD |= (0xF0 & val);
			break;
		default:
			break;
	}

}
