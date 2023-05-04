/*
 * ----------------------------------------------------------------------------------
 * Filename		:	DMA_Stack.c
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	Mar 16, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIB/STD_TYPES.h"
#include "DMA_Stack.h"

struct Node
{
    u8 Data;
    struct Node * PointerToNextNode;
};

struct Node * HEAD = NULL;
struct Node * TOP = NULL;


void    DMA_Stack_voidPush(u8 Copy_u8UserData)
{
    /* Declare And Reserve A New Node Pointer To Struct */
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode -> Data = Copy_u8UserData;
    NewNode -> PointerToNextNode = NULL;

    if (HEAD == NULL)
    {
        /* HEAD And TOP Pointers Point To The First Created Node */
        HEAD = NewNode;
        TOP = NewNode;
    }
    else
    {
        /* TOP Node Pointer To Next Node Points To The Created Node */
        TOP -> PointerToNextNode = NewNode;
        /* TOP Points To The Created Node*/
        TOP = NewNode;
    }
}

u8      DMA_Stack_u8Pop(void)
{
    if(DMA_Stack_u8IsEmpty())
    {
        printf("Stack Is Empty\n");
        return;
    }
    else
    {
        /* Save The TOP Node Data */
        u8 UserData =  TOP -> Data;
        /* Move The TOP Pointer to Point To The Previos Node */
        struct Node * CurrentNode = HEAD;
        struct Node * PreviosNode = HEAD;
        while(CurrentNode -> PointerToNextNode != NULL)
        {
            PreviosNode = CurrentNode;
            CurrentNode = CurrentNode -> PointerToNextNode;
        }
        /* Free The Node That TOP Is Pointing To */
        free(TOP);
        /* TOP is Pointing To The Previos Node */
        TOP = PreviosNode;
        TOP -> PointerToNextNode = NULL;
        /* Return User Data */
        return UserData;
    }
}

u8      DMA_Stack_u8Top(void)
{
    if(DMA_Stack_u8IsEmpty())
    {
        printf("Stack Is Empty\n");
        return;
    }
    else
    {
        return TOP -> Data;
    }
}

static u8      DMA_Stack_u8IsEmpty(void)
{
    u8 Status;
    if(TOP == NULL)
    {
        Status = TRUE;
    }
    else
    {
        Status = FALSE;
    }
    return Status;
}

