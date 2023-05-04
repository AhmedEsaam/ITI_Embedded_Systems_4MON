/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ICU.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 12, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 12, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "util/delay.h"

#include "../HAL/LED/LED_interface.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/WDT/WDT_interface.h"

LED_t led1 ={DIO_PORT_D, PIN0};

void main(void)
{
    LED_voidInit(&led1);
    WDT_voidEnable();
    LED_voidTurnOn(&led1);
    _delay_ms(100);
    LED_voidTurnOff(&led1);
    WDT_voidSleep(WDT_SLEEP_16_3_MS);
    while(1);
}