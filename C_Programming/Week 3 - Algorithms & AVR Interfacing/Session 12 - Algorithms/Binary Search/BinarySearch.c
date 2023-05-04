/*
 * ----------------------------------------------------------------------------------
 * Filename     :	BinarySearch.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 18, 2023
 * Version      :   v1.0
 * C Standard   :   C99
 * Compiler     :   GNU GCC
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>
#include "LIB/STD_TYPES.h"
#include "BinarySearch.h"

void BinarySearch_voidSearch(u8 * Copy_Arr, u8 Copy_ArrSize, u8 Copy_UserData)
{
    u8 Left     = 0;
    u8 Right    = Copy_ArrSize - 1;
    u8 Mid;

    u8 FoundStatus = 0;

    while(Left <= Right)
    {
        Mid = Left + (Right - Left) / 2;

        if(Copy_Arr[Mid] == Copy_UserData)
        {
            FoundStatus = 1;
            break;    
        }
        else if(Copy_Arr[Mid] < Copy_UserData)
        {
            Left = Mid + 1;
        }
        else if (Copy_Arr[Mid] > Copy_UserData)
        {
            Right = Mid - 1;
        }
    }

    if (FoundStatus == 1)
    {
        printf("User Data Is Found!\n");
    }
    else if (FoundStatus == 0)
    {
        printf("User Data Not Found!\n");
    }
}