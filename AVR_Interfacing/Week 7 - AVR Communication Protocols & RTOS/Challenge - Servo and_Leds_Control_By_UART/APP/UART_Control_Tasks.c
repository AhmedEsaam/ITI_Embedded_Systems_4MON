/*
 * ----------------------------------------------------------------------------------
 * Filename     :	UART_Control_Tasks.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 24, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 24, 2023		Ahmed Essam El-Mogy		Initial Creation
 * v1.1		    APR 27, 2023		Ahmed Essam El-Mogy		UART Control LEDs and Servo
 * ----------------------------------------------------------------------------------
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/Timer/Timer_interface.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"

#define OCR_VALUE_AT_ANGLE_0        590
#define OCR_VALUE_AT_ANGLE_180      2535
#define OCR_VALUE_RANGE             1945.0

void main(void)
{
    LED_t leds[3] = {
        {DIO_PORT_D, PIN2},
        {DIO_PORT_D, PIN3},
        {DIO_PORT_D, PIN4},
    };
    u8 Local_u8ReceivedData;
    u8 Local_u8ServoAngle = 0;
    u8 Local_u8LedNo;
    u8 Local_u8Command[8] = {'\0'};
    u8 Local_u8CommandCharCOunt = 0;
    u16 Local_u16Timer1OCRValue = OCR_VALUE_AT_ANGLE_0;
    TIMER1_voidInit();
    MDIO_voidSetPinDir(DIO_PORT_D, PIN5, OUTPUT);
    LED_voidInit(&leds[0]);
    LED_voidInit(&leds[1]);
    LED_voidInit(&leds[2]);
    LCD_voidInit();
    LCD_voidClearDisplay();

    TIMER1_coidSetICR1Value(20000);

    /* Set Rx Pin To Be Intput Pin */
    MDIO_voidSetPinDir(DIO_PORT_D, PIN0, INPUT_NO_PULLUP);
    /* Set Tx Pin To Be Output Pin */
    MDIO_voidSetPinDir(DIO_PORT_D, PIN1, OUTPUT);

    UART_voidInit();

    while (1)
    {
        /* Change The Angle of The Servo */
        if(Local_u16Timer1OCRValue <= OCR_VALUE_AT_ANGLE_180)
        {
            TIMER1_coidSetOCR1AValue(Local_u16Timer1OCRValue);
        }

        /* Receive 1 character from UART */
        UART_voidReceiveDataSynchronous(&Local_u8ReceivedData);
        /* Transmit The Received Character From UART */
        UART_voidTransmitDataSynchronous(Local_u8ReceivedData);

        if (Local_u8ReceivedData == '.') // 'Enter' Char: 'Line Feed'
        {
            LCD_voidGoToXY(1,0);
            if(!strcmp(Local_u8Command, "servo,"))
            {
                Local_u16Timer1OCRValue = OCR_VALUE_AT_ANGLE_0 + (OCR_VALUE_RANGE * (Local_u8ServoAngle / 180.0));
                Local_u8ServoAngle = 0;
            }
            else if(!strcmp(Local_u8Command, "ledon,"))
            {
                LED_voidTurnOn(&leds[Local_u8LedNo]);
            }
            else if(!strcmp(Local_u8Command, "ledoff,"))
            {
                LED_voidTurnOff(&leds[Local_u8LedNo]);
            }

            Local_u8CommandCharCOunt = 0;
            Local_u8Command[6] = '\0';
        }
        else if(Local_u8ReceivedData >= '0' && Local_u8ReceivedData <= '9')
        {
            LCD_voidSendData(Local_u8ReceivedData);
            if(!strcmp(Local_u8Command, "servo,"))
            {
                Local_u8ServoAngle = (Local_u8ServoAngle * 10) + (Local_u8ReceivedData - '0');
            }
            else if(!strcmp(Local_u8Command, "ledon,"))
            {
                Local_u8LedNo = Local_u8ReceivedData - '0';
            }
            else if(!strcmp(Local_u8Command, "ledoff,"))
            {
                Local_u8LedNo = Local_u8ReceivedData - '0';
            }
        }
        else
        {
            if(Local_u8CommandCharCOunt == 0)
            {
                LCD_voidClearDisplay();
            }
            LCD_voidSendData(Local_u8ReceivedData);
            Local_u8Command[Local_u8CommandCharCOunt] = Local_u8ReceivedData;
            Local_u8CommandCharCOunt++;
        }
    }
}
