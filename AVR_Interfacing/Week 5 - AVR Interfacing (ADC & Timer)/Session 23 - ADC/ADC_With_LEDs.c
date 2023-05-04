/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ADC_With_LEDs.c
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
	LED_t led1 = {DIO_PORT_C, PIN0};
	LED_t led2 = {DIO_PORT_C, PIN1};
	LED_t led3 = {DIO_PORT_C, PIN2};
	LED_t led4 = {DIO_PORT_C, PIN3};
	LED_t led5 = {DIO_PORT_C, PIN4};
	LED_t led6 = {DIO_PORT_C, PIN5};
	LED_t led7 = {DIO_PORT_C, PIN6};
	LED_t led8 = {DIO_PORT_C, PIN7};

	LED_voidInit(&led1);
	LED_voidInit(&led2);
	LED_voidInit(&led3);
	LED_voidInit(&led4);
	LED_voidInit(&led5);
	LED_voidInit(&led6);
	LED_voidInit(&led7);
	LED_voidInit(&led8);

	ADC_voidInit();

	u8 Local_u8Value;
	while (1)
	{
		Local_u8Value=(ADC_u8StartConversionSynchronous(ADC_Channel_0) * 100) / 256 + 1;
		DIO_voidSetPortSpecificValue(DIO_PORT_C, Local_u8Value);
	}

}

