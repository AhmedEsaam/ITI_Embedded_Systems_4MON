/*
 * ----------------------------------------------------------------------------------
 * Name      	: Assignment_1.c
 *
 * Created on	: Mar 7th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Search for then print a number
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	/** Write a C code that ask the user to enter 10
		numbers, then ask him to enter another number
		to search on it in the 10 numbers and print its
		location in case it is found.
		In case the number is not found, it will print
		number no exist
	*/
	
	int num[10];
	
	// User input
	printf("Enter Number 1: ");
	scanf("%d", &num[0]);
	printf("Enter Number 2: ");
	scanf("%d", &num[1]);
	printf("Enter Number 3: ");
	scanf("%d", &num[2]);
	printf("Enter Number 4: ");
	scanf("%d", &num[3]);
	printf("Enter Number 5: ");
	scanf("%d", &num[4]);
	printf("Enter Number 6: ");
	scanf("%d", &num[5]);
	printf("Enter Number 7: ");
	scanf("%d", &num[6]);
	printf("Enter Number 8: ");
	scanf("%d", &num[7]);
	printf("Enter Number 9: ");
	scanf("%d", &num[8]);
	printf("Enter Number 10: ");
	scanf("%d", &num[9]);
	
	// Search
	int search;
	printf("Enter the value to search: ");
	scanf("%d", &search);
	
	if (search == num[0])
	{
		printf("Value is exist at element number %d\n", 1);
	}
	else if (search == num[1])
	{
		printf("Value is exist at element number %d\n", 2);
	} 
	else if (search == num[2])
	{
		printf("Value is exist at element number %d\n", 3);
	} 
	else if (search == num[3])
	{
		printf("Value is exist at element number %d\n", 4);
	} 
	else if (search == num[4])
	{
		printf("Value is exist at element number %d\n", 5);
	} 
	else if (search == num[5])
	{
		printf("Value is exist at element number %d\n", 6);
	} 
	else if (search == num[6])
	{
		printf("Value is exist at element number %d\n", 7);
	} 
	else if (search == num[7])
	{
		printf("Value is exist at element number %d\n", 8);
	} 
	else if (search == num[8])
	{
		printf("Value is exist at element number %d\n", 9);
	} 
	else if (search == num[9])
	{
		printf("Value is exist at element number %d\n", 10);
	} 
	else
	{
		printf("Number does not exist.\n");
	}
	
}

