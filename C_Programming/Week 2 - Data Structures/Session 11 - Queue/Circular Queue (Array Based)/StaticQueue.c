/*
 * ----------------------------------------------------------------------------------
 * Filename     :   StaticQueue.c
 *
 * Author       :   Ahmed Essam El-Mogy
 * Created on	:	Mar 16, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>
#include "LIB/STD_TYPES.h"
#include "StaticQueue.h"

u8 Queue_s8Arr[QUEUE_SIZE] = {0};   /* It's Better to Not Initialize */
s8 Queue_s8Front   = -1;
s8 Queue_s8Rear    = -1;

void    Queue_voidEnQueue(u8 Copy_u8UserData)
{
    /* Check If The Queue Is Full */
    if(Queue_u8IsFull())
    {
        printf("Queue Is Full\n");
    }
    else
    {
        /* Check If Queue Is Empty */
        if(Queue_s8Front == -1)
        {
            Queue_s8Front = 0;
        }
        /* Increment Queue Rear Then Assign The Value In The New Place */
        Queue_s8Rear = (Queue_s8Rear + 1) % QUEUE_SIZE;     /* Circular Queue */
        Queue_s8Arr[Queue_s8Rear] = Copy_u8UserData;
    }
}

u8      Queue_u8DeQueue(void)
{
    u8 Local_u8ReturnedValue;
    if(Queue_u8IsEmpty())
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        /* Storing The Value At Queue Front */
        Local_u8ReturnedValue = Queue_s8Arr[Queue_s8Front];
        /* When Doing DeQueue Of The Value At Rear, Then Queue Becomes Empty */
        if(Queue_s8Front == Queue_s8Rear) /* Queue Becomes Empty */
        {
            Queue_s8Front   = -1;
            Queue_s8Rear    = -1;
        }
        else
        {
            /* Increment Queue Front */
            Queue_s8Front = (Queue_s8Front + 1) % QUEUE_SIZE;
        }

        return Local_u8ReturnedValue;
    }
}

u8      Queue_u8Peak(void)
{
    if(Queue_s8Front == -1)
    {
        printf("Queue Is Empty\n");
        
    }
    else
    {
        return Queue_s8Arr[Queue_s8Front];
    }
}

static u8   Queue_u8IsFull(void)
{
    u8 Local_u8Status;
    /* Check If All The Circular Queue Elements Are Occupied */
    if(((Queue_s8Front == 0) && (Queue_s8Rear == (QUEUE_SIZE - 1))) || (Queue_s8Front == Queue_s8Rear + 1))
    {
        Local_u8Status = TRUE;
    }
    else
    {
        Local_u8Status = FALSE;
    }
    return Local_u8Status;

}

static u8   Queue_u8IsEmpty(void)
{
    u8 Local_u8Status;
    if(Queue_s8Front == -1)
    {
        Local_u8Status = TRUE;
    }
    else
    {
        Local_u8Status = FALSE;
    }
    return Local_u8Status;
}