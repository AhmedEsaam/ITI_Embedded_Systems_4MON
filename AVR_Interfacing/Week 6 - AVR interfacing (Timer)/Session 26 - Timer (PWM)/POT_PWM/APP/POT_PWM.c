 /*
  * ----------------------------------------------------------------------------------
  * Filename     :	LED_PWM.c
  *
  * Author       :	Ahmed Essam El-Mogy
  * Created on   :	APR 10, 2023
  * Version      :	v1.0
  * C Standard   :	C99
  * Compiler     :	AVR GCC
  * ----------------------------------------------------------------------------------
  *
  * ----------------------------------------------------------------------------------
  * Version		Date 		        Author			        Description
  * v1.0		    APR 10, 2023		Ahmed Essam El-Mogy		Initial Creation
  * ----------------------------------------------------------------------------------
  */

 #include "../LIB/STD_TYPES.h"

 #include "../MCAL/DIO/DIO_interface.h"
 #include "../MCAL/ADC/ADC_interface.h"
 #include "../MCAL/Timer/Timer_interface.h"

 #include "../HAL/LED/LED_interface.h"

 void main(void)
 {
     u8 Local_u8DigitalValue;

     /* Initialize Timer */
     TIMER0_voidInit();
     ADC_voidInit();
     MDIO_voidSetPinDir(DIO_PORT_B, PIN3, OUTPUT);
     MDIO_voidSetPinDir(DIO_PORT_A, PIN0, INPUT);
     while(1)
     {
         Local_u8DigitalValue = ADC_u8StartConversionSynchronous(ADC_Channel_0);
         TIMER0_voidSetCTCCompareMatchValue(Local_u8DigitalValue);
     }
 }
