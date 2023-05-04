/*
 * ----------------------------------------------------------------------------------
 * Filename		:	main.c
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	Mar 16, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>
#include "LIB/STD_TYPES.h"
#include "StaticQueue.h"

int main()
{

    u8 Local_u8ReturnedValue;

    /* Check EnQueue Overflow */

    // Queue_voidEnQueue(1);
    // Queue_voidEnQueue(2);


    /* Check DeQueue UnderFlow */

    // Local_u8ReturnedValue = Queue_u8DeQueue();
    // Local_u8ReturnedValue = Queue_u8DeQueue();

    /* Check EnQueue When QueueFront = QueueRear */
    Queue_voidEnQueue(3);
    Local_u8ReturnedValue = Queue_u8DeQueue();
    Queue_voidEnQueue(6);

    return 0;
}
