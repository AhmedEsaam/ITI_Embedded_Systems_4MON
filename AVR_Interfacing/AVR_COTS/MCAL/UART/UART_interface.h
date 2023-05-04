/*
 * ----------------------------------------------------------------------------------
 * Filename     :	UART_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 17, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		    Author			        Description
 * v1.0		    APR 17, 2023	Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);
void UART_voidTransmitDataSynchronous(u8 Copy_u8Data);
void UART_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData);
/*
transmit data As
receive data As
isr for transmitting
isr for receiving
isr for udr empty
transmit string
transmit number

*/

#endif /* UART_INTERFACE_H */
