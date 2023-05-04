/*
 * ----------------------------------------------------------------------------------
 * Filename     :	main.c
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

void main(void)
{
	LCD_voidInit();
	LCD_voidSendData('A');
	while (1)
	{

	}
}
