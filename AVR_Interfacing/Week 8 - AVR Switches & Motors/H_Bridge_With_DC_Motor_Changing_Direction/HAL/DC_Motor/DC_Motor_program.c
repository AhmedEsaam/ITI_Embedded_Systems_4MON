/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DC_Motor_program.c
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

#include "../../HAL/Transistor/Transistor_interface.h"
#include "../../HAL/H_Bridge/H_Bridge_interface.h"

#include "DC_Motor_interface.h"
#include "DC_Motor_private.h"
#include "DC_Motor_config.h"

DC_Motor_Err_t DC_Motor_voidConfigure(DC_Motor_t * Copy_DC_MotorName)
{
    /* Set The DC-Motor Error Handling Initial State */
    DC_Motor_Err_t Local_DC_MotorErrorState = DC_MotorOk;

    /* Checking DC-Motor Direction, and H-Bridge Configuration */
    if( Copy_DC_MotorName->DC_Motor_InitialDirection                       >    DC_Motor_AntiClockWise  ||
        H_Bridge_voidConfigure(&(Copy_DC_MotorName->DC_Motor_H_Bridge))    !=   H_BridgeOk
        )
    {
        /* Set Error Handling State */
        Local_DC_MotorErrorState = DC_MotorInvalidConfiguration;
    }
    else
    {
        /* Set the DC-Motor Direction to be 'Stop' by Changing H-Bridge Polarity to 'H_Bridge_Stop' */
        if (H_Bridge_voidChangePolarity(&(Copy_DC_MotorName->DC_Motor_H_Bridge), H_Bridge_Stop) != H_BridgeOk)
        {
            /* Set Error Handling State */
            Local_DC_MotorErrorState = DC_MotorInvalidConfiguration;
        }
    }

    /* Return Error Handling State */
    return Local_DC_MotorErrorState;
}

DC_Motor_Err_t DC_Motor_voidChangeDirection(DC_Motor_t * Copy_DC_MotorName, DC_Motor_Direction_t Copy_DC_MotorDirection)
{
    /* Set The DC-Motor Error Handling Initial State */
    DC_Motor_Err_t Local_DC_MotorErrorState = DC_MotorOk;
    
    /* Check for the Direction of the DC-Motor */
    switch (Copy_DC_MotorDirection)
    {
    case DC_Motor_Stop:
        /* Set the DC-Motor Direction to be 'Stop' by Changing H-Bridge Polarity to 'H_Bridge_Stop' */
        H_Bridge_voidChangePolarity(&(Copy_DC_MotorName->DC_Motor_H_Bridge), H_Bridge_Stop);
        break;

    case DC_Motor_ClockWise:
        /* Set the DC-Motor Direction to be 'Cloc kWise' by Changing H-Bridge Polarity to 'H_Bridge_Left_to_Right' 
            (When Changing Polarity, The function begins with setting Polarity to 'Stop') */
        H_Bridge_voidChangePolarity(&(Copy_DC_MotorName->DC_Motor_H_Bridge), H_Bridge_Left_to_Right);
        break;

    case DC_Motor_AntiClockWise:
        /* Set the DC-Motor Direction to be 'Anti Clock Wise' by Changing H-Bridge Polarity to 'H_Bridge_Right_to_Left'
            (When Changing Polarity, The function begins with setting Polarity to 'Stop') */
        H_Bridge_voidChangePolarity(&(Copy_DC_MotorName->DC_Motor_H_Bridge), H_Bridge_Right_to_Left);
        break;
    
    default:
        Local_DC_MotorErrorState = DC_MotorInvalidDirection;
        break;
    }

    /* Return Error Handling State */
    return Local_DC_MotorErrorState;
}
