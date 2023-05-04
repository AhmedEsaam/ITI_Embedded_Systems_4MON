/*
 * ----------------------------------------------------------------------------------
 * Name      	: Assignment_2.c
 *
 * Created on	: Mar 7th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Checking ID and Password
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	/** Write a C code that ask the user to enter his ID, if the ID is valid it will
		ask the user to enter his password, if the password is correct the
		program will print the user name, if the password is incorrect the
		program will print Incorrect Password.
		In case of not existing ID, the program will print Incorrect ID
	*/
	
	//saved data
	int id_saved = 12345;
	int password_saved = 987654321;
	char user_name_saved[15] = "Ahmed_Essam";
	
	//User input
	int id;
	int password;
	
	printf("Please Enter Your ID: ");
	scanf("%d", &id);
	if (id == id_saved)
	{
		printf("Please Enter Your Password: ");
		scanf("%d", &password);
		if (password == password_saved)
		{
			printf("User name is: %s\n", user_name_saved);
		}
		else
		{
			printf("Incorrect Password.\n");
		}
	}
	else
	{
		printf("Incorrect ID.\n");
	}
	
	
	
}

