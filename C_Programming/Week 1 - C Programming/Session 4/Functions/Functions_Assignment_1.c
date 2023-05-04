/*
 * ----------------------------------------------------------------------------------
 * Name      	: Functions_Assignment_1.c
 *
 * Created on	: Mar 8th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Minimum and Maximum of 4 numbers
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

int max(int num1, int num2, int num3, int num4);
int min(int num1, int num2, int num3, int num4);

void main(void)
{
	int num[4];
	
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("Please enter value number %d: \n", i);
		scanf("%d", &num[i]);
	}
	
	printf("The Maximum is: %d\n", max(num[0], num[1], num[2], num[3]));
	printf("The Maximum is: %d\n", min(num[0], num[1], num[2], num[3]));
}

int max(int num1, int num2, int num3, int num4)
{
	int num[4] = {num1, num2, num3, num4};
	int max = num[0];
	
	int i;
	for (i = 1; i < 4; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
		}			
	}
	return max;
}

int min(int num1, int num2, int num3, int num4)
{
	int num[4] = {num1, num2, num3, num4};
	int min = num[0];
	
	int i;
	for (i = 1; i < 4; i++)
	{
		if (num[i] < min)
		{
			min = num[i];
		}			
	}
	return min;
}

