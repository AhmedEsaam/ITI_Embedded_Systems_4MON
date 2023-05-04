/*
 * ----------------------------------------------------------------------------------
 * Filename     :	SPI_interface.h
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
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_voidTranceive(u8 Copy_u8Data);
u8 SPI_voidSlaveReceive(void);

#endif /* SPI_INTERFACE_H */
