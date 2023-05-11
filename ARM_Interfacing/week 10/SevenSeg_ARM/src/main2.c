#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

int main()
{
	MRCC_voidInit();
	MSYSTICK_ErrInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_AHB1_GPIOA);

	MGPIO_ErrSetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT);
	MGPIO_ErrSetPinOutputSpeed(GPIO_PORTA, GPIO_PIN2, GPIO_LOW_SPEED);
	MGPIO_ErrSetPinOutputType(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_PUSH_PULL);

	while(1)
	{
		MGPIO_ErrSetPinValue(GPIO_PORTA, GPIO_PIN2, HIGH);
		MSYSTICK_ErrSetBusyWait(1000000);
		MGPIO_ErrSetPinValue(GPIO_PORTA, GPIO_PIN2, LOW);
		MSYSTICK_ErrSetBusyWait(1000000);

	}

	return 0;
}
