/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ADC_With_LCD.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 5, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 5, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/ADC/ADC_interface.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"

void main(void)
{
	/* Initializations */
	LCD_voidInit();
	ADC_voidInit();

	u8 Local_u8DigitalVal;
	u8 Local_u8LastDigitalVal;

	while (1)
	{
		Local_u8DigitalVal = (ADC_u8StartConversionSynchronous(ADC_Channel_0) * 100) / 256 + 1;
		if (Local_u8LastDigitalVal != Local_u8DigitalVal)
		{
			LCD_voidClearDisplay();
			LCD_voidsendnum(Local_u8DigitalVal);
			Local_u8LastDigitalVal = Local_u8DigitalVal;
		}
	}
}