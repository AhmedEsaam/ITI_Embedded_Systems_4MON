/*
 * ----------------------------------------------------------------------------------
 * Filename     :	ICU.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 12, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 12, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../HAL/LCD/LCD_interface.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/Timer/Timer_interface.h"

void ICU_HW(void);

volatile u16 App_u16Reading1;
volatile u16 App_u16Reading2;
volatile u16 App_u16Reading3;
volatile u16 App_u16OnTicks = 0;
volatile u16 App_u16PeriodTicks = 0;

void main(void)
{
    /* Set PB3 Output */
    MDIO_voidSetPinDir(DIO_PORT_B, PIN3, OUTPUT);
    /* Set PD6 Input (ICU) */
    MDIO_voidSetPinDir(DIO_PORT_D, PIN6, INPUT_NO_PULLUP);

    /* Initialize LCD */
    LCD_voidInit();
    
    /* Initialize Timer 0 */
    TIMER0_voidInit();
    /* Generate PWM Signal with Period Time = 256usec, On Time = 50usec */
    TIMER0_voidSetCTCCompareMatchValue(50);

    /* Set The Trigger to be Rising Edge */
    ICU_voidSetTriggerSignal(ICU_RISING_EDGE);
    /* Clear The Timer Counter Register */
    TIMER1_voidClearTCNT1();
    
    /* Set The ICU Callback */
    ICU_vodSetCallBack(&ICU_HW);

    /* Enable ICU Interrupt */
    ICU_voidInterruptControl(ICU_ENABLE);

    /* Enable Global Interrupt */
    GIE_voidEnableGlobalInterrupt();
    /* Initialize Timer 1 */
    TIMER1_voidInit();

    while (1)
    {
        /* Stuck In This Line Till The OnTicks & PeriodTicks Are Changed */
        while(App_u16OnTicks == 0 || App_u16PeriodTicks == 0);
        LCD_voidGoToXY(0, 0);
        LCD_voidSendString("P.T = ");
        LCD_voidSendNumber(App_u16PeriodTicks);
        LCD_voidGoToXY(1, 0);
        LCD_voidSendString("O.T = ");
        LCD_voidSendNumber(App_u16OnTicks);

    }
    
}

void ICU_HW(void)
{
    static u8 Local_u8COunter = 0;
    Local_u8COunter++;
    if(Local_u8COunter == 1) // You are in state 1
    {
        /* Read The ICR1 Register And Store Its Value in Reading1 Variable */
        App_u16Reading1 = ICU_u16GetICRRegister();
        /* Change The Sense Trigger Signal To Be Falling Edge */
        ICU_voidSetTriggerSignal(ICU_FALLING_EDGE);
    }
    else if(Local_u8COunter == 2) // You are in state 2
    {
        /* Read The ICR1 Register And Store Its Value in Reading2 Variable */
        App_u16Reading2 = ICU_u16GetICRRegister();

        /* Calculate On Ticks */
        App_u16OnTicks = App_u16Reading2 - App_u16Reading1 - 1;
    }
    else if(Local_u8COunter == 3) // You are in state 3
    {
        /* Read The ICR1 Register And Store Its Value in Reading3 Variable */
        App_u16Reading3 = ICU_u16GetICRRegister();

        /* Calculate Period Ticks */
        App_u16PeriodTicks = App_u16Reading3 - App_u16Reading2 - 1;
        /* Disable The ICU Interrupt */
        ICU_voidInterruptControl(ICU_DISABLE);

        /* Reset The Counter */
        Local_u8COunter = 0;
    }
}
