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
#include <stdlib.h>
#include "LIB/STD_TYPES.h"
#include "DMA_Stack.h"

int main()
{
    DMA_Stack_voidPush(5);
    DMA_Stack_voidPush(6);
    DMA_Stack_voidPush(7);

    u8 x = DMA_Stack_u8Pop();

    struct Node * T = DMA_Stack_u8Top();

    return 0;
}
