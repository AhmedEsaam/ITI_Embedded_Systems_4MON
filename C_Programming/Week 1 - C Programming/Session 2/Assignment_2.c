/*
 * ----------------------------------------------------------------------------------
 * Name      	: Assignment_2.c
 *
 * Created on	: Mar 6th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Scanning 3 numbers then printing in reversed order
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	/** Write a code that scan 3 numbers from the user
	 * and print them in reversed order.
	 */
	 
	int num_1, num_2, num_3;
	
	// Scanning
	printf("Please enter number 1: ");
	scanf("%d", &num_1);
	printf("Please enter number 2: ");
	scanf("%d", &num_2);
	printf("Please enter number 3: ");
	scanf("%d", &num_3);
	
	//Printing in reverse
	printf("number 3: %d\n", num_3);
	printf("number 2: %d\n", num_2);
	printf("number 1: %d\n", num_1);
	
}

