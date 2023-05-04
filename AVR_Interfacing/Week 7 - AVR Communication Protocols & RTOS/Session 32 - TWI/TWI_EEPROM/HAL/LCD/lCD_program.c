/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LCD_program.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 26, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 26, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

/* Library Inclusions */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
/* Lower Layer Inclusions */
#include "../../MCAL/DIO/DIO_interface.h"
/* Self Files Inclusions */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


void LCD_voidInit(void)
{
    #if LCD_INIT_MODE == EIGHT_BIT_MODE
    /* Initialize Data Port */
    MDIO_voidSetPortSpecificDir(LCD_DATA_PORT, LCD_ALL_OUT);
        
    MDIO_voidSetPinDir(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
    MDIO_voidSetPinDir(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);
    MDIO_voidSetPinDir(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT);

    /* Wait For More Than 30 ms */
    _delay_ms(40);

    /* Send Function Set Command */
    LCD_voidSendCommand(FUNCTION_SET_CMD);
    /* Send Display */
    LCD_voidSendCommand(DISPLAY_ON_OFF_CMD);
    /* Send Display Clear Command */
    LCD_voidSendCommand(DISPLAY_CLEAR_CMD);

    #elif LCD_INIT_MODE == FOUR_BIT_MODE

    #else
        #error ("LCD_INIT_MODE Configuration Error")
    #endif
}

void LCD_voidSendData(u8 Copy_u8Data)
{
    /* Clear The RS Pin To Send The Data (RS -> 0 : Command, 1: Data) */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
    /* Clear The RW Pin To Write The Command (R/W -> 0 : Write, 1: Read) */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    /* Set The Command On The Data/Command Port */
    MDIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);

    /* Send ENable Pulse */
    /* LOW */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    /* High For 2 ms */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    /* Low */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    /* Clear The RS Pin To Send The Command (RS -> 0 : Command, 1: Data) */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
    /* Clear The RW Pin To Write The Command (R/W -> 0 : Write, 1: Read) */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    /* Set The Command On The Data/Command Port */
    MDIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);

    /* Send ENable Pulse */
    /* LOW */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    /* High For 2 ms */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    /* Low */
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(DISPLAY_CLEAR_CMD);
}

void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
    u8 Local_u8CharacterAddress = 0;
    /* Calculate The Address Of The Character On LCD */
    if(Copy_u8XPos == 0)
    {
        /* @ x = 0 -> Address = Y-Position */
        Local_u8CharacterAddress = Copy_u8YPos;
    }
    else if(Copy_u8XPos == 1)
    {
        /* @ x = 1 -> Address = Y-Position + 0x40 */
        Local_u8CharacterAddress = Copy_u8YPos + 0x40;
    }
    else
    {
        /* Raise an error */
    }
    /* Set The 7th bit in the Address variable */
    // SET_BIT(Local_u8CharacterAddress, 7);
    /* Send the Address variable as a command */
    LCD_voidSendCommand(SET_DDRAM_ADDRESS_CMD ^ Local_u8CharacterAddress);
}

void LCD_voidSendString(u8 * Copy_pu8StringArray)
{
    u8 Local_u8LoopCounter = 0;
    /* Loop On The String Till The Null terminator */
    while(Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
    {
        /* Send The Array Elements */
        LCD_voidSendData(Copy_pu8StringArray[Local_u8LoopCounter]);
        Local_u8LoopCounter++;
    }
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
    u8 Local_u8DigitArray[10];
    s8 Local_u8LoopCounter = 0;
    if(Copy_u32Number < 0)
    {
        LCD_voidSendData('-');
        Copy_u32Number *= -1;
    }
    while (Copy_u32Number != 0)
    {   
        Local_u8DigitArray[Local_u8LoopCounter] = Copy_u32Number % 10;
        Copy_u32Number /= 10;
        Local_u8LoopCounter++;
    }
    Local_u8LoopCounter--;

    while(Local_u8LoopCounter >= 0)
    {
        LCD_voidSendData(Local_u8DigitArray[Local_u8LoopCounter] + '0');
        Local_u8LoopCounter--;
    }
}

void LCD_voidSendCustomCharacter(u8 * Copy_pu8CharacterArray,
                                 u8 Copy_u8PatternNumber,
                                 u8 Copy_u8XPos, 
                                 u8 Copy_u8YPos)
{
    u8 Local_u8LoopCounter;
    u8 Local_u8CGRAMAddress = 0;
    /* Calculate The CGRAM Address = Pattern Number */
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
    /* Send The CGRAM Address Command To The LCD */
    LCD_voidSendCommand(SET_CGRAM_ADDRESS_CMD ^ Local_u8CGRAMAddress);
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
        /* Send Byte From The Character Array */
        LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
    }
    /* Send The Command To Set The DDRAM Address */
    LCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);
    /* Display The Pattern From The CGRAM */
    LCD_voidSendData(Copy_u8PatternNumber);
}
