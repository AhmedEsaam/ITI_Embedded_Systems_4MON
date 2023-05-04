/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Stepper_Motor_interface.h
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

#ifndef STEPPER_MOTOR_INTERFACE_H
#define STEPPER_MOTOR_INTERFACE_H

typedef enum
{
	Stepper_Motor_Stop,
	Stepper_Motor_ClockWise,
	Stepper_Motor_CounterClockWise
}Stepper_Motor_Direction_t;

typedef struct 
{
	ULN2003_t 					Stepper_Motor_ULN2003DarlingtonPairs;
	Stepper_Motor_Direction_t 	Stepper_Motor_InitialDirection;
}Stepper_Motor_t;


typedef enum
{
	Stepper_MotorOk,
	Stepper_MotorInvalidConfiguration,
	Stepper_MotorInvalidDirection,
	Stepper_MotorInvalidAngle,
}Stepper_Motor_Err_t;

Stepper_Motor_Err_t Stepper_Motor_voidConfigure(Stepper_Motor_t * Copy_Stepper_MotorName);
Stepper_Motor_Err_t Stepper_Motor_voidChangeDirection(Stepper_Motor_t * Copy_Stepper_MotorName, u8 Copy_Stepper_MotorDirection);
Stepper_Motor_Err_t Stepper_Motor_voidChangeAngle(Stepper_Motor_t * Copy_Stepper_MotorName, u8 Copy_Stepper_MotorDirection, u16 Copy_Stepper_MotorAngle);

#endif /* STEPPER_MOTOR_INTERFACE_H */
