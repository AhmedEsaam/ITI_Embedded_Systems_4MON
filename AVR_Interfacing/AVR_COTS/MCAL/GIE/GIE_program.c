/*
 * ----------------------------------------------------------------------------------
 * Filename     :	GIE_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 28, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 28, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"

void GIE_voidEnableGlobalInterrupt(void)
{
    SET_BIT(SREG, SREG_BIT7);
}

void GIE_voidDisableGlobalInterrupt(void)
{
    CLR_BIT(SREG, SREG_BIT7);
}