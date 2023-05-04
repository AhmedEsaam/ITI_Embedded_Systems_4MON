/*
 * ----------------------------------------------------------------------------------
 * Filename     :	TWI_EEPROM.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 19, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 19, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TWI/TWI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"

LED_t led1 = {DIO_PORT_D, PIN7};
EXTI_t ext = {INT0, FALLING_EDGE};
void ButtonAction(void);
u8 Local_u8ReceivedData;


void main(void)
{

    LCD_voidInit();
    LED_voidInit(&led1);
    GIE_voidEnableGlobalInterrupt();
    EXTI_voidInitPinConnection(&ext);
    TWI_voidMasterInit(0b00010000);

    LED_voidTurnOff(&led1);
    EXTI_voidEnable(&ext);
    EXTI_voidTriggerEdge(&ext);
    EXTI_voidSetCallback(&ext, &ButtonAction);

    EEPROM_voidReceiveDataByte(10, &Local_u8ReceivedData);

    /* Display on Screen */
    LCD_voidSendString("Received Data:");
    LCD_voidGoToXY(1, 0);
    LCD_voidSendNumber((u32)Local_u8ReceivedData);


    while(1)
    {
        if(Local_u8ReceivedData == 5)
        {
            LED_voidTurnOn(&led1);
        }
        
        
    }
}

void ButtonAction(void)
{
    EEPROM_voidSendDataByte(10, 5);

    EEPROM_voidReceiveDataByte(10, &Local_u8ReceivedData);

    /* Display on Screen */
    LCD_voidClearDisplay();
    LCD_voidSendString("Received Data:");
    LCD_voidGoToXY(1, 0);
    LCD_voidSendNumber((u32)Local_u8ReceivedData);
    
}
