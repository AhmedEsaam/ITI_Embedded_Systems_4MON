/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LCD_private.h
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

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define LCD_ALL_OUT             0xFF

/* LCD Modes */
#define EIGHT_BIT_MODE          1
#define FOUR_BIT_MODE           0

/* LCD Commands */
#define FUNCTION_SET_CMD        0x38    /* 0b00111000 */
#define DISPLAY_ON_OFF_CMD      0x0F    /* 0b00001111 */ /* Cursor On And Blinking */
#define DISPLAY_CLEAR_CMD       0x01    /* 0b00000001 */
#define RETURN_HOME_CMD         0x02    /* 0b00000010 */

#define SET_DDRAM_ADDRESS_CMD   0x80    /* 0b10000000 */
#define SET_CGRAM_ADDRESS_CMD   0x40    /* 0b01000000 */

/* Prototypes */
static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif /* LCD_PRIVATE_H */