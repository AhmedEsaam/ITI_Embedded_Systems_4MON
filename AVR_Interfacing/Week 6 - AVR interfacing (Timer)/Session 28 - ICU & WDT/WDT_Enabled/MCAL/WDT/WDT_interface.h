/*
 * ----------------------------------------------------------------------------------
 * Filename     :	WDT_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 12, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		    Author			        Description
 * v1.0		    APR 12, 2023	Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#define WDT_SLEEP_16_3_MS       0b000
#define WDT_SLEEP_23_5_MS       0b001
#define WDT_SLEEP_64_0_MS       0b010

void WDT_voidEnable(void);
void WDT_voidDisnable(void);
void WDT_voidSleep(u8 Copy_u8TimeOut);

#endif /* WDT_INTERFACE_H */