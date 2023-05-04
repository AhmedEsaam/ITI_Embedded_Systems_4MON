/*
 * ----------------------------------------------------------------------------------
 * Filename     :	EEPROM_program.c
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
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "util/delay.h"

#include "../../MCAL/TWI/TWI_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8Data)
{
    u8 Local_u8SlaveAddress = FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);
    /*Send Start Condition*/
    TWI_ERRSendStartCondition();
    /*Send Slave Address + Write Request*/
    TWI_ERRSendSlaveAddressWithWrite(Local_u8SlaveAddress);
    /*Send Location Address*/
    TWI_ERRSendDataPacket((u8)Copy_u16LocationAddress);
    /*Send Data*/
    TWI_ERRSendDataPacket(Copy_u8Data);
    /*Send Stop Condition*/
    TWI_voidSendStopCondition();
    /*Delay 5msec*/
    _delay_ms(5);
}

void EEPROM_voidReceiveDataByte(u16 Copy_u16LocationAddress, u8 * Copy_pu8ReceivedData)
{
    u8 Local_u8SlaveAddress = FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);

    /*Send Start Condition*/
    TWI_ERRSendStartCondition();
    /*Send Slave Address + Write Request*/
    TWI_ERRSendSlaveAddressWithWrite(Local_u8SlaveAddress);
    /*Send Location Address*/
    TWI_ERRSendDataPacket((u8)Copy_u16LocationAddress);
    /*Send Repeated Start Condition*/
    TWI_ERRSendRepeatedStartCondition();
    /*Send Slave Address + Read Request*/
    TWI_voidSendSlaveAddressWithRead(Local_u8SlaveAddress);
    /*Receive Data*/
    TWI_ERRReceiveDataPacket(Copy_pu8ReceivedData);
    /*Send Stop Condition*/
    TWI_voidSendStopCondition();

    // *Copy_pu8ReceivedData = 13;
}
