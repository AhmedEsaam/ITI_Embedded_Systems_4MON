/*
 * ----------------------------------------------------------------------------------
 * Name      	: Assignment_3.c
 *
 * Created on	: Mar 6th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Bit-wise operators
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	/** Write a code that takes 2 numbers and print their
	 * summation, subtraction, anding, oring, and Xoring
	 */
	
	// Inputs
	int a, b;
	printf("Please Enter Number a: ");
	scanf("%d", &a);
	printf("Please Enter Number b: ");
	scanf("%d", &b);
	
	//Bit-wise operators
	printf("%d\n", a + b);
	printf("%d\n", a - b);
	printf("%d\n", a & b);
	printf("%d\n", a | b);
	printf("%d\n", a ^ b);
	
}

