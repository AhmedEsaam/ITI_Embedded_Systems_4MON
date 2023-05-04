/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DIO_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 22, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

// Values
#define INPUT	0
#define OUTPUT	1

#define LOW		0
#define HIGH	1

// Ports
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


// Function Prototypes
void DIO_SetPinDirection(u8 reg, u8 pin, u8 dir);
void DIO_SetPinValue(u8 reg, u8 pin, u8 val);
void DIO_TogglePin(u8 reg, u8 pin);
u8 DIO_GetPinValue(u8 reg, u8 pin);

void DIO_SetPortDir(u8 reg, u8 dir);
void DIO_SetPortValue(u8 reg, u8 val);
void DIO_ClrPortValue(u8 reg);

void DIO_SetLowerNibbleDir(u8 reg, u8 dir);
void DIO_SetLowerNibbleValue(u8 reg, u8 val);

void DIO_SetHigherNibbleDir(u8 reg, u8 dir);
void DIO_SetHigherNibbleValue(u8 reg, u8 val);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
