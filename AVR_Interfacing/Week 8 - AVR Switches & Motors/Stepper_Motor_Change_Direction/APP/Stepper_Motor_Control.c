/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Stepper_Motor_Control.c
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

#include "../HAL/ULN2003/ULN2003_interface.h"
#include "../HAL/Stepper_Motor/Stepper_Motor_interface.h"
#include "../HAL/LCD/LCD_interface.h"

void Tactile_0_Action(void);
void Tactile_1_Action(void);
Stepper_Motor_t Local_Stepper_Motor_1;

int main(void)
{
    /* Create 2 External Interrupts for The Tactiles Action */
    EXTI_t Local_EXTI0 = {INT0, FALLING_EDGE};
    EXTI_t Local_EXTI1 = {INT1, FALLING_EDGE};
    
    /* Create a ULN2003 */
    ULN2003_t ULN2003 = {   .ULN2003_Base_PortName  = DIO_PORT_C,
                            .ULN2003_PortPins       = ULN2003_LowerHalf };

    /* Stepper Motor Connected With A ULN2003 IC and Initially Stopped */
    Local_Stepper_Motor_1.Stepper_Motor_ULN2003DarlingtonPairs  = ULN2003;
    Local_Stepper_Motor_1.Stepper_Motor_InitialDirection        = Stepper_Motor_Stop;

    /* DC Motor Configuration */
    Stepper_Motor_voidConfigure(&Local_Stepper_Motor_1);
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
    // Turn Motor Clock Wise 180 degrees
    Stepper_Motor_voidChangeAngle(&Local_Stepper_Motor_1, Stepper_Motor_ClockWise, 180);

    /* Display on Screen */
    LCD_voidClearDisplay();
    LCD_voidSendString("Direction:");
    LCD_voidGoToXY(1, 0);
    LCD_voidSendString("180 Degrees CW");
}

void Tactile_1_Action(void)
{
    // Turn Motor Anti Clock Wise 180 degrees
    Stepper_Motor_voidChangeAngle(&Local_Stepper_Motor_1, Stepper_Motor_CounterClockWise, 180);

    /* Display on Screen */
    LCD_voidClearDisplay();
    LCD_voidSendString("Direction:");
    LCD_voidGoToXY(1, 0);
    LCD_voidSendString("180 Degrees CCW");
}