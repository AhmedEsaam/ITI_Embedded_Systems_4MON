/*
 * ----------------------------------------------------------------------------------
 * Filename     :	main.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 17, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>
#include "LIB/STD_TYPES.h"
#include "DynamicQueue.h"

int main()
{

    u8 Local_u8ReturnedValue;

    // DynamicQueue_voidEnQueue(1);
    // DynamicQueue_voidEnQueue(2);
    // DynamicQueue_voidEnQueue(3);

    // Local_u8ReturnedValue = DynamicQueue_u8DeQueue();
    // Local_u8ReturnedValue = DynamicQueue_u8DeQueue();
    // Local_u8ReturnedValue = DynamicQueue_u8DeQueue();

    /* Check EnQueue When QueueFront = QueueRear */
    DynamicQueue_voidEnQueue(3);
    Local_u8ReturnedValue = DynamicQueue_u8DeQueue();
    DynamicQueue_voidEnQueue(6);

    return 0;
}
