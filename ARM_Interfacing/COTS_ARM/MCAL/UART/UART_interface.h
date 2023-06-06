/*
 * ----------------------------------------------------------------------------------
 * Filename		:	UART_interface.h
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	JUN 6, 2023
 * Version		:	v1.0
 * C Standard	:	C99
 * Compiler		:	GNU ARM GCC
 * Controller	:	STM32F401CCU6 (32-bit Architecture)
 * Layer		:	MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version 		Date 				Author 						Describtion
 * v1.0 		JUN 6, 2023 		Ahmed Essam El-Mogy 		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

// UART Mode Selection ................................
#define         MUART_ASYNCHRONOUS               0 
#define         MUART_SYNCHRONOUS                1

// UART Stop Bits Selection ...........................
#define         MUART_1_STOP_BIT                 0b00 
#define         MUART_HALF_STOP_BIT              0b01
#define         MUART_2_STOP_BIT                 0b10


#endif /* UART_INTERFACE_H_ */