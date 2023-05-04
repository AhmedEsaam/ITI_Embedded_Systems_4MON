/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DynamicQueue.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 17, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIB/STD_TYPES.h"
#include "DynamicQueue.h"

struct Node
{
    u8 Data;
    struct Node * PointerToNextNode;
};

struct Node * Queue_NodeFront   = NULL;
struct Node * Queue_NodeRear    = NULL;

void    DynamicQueue_voidEnQueue(u8 Copy_u8UserData)
{
    /* Declare A New Node Pointer To Struct */
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    /* Check If The Heap Is Full */
    if(NewNode == NULL)
    {
        printf("Heap Is Full\n");
    }
    else
    {
        /* Reserve Data in The New Node */
        NewNode -> Data = Copy_u8UserData;
        NewNode -> PointerToNextNode = NULL;
        /* Check If Queue Is Empty */
        if(DynamicQueue_u8IsEmpty())
        {
            Queue_NodeFront     = NewNode;
            Queue_NodeRear      = NewNode;
        }
        else
        {
            /* Queue Rear Pointer To Next Node Points To The Created Node  */
            Queue_NodeRear -> PointerToNextNode = NewNode;
            /* Queue Rear Points To The Created Node */
            Queue_NodeRear = NewNode;
        }
        
    }
}

u8      DynamicQueue_u8DeQueue(void)
{
    u8 Local_u8ReturnedValue;
    if(DynamicQueue_u8IsEmpty())
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        /* Storing The Value At Queue Front */
        Local_u8ReturnedValue = Queue_NodeFront -> Data;
        /* When Doing DeQueue Of The Value At Rear, Then Queue Becomes Empty */
        if(Queue_NodeFront == Queue_NodeRear) /* Queue Becomes Empty */
        {
            Queue_NodeFront   = NULL;
            Queue_NodeRear    = NULL;
        }
        else
        {
            /* Increment Queue Front */
            Queue_NodeFront = Queue_NodeFront -> PointerToNextNode;
        }

        return Local_u8ReturnedValue;
    }
}

u8      DynamicQueue_u8Peak(void)
{
    if(DynamicQueue_u8IsEmpty())
    {
        printf("Queue Is Empty\n");
        
    }
    else
    {
        return Queue_NodeFront -> Data;
    }
}

static u8   DynamicQueue_u8IsEmpty(void)
{
    u8 Local_u8Status;
    if(Queue_NodeFront == NULL)
    {
        Local_u8Status = TRUE;
    }
    else
    {
        Local_u8Status = FALSE;
    }
    return Local_u8Status;
}