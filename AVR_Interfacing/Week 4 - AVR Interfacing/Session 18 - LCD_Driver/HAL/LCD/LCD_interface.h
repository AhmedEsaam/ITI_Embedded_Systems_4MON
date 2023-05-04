/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LCD_interface.h
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

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidInit(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidClearDisplay(void);

#endif /* LCD_INTERFACE_H */