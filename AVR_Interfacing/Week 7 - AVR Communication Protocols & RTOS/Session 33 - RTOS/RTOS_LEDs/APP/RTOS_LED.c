/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RTOS_LED.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 20, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 20, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../SERVICES/RTOS/RTOS_interface.h"


void LED1_Task(void);
void LED2_Task(void);
void LED3_Task(void);

LED_t led1 = {DIO_PORT_D, PIN0};
LED_t led2 = {DIO_PORT_D, PIN1};
LED_t led3 = {DIO_PORT_D, PIN2};

void main(void)
{
    LED_voidInit(&led1);
    LED_voidInit(&led2);
    LED_voidInit(&led3);

    RTOS_voidCreateTask(0, 1000, &LED1_Task); // red
    RTOS_voidCreateTask(1, 2000, &LED2_Task); // yellow
    RTOS_voidCreateTask(2, 3000, &LED3_Task); // green

    RTOS_voidInit();

    while (1);
}

void LED1_Task(void)
{
   LED_voidToggle(&led1);
}
void LED2_Task(void)
{
   LED_voidToggle(&led2);
}
void LED3_Task(void)
{
   LED_voidToggle(&led3);
}
