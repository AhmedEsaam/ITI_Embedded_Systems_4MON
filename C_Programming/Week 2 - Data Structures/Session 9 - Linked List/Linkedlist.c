/*
 * ----------------------------------------------------------------------------------
 * Filename		:	LinkedList.c
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	Mar 14, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"

struct Node
{
    u8 Data;
    struct Node * PointerToNextNode;
};

struct Node * Head = NULL;


void LinkedList_voidInsertNodeAtTail(u32 UserData)
{
    /* Declare And Reserve A New Node Pointer To Struct */
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode -> Data = UserData;
    NewNode -> PointerToNextNode = NULL;

    /* Check If The Linked List Is Empty or Not */
    if (Head == NULL)
    {
        /* Head Pointer Points To The First Created Node */
        Head = NewNode;
    }
    else
    {
        /* Last Pointer In The Linked List Points To The Created Node */

        struct Node *TempPtr;
        TempPtr = Head;
        /* Loop Till Reach The Last Node */
        while(TempPtr -> PointerToNextNode != NULL)
        {
            TempPtr = TempPtr -> PointerToNextNode;
        }
        /* Last Node Pointer To Next Points To The New Node */
        TempPtr -> PointerToNextNode = NewNode;
    }
}

void LinkedList_voidInsertNodeAtHead(u32 UserData)
{
    /* Declare And Reserve A New Node Pointer To Struct */
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode -> Data = UserData;
    /* New Node Pointes to the Node That Head Is Pointing To */
    NewNode -> PointerToNextNode = Head;
    /* Head Pointer Points To The First Created Node */
    Head = NewNode;
}

void LinkedList_voidInsertNodeAtIndex(u32 UserData, u32 Index)
{
    /* Declare And Reserve A New Node Pointer To Struct */
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode -> Data = UserData;
    NewNode -> PointerToNextNode = NULL;

    /* TempNode Points To the Head */
    struct Node *TempNode;
    TempNode = Head;

    /* Check If The Linked List Is Empty or Not */
    if (Index == 1)
    {
        /* New Node Pointes to the Node That Head Is Pointing To */
        NewNode -> PointerToNextNode = Head;
        /* Head Pointer Points To The First Created Node */
        Head = NewNode;
    }
    else
    {
        u32 LoopCounter;
        for(LoopCounter = 2;  LoopCounter < Index; LoopCounter++)
        {
            TempNode = TempNode -> PointerToNextNode;
        }
        NewNode -> PointerToNextNode = TempNode -> PointerToNextNode;
        TempNode -> PointerToNextNode = NewNode;
    }
}

void LinkedList_voidDeleteNode(u32 UserData)
{
    struct Node * CurrentNode;
    struct Node * PreviousNode;
    CurrentNode = Head;
    PreviousNode = Head;
    if(CurrentNode -> Data == UserData)
    {
        Head = CurrentNode -> PointerToNextNode;
        free(CurrentNode);
    }
    else
    {
        while (CurrentNode != NULL && CurrentNode -> Data != UserData)
        {
            PreviousNode = CurrentNode;
            CurrentNode = CurrentNode -> PointerToNextNode;
        }
        if(CurrentNode == NULL)
        {
            /* Error message*/
            return;
        }
        else
        {
            PreviousNode -> PointerToNextNode = CurrentNode -> PointerToNextNode;
            free(CurrentNode);
        }
    }
}

void LinkedList_voidSearchForNode(u32 UserData)
{
    struct Node *TempNode;
    TempNode = Head;

    u8 Index = 0;
    /* Loop Till Reach The Searched Node */
    while(TempNode -> Data != UserData)
    {
        TempNode = TempNode -> PointerToNextNode;
        Index ++;
    }

    if (TempNode -> Data != UserData)
    {
        printf("The Node You Search For Does Not Exist In the Linked List\n");
        
    }
    else
    {
        printf("The Node You Searched For Is At Index %d\n", Index + 1);
    }
    
    

}

void LinkedList_voidTraverse(void)
{
    struct Node * TempNode;
    TempNode = Head;

    /* Print Nodes Data */
    printf("-----------------------------\n");
    u8 Index = 1;
    if (Head == NULL)
    {
        printf("List Is Empty\n");
    } 
    else
    {
        while(TempNode != NULL)
        {
            printf("Node Number %d = %d\n", Index, TempNode -> Data);
            TempNode = TempNode -> PointerToNextNode;
            Index++;
        }
    }
    printf("-----------------------------\n");
}



