/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LCD_config.h
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

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* Options :
    DIO_PORTA
    DIO_PORTB
    DIO_PORTC
    DIO_PORTD
    */
#define LCD_DATA_PORT       DIO_PORT_D

/* Options:
    (Ports)
    DIO_PORT_A
    DIO_PORT_B
    DIO_PORT_C
    DIO_PORT_D
    */
#define LCD_CTRL_PORT       DIO_PORT_C

/* Options:
    PIN0
    PIN1
    PIN2
    PIN3
    PIN4
    PIN5
    PIN6
    PIN7
    PIN8
    PIN9
    */
#define LCD_RS_PIN          PIN0
#define LCD_RW_PIN          PIN1
#define LCD_EN_PIN          PIN2

/* Options :
    EIGHT_BIT_MODE
    FOUR_BIT_MODE
    */
#define LCD_INIT_MODE       EIGHT_BIT_MODE


#endif /* LCD_PRIVATE_H */