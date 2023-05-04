/*
 * ----------------------------------------------------------------------------------
 * Filename		:	DMA_Stack.h
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	Mar 16, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#ifndef DMA_STACK_H
#define DMA_STACK_H

#include "LIB/STD_TYPES.h"


#define     TRUE    1
#define     FALSE   0

void            DMA_Stack_voidPush(u8 Copy_u8UserData);
u8              DMA_Stack_u8Pop(void);
u8              DMA_Stack_u8Top(void);

static u8       DMA_Stack_u8IsEmpty(void);

#endif /* DMA_STACK_H */
