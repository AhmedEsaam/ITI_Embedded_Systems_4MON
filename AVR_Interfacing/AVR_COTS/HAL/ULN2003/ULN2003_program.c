/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ULN2003_program.c
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

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "ULN2003_interface.h"
#include "ULN2003_private.h"
#include "ULN2003_config.h"


ULN2003_Err_t ULN2003_voidConfigure(ULN2003_t * Copy_ULN2003Name)
{
    /* Set The ULN2003 Error Handling Initial State */
    ULN2003_Err_t Local_ULN2003ErrorState = ULN2003Ok;

    /* Checking ULN2003 Port Name, and Port Pins */
    if( Copy_ULN2003Name->ULN2003_Base_PortName     >   DIO_PORT_D      ||
        Copy_ULN2003Name->ULN2003_PortPins          >   ULN2003_AllPort     
        )
    {
        /* Set Error Handling State */
        Local_ULN2003ErrorState = ULN2003InvalidConfiguration;
    }
    else
    {
        /* Check The UNL2003 Port Pins */
        switch (Copy_ULN2003Name->ULN2003_PortPins)
        {
        case ULN2003_LowerHalf:
            MDIO_voidSetLowerNibbleDir(Copy_ULN2003Name->ULN2003_Base_PortName, OUTPUT);
            MDIO_voidSetLowerNibbleValue(Copy_ULN2003Name->ULN2003_Base_PortName, ULN2003_STOP);
            break;
        
        case ULN2003_UpperHalf:
            MDIO_voidSetHigherNibbleDir(Copy_ULN2003Name->ULN2003_Base_PortName, OUTPUT);
            MDIO_voidSetHigherNibbleValue(Copy_ULN2003Name->ULN2003_Base_PortName, ULN2003_STOP);
            break;
        
        case ULN2003_AllPort:
            MDIO_voidSetPortDir(Copy_ULN2003Name->ULN2003_Base_PortName, OUTPUT);
            MDIO_voidSetPortSpecificValue(Copy_ULN2003Name->ULN2003_Base_PortName, ULN2003_STOP);
            break;
        
        default:
            /* Set Error Handling State */
            Local_ULN2003ErrorState = ULN2003InvalidConfiguration;
            break;
        }
    }

    /* Return Error Handling State */
    return Local_ULN2003ErrorState;
}

ULN2003_Err_t ULN2003_voidChangeBaseValue(ULN2003_t * Copy_ULN2003Name, u8 Copy_ULN2003Value)
{
    /* Set The ULN2003 Error Handling Initial State */
    ULN2003_Err_t Local_ULN2003ErrorState = ULN2003Ok;

    /* Check The UNL2003 Port Pins */
    switch (Copy_ULN2003Name->ULN2003_PortPins)
    {
    case ULN2003_LowerHalf:
        MDIO_voidSetLowerNibbleValue(Copy_ULN2003Name->ULN2003_Base_PortName, Copy_ULN2003Value);
        break;
    
    case ULN2003_UpperHalf:
        MDIO_voidSetHigherNibbleValue(Copy_ULN2003Name->ULN2003_Base_PortName, Copy_ULN2003Value << 4);
        break;
    
    case ULN2003_AllPort:
        MDIO_voidSetPortSpecificValue(Copy_ULN2003Name->ULN2003_Base_PortName, Copy_ULN2003Value);
        break;
    
    default:
        /* Set Error Handling State */
        Local_ULN2003ErrorState = ULN2003InvalidConfiguration;
        break;
    }

    /* Return Error Handling State */
    return Local_ULN2003ErrorState;
}
