#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "SEVEN_SEG_interface.h"


int main()
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_AHB1_GPIOB);

	SEVEN_SEG_t sev0 = {.SEVEN_SEG_u8PORT = GPIO_PORTA, 
					   .SEVEN_SEG_u8CONNECTION = COMMON_CATHODE};

	SEVEN_SEG_t sev1 = {.SEVEN_SEG_u8PORT = GPIO_PORTB, 
					   .SEVEN_SEG_u8CONNECTION = COMMON_CATHODE};

	SEVEN_SEG_voidInit(&sev0);
	SEVEN_SEG_voidInit(&sev1);

	MSYSTICK_ErrInit();


	while(1)
	{
		u8 Local_u8Counter;
		for(Local_u8Counter = 0; Local_u8Counter <= 10; Local_u8Counter++)
		{
			SEVEN_SEG_voidSendDigit(&sev0, Local_u8Counter%10);
			SEVEN_SEG_voidSendDigit(&sev1, Local_u8Counter/10);
			MSYSTICK_ErrSetBusyWait(1000000);
		}

		for(Local_u8Counter = 0; Local_u8Counter < 9; Local_u8Counter++)
		{
			SEVEN_SEG_voidSendDigit(&sev0, (9 - Local_u8Counter)%10);
			SEVEN_SEG_voidSendDigit(&sev1, (9 - Local_u8Counter)/10);
			MSYSTICK_ErrSetBusyWait(1000000);
		}


	}

	return 0;
}
