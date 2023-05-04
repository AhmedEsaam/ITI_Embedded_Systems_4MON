/*
 * ----------------------------------------------------------------------------------
 * Filename     :	main.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 28, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 28, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef EXTI_PROGRAM_H
#define EXTI_PROGRAM_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void EXTI_voidInit(EXTI_t* Copy_pEXTI_t_Obj);
void EXTI_voidTriggerEdge(EXTI_t* Copy_pEXTI_t_Obj);
void EXTI_voidEnable(EXTI_t* Copy_pEXTI_t_Obj);
void EXTI_voidDisable(EXTI_t* Copy_pEXTI_t_Obj);

void EXTI_voidInit(EXTI_t* Copy_pEXTI_t_Obj)
{
    switch (Copy_pEXTI_t_Obj->EXTI_u8IntNum)
    {
    case INT0:
        #if INT0_PIN == INT0_INPUT_PULLUP
            DIO_voidSetPinDirection(DIO_PORT_D, PIN2, INPUT);
            DIO_voidSetPinValue(DIO_PORT_D, PIN2, HIGH);
        #elif INT0_PIN == INT0_INPUT_EXTERNALPULLDOWN
            DIO_voidSetPinDirection(DIO_PORT_D, PIN2, INPUT);
            break;
        #elif INT0_PIN == INT0_INPUT_EXTERNALPULLUP
            DIO_voidSetPinDirection(DIO_PORT_D, PIN2, INPUT);
            break;
        #endif
    case INT1:
        #if INT1_PIN == INT0_INPUT_PULLUP
            DIO_voidSetPinDirection(DIO_PORT_D, PIN3, INPUT);
            DIO_voidSetPinValue(DIO_PORT_D, PIN3, HIGH);
        #elif INT1_PIN == INT0_INPUT_EXTERNALPULLDOWN
            DIO_voidSetPinDirection(DIO_PORT_D, PIN3, INPUT);
            break;
        #elif INT1_PIN == INT0_INPUT_EXTERNALPULLUP
            DIO_voidSetPinDirection(DIO_PORT_D, PIN3, INPUT);
            break;
        #endif
    case INT2:
        #if INT2_PIN == INT0_INPUT_PULLUP
            DIO_voidSetPinDirection(DIO_PORT_B, PIN2, INPUT);
            DIO_voidSetPinValue(DIO_PORT_B, PIN2, HIGH);
        #elif INT2_PIN == INT0_INPUT_EXTERNALPULLDOWN
            DIO_voidSetPinDirection(DIO_PORT_B, PIN2, INPUT);
            break;
        #elif INT2_PIN == INT0_INPUT_EXTERNALPULLUP
            DIO_voidSetPinDirection(DIO_PORT_B, PIN2, INPUT);
            break;
        #endif
    
    default:
        break;
    }
}

void EXTI_voidTriggerEdge(EXTI_t* Copy_pEXTI_t_Obj)
{
    switch (Copy_pEXTI_t_Obj->EXTI_u8IntNum)
    {
    case INT0:
        MCUCR &= ~(0x03);   /* Clear First Two Lease Significant Bits (Bit 0, Bit 1) */
        MCUCR |= (Copy_pEXTI_t_Obj->EXTI_u8IntSense); /* Set Bits of Interrupt Sense In those Positions */
        break;

    case INT1:
        MCUCR &= ~(0x0C);   /* Clear Second Two Lease Significant Bits (Bit 2, Bit 3)*/
        MCUCR |= ((Copy_pEXTI_t_Obj->EXTI_u8IntSense) << 2);  /* Set Bits of Interrupt Sense In those Positions */
        break;

    case INT2:
        switch (Copy_pEXTI_t_Obj->EXTI_u8IntSense)
        {
        case FALLING_EDGE:
            CLR_BIT(MCUCSR, MCUCSR_ISC2);
            break;
        case RISING_EDGE:
            SET_BIT(MCUCSR, MCUCSR_ISC2);
            break;
        default:
            /* Do Nothing */
            break;
        }
        break;

    default:
        /* Do Nothing */
        break;
    }
}

void EXTI_voidEnable(EXTI_t* Copy_pEXTI_t_Obj)
{
    switch (Copy_pEXTI_t_Obj->EXTI_u8IntNum)
    {
    case INT0:
        SET_BIT(GICR, GICR_INT0);
        break;
    case INT1:
        SET_BIT(GICR, GICR_INT1);
        break;
    case INT2:
        SET_BIT(GICR, GICR_INT2);
        break;
    default:
        break;
    }
}
void EXTI_voidDisable(EXTI_t* Copy_pEXTI_t_Obj)
{
    switch (Copy_pEXTI_t_Obj->EXTI_u8IntNum)
    {
    case INT0:
        CLR_BIT(GICR, GICR_INT0);
        break;
    case INT1:
        CLR_BIT(GICR, GICR_INT1);
        break;
    case INT2:
        CLR_BIT(GICR, GICR_INT2);
        break;
    default:
        break;
    }
}


#endif /* EXTI_PRIVATE_H */