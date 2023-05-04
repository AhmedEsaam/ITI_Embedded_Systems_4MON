/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RTOS_private.c
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
#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

typedef enum
{
    Deleted,
    Ready,
}States_t;

typedef struct
{
    u8 Priority;
    u16 Periodicity;
    States_t State;
    void (*TaskFunc)(void);
}Task_t;



static void voidScheduler(void);

#endif
