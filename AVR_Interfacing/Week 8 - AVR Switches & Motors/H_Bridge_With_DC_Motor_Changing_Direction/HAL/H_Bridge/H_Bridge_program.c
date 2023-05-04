/*
 * ----------------------------------------------------------------------------------
 * Filename     :	H_Bridge_program.c
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

#include "H_Bridge_interface.h"
#include "H_Bridge_private.h"
#include "H_Bridge_config.h"


H_Bridge_Err_t H_Bridge_voidConfigure(H_Bridge_t * Copy_H_BridgeName)
{
    /* Set The H-Bridge Error Handling Initial State */
    H_Bridge_Err_t Local_H_BridgeErrorState = H_BridgeOk;

    /* Checking H-Bridge Polarity, and Left-to-Right & Right-to-Left Transistor Pairs Configuration */
    if( Copy_H_BridgeName->H_Bridge_InitialPolarity     >   H_Bridge_Right_to_Left                                  ||
        Transistor_voidConfigure(&(Copy_H_BridgeName->H_Bridge_LeftToRightTransistorPair))    !=    TransistorOk    ||
        Transistor_voidConfigure(&(Copy_H_BridgeName->H_Bridge_RightToLeftTransistorPair))    !=    TransistorOk
        )
    {
        /* Set Error Handling State */
        Local_H_BridgeErrorState = H_BridgeInvalidConfiguration;
    }
    else
    {
        /* Set the H-Bridge Polarity to be 'Stop' by Changing Both Transistor Pairs State to be Cutoff */
        if (Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_LeftToRightTransistorPair), Transistor_Cutoff) != TransistorOk ||
            Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_RightToLeftTransistorPair), Transistor_Cutoff) != TransistorOk
            )
        {
            /* Set Error Handling State */
            Local_H_BridgeErrorState = H_BridgeInvalidConfiguration;
        }
    }

    /* Return Error Handling State */
    return Local_H_BridgeErrorState;
}

H_Bridge_Err_t H_Bridge_voidChangePolarity(H_Bridge_t * Copy_H_BridgeName, H_Bridge_Polarity_t Copy_H_BridgePolarity)
{
    /* Set The H-Bridge Error Handling Initial State */
    H_Bridge_Err_t Local_H_BridgeErrorState = H_BridgeOk;
    
    /* Check for the polarity of the H-Bridge */
    switch (Copy_H_BridgePolarity)
    {
    case H_Bridge_Stop:
        /* Set the H-Bridge Polarity to be 'Stop' by Changing Both Transistor Pairs State to be Cutoff */
        Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_LeftToRightTransistorPair), Transistor_Cutoff);
        Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_RightToLeftTransistorPair), Transistor_Cutoff);
        break;

    case H_Bridge_Left_to_Right:
        /* Set the H-Bridge Polarity to be 'Stop' by Changing Both Transistor Pairs State to be Cutoff */
        Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_LeftToRightTransistorPair), Transistor_Cutoff);
        Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_RightToLeftTransistorPair), Transistor_Cutoff);
        /* Set the Polarity to be 'Left-to-Right' by Changing Left-to-Right Transistor Pair State to be Saturation */
        Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_LeftToRightTransistorPair), Transistor_Saturation);
        break;

    case H_Bridge_Right_to_Left:
        /* Set the H-Bridge Polarity to be 'Stop' by Changing Both Transistor Pairs State to be Cutoff */
        Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_LeftToRightTransistorPair), Transistor_Cutoff);
        Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_RightToLeftTransistorPair), Transistor_Cutoff);
        /* Set the Polarity to be 'Left-to-Right' by Changing Right-to-Left Transistor Pair State to be Saturation */
        Transistor_voidChangeTransistorState(&(Copy_H_BridgeName->H_Bridge_RightToLeftTransistorPair), Transistor_Saturation);
        break;
    
    default:
        Local_H_BridgeErrorState = H_BridgeInvalidPolarity;
        break;
    }

    /* Return Error Handling State */
    return Local_H_BridgeErrorState;
}


