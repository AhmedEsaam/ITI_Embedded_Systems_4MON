/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LEDMATRIX_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 14, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   HAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 14, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_private.h"
#include "LEDMATRIX_config.h"

u8 Global_u8ColumnsArray[16] = {
    HLEDMATRIX_C0_PIN,
    HLEDMATRIX_C1_PIN,
    HLEDMATRIX_C2_PIN,
    HLEDMATRIX_C3_PIN,
    HLEDMATRIX_C4_PIN,
    HLEDMATRIX_C5_PIN,
    HLEDMATRIX_C6_PIN,
    HLEDMATRIX_C7_PIN,
};

u8 Global_u8RowsArray[16] = {
    HLEDMATRIX_R0_PIN,
    HLEDMATRIX_R1_PIN,
    HLEDMATRIX_R2_PIN,
    HLEDMATRIX_R3_PIN,
    HLEDMATRIX_R4_PIN,
    HLEDMATRIX_R5_PIN,
    HLEDMATRIX_R6_PIN,
    HLEDMATRIX_R7_PIN,
};

void  HLEDMATRIX_voidInit(void)
{
    u8 Local_u8ColumnPin;
    u8 Local_u8RowPin;

    
    /* Initialize Rows and Columns Pins To be Output */
    for (Local_u8ColumnPin = 0; Local_u8ColumnPin < 8; Local_u8ColumnPin++)
    {
        MGPIO_ErrSetPinMode(HLEDMATRIX_C_PORT, Global_u8ColumnsArray[Local_u8ColumnPin], GPIO_OUTPUT);

    }

    for (Local_u8RowPin = 0; Local_u8RowPin < 8; Local_u8RowPin++)
    {
        MGPIO_ErrSetPinMode(HLEDMATRIX_R_PORT, Global_u8RowsArray[Local_u8RowPin], GPIO_OUTPUT);

    }

    /* Disbale Port Values */
    MGPIO_ErrSetPortValue(HLEDMATRIX_C_PORT, HIGH);

}

void HLEDMATRIX_voidDisplay(u8 * Copy_pu8Data)
{
    u8 Local_u8ColumnIndex = 0;
    u8 Local_u8RowIndex = 0;
    u8 Local_u8Bit = 0;

   
    for (Local_u8ColumnIndex = 0; Local_u8ColumnIndex < 8; Local_u8ColumnIndex++)
    {
         /* Disbale Port Values */
        MGPIO_ErrSetPortValue(HLEDMATRIX_C_PORT, HIGH);

        for (Local_u8RowIndex = 0; Local_u8RowIndex < 8; Local_u8RowIndex++)
        {
            Local_u8Bit = GET_BIT(Copy_pu8Data[Local_u8ColumnIndex], Local_u8RowIndex);
            MGPIO_ErrSetPinValue(HLEDMATRIX_R_PORT, Global_u8RowsArray[Local_u8RowIndex], Local_u8Bit);
        }
        MGPIO_ErrSetPinValue(HLEDMATRIX_C_PORT, Global_u8ColumnsArray[Local_u8ColumnIndex], LOW);
    	MSYSTICK_ErrSetBusyWait(2500);
    }
}
