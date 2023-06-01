/*
 * ----------------------------------------------------------------------------------
 * Filename     :	SPI_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 21, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 21, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI1_voidInit(void)
{

}

u8 MSPI1_u8Tranceive(u8 Copy_u8Data)
{
    /* Set The Data TO Be Transmit In DR Register */
    SPI1 -> DR = Copy_u8Data;
    /* Wait For SPI1 Not Busy */
    while(GET_BIT(SPI1->SR, 7) == 1);
    /* Return The Received Data */
    return (SPI1 -> DR);
}