/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		30 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  30 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
    MGPIO_ErrSetPinMode(HTFT_A0_PORT_PIN, GPIO_OUTPUT); // PA0 A0
    // MGPIO_ErrSetPinMode(HTFT_CS_PORT_PIN, GPIO_OUTPUT); // PA1 CS
    MGPIO_ErrSetPinMode(HTFT_RST_PORT_PIN, GPIO_OUTPUT); // PA1 CS
	
    MGPIO_ErrSetPinOutputSpeed(HTFT_A0_PORT_PIN, GPIO_LOW_SPEED);
	// MGPIO_ErrSetPinOutputSpeed(HTFT_CS_PORT_PIN, GPIO_LOW_SPEED);
	MGPIO_ErrSetPinOutputSpeed(HTFT_RST_PORT_PIN, GPIO_LOW_SPEED);

    /*Hardware Reseting*/
    MGPIO_ErrSetPinValue(HTFT_RST_PORT_PIN, GPIO_OUTPUT_HIGH);
    MSYSTICK_ErrSetBusyWait(100);
    MGPIO_ErrSetPinValue(HTFT_RST_PORT_PIN, GPIO_OUTPUT_LOW);
    MSYSTICK_ErrSetBusyWait(1);
    MGPIO_ErrSetPinValue(HTFT_RST_PORT_PIN, GPIO_OUTPUT_HIGH);
    MSYSTICK_ErrSetBusyWait(100);
    MGPIO_ErrSetPinValue(HTFT_RST_PORT_PIN, GPIO_OUTPUT_LOW);
    MSYSTICK_ErrSetBusyWait(100);
    MGPIO_ErrSetPinValue(HTFT_RST_PORT_PIN, GPIO_OUTPUT_HIGH);
    MSYSTICK_ErrSetBusyWait(120000);

    HTFT_voidSendCommand(SLPOUT_CMD);
    MSYSTICK_ErrSetBusyWait(150000);
    HTFT_voidSendCommand(COLMOD_CMD);
    HTFT_voidSendData(0x05);
    HTFT_voidSendCommand(DISPON_CMD);

}

static void HTFT_voidSendCommand(u8 Copy_u8Command)
{
    u8 Local_u8Dummy;
    MGPIO_ErrSetPinValue(HTFT_A0_PORT_PIN, GPIO_OUTPUT_LOW);
    MSPI_u8TrancieveSynchronous(Copy_u8Command, &Local_u8Dummy);
}


static void HTFT_voidSendData(u8 Copy_u8Data)
{
    u8 Local_u8Dummy;
    MGPIO_ErrSetPinValue(HTFT_A0_PORT_PIN, GPIO_OUTPUT_HIGH);
    MSPI_u8TrancieveSynchronous(Copy_u8Data, &Local_u8Dummy);
}

void HTFT_voidDisplayImage(u16 * Copy_pu16Image)
{
    /*Send Set X - Y Coordinates */
	HTFT_voidSetWindow(0, 127, 0, 159);
    /*Send Write RAM Command*/
    HTFT_voidSendCommand(0x2C);
    u16 Local_u16LoopCounter;
    u8 Local_u8Data = 0;
    for(Local_u16LoopCounter=0;Local_u16LoopCounter<20480;Local_u16LoopCounter++)
    {
    	Local_u8Data=Copy_pu16Image[Local_u16LoopCounter]>>8;
    	HTFT_voidSendData(Local_u8Data);
    	Local_u8Data=(u8)Copy_pu16Image[Local_u16LoopCounter];
    	HTFT_voidSendData(Local_u8Data);

    }
}

void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1)
{
    /*Send Set X Address Command*/
    HTFT_voidSendCommand(0x2A);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8X0);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8X1);
    /*Send Set Y Address Command*/
    HTFT_voidSendCommand(0x2B);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8Y0);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8Y1);
}

