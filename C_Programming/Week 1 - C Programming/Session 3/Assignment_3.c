/*
 * ----------------------------------------------------------------------------------
 * Name      	: Assignment_3.c
 *
 * Created on	: Mar 7th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: The maximum of 3 numbers
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	/** Write a code that will ask the user to enter 3
		numbers, the program will print the maximum
		number of them.
	*/
	
	// Inputs
	int num[3];
	printf("Please Enter Number 1: ");
	scanf("%d", &num[0]);
	printf("Please Enter Number 2: ");
	scanf("%d", &num[1]);
	printf("Please Enter Number 3: ");
	scanf("%d", &num[2]);
	
	// Maximum
	if (num[0] > num[1])
	{
		if (num[0] > num[2])
		{
			printf("Maximum number is %d\n", num[0]);
		}
		else
		{
			printf("Maximum number is %d\n", num[2]);
		}
	}
	else if (num[1] > num[2])
	{
		printf("Maximum number is %d\n", num[1]);
	}
	else
	{
		printf("Maximum number is %d\n", num[2]);
	}
	
}

