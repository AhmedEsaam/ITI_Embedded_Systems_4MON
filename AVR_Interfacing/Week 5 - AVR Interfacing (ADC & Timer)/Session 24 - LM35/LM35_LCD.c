/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LM35_LCD.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 6, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 6, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/ADC/ADC_interface.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LM35/LM35_interface.h"

void main(void)
{
	LM35_t Local_LM35TempSensor = {DIO_PORT_A, ADC_Channel_0};
	LM35_voidInit(&Local_LM35TempSensor);

	LCD_voidInit();
	ADC_voidInit();

	u8 Local_u8DigitalVal;
	u8 Local_u8LastDigitalVal;
	while (1)
	{
		Local_u8DigitalVal = LM35_u8GetValue(&Local_LM35TempSensor) + 1;
		if (Local_u8LastDigitalVal != Local_u8DigitalVal)
		{
			LCD_voidClearDisplay();
			LCD_voidsendnum(Local_u8DigitalVal);
			Local_u8LastDigitalVal = Local_u8DigitalVal; // To make sure LCD will not rewrite the value until it changes
		}
	}
}
