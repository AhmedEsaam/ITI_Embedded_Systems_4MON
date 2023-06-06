/*
 * ----------------------------------------------------------------------------------
 * Filename		:	UART_program.c
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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void MUART_voidInit(void)
{
    /* USART Parameters:
        - Asynchronous
        - Data Size = 8 Bit
        - Parity = Disabled
        - Stop Bits = 1-Bit
        - Baudrate = 115200bps
    */
    /* Set Pins Mode */
    MGPIO_ErrSetPinMode(MUART_TX_PORT_PIN, GPIO_ALTERNATE_FUNCTION); // PA9
    MGPIO_ErrSetPinMode(MUART_RX_PORT_PIN, GPIO_ALTERNATE_FUNCTION); // PA10
	/* Set Alternate Functions */
    MGPIO_ErrSetPinAlternateFunction(MUART_TX_PORT_PIN, MGPIO_AF7);
    MGPIO_ErrSetPinAlternateFunction(MUART_RX_PORT_PIN, MGPIO_AF7);
   
    /* Set The USART Mode To Be Asynchronous Mode */
    CLR_BIT(UART->CR2, CLKEN);
    /* Enable The Tx & Rx Circuits */
    SET_BIT(UART->CR1, TE);
    SET_BIT(UART->CR1, RE);
    /* Set The Data Size Bits To Be 8-bit */
    CLR_BIT(UART->CR1, M);
    /* Disbale The Parity Mode */
    CLR_BIT(UART->CR1, PCE);
    /* Stop Bit = 1-bit */
    (UART->CR2) &= ~(STOP_MASK);
    (UART->CR2) |= (STOP_BITS<<STOP_LOCATION);
    
    /* Set The Baud Rate To Be 115200bps */
    /* Mantissa */
    (UART->BRR) &= ~(DIV_Mantissa_MASK);
    (UART->BRR) |= (8<<DIV_Mantissa_LOCATION);
    /* Fraction */
    (UART->BRR) &= ~(DIV_Fraction_MASK);
    (UART->BRR) |= 11;


    /* Enable the UART */
    SET_BIT(UART->CR1, UE);


}

void MUART_voidTransmitDataSynchronous(u8 Copy_u8Data)
{
    /* Polling (Busy Wait) On The TXE Empty Flag */
    while(GET_BIT(UART->SR, TXE) == 0);
    /* Copy The Data To The DR Register */
    (UART->DR) = Copy_u8Data;
    /* Polling (Busy Wait) On The TC Flag */
    while(GET_BIT(UART->SR, TC) == 0);
    /* Clear The Flag */
    CLR_BIT(UART->SR, TC);
}

void MUART_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData)
{
    /* Polling (Busy Wait) On The Recieve Complete Flag */
    while(GET_BIT(UART->SR, RXNE) == 0);
    /* Get The REceived Data And Assign It To The Passed Variable */
    *Copy_pu8ReceivedData = UART->DR;
}

void MUART_voidSendString(u8 * Copy_pu8StringArray)
{
	u8 Local_u8LoopCounter = 0 ;
	/* Loop On The String till the null terminator */
	while(Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
	{
		/* Send The Char */
		UART_voidTransmitDataSynchronous(Copy_pu8StringArray[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}

void MUART_voidSendNumber(u32 Copy_u32Number)
{
	u8 Local_u8ArrayNumber[10];
	s8 Local_s8LoopCounter = 0;
	while(Copy_u32Number != 0)
	{
		Local_u8ArrayNumber[Local_s8LoopCounter] = Copy_u32Number % 10;
		Copy_u32Number /= 10;
		Local_s8LoopCounter++;
	}
	Local_s8LoopCounter--;

	while(Local_s8LoopCounter >= 0)
	{
		MUART_voidTransmitDataSynchronous(Local_u8ArrayNumber[Local_s8LoopCounter] + '0');
		Local_s8LoopCounter--;
	}
}
