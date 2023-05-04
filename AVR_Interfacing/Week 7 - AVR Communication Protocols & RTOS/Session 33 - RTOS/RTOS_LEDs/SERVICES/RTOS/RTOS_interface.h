/*
 * ----------------------------------------------------------------------------------
 * Filename     :	RTOS_interface.c
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
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

void RTOS_voidInit(void);
void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void(*TaskFunction)(void));
void RTOS_voidDeleteTask(u8 Copy_u8Priority);
static void voidScheduler(void);

#endif