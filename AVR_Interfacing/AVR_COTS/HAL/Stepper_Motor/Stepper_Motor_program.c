/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Stepper_Motor_program.c
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

#include "util//delay.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/ULN2003/ULN2003_interface.h"

#include "Stepper_Motor_interface.h"
#include "Stepper_Motor_private.h"
#include "Stepper_Motor_config.h"

Stepper_Motor_Err_t Stepper_Motor_voidConfigure(Stepper_Motor_t * Copy_Stepper_MotorName)
{
    /* Set The Stepper Motor Error Handling Initial State */
    Stepper_Motor_Err_t Local_Stepper_MotorErrorState = Stepper_MotorOk;

    /* Checking Stepper Motor Direction, and UNL2003 Configuration */
    if( Copy_Stepper_MotorName->Stepper_Motor_InitialDirection                                 >   Stepper_Motor_CounterClockWise   ||
        ULN2003_voidConfigure(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs)) !=  ULN2003Ok  
        )
    {
        /* Set Error Handling State */
        Local_Stepper_MotorErrorState = Stepper_MotorInvalidConfiguration;
    }
    else
    {
        /* Set The Stepper Motor Initial Direction to be 'Motor Stop' By Setting UNL2003 IC Bases Value to be All Ones */
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
    }

    /* Return Error Handling State */
    return Local_Stepper_MotorErrorState;
}

Stepper_Motor_Err_t Stepper_Motor_voidChangeDirection(Stepper_Motor_t * Copy_Stepper_MotorName, u8 Copy_Stepper_MotorDirection)
{
    /* Set The Stepper Motor Error Handling Initial State */
    Stepper_Motor_Err_t Local_Stepper_MotorErrorState = Stepper_MotorOk;

    /* Check The Stepper Motor Direction */
    switch (Copy_Stepper_MotorName->Stepper_Motor_InitialDirection)
    {
    case Stepper_Motor_Stop:
       /* Set The Stepper Motor Direction to be 'Motor Stop' By Setting UNL2003 IC Bases Value to be All Ones */
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
        _delay_ms(10);
        break;
    
    case Stepper_Motor_ClockWise:
       /* Set The Stepper Motor Direction to be 'Clock Wise' By Setting UNL2003 IC Bases Value to Change From Blue Coil to Orange Coil */
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), BLUE_COIL);
        _delay_ms(10);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), PINK_COIL);
        _delay_ms(10);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), YELLOW_COIL);
        _delay_ms(10);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), ORANGE_COIL);
        _delay_ms(10);
        break;

    case Stepper_Motor_CounterClockWise:
       /* Set The Stepper Motor Direction to be 'Counter Clock Wise' By Setting UNL2003 IC Bases Value to Change From Orange Coil to Blue Coil */
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), ORANGE_COIL);
        _delay_ms(10);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), YELLOW_COIL);
        _delay_ms(10);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), PINK_COIL);
        _delay_ms(10);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
        ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), BLUE_COIL);
        break;

    default:
        /* Set Error Handling State */
        Local_Stepper_MotorErrorState = Stepper_MotorInvalidDirection;
        break;
    }

    /* Return Error Handling State */
    return Local_Stepper_MotorErrorState;
}

Stepper_Motor_Err_t Stepper_Motor_voidChangeAngle(Stepper_Motor_t * Copy_Stepper_MotorName, u8 Copy_Stepper_MotorDirection, u16 Copy_Stepper_MotorAngle)
{
    u32 Local_u32Steps;
    u16 Local_u16NoOfIterations;
    u16 Local_u16Counter;
    /* Set The Stepper Motor Error Handling Initial State */
    Stepper_Motor_Err_t Local_Stepper_MotorErrorState = Stepper_MotorOk;

    /* Check The Stepper Motor Angle */
    if(Copy_Stepper_MotorAngle > 360)
    {
        /* Set Error Handling State */
        Local_Stepper_MotorErrorState = Stepper_MotorInvalidAngle;
    }
    else
    {
        /* Calculate The Number Of Iterations Needed To Make The Required Angle (Assuming Stride Angle = 5.625/64)*/
        Local_u32Steps = ((u32)Copy_Stepper_MotorAngle * 2048UL) / 360UL;
        Local_u16NoOfIterations = (u16)(Local_u32Steps / 4UL);

        /* Check The Stepper Motor Direction */
        switch (Copy_Stepper_MotorName->Stepper_Motor_InitialDirection)
        {
        case Stepper_Motor_Stop:
            /* Set The Stepper Motor Direction to be 'Motor Stop' By Setting UNL2003 IC Bases Value to be All Ones */
            ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
            break;
        
        case Stepper_Motor_ClockWise:
            for (Local_u16Counter = 0; Local_u16Counter < Local_u16NoOfIterations; Local_u16Counter++)
            {
                /* Set The Stepper Motor Direction to be 'Clock Wise' By Setting UNL2003 IC Bases Value to Change From Blue Coil to Orange Coil */
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), BLUE_COIL);
                _delay_ms(10);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), PINK_COIL);
                _delay_ms(10);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), YELLOW_COIL);
                _delay_ms(10);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), ORANGE_COIL);
                _delay_ms(10);
            }
            break;

        case Stepper_Motor_CounterClockWise:
            for (Local_u16Counter = 0; Local_u16Counter < Local_u16NoOfIterations; Local_u16Counter++)
            {
                /* Set The Stepper Motor Direction to be 'Counter Clock Wise' By Setting UNL2003 IC Bases Value to Change From Orange Coil to Blue Coil */
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), ORANGE_COIL);
                _delay_ms(10);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), YELLOW_COIL);
                _delay_ms(10);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), PINK_COIL);
                _delay_ms(10);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), MOTOR_STOP);
                ULN2003_voidChangeBaseValue(&(Copy_Stepper_MotorName->Stepper_Motor_ULN2003DarlingtonPairs), BLUE_COIL);
                _delay_ms(10);
            }
            break;

        default:
            /* Set Error Handling State */
            Local_Stepper_MotorErrorState = Stepper_MotorInvalidDirection;
            break;
        }
    }
}