/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Timer_toggle_LED.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 9, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 9, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/Timer/Timer_interface.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"

#define F_CPU	8000000UL

void main(void)
{
    LED_t led1 = {DIO_PORT_A, PIN0};

    TIMER0_voidInit();
    LED_voidInit(&led1);
    while(1)
    {
        TIMER0_voidSetBusyWaitMS_CTCMode(1000);
        LED_voidToggle(&led1);
    }
}
