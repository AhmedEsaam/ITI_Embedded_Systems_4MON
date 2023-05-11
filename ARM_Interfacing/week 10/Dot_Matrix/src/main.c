#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#define COLUMNS_PORT 		GPIO_PORTA
#define ROWS_PORT 			GPIO_PORTB

#define WORD_LENGTH 		48

int main()
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_AHB1_GPIOB);

	// Columns (Port A)
	MGPIO_ErrSetPortMode(COLUMNS_PORT, GPIO_OUTPUT);
	MGPIO_ErrSetPortOutputSpeed(COLUMNS_PORT, GPIO_LOW_SPEED);
	MGPIO_ErrSetPortOutputType(COLUMNS_PORT, GPIO_OUTPUT_PUSH_PULL);
	// Rows (Port B)
	MGPIO_ErrSetPortMode(ROWS_PORT, GPIO_OUTPUT);
	MGPIO_ErrSetPortOutputSpeed(ROWS_PORT, GPIO_LOW_SPEED);
	MGPIO_ErrSetPortOutputType(ROWS_PORT, GPIO_OUTPUT_PUSH_PULL);

	MSYSTICK_ErrInit();

	u8 Local_u8AnimatedWord[48] = {
		0,   0,   0,   0,   0,   0, 0, 0,
		0, 252,  18,  18,  18, 252, 0, 0, 	// Letter A
		0, 254,  16,  16,  16, 254, 0, 0, 	// Letter H
		0, 254,   4,   8,   4, 254, 0, 0, 	// Letter M
		0, 254, 146, 146, 146, 130, 0, 0, 	// Letter E
		0, 254, 130, 130, 130, 124, 0, 0, 	// Letter D
	};

	u8 Local_u8ColumnsPortValues[] = {
		0b11111110,
		0b11111101,
		0b11111011,
		0b11110111,
		0b11101111,
		0b11011111,
		0b10111111,
		0b01111111,
	};

	u8 Local_u8ColumnsCounter;
	u8 Local_u8FramesdCounter;
	u8 Local_u8FrameTime;

	while(1)
	{
		for(Local_u8FramesdCounter = 0; Local_u8FramesdCounter < WORD_LENGTH; Local_u8FramesdCounter++)
		{
			for(Local_u8FrameTime = 0; Local_u8FrameTime < 100; Local_u8FrameTime++)
			{
				for(Local_u8ColumnsCounter = 0; Local_u8ColumnsCounter < 8; Local_u8ColumnsCounter++)
				{
					MGPIO_ErrSetPortSpecificValue(COLUMNS_PORT, Local_u8ColumnsPortValues[Local_u8ColumnsCounter]);
					MGPIO_ErrSetPortSpecificValue(ROWS_PORT, Local_u8AnimatedWord[Local_u8FramesdCounter + Local_u8ColumnsCounter]);
					MSYSTICK_ErrSetBusyWait(100);
				}
			}
		}
	}

	return 0;
}
