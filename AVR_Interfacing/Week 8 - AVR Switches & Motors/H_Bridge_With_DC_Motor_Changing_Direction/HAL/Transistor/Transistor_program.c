/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Transistor_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	01 SEP, 2021
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU AVR-GCC
 * Controller   :   ATmega32 (8-bit Architecture)
 * Layer        :   HAL (ECUAL)
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.1		    APR 28, 2023		Ahmed Essam El-Mogy		Adding Error Handling
 * ----------------------------------------------------------------------------------
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "Transistor_interface.h"
#include "Transistor_private.h"
#include "Transistor_config.h"

void Transistor_voidInit(void)
{
    #if TRANSISTOR_PORT != DIO_PORT_A &&\
        TRANSISTOR_PORT != DIO_PORT_B &&\
        TRANSISTOR_PORT != DIO_PORT_C &&\
        TRANSISTOR_PORT != DIO_PORT_D
        #error "Transistor Port Name Invalid Configuration"
    #endif

    #if TRANSISTOR_PIN > PIN0
        #error "Transistor Pin Number Invalid Configuration"
    #endif

    #if TRANSISTOR_INITIAL_STATE > TRANSISTOR_SATURATION
        #error "Transistor Initial State Invalid Configuration"
    #endif

    #if TRANSISTOR_TYPE > TRANSISTOR_PNP
        #error "Transistor Type Invalid Configuration"
    #endif
    /*Set the transistor pin direction of the transistor to be output*/
    MDIO_voidSetPinDir(TRANSISTOR_PORT, TRANSISTOR_PIN, OUTPUT);
    /* Check for the transistor initial state configuration */
    #if TRANSISTOR_INITIAL_STATE == TRANSISTOR_SATURATION
    /* Check for the transistor type configuration */
        #if TRANSISTOR_TYPE == TRANSISTOR_NPN
            /* Set the transistor pin to be high*/
            MDIO_voidSetPinValue(TRANSISTOR_PORT, TRANSISTOR_PIN, HIGH);
        #else
            MDIO_voidSetPinValue(TRANSISTOR_PORT, TRANSISTOR_PIN, LOW);
        #endif
    #else
    /* Check for the transistor type configuration */
        #if TRANSISTOR_TYPE == TRANSISTOR_NPN
            MDIO_voidSetPinValue(TRANSISTOR_PORT, TRANSISTOR_PIN, LOW);
        #else
            MDIO_voidSetPinValue(TRANSISTOR_PORT, TRANSISTOR_PIN, HIGH);
        #endif
    #endif
}

Transistor_Err_t Transistor_voidConfigure(Transistor_t * Copy_TransistorName)
{
    /* Set The Transistor Error Handling Initial State */
    Transistor_Err_t Local_TransistorErrorState = TransistorOk;

    /*Checking for the transistor PortName, PinNumber, Type, and InitialState */
    if( Copy_TransistorName->Transistor_PortName        > DIO_PORT_D            || 
        Copy_TransistorName->Transistor_PinNumber       > PIN7                  ||
        Copy_TransistorName->Transistor_Type            > TRANSISTOR_PNP        ||
        Copy_TransistorName->Transistor_InitialState    > Transistor_Saturation
        )
    {
        /* Change Error Handling State */
        Local_TransistorErrorState = TransistorInvalidConfiguration;
    }
    else
    {
        /*Set the transistor Pin to be output pin*/
        MDIO_voidSetPinDir( Copy_TransistorName->Transistor_PortName,
                            Copy_TransistorName->Transistor_PinNumber, 
                            OUTPUT);

        /* Check for the type of the transistor*/
        switch(Copy_TransistorName -> Transistor_Type)
        {
            case TRANSISTOR_NPN:
                /*Check for the Initial State for the NPN Transistor, if Saturation, then set the transistor pin
                if Cutoff then clear the transistor pin*/
                switch(Copy_TransistorName -> Transistor_InitialState)
                {
                    case Transistor_Saturation:
                        MDIO_voidSetPinValue(   Copy_TransistorName->Transistor_PortName,
                                                Copy_TransistorName->Transistor_PinNumber, 
                                                HIGH);
                    break;
                    case Transistor_Cutoff:
                        MDIO_voidSetPinValue(   Copy_TransistorName->Transistor_PortName,
                                                Copy_TransistorName->Transistor_PinNumber, 
                                                LOW);
                    break;
                }
            break;
            
            case Transistor_PNP:
                /*Check for the Initial State for the PNP Transistor, if Saturation, then Clear the transistor pin
                if Cutoff then Set the transistor pin*/
                switch(Copy_TransistorName -> Transistor_InitialState)
                {
                    case Transistor_Saturation:
                        MDIO_voidSetPinValue(   Copy_TransistorName->Transistor_PortName,
                                                Copy_TransistorName->Transistor_PinNumber, 
                                                LOW);
                    break;
                    case Transistor_Cutoff:
                        MDIO_voidSetPinValue(   Copy_TransistorName->Transistor_PortName,
                                                Copy_TransistorName->Transistor_PinNumber, 
                                                HIGH);
                    break;
                }
            break;
            
        }
    }

    /* Return Error Handling State */
    return Local_TransistorErrorState;
}

Transistor_Err_t Transistor_voidChangeTransistorState(Transistor_t * Copy_TransistorName, u8 Copy_u8TransistorState)
{
    /* Set The Transistor Error Handling Initial State */
    Transistor_Err_t Local_TransistorErrorState = TransistorOk;

    if(Copy_u8TransistorState > TRANSISTOR_SATURATION)
    {
        /* Change Error Handling State */
        Local_TransistorErrorState = TransistorInvalidState;
    }
    else
    {
        switch(Copy_TransistorName -> Transistor_Type)
        {
            case Transistor_NPN:
                switch(Copy_u8TransistorState)
                {
                    case TRANSISTOR_SATURATION:
                        MDIO_voidSetPinValue(   Copy_TransistorName->Transistor_PortName,
                                                Copy_TransistorName->Transistor_PinNumber, 
                                                HIGH);                        
                    break;

                    case TRANSISTOR_CUTOFF:
                        MDIO_voidSetPinValue(   Copy_TransistorName->Transistor_PortName,
                                                Copy_TransistorName->Transistor_PinNumber, 
                                                LOW);
                    break;

                    default:
                        /* Change Error Handling State */
                        Local_TransistorErrorState = TransistorInvalidState;
                    break;
                }
            break;

            case Transistor_PNP:
                switch(Copy_u8TransistorState)
                {
                    case TRANSISTOR_SATURATION:
                        MDIO_voidSetPinValue(   Copy_TransistorName->Transistor_PortName,
                                                Copy_TransistorName->Transistor_PinNumber, 
                                                LOW);                        
                    break;

                    case TRANSISTOR_CUTOFF:
                        MDIO_voidSetPinValue(   Copy_TransistorName->Transistor_PortName,
                                                Copy_TransistorName->Transistor_PinNumber, 
                                                HIGH);
                    break;

                    default:
                        /* Change Error Handling State */
                        Local_TransistorErrorState = TransistorInvalidState;
                    break;
                }
            break;

            default:
                /* Change Error Handling State */
                Local_TransistorErrorState = TransistorInvalidConfiguration;
            break;
        }
    }

    /* Return Error Handling State */
    return Local_TransistorErrorState;
}
