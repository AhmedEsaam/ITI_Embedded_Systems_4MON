/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Za3bola.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 26, 2023
 * Description	:	
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 26, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

/* Libraries */
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/* Lower Layers */
#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/DIO/DIO_interface.h"

u8 Copy_pu8Za3bolaWaving1[] = 
{
0x0C,
  0x15,
  0x0E,
  0x04,
  0x04,
  0x0A,
  0x11,
  0x00
};

u8 Copy_pu8Za3bolaWaving2[] = 
{
	0x0C,
  0x04,
  0x0E,
  0x15,
  0x04,
  0x0A,
  0x11,
  0x00
};

u8 Copy_pu8Za3bolaFootball1[] = 
{
	0x0C,
  0x04,
  0x0E,
  0x0D,
  0x04,
  0x1A,
  0x11,
  0x00
};

u8 Copy_pu8Za3bolaFootball2[] = 
{
	0x0C,
  0x04,
  0x0E,
  0x0D,
  0x14,
  0x0A,
  0x11,
  0x00
};
u8 Copy_pu8Za3bolaFootball3[] = 
{
	0x0C,
  0x04,
  0x0E,
  0x1D,
  0x04,
  0x0A,
  0x11,
  0x00
};
u8 Copy_pu8Za3bolaFootball4[] = 
{
	0x0C,
  0x04,
  0x1E,
  0x0D,
  0x04,
  0x0A,
  0x11,
  0x00
};
u8 Copy_pu8Za3bolaFootball5[] = 
{
	0x0C,
  0x14,
  0x0E,
  0x0D,
  0x04,
  0x0A,
  0x11,
  0x00
};
u8 Copy_pu8Za3bolaFootball6[] = 
{
	0x1C,
  0x04,
  0x0E,
  0x0D,
  0x04,
  0x0A,
  0x11,
  0x00
};

u8 Copy_pu8AngryFace1[] = 
{
	 0x02,
  0x04,
  0x08,
  0x04,
  0x0A,
  0x0A,
  0x04,
  0x00
};

u8 Copy_pu8AngryFace2[] = 
{
0x08,
  0x04,
  0x02,
  0x04,
  0x0A,
  0x0A,
  0x04,
  0x00
};

u8 Copy_pu8AngryFace3[] = 
{
	 0x02,
  0x04,
  0x18,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00
};

u8 Copy_pu8AngryFace4[] = 
{
0x08,
  0x04,
  0x03,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00
};

u8 Copy_pu8Gun1[] = 
{
0x00,
  0x07,
  0x0F,
  0x1A,
  0x1E,
  0x18,
  0x18,
  0x18
};
u8 Copy_pu8Gun2[] = 
{
0x00,
  0x1F,
  0x1F,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00
};

u8 Copy_pu8Killed1[] = 
{
0x00,
  0x00,
  0x00,
  0x00,
  0x10,
  0x0B,
  0x1F,
  0x1C
};
u8 Copy_pu8Killed2[] = 
{
0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x1F,
  0x1F
};

void main(void)
{
	LCD_voidInit();

	/* My name is Za3bola */
	LCD_voidGoToXY(0, 0);
	LCD_voidSendString("My name is");
	LCD_voidGoToXY(1, 0);
	LCD_voidSendString("Za3bola!");
	u8 counter;
	for(counter = 0; counter < 5; counter++)
	{
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaWaving1, 0, 1, 15);
		_delay_ms(200);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaWaving2, 1, 1, 15);
		_delay_ms(200);
	}
	

	/* I can play football */
	LCD_voidClearDisplay();
	LCD_voidGoToXY(0, 0);
	LCD_voidSendString("I can play");
	LCD_voidGoToXY(1, 0);
	LCD_voidSendString("football");
	for(counter = 0; counter < 4; counter++)
	{
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball1, 3, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball2, 4, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball3, 5, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball4, 6, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball5, 7, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball6, 0, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball5, 7, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball4, 6, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball3, 5, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball2, 4, 1, 15);
		_delay_ms(30);
		LCD_voidSendCustomCharacter(Copy_pu8Za3bolaFootball1, 3, 1, 15);
		_delay_ms(30);
	}

	/* Let's play a Game */
	LCD_voidClearDisplay();
	LCD_voidGoToXY(0, 0);
	LCD_voidSendString("Let's play a");
	LCD_voidGoToXY(1, 0);
	LCD_voidSendString("Game!");
	LCD_voidSendCustomCharacter(Copy_pu8AngryFace1, 0, 0, 15);
	LCD_voidSendCustomCharacter(Copy_pu8AngryFace2, 1, 0, 14);	
	LCD_voidSendCustomCharacter(Copy_pu8AngryFace3, 2, 1, 15);
	LCD_voidSendCustomCharacter(Copy_pu8AngryFace4, 3, 1, 14);
	_delay_ms(1500);

	/* Don't kill me */
	LCD_voidClearDisplay();
	LCD_voidGoToXY(0, 5);
	LCD_voidSendString("Don't");
	LCD_voidGoToXY(1, 5);
	LCD_voidSendString("kill me!");
	LCD_voidSendCustomCharacter(Copy_pu8Gun1, 0, 1, 0);
	LCD_voidSendCustomCharacter(Copy_pu8Gun2, 1, 1, 1);
	LCD_voidSendCustomCharacter(Copy_pu8Za3bolaWaving2, 2, 1, 15);

	MDIO_voidSetPinDir(DIO_PORT_D, PIN0, INPUT_PULLUP);
	
	while(1)
	{
		u8 state = HIGH;
		MDIO_voidGetPinValue(DIO_PORT_D, PIN0, &state);
		if(state == LOW)
		{
			for(counter = 2; counter < 15; counter++)
			{
				LCD_voidGoToXY(1, counter);
				LCD_voidSendData('-');
				_delay_ms(22);
			}
			break;
		}
	}

	/* Killed */
	LCD_voidClearDisplay();
	LCD_voidSendCustomCharacter(Copy_pu8Killed1, 3, 1, 15);
	LCD_voidSendCustomCharacter(Copy_pu8Killed2, 4, 1, 14);
	

}
