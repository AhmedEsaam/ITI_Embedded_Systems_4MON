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
    MDIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Data);

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
    MDIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Command);

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
