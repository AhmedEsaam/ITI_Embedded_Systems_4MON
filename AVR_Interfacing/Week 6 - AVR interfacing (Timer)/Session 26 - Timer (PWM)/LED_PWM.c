/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LED_PWM.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 10, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 10, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../LIB/STD_TYPES.h"

#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/Timer/Timer_interface.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"

void main(void)
{
    u16 Local_u16Counter;
    /* Set Oc0 Pin to be Output with LED */
    LED_t led1 = {DIO_PORT_B, PIN3};

    /* Initialize Timer */
    TIMER0_voidInit();
    LED_voidInit(&led1);

    while(1)
    {
        /* Set The Compare Match Value from 0 to 255 */
        for(Local_u16Counter = 0; Local_u16Counter <= 255; Local_u16Counter++)
        {
            TIMER0_voidSetCTCCompareMatchValue(Local_u16Counter);
            _delay_ms(1000);
        }
        /* Set The Compare Match Value from 255 to 0 */
        for(Local_u16Counter = 0; Local_u16Counter <= 255; Local_u16Counter++)
        {
            TIMER0_voidSetCTCCompareMatchValue(255 - Local_u16Counter);
            _delay_ms(1000);
        }
    }
}
