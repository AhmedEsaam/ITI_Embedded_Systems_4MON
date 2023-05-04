/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DynamicQueue.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 17, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include "LIB/STD_TYPES.h"

#define     TRUE        1
#define     FALSE       0

void    DynamicQueue_voidEnQueue(u8 Copy_u8UserData);
u8      DynamicQueue_u8DeQueue(void);
u8      DynamicQueue_u8Peak(void);

static u8   DynamicQueue_u8IsEmpty(void);

#endif /* STATIC_QUEUE_H */
