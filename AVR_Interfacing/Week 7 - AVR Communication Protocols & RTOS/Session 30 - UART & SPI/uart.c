#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"

LED_t led1 = {DIO_PORT_C, PIN0};

void main(void)
{
    u8 Local_u8ReceivedData;
    LED_voidInit(&led1);
    LCD_voidInit();

    /* Set Rx Pin To Be Intput Pin */
    MDIO_voidSetPinDir(DIO_PORT_D, PIN0, INPUT_NO_PULLUP);
    /* Set Tx Pin To Be Output Pin */
    MDIO_voidSetPinDir(DIO_PORT_D, PIN1, OUTPUT);

    UART_voidInit();
    
    while(1)
    {
        /* Receive 1 character from UART */
        UART_voidReceiveDataSynchronous(&Local_u8ReceivedData);
        /* Transmit The Received Character From UART */
        UART_voidTransmitDataSynchronous(Local_u8ReceivedData);
        
        LCD_voidSendData(Local_u8ReceivedData);
        
        if(Local_u8ReceivedData == 'A')
        {
            /* Turn On LED */
            LED_voidTurnOn(&led1);
        }
        else if(Local_u8ReceivedData == 'B')
        {
            /* Turn Off LED */
            LED_voidTurnOff(&led1);
        }
        else
        {
            /* Do Nothing */
        }
    }
}

