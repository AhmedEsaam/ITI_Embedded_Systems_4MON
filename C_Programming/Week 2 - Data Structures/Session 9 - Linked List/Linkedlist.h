/*
 * ----------------------------------------------------------------------------------
 * Filename		:	LinkedList.h
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	Mar 14, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../../../Utilities/STD_TYPES.h"

void LinkedList_voidInsertNodeAtTail(u32 UserData);
void LinkedList_voidInsertNodeAtHead(u32 UserData);
void LinkedList_voidInsertNodeAtIndex(u32 UserData, u32 Index);

void LinkedList_voidDeleteNode(u32 UserData);
void LinkedList_voidSearchForNode(u32 UserData);
void LinkedList_voidTraverse(void);

#endif /* LINKED_LIST */
