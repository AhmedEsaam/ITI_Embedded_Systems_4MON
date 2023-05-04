#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "util/delay.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"

#include "../HAL/LED/LED_interface.h"

static void intAction(void);

LED_t led1 = {DIO_PORT_A, PIN0};
EXTI_t ext = {INT0, FALLING_EDGE};

void main(void)
{
    LED_voidInit(&led1);
    GIE_voidEnableGlobalInterrupt();

    EXTI_voidInitPinConnection(&ext);
    EXTI_voidTriggerEdge(&ext);
    EXTI_voidEnable(&ext);

    LED_voidTurnOff(&led1);
    EXTI_voidSetCallback(&ext, &intAction);
    while(1)
    {
    }
}

static void intAction(void)
{
    LED_voidToggle(&led1);
}



