/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Calculator.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 28, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 28, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

/* Library Inclusions */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>
/* Lower Layer Inclusions */
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include "../HAL/LED/LED_interface.h"

void main(void)
{
	/* KPD */
	u8 Local_u8PressedKey;
	LCD_voidInit();
	KPD_voidInit();

	u32 Local_u32Operand1 = 0;
	u32 Local_u32Operand2 = 0;
	u32 Local_u32OperandValue = 0;
	u8 Local_u8Operator;
	s32 Local_s32Result;

	u8 Local_u8NewCalculationFlag = FALSE; 

	while(1)
	{
	 	do
	 	{
	 		Local_u8PressedKey = KPD_u8GetPressedKey();
	 	}while(Local_u8PressedKey == 255);

		if((Local_u8NewCalculationFlag == TRUE) && (Local_u8PressedKey != 255))
		{
			LCD_voidClearDisplay();
			Local_u8NewCalculationFlag = FALSE;
		}

	 	LCD_voidSendData(Local_u8PressedKey);
		switch (Local_u8PressedKey)
		{
		case '+':
			Local_u8Operator = '+';
			Local_u32Operand1 = Local_u32OperandValue;
			Local_u32OperandValue = 0;
			break;
		case '-':
			Local_u8Operator = '-';
			Local_u32Operand1 = Local_u32OperandValue;
			Local_u32OperandValue = 0;
			break;
		case 'x':
			Local_u8Operator = 'x';
			Local_u32Operand1 = Local_u32OperandValue;
			Local_u32OperandValue = 0;
			break;
		case '/':
			Local_u8Operator = '/';
			Local_u32Operand1 = Local_u32OperandValue;
			Local_u32OperandValue = 0;
			break;
		case '=':
			Local_u32Operand2 = Local_u32OperandValue;
			Local_u32OperandValue = 0;
			Local_u8NewCalculationFlag = TRUE;
			switch (Local_u8Operator)
			{
			case '+':
				Local_s32Result = Local_u32Operand1 + Local_u32Operand2;
				LCD_voidClearDisplay();
				LCD_voidSendNumber(Local_s32Result);
				break;
			case '-':
				Local_s32Result = Local_u32Operand1 - Local_u32Operand2;
				LCD_voidClearDisplay();
				LCD_voidSendNumber(Local_s32Result);
				break;
			case 'x':
				Local_s32Result = Local_u32Operand1 * Local_u32Operand2;
				LCD_voidClearDisplay();
				LCD_voidSendNumber(Local_s32Result);
				break;
			case '/':
				if(Local_u32Operand2 == 0)
				{
					LCD_voidClearDisplay();
					LCD_voidSendString("Error Div. By 0");
				}
				else
				{
					Local_s32Result = Local_u32Operand1 / Local_u32Operand2;
					LCD_voidClearDisplay();
					LCD_voidSendNumber(Local_s32Result);
				}
				break;
			default:
				break;
			}
			if(Local_s32Result == 0)
			{
				LCD_voidSendData('0');
			}
			break;
		case 'C':
			LCD_voidClearDisplay();
			break;
		default:
			Local_u32OperandValue *= 10;
			Local_u32OperandValue += Local_u8PressedKey - 48;
			break;
		}
	}
	
}
