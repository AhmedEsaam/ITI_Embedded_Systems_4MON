/*
 * ----------------------------------------------------------------------------------
 * Filename     :	lab2.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 27, 2023
 * Description	:	Animated Moving Name from Left To Right
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



void main(void)
{
	LCD_voidInit();

  s8 Local_u8YPos = 5;
  u8 Local_u8Direction = 'L';   /* Left */
  while (1)
  {
    LCD_voidClearDisplay();
    LCD_voidGoToXY(0, Local_u8YPos);
	  LCD_voidSendString("Ahmed Essam");
    if(Local_u8Direction == 'L')
    {
      if(Local_u8YPos == 0)
      {
        Local_u8YPos++;
        Local_u8Direction = 'R';  /* Right */
      }
      else
      {
        Local_u8YPos--;
      }
    }
    else if(Local_u8Direction == 'R')
    {
      if(Local_u8YPos == 5)
      {
        Local_u8YPos--;
        Local_u8Direction = 'L';  /* Right */
      }
      else
      {
        Local_u8YPos++;
      }
    }
    _delay_ms(100);
  }

}
