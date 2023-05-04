/*
 * ----------------------------------------------------------------------------------
 * Filename     :	KPD_program.h
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

/* Library Inclusions */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
/* Lower Layer Inclusions */
#include "../../MCAL/DIO/DIO_interface.h"
/* Self Files Inclusions */
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

void KPD_voidInit(void)
{
   /* Set Rows Pins To Be Input PulldUp */
   MDIO_voidSetPinDir(KPD_ROWS_PORT, KPD_ROW0_PIN, INPUT_PULLUP);
   MDIO_voidSetPinDir(KPD_ROWS_PORT, KPD_ROW1_PIN, INPUT_PULLUP);
   MDIO_voidSetPinDir(KPD_ROWS_PORT, KPD_ROW2_PIN, INPUT_PULLUP);
   MDIO_voidSetPinDir(KPD_ROWS_PORT, KPD_ROW3_PIN, INPUT_PULLUP);

   /* Set Columns Pins To Be Output High */
   MDIO_voidSetPinDir(KPD_COLUMNS_PORT, KPD_COL0_PIN, OUTPUT);
   MDIO_voidSetPinDir(KPD_COLUMNS_PORT, KPD_COL1_PIN, OUTPUT);
   MDIO_voidSetPinDir(KPD_COLUMNS_PORT, KPD_COL2_PIN, OUTPUT);
   MDIO_voidSetPinDir(KPD_COLUMNS_PORT, KPD_COL3_PIN, OUTPUT);

   MDIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COL0_PIN, HIGH);
   MDIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COL1_PIN, HIGH);
   MDIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COL2_PIN, HIGH);
   MDIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COL3_PIN, HIGH);
}

u8 KPD_u8GetPressedKey(void)
{
    static u8 Local_u8KPDArray[KPD_ROWS_NUM][KPD_COLUMNS_NUM] = KPD_ARR_VAL;
    static u8 Local_u8KPDColumnsArray[KPD_COLUMNS_NUM] = {KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN, KPD_COL3_PIN};
    static u8 Local_u8KPDRowsArray[KPD_ROWS_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
    u8 Local_u8RowValue;
    u8 Local_u8PressedKey = KPD_NOT_PRESSED_VAL;

    u8 Local_u8ColumnsIterator;
    u8 Local_u8RowsIterator;
    for(Local_u8ColumnsIterator = 0; Local_u8ColumnsIterator < KPD_COLUMNS_NUM; Local_u8ColumnsIterator++)
    {
        /* Activate A Column, Activate (Ground) */
        MDIO_voidSetPinValue(KPD_COLUMNS_PORT, u8_Local_u8KPDColumnsArray[Local_u8ColumnsIterator], LOW);
        /* Iterate On The KPD Rows */
        for(Local_u8RowsIterator = 0; Local_u8RowsIterator < KPD_ROWS_NUM, Local_u8RowsIterator++)
        {
            /* Get The Pin Value */
            MDIO_voidGetPinValue(KPD_COLUMNS_PORT,Local_u8KPDRowsArray[Local_u8RowsIterator], &Local_u8RowValue);
            if(Local_u8RowValue == LOW)
            {
                /* Get The Pressed Key */
                Local_u8PressedKey = Local_u8KPDArray[Local_u8RowsIterator][Local_u8ColumnsIterator];
                
                /* Polling The (busy wait) till the key is released */
                while(Local_u8RowValue == LOW)
                {
                    MDIO_voidGetPinValue(KPD_COLUMNS_PORT,Local_u8KPDRowsArray[Local_u8RowsIterator], &Local_u8RowValue);
                }

                /* Return The Pressed Key */
                return Local_u8PressedKey;
            }
        }
        /* Dectivate A Column, Activate (VCC) */
        MDIO_voidSetPinValue(KPD_COLUMNS_PORT, u8_Local_u8KPDColumnsArray[Local_u8ColumnsIterator], HIGH);
    }

    return Local_u8PressedKey;
}