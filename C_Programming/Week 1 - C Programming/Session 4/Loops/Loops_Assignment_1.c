/*
 * ----------------------------------------------------------------------------------
 * Name      	: Loops_Assignment_1.c
 *
 * Created on	: Mar 8th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Session 4 >> Assignment 1 >> Infinite app cycle
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	int num1, num2;
	while(1)
	{
		printf("Please enter first number: ");
		scanf("%d", &num1);
		printf("Please enter second number: ");
		scanf("%d", &num2);
		
		printf("The result is %d\n\n", num1 + num2);
	}
	
}

