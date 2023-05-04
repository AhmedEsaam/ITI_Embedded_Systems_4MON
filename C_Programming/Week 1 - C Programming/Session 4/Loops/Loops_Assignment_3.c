/*
 * ----------------------------------------------------------------------------------
 * Name      	: Loops_Assignment_3.c
 *
 * Created on	: Mar 8th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Session 4 >> Assignment 3 >> Drawing a pyramid with height as input
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	// User input
	int height;
	printf("Plwase Enter the height of the pyramid: \n");
	scanf("%d", &height);
	
	// Drawing
	int i, j;
	for (i = height; i > 0; i--)
	{
		for (j = 1; j < i; j++)
		{
			printf(" ");
		}
		
		printf("*");
		for (j = 0; j < height - i; j++)
		{
			printf("**");
		}
		
		for (j = 1; j < i; j++)
		{
			printf(" ");
		}
		
		printf("\n");
	}
}

