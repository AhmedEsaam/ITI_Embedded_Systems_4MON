/*
 * ----------------------------------------------------------------------------------
 * Name      	: 161_length_of_string.c
 *
 * Created on	: Mar 9th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Finding the length of a string using a pointer
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	char str[100];
	printf("Enter any string: ");
	scanf("%s", &str);
	
	char *ptr = str;
	int length = 0;
	
	int i = 0;
	while (ptr[i] != '\0')
	{
		length++;
		i++;
	}
	
	printf("Length of '%s' = %d\n", str, length);
	
}

