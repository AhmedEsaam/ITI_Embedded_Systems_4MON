/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Timer_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 9, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 9, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Timer_interface.h"
#include "Timer_private.h"
#include "Timer_config.h"

static void (*Timer_pvoidOVFNotificationFunction) (void) = NULL;
static void (*Timer_pvoidCTCNotificationFunction) (void) = NULL;

void TIMER0_voidInit(void)
{
    /* Set Normal Mode */
    // CLR_BIT(TCCR0, TCCR0_WGM00);
    // CLR_BIT(TCCR0, TCCR0_WGM01);

    /* Set CTC Mode */
    CLR_BIT(TCCR0, TCCR0_WGM00);
    SET_BIT(TCCR0, TCCR0_WGM01);

    /* Set Prescaler */
    TCCR0 &= CLK_SEL_BIT_MASK;
    TCCR0 |= TIMER_PRESCALER_VALUE;
}
void TIMER0_voidSetBusyWaitMS_OVFMode(u32 Copy_u32DelayMS)
{
    u32 Local_u32NumberOfOVF;
    u32 Local_u32Counter = 0;
    Local_u32NumberOfOVF = (Copy_u32DelayMS * 1000UL) / 256UL;

    while(Local_u32Counter < Local_u32NumberOfOVF)
    {
        while(!GET_BIT(TIFR, TIFR_TOV0));
        SET_BIT(TIFR, TIFR_TOV0);
        Local_u32Counter++;
    }
}
void TIMER0_voidSetBusyWaitMS_CTCMode(u32 Copy_u32DelayMS)
{
    TIMER0_voidSetCTCCompareMatchValue(250); // compare value

    u32 Local_u32NumberOfCTCFlag;
    u32 Local_u32Counter = 0;
    Local_u32NumberOfCTCFlag = (Copy_u32DelayMS * 1000UL / 250UL);

    while(Local_u32Counter < Local_u32NumberOfCTCFlag)
    {
        while(!GET_BIT(TIFR, TIFR_OCF0));
        SET_BIT(TIFR, TIFR_OCF0);
        Local_u32Counter++;
    }
}
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value)
{
    TCCR0 = Copy_u8Value;
    
}
void TIMER0_voidSetCTCCompareMatchValue(u8 Copy_u8Value)
{
    OCR0 = Copy_u8Value;
}
void TIMER0_voidSetOVFCallback(void (*pvoidNotificationFunction(void)))
{
    Timer_pvoidOVFNotificationFunction = pvoidNotificationFunction;
}
void TIMER0_voidSetCTCCallback(void (*pvoidNotificationFunction(void)))
{
    Timer_pvoidCTCNotificationFunction = pvoidNotificationFunction;
}
void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode)
{
    if(Copy_u8Mode == Normal_MODE)
    {
        SET_BIT(TIMSK, TIMSK_TOIE0);
    }
    else if(Copy_u8Mode == CTC_MODE)
    {
        SET_BIT(TIMSK, TIMSK_OCIE0);
    }
}
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode)
{
    if(Copy_u8Mode == Normal_MODE)
    {
        CLR_BIT(TIMSK, TIMSK_TOIE0);
    }
    else if(Copy_u8Mode == CTC_MODE)
    {
        CLR_BIT(TIMSK, TIMSK_OCIE0);
    }
}

// CTC ISR
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
    if(Timer_pvoidCTCNotificationFunction != NULL)
    {
        Timer_pvoidCTCNotificationFunction();
    }
}

// OVF ISR
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
    if(Timer_pvoidOVFNotificationFunction != NULL)
    {
        Timer_pvoidOVFNotificationFunction();
    }
}

