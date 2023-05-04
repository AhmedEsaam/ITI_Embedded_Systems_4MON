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
 * v1.0		    MAR 27, 2023		Ahmed Essam El-Mogy		Initial Creation
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
  LCD_voidClearDisplay();
  LCD_voidGoToXY(0, 0);
  LCD_voidSendString("Ahmed Essam");
  

}
