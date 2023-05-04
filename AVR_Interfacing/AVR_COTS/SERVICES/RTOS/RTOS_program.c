/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RTOS_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 20, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 20, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/Timer/Timer_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"

#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

static Task_t SystemTasks[NUMBER_OF_TASKS] = {{0}};

void RTOS_voidInit(void)
{
    /* Set The Compare Match Value To 125 To Make CTC Event Every 1 msec */
    TIMER0_voidSetCTCCompareMatchValue(125);
    /* Set The Callback For Timer0 To Call Scheduler Function For Each Interrupt */
    TIMER0_voidSetCTCCallback(&voidScheduler);
    /* Enable The CTC Mode Interrupt */
    TIMER0_voidEnableInterrupt(CTC_MODE);
    /* Enable Global Interrupt */
    GIE_voidEnableGlobalInterrupt();
    /* Set The CTC Mode, Prescaler = 64 */
    TIMER0_voidInit();
}

void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void(*TaskFunction)(void))
{
    SystemTasks[Copy_u8Priority].Priority = Copy_u8Priority;
    SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
    SystemTasks[Copy_u8Priority].TaskFunc = TaskFunction;
    // SystemTasks[Copy_u8Priority].State = READY;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
    SystemTasks[Copy_u8Priority].TaskFunc = NULL;
    // SystemTasks[Copy_u8Priority].State = DELETED;
}

static void voidScheduler(void)
{
    /* Algorithm = Priority Based */
    static u32 Local_u32TickCounter = 0;
    Local_u32TickCounter++;
    u8 Local_u8LoopCounter;
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < NUMBER_OF_TASKS; Local_u8LoopCounter++)
    {
        // if(SystemTasks[Local_u8LoopCounter].State == READY)
        // {
        if(Local_u32TickCounter % SystemTasks[Local_u8LoopCounter].Periodicity == 0)
        {
            /* Execute The Task Function */
            SystemTasks[Local_u8LoopCounter].TaskFunc();
        }
        // }
    }
}
