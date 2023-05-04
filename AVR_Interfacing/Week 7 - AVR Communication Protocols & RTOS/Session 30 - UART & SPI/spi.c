#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "util/delay.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/Timer/Timer_interface.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"

#define MASTER_MODE 0
#define SLAVE_MODE  1

#if MASTER_MODE

void main(void)
{

    MDIO_voidSetPinDir(DIO_PORT_B, PIN4, INPUT_PULLUP);
    MDIO_voidSetPinDir(DIO_PORT_B, PIN5, OUTPUT);
    MDIO_voidSetPinDir(DIO_PORT_B, PIN6, INPUT_NO_PULLUP);
    MDIO_voidSetPinDir(DIO_PORT_B, PIN7, OUTPUT);

    SPI_voidMasterInit();    

    while(1)
    {
        SPI_voidTranceive(10);
        _delay_ms(200);
        SPI_voidTranceive(20);
        _delay_ms(200);
    }
}

#elif SLAVE_MODE

LED_t led1 = {DIO_PORT_D, PIN0};

void main(void)
{
    LED_voidInit(&led1);

    MDIO_voidSetPinDir(DIO_PORT_B, PIN4, INPUT_NO_PULLUP);
    MDIO_voidSetPinDir(DIO_PORT_B, PIN5, INPUT_NO_PULLUP);
    MDIO_voidSetPinDir(DIO_PORT_B, PIN6, OUTPUT);
    MDIO_voidSetPinDir(DIO_PORT_B, PIN7, INPUT_NO_PULLUP);

    SPI_voidSlaveInit();

    u8 data;
    
    while(1)
    {
        data = SPI_voidSlaveReceive();

        if(data == 10)
        {
            LED_voidTurnOn(&led1);
        }
        else if(data == 20)
        {
            LED_voidTurnOff(&led1);
        } 

    }
}

#endif

