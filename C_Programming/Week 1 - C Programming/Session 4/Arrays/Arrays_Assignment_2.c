/*
 * ----------------------------------------------------------------------------------
 * Name      	: Arrays_Assignment_2.c
 *
 * Created on	: Mar 9th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: School classes grades
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{	
	// Grades (out of 100)
	int class_1[10] = {40, 61, 30, 10, 85, 74, 52, 94, 30, 42};
	int class_2[10] = {55, 99, 52, 87, 74, 91, 41, 25, 63, 74};
	int class_3[10] = {87, 75, 94, 72, 64, 74, 91, 54, 28, 34};
	
	int passed = 0, failed = 0, lowest = class_1[0], highest = class_1[0], sum = 0; 
	int i;
	
	// for class_1
	for (i = 0; i < 10; i++)
	{
		if (class_1[i] >= 50)
		{
			passed++;
		}
		else
		{
			failed++;
		}
		
		if (class_1[i] < lowest)
		{
			lowest = class_1[i];
		}
		
		if (class_1[i] > highest)
		{
			highest = class_1[i];
		}
		
		sum += class_1[i];
	}
	
	// for class_2
	for (i = 0; i < 10; i++)
	{
		if (class_2[i] >= 50)
		{
			passed++;
		}
		else
		{
			failed++;
		}
		
		if (class_2[i] < lowest)
		{
			lowest = class_2[i];
		}
		
		if (class_2[i] > highest)
		{
			highest = class_2[i];
		}
		
		sum += class_2[i];
	}
	
	// for class_3
	for (i = 0; i < 10; i++)
	{
		if (class_3[i] >= 50)
		{
			passed++;
		}
		else
		{
			failed++;
		}
		
		if (class_3[i] < lowest)
		{
			lowest = class_3[i];
		}
		
		if (class_3[i] > highest)
		{
			highest = class_3[i];
		}
		
		sum += class_3[i];
	}
	
	printf("Number of passed students is: %d\n", passed);
	printf("Number of failed students is: %d\n", failed);
	printf("Highest grade is: %d\n", highest);
	printf("Lowest grade is: %d\n", lowest);
	printf("Average grade is: %f\n", (sum/30.0));
	
}


