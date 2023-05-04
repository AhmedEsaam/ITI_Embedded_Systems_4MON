/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DC_Motor_interface.h
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

#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H

typedef enum
{
	DC_Motor_Stop,
	DC_Motor_ClockWise,
	DC_Motor_AntiClockWise,
}DC_Motor_Direction_t;

typedef struct 
{
	H_Bridge_t 				DC_Motor_H_Bridge;
	DC_Motor_Direction_t	DC_Motor_InitialDirection;
}DC_Motor_t;


typedef enum
{
	DC_MotorOk,
	DC_MotorInvalidConfiguration,
	DC_MotorInvalidDirection,
}DC_Motor_Err_t;

DC_Motor_Err_t DC_Motor_voidConfigure(DC_Motor_t * Copy_DC_MotorName);
DC_Motor_Err_t DC_Motor_voidChangeDirection(DC_Motor_t * Copy_DC_MotorName, DC_Motor_Direction_t Copy_DC_MotorPolarity);

#endif /* DC_MOTOR_INTERFACE_H */
