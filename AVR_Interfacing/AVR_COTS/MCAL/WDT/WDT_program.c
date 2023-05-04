/*
 * ----------------------------------------------------------------------------------
 * Filename     :	WDT_program.c
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
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void WDT_voidEnable(void)
{
    /* Set The WDE Bit to Enable The WatchDog Timer */
    SET_BIT(WDTCR, WDTCR_WDE);
}
void WDT_voidSleep(u8 Copy_u8TimeOut)
{
    /* Mask (clear) The First Three Bits In The WDTCR (WDP2:0) */
    WDTCR &= 0b11111000;
    /* Set The Timeout To WDT */
    WDTCR |= Copy_u8TimeOut;
}
void WDT_voidDisable(void)
{
    /* WDT Disbale Sequence :
        1- WDTOE, WDE -> 1 @ The Same Time
        2- Write 0 On WDE -> Withing The Next Four Clock Cycles */
    WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);
    WDTCR = 0;
}
