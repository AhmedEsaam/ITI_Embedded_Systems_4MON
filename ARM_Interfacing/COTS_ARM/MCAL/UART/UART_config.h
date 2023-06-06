/*
 * ----------------------------------------------------------------------------------
 * Filename		:	UART_config.h
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

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define F_CPU                   16000000UL
#define BAUDRATE                115200


#define MUART_TX_PORT_PIN		GPIO_PORTA, GPIO_PIN9
#define MUART_RX_PORT_PIN		GPIO_PORTA, GPIO_PIN10


#define MODE                    MUART_ASYNCHRONOUS
#define STOP_BITS               MUART_1_STOP_BIT


#endif /* UART_CONFIG_H_*/