/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Timer_interface.h
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
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#define Normal_MODE         0
#define CTC_MODE            1

void TIMER0_voidInit(void);
void TIMER0_voidSetBusyWaitMS_OVFMode(u32 Copy_u32DelayMS);
void TIMER0_voidSetBusyWaitMS_CTCMode(u32 Copy_u32DelayMS);
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);
void TIMER0_voidSetCTCCompareMatchValue(u8 Copy_u8Value);
void TIMER0_voidSetOVFCallback(void (*pvoidNotificationFunction(void)));
void TIMER0_voidSetCTCCallback(void (*pvoidNotificationFunction(void)));
void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode);

// set mode in run time

#endif /* TIMER_INTERFACE_H */