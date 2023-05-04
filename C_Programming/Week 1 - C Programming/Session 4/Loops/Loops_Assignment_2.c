/*
 * ----------------------------------------------------------------------------------
 * Name      	: Loops_Assignment_2.c
 *
 * Created on	: Mar 8th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Session 4 >> Assignment 2 >> Asking user to try entering password for 3 times
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	// Data
	int IDs[3] = {1234, 5678, 9870};
	int Passwords[3] = {7788, 5566, 1122};
	char Users[3][6] = {"Ahmed", "Amr", "Wael"};
	
	// User Inputs
	int id, password;
	printf("Please Enter your ID: ");
	scanf("%d", &id);
	
	// Search for id in the saved data
	int i, j;
	for (i = 0; i < 3; i++)
	{
		if (id == IDs[i])
		{
			for (j = 0; j < 3; j++)
			{
				// Input password
				if (j == 0)
				{
					printf("Please Enter your Password: ");
				}
				else
				{
					printf("Try again: ");
				}
				scanf("%d", &password);
				if (password == Passwords[i])
				{
					printf("Welcome %s\n", Users[i]);
					break;
				}
				
				if (j == 2)
				{
					printf("Incorrect password for 3 times. No more tries\n");
				}
			}
			break;
		}
		
		if (i == 2)
		{
			printf("You are not registered.\n");
		}
	}
	
	
}

