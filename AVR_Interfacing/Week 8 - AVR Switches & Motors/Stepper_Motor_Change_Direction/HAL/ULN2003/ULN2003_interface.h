/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ULN2003_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 28, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * Controller   :   ATmega32 (8-bit Architecture)
 * Layer        :   HAL (ECUAL)
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 28, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef ULN2003_INTERFACE_H
#define ULN2003_INTERFACE_H

typedef enum
{
	ULN2003_LowerHalf,
	ULN2003_UpperHalf,
	ULN2003_AllPort,
}ULN2003_Pins_t;

typedef struct 
{
	u8 				ULN2003_Base_PortName;
	ULN2003_Pins_t	ULN2003_PortPins;
}ULN2003_t;

#define ULN2003_STOP	0xFF

typedef enum
{
	ULN2003Ok,
	ULN2003InvalidConfiguration,
	ULN2003InvalidValue,
}ULN2003_Err_t;

ULN2003_Err_t ULN2003_voidConfigure(ULN2003_t * Copy_ULN2003Name);
ULN2003_Err_t ULN2003_voidChangeBaseValue(ULN2003_t * Copy_ULN2003Name, u8 Copy_ULN2003Value);

#endif /* ULN2003_INTERFACE_H */
