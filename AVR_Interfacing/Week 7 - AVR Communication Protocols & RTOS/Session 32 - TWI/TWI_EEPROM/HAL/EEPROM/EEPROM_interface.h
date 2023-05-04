/*
 * ----------------------------------------------------------------------------------
 * Filename     :	EEPROM_interface.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 19, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 19, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8Data);
void EEPROM_voidReceiveDataByte(u16 Copy_u16LocationAddress, u8 * Copy_pu8ReceivedData);

#endif