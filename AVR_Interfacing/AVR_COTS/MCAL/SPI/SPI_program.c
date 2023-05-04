/*
 * ----------------------------------------------------------------------------------
 * Filename     :	SPI_program.c
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

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidMasterInit(void)
{
    /* Set The MCU To Be Master */
    SET_BIT(SPCR, SPCR_MSTR);
    /* Set MSB To Be Sent First */
    CLR_BIT(SPCR, SPCR_DORD);
    /* Set Leading Edge Rising and Trailing Edge Falling */
    CLR_BIT(SPCR, SPCR_CPOL);
    /* Sample At Leading Edge */
    CLR_BIT(SPCR, SPCR_CPHA);
    /* Prescaler divide by 16 */
    SET_BIT(SPCR, SPCR_SPR0);
    CLR_BIT(SPCR, SPCR_SPR1);
    CLR_BIT(SPSR, SPSR_SPI2X);

    /* Enable SPI */
    SET_BIT(SPCR, SPCR_SPE);
}

void SPI_voidSlaveInit(void)
{
    /* Set The MCU To Be Slave */
    CLR_BIT(SPCR, SPCR_MSTR);
    /* Set MSB To Be Sent First */
    CLR_BIT(SPCR, SPCR_DORD);
    /* Set Leading Edge Rising and Trailing Edge Falling */
    CLR_BIT(SPCR, SPCR_CPOL);
    /* Sample At Leading Edge */
    CLR_BIT(SPCR, SPCR_CPHA);

    /* Enable SPI */
    SET_BIT(SPCR, SPCR_SPE);
}

u8 SPI_voidTranceive(u8 Copy_u8Data)
{
    /* Set Data In SPDR To Send */
    SPDR = Copy_u8Data;
    /* Polling (Busy Wait) until Transmission Complete */
    while(GET_BIT(SPSR, SPSR_SPIF) == 0);
    /* Clear The Flag */
    SET_BIT(SPSR, SPSR_SPIF);
    /* Get Received Data */
    return SPDR;
}

u8 SPI_voidSlaveReceive(void)
{
	/* 1. Set dummy value */
	SPDR = 0xFF;
		
	/* 2. Wait till reception complete */
    while(GET_BIT(SPSR, SPSR_SPIF) == 0);
		
	/* 3. Get received data and flush buffer */
	return SPDR;
}
