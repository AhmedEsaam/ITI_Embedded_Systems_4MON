/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LM35_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 6, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 6, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

#include "LM35_interface.h"
#include "LM35_private.h" 
#include "LM35_config.h"


void LM35_voidInit(LM35_t* LM35obj)
{
DIO_voidSetPinDirection(DIO_PORT_A, LM35obj->LM35_u8Channel, INPUT_NO_PULLUP);

}
u8 LM35_u8GetValue(LM35_t* LM35obj)
{
	u8 Local_u8DigitalValue;
	u16 Local_u16MilliVolt;
	u8 Local_u8TempValue;
	Local_u8DigitalValue = ADC_u8StartConversionSynchronous(LM35obj->LM35_u8Channel);
	Local_u16MilliVolt = ((u32)Local_u8DigitalValue * 5000UL) / 256UL;

    u8 Local_u8TempValue = Local_u16MilliVolt / 10;
    return Local_u8TempValue;
}
