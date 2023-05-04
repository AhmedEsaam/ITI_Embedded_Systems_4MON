/*
 * ----------------------------------------------------------------------------------
 * Filename     :	BinarySearch_Recursive.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 19, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>
#include "LIB/STD_TYPES.h"
#include "BinarySearch_Recursive.h"

void BinarySearchRecursive_voidSearch(u8 * Copy_Arr, u8 Copy_ArrSize,
    u8 Copy_Left, u8 Copy_Right, u8 Copy_UserData)
{
    if(Copy_Left <= Copy_Right)
    {
        u8 Mid = Copy_Left + (Copy_Right - Copy_Left) / 2;

        if(Copy_Arr[Mid] == Copy_UserData)
        {
            printf("User Data Is Found!\n");
            return;
        }
        else if(Copy_Arr[Mid] < Copy_UserData)
        {
            Copy_Left = Mid + 1;
        }
        else if (Copy_Arr[Mid] > Copy_UserData)
        {
            Copy_Right = Mid - 1;
        }

        BinarySearchRecursive_voidSearch(Copy_Arr, Copy_ArrSize,
             Copy_Left, Copy_Right, Copy_UserData);
    }
    else
    {
        printf("User Data Not Found!\n");
    }
}