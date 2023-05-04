/*
 * ----------------------------------------------------------------------------------
 * Filename		:	StaticQueue.h
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	Mar 16, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include "LIB/STD_TYPES.h"

#define     QUEUE_SIZE  1

#define     TRUE        1
#define     FALSE       0

void    Queue_voidEnQueue(u8 Copy_u8UserData);
u8      Queue_u8DeQueue(void);
u8      Queue_u8Peak(void);


static u8   Queue_u8IsFull(void);
static u8   Queue_u8IsEmpty(void);

#endif /* STATIC_QUEUE_H */
