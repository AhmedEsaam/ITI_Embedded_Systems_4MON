/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Transistor_interface.h
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

#ifndef TRANSISTOR_INTERFACE_H
#define TRANSISTOR_INTERFACE_H


typedef enum
{
    Transistor_NPN,
    Transistor_PNP,
}Transistor_Type_t;

typedef enum
{
    Transistor_Cutoff,
    Transistor_Saturation,
}Transistor_InitialState_t;

typedef struct
{
    u8                          Transistor_PortName;
    u8                          Transistor_PinNumber;
    Transistor_Type_t           Transistor_Type;
    Transistor_InitialState_t   Transistor_InitialState;
}Transistor_t;

#define TRANSISTOR_CUTOFF           0
#define TRANSISTOR_SATURATION       1


typedef enum
{
    TransistorOk,
    TransistorInvalidConfiguration,
    TransistorInvalidState,
}Transistor_Err_t;

void Transistor_voidInit(void);
Transistor_Err_t Transistor_voidConfigure(Transistor_t * Copy_TransistorName);
Transistor_Err_t Transistor_voidChangeTransistorState(Transistor_t * Copy_TransistorName, u8 Copy_u8TransistorState);


#endif
