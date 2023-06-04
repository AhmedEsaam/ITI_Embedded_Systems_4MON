#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"
#include "TFT_interface.h"
#include "image.h"

int main() {
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheralClock(RCC_APB2, RCC_APB2_SPI1);
	MSYSTICK_ErrInit();
	MSPI1_voidInit();
	HTFT_voidInit();
	HTFT_voidDisplayImage(image);


	while(1)
	{

	}

	
	return 0;
}


