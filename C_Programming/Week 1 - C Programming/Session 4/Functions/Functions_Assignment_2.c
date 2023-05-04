/*
 * ----------------------------------------------------------------------------------
 * Name      	: Functions_Assignment_2.c
 *
 * Created on	: Mar 8th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Operations calculator
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

// Prototypes
int Add(int num1, int num2);
int Sub(int num1, int num2);
int Mul(int num1, int num2);
int Div(int num1, int num2);
int And(int num1, int num2);
int Or(int num1, int num2);
int Not(int num);
int Xor(int num1, int num2);
int Remainder(int num1, int num2);
int Increment(int num);
int Decrement(int num);


void main(void)
{
	// User input
	int op_ID, num1, num2, result;
	int flag = 0;  // 0 = No logical errors
	
	printf("Please Enter the operator ID: ");
	scanf("%d", &op_ID);
	
	if ((op_ID < 10) && (op_ID > 0) && (op_ID != 7))
	{
		printf("Please enter first number: ");
		scanf("%d", &num1);
		printf("Please enter second number: ");
		scanf("%d", &num2);
	}
	else if (op_ID <= 11)
	{
		printf("Please enter the number: ");
		scanf("%d", &num1);
	}
	else
	{
		printf("Wrong ID\n");
	}
	
	// Evaluate
	switch (op_ID)
	{
		case 1: // '+'
			result = Add(num1, num2);
			break;
			
		case 2: // '-'
			result = Sub(num1, num2);
			break;
			
		case 3: // '*'
			result = Mul(num1, num2);
			break;
			
		case 4: // '/'
			if (num2 != 0)
			{
				result = Div(num1, num2);
			}
			else
			{
				printf("Wrong input: Divide by zero\n");
				flag = 1;
			}
			break;

		case 5: // '&'
			result = And(num1, num2);
			break;
			
		case 6: // '|'
			result = Or(num1, num2);
			break;
			
		case 7: // '~'
			result = Not(num1);
			break;
			
		case 8: // '^'
			result = Xor(num1, num2);
			break;
			
		case 9: // '%'
		if (num2 != 0)
			{
				result = Remainder(num1, num2);
			}
			else
			{
				printf("Wrong input: Divide by zero\n");
				flag = 1;
			}
			break;
			
		case 10: // '++'
			result = Increment(num1);
			break;
			
		case 11: // '--'
			result = Decrement(num1);
			break;

		default:
			break;	
	}
	
	if (flag == 0)
	{
		printf("Result is: %d\n", result);
	}
}


// Function inplementations
int Add(int num1, int num2)
{
	return (num1 + num2);
}
int Sub(int num1, int num2)
{
	return (num1 - num2);
}
int Mul(int num1, int num2)
{
	return (num1 * num2);
}
int Div(int num1, int num2)
{
	return (num1 / num2);
}
int And(int num1, int num2)
{
	return (num1 & num2);
}
int Or(int num1, int num2)
{
	return (num1 | num2);
}
int Not(int num)
{
	return ~num;
}
int Xor(int num1, int num2)
{
	return (num1 ^ num2);
}
int Remainder(int num1, int num2)
{
	return (num1 % num2);
}
int Increment(int num)
{
	return ++num;
}
int Decrement(int num)
{
	return --num;
}