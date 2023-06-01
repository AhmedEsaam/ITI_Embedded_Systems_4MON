#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "EXTI_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"

void APP_GetFrame(void);
void App_TakeAction(void);

u8  APP_u8StartEdgeFlag = 0;
u32 ReceivedFrame[50] = {0}; 
u8  APP_u8EdgeCounter = 0;

void main(void)
{
  MRCC_voidInit();
  MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_AHB1_GPIOA);

  /* Set The A0 Pin To Be Input (EXTI0) */
  MGPIO_ErrSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);
  /* Set The A0 Pin To Be Pull Up */
  MGPIO_ErrSetPinPullUpPullDown(GPIO_PORTA, GPIO_PIN0, GPIO_PULL_UP);

  /* Initialize STK */
  MSYSTICK_ErrInit();

  /* Setup EXTI Line0 */
  MEXTI_voidInit();
  MEXTI_voidChangeSenseMode(MEXTI_LINE0, MEXTI_FALLING_EDGE);
  MEXTI_voidSetCallBack(MEXTI_LINE0, &APP_GetFrame);
  MEXTI_voidEnableInterrupt(MEXTI_LINE0);

  /* Initialize NVIC */
  MNVIC_voidInit();
  /* Enable EXTI Peripheral In NVIC */
  MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

  while(1)
  {
    APP_voidPlay();
  }

}

void APP_GetFrame(void)
{
  if (APP_u8StartEdgeFlag == 0)
  {
    MSYSTICK_ErrSetIntervalSingle(1000000, &App_TakeAction);
    APP_u8StartEdgeFlag = 1;
  }
  else
  {
    /* Get the Counted Time */
    MSYSTICK_ErrGetElapsedTime(&ReceivedFrame[APP_u8EdgeCounter]);
    // /* Reset The Timer */
    // MSYSTICK_ErrResetSysTick();
    /* Set Preload Value */
    MSYSTICK_ErrSetIntervalSingle(1000000, &App_TakeAction);
    /* Increment Edge Counter */
    APP_u8EdgeCounter++;
  }
}

u8 APP_u8ButtonData = 0;
void App_TakeAction(void)
{
  u8 Local_u8LoopCounter = 0;
  for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
  {
    if((ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
    (ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
    {
      CLR_BIT(APP_u8ButtonData, Local_u8LoopCounter);
    }
    else
    {
      SET_BIT(APP_u8ButtonData, Local_u8LoopCounter);
    }
  }

  APP_u8StartEdgeFlag = 0;
  APP_u8EdgeCounter = 0;
  
}

void APP_voidPlay(void)
{
  switch (APP_u8ButtonData)
  {
  case 24:
    asm("NOP");
    break;
  
  case 69:
    asm("NOP");
    break;
  
  default:
    break;
  }
}
