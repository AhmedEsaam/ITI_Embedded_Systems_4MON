#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

void Toggle_LED(void);

void main(void)
{
  MRCC_voidInit();
  MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_AHB1_GPIOA);

  MGPIO_ErrSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);
  MGPIO_ErrSetPinPullUpPullDown(GPIO_PORTA, GPIO_PIN0, GPIO_PULL_UP);

  MNVIC_voidInit();
  MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

  MEXTI_voidChangeSenseMode(MEXTI_LINE0, MEXTI_FALLING_EDGE);
  MEXTI_voidSetCallBack(MEXTI_LINE0, &Toggle_LED);
  MEXTI_voidEnableInterrupt(MEXTI_LINE0);

  while(1)
  ;

}

void Toggle_LED(void)
{
  asm("NOP"); // Do Nothing
}