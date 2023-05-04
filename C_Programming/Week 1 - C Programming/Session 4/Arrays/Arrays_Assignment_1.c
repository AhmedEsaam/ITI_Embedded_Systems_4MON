/*
 * ----------------------------------------------------------------------------------
 * Name      	: Arrays_Assignment_1.c
 *
 * Created on	: Mar 9th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Minimum and Maximum of an array
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	int values[10];
	
	printf("Please enter 10 values: \n");
	scanf("%d", &values[0]);
	int i, min = values[0], max = values[0];
	
	for (i = 1; i < 10; i++)
	{
		scanf("%d", &values[i]);
		
		if (values[i] < min)
		{
			min = values[i];
		}
		
		if (values[i] > max)
		{
			max = values[i];
		}
	}
	
	printf("Minimum number is: %d\n", min);
	printf("Maximum number is: %d\n", max);
}


