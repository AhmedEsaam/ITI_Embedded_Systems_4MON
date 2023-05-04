/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Motor_Control.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 28, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 28, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "util//delay.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/Timer/Timer_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"

#include "../HAL/Transistor/Transistor_interface.h"
#include "../HAL/H_Bridge/H_Bridge_interface.h"
#include "../HAL/DC_Motor/DC_Motor_interface.h"
#include "../HAL/LCD/LCD_interface.h"

void Tactile_0_Action(void);
void Tactile_1_Action(void);
DC_Motor_t Local_DC_Motor1;

int main(void)
{
    /* Create 2 External Interrupts for The Tactiles Action */
    EXTI_t Local_EXTI0 = {INT0, FALLING_EDGE};
    EXTI_t Local_EXTI1 = {INT1, FALLING_EDGE};
    
    /* Create A Transistor for the (T1 & T4) Left-to-Right H-Bridge Transistor Pair */
    Transistor_t Local_TransistorPairLeftToRight = {.Transistor_PortName       = DIO_PORT_D,
                                                    .Transistor_PinNumber      = PIN0,
                                                    .Transistor_Type           = Transistor_NPN,
                                                    .Transistor_InitialState   = Transistor_Cutoff};

    /* Create A Transistor for the (T2 & T3) Right-to-Left H-Bridge Transistor Pair */
    Transistor_t Local_TransistorPairRightToLeft = {.Transistor_PortName       = DIO_PORT_D,
                                                    .Transistor_PinNumber      = PIN1,
                                                    .Transistor_Type           = Transistor_NPN,
                                                    .Transistor_InitialState   = Transistor_Cutoff};

    /* Create an H-Bridge with Initial Polarity set to 'Stop' */
    H_Bridge_t Local_H_Bridge1 = {  .H_Bridge_LeftToRightTransistorPair = Local_TransistorPairLeftToRight,
                                    .H_Bridge_RightToLeftTransistorPair = Local_TransistorPairRightToLeft,
                                    .H_Bridge_InitialPolarity           = H_Bridge_Stop };

    /* DC-Motor Connected with an H-Bridge and Initial Direction set to 'Stop' */
    Local_DC_Motor1.DC_Motor_H_Bridge          =    Local_H_Bridge1;
    Local_DC_Motor1.DC_Motor_InitialDirection  =    DC_Motor_Stop;

    /* DC Motor Configuration */
    DC_Motor_voidConfigure(&Local_DC_Motor1);
    /* LCD Initialization */
    LCD_voidInit();
    /* GIE Enable */
    GIE_voidEnableGlobalInterrupt();
    /* Tactile 0 Interrupt Configuration */
    EXTI_voidInitPinConnection(&Local_EXTI0);
    EXTI_voidTriggerEdge(&Local_EXTI0);
    EXTI_voidSetCallback(&Local_EXTI0, &Tactile_0_Action);
    EXTI_voidEnable(&Local_EXTI0);
    /* Tactile 1 Interrupt Configuration */
    EXTI_voidInitPinConnection(&Local_EXTI1);
    EXTI_voidTriggerEdge(&Local_EXTI1);
    EXTI_voidSetCallback(&Local_EXTI1, &Tactile_1_Action);
    EXTI_voidEnable(&Local_EXTI1);

    while (1)
    {
        ;
    }

    return 0;
}


void Tactile_0_Action(void)
{
    // Turn Motor Clock Wise
    DC_Motor_voidChangeDirection(&Local_DC_Motor1, DC_Motor_ClockWise);

    /* Display on Screen */
    LCD_voidClearDisplay();
    LCD_voidSendString("Direction:");
    LCD_voidGoToXY(1, 0);
    LCD_voidSendString("Clock Wise");
}

void Tactile_1_Action(void)
{
    // Turn Motor Anti Clock Wise
    DC_Motor_voidChangeDirection(&Local_DC_Motor1, DC_Motor_AntiClockWise);

    /* Display on Screen */
    LCD_voidClearDisplay();
    LCD_voidSendString("Direction:");
    LCD_voidGoToXY(1, 0);
    LCD_voidSendString("Anti Clock Wise");
}