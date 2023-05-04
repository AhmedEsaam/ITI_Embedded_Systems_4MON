/*
 * ----------------------------------------------------------------------------------
 * Filename     :	UART_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 17, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 17, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_voidInit(void)
{
    // Result = 0000 0000 0000 0000
    // UBRRL= (u8) Result
    // UBRRH = Result >> 8;

    u8 Local_u8UCSRCTemp = 0;
    /* USART Parameters:
        - Asynchronous
        - Enable Tx & Rx Circuits
        - Data Size = 8 Bit
        - Parity = Disabled
        - Stop Bits = 1-Bit
        - Baudrate = 9600bps
        - Disable Double Speed Mode
    */
   
    /* Set The USART Mode To Be Asynchronous Mode */
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UMSEL);
    /* Enable The Tx & Rx Circuits */
    SET_BIT(UCSRB, UCSRB_TXEN);
    SET_BIT(UCSRB, UCSRB_RXEN);
    /* Set The Data Size Bits To Be 8-bit */
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ0);
    SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ1);
    CLR_BIT(UCSRB, UCSRB_UCSZ2);
    /* Disbale The Parity Mode */
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM0);
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM1);
    /* Stop Bit = 1-bit */
    CLR_BIT(Local_u8UCSRCTemp, UCSRC_USBS);
    /* Set The USART Register Select Bit To Write On UCSRC */
    SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);
    /* Assign The Variable Value To The Register */
    UCSRC = Local_u8UCSRCTemp;
    /* Set The Baud Rate To Be 9600bps (by Formula )*/
    CLR_BIT(UCSRA, UCSRA_U2X);
    UBRRL= 51;
    /* Clear The USART Register Select Bit To Write On UBRRH */
    CLR_BIT(UBRRH, UBRRH_URSEL);
    UBRRH = 0;
    
}

void UART_voidTransmitDataSynchronous(u8 Copy_u8Data)
{
    /* Polling (Busy Wait) On The UDR Empty Flag */
    while(GET_BIT(UCSRA, UCSRA_UDRE) == 0);
    /* Copy The Data To The UDR Register */
    UDR = Copy_u8Data;
    /* Polling (Busy Wait) On The TXC Flag */
    while(GET_BIT(UCSRA, UCSRA_TXC) == 0);
    /* Clear The Flag */
    SET_BIT(UCSRA, UCSRA_TXC);
}

void UART_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData)
{
    /* Polling (Busy Wait) On The Recieve Complete Flag */
    while(GET_BIT(UCSRA, UCSRA_RXC) == 0);
    /* Get The REceived Data And Assign It To The Passed Variable */
    *Copy_pu8ReceivedData = UDR;
}