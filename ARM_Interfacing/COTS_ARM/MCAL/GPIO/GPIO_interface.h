/*
 * ----------------------------------------------------------------------------------
 * Filename     :	GPIO_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 5, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 5, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

// GPIO Ports
#define     GPIO_PORTA                          0 
#define     GPIO_PORTB                          1 
#define     GPIO_PORTC                          2

// GPIO Pins
#define     GPIO_PIN0                           0 
#define     GPIO_PIN1                           1 
#define     GPIO_PIN2                           2 
#define     GPIO_PIN3                           3 
#define     GPIO_PIN4                           4 
#define     GPIO_PIN5                           5 
#define     GPIO_PIN6                           6 
#define     GPIO_PIN7                           7 
#define     GPIO_PIN8                           8 
#define     GPIO_PIN9                           9 
#define     GPIO_PIN10                          10 
#define     GPIO_PIN11                          11
#define     GPIO_PIN12                          12
#define     GPIO_PIN13                          13
#define     GPIO_PIN14                          14
#define     GPIO_PIN15                          15

// GPIO Pin Mode
#define     GPIO_INPUT                          0b00
#define     GPIO_OUTPUT                         1
#define     GPIO_ALTERNATE_FUNCTION             2

// GPIO Pin Output Type
#define     GPIO_OUTPUT_PUSH_PULL               0
#define     GPIO_OUTPUT_OPEN_DRAIN              1

// GPIO Pin Output Speed
#define     GPIO_LOW_SPEED                      0b00             
#define     GPIO_MEDIUM_SPEED                   1             
#define     GPIO_HIGH_SPEED                     2             
#define     GPIO_VERY_HIGH_SPEED                3             

// GPIO Pin Pullup/Pulldown
#define     GPIO_NO_PULL_UP_PULL_DOWN           0b00             
#define     GPIO_PULL_UP                        1             
#define     GPIO_PULL_DOWN                      2    

// GPIO Pin Function Selection
#define     GPIO_AF0                            0b0000              
#define     GPIO_AF1                            1              
#define     GPIO_AF2                            2              
#define     GPIO_AF3                            3              
#define     GPIO_AF4                            4              
#define     GPIO_AF5                            5              
#define     GPIO_AF6                            6              
#define     GPIO_AF7                            7              
#define     GPIO_AF8                            8              
#define     GPIO_AF9                            9              
#define     GPIO_AF10                           10             
#define     GPIO_AF11                           11             
#define     GPIO_AF12                           12             
#define     GPIO_AF13                           13             
#define     GPIO_AF14                           14             
#define     GPIO_AF15                           15    

// GPIO Pin Set/Reset
// Set Pin (ex: BSRR = SET_PIN3)
#define     SET_PIN0                            0x1 
#define     SET_PIN1                            0x2
#define     SET_PIN2                            0x4
#define     SET_PIN3                            0x8
#define     SET_PIN4                            0x10
#define     SET_PIN5                            0x20
#define     SET_PIN6                            0x40
#define     SET_PIN7                            0x80
#define     SET_PIN8                            0x100
#define     SET_PIN9                            0x200
#define     SET_PIN10                           0x400
#define     SET_PIN11                           0x800
#define     SET_PIN12                           0x1000
#define     SET_PIN13                           0x2000
#define     SET_PIN14                           0x4000
#define     SET_PIN15                           0x8000
// Reset Pin
#define     RESET_PIN0                          0x10000 
#define     RESET_PIN1                          0x20000
#define     RESET_PIN2                          0x40000
#define     RESET_PIN3                          0x80000
#define     RESET_PIN4                          0x100000
#define     RESET_PIN5                          0x200000
#define     RESET_PIN6                          0x400000
#define     RESET_PIN7                          0x800000
#define     RESET_PIN8                          0x1000000
#define     RESET_PIN9                          0x2000000
#define     RESET_PIN10                         0x4000000
#define     RESET_PIN11                         0x8000000
#define     RESET_PIN12                         0x10000000
#define     RESET_PIN13                         0x20000000
#define     RESET_PIN14                         0x40000000
#define     RESET_PIN15                         0x80000000

// Set Pin Value Array
u32 Global_u32SetPin[16] = {
    0x1,
    0x2,
    0x4,
    0x8,
    0x10,
    0x20,
    0x40,
    0x80,
    0x100,
    0x200,
    0x400,
    0x800,
    0x1000,
    0x2000,
    0x4000,
    0x8000
};

// Set Pin Value Array
u32 Global_u32ResetPin[16] = {
    0x10000,
    0x20000,
    0x40000,
    0x80000,
    0x100000,
    0x200000,
    0x400000,
    0x800000,
    0x1000000,
    0x2000000,
    0x4000000,
    0x8000000,
    0x10000000,
    0x20000000,
    0x40000000,
    0x80000000
};

// GPIO Pin Values
#define     LOW                                 0
#define     HIGH                                1


typedef struct GPIO_OutputPin_t
{
    u8 PortName;
    u8 PinNum;
    u8 OutputType;
    u8 OutputSpeed;
}GPIO_OutputPin_t;

typedef struct GPIO_InputPin_t
{
    u8 PortName;
    u8 PinNum;
    u8 PullUpPullDown;
}GPIO_InputPin_t;

// Error Handling
typedef enum GPIO_Error_t
{
    GPIO_OK,
    GPIO_OutputPinInvalidConfiguration,
    GPIO_InputPinInvalidConfiguration,
    GPIO_PortNameInvalidConfiguration,
    GPIO_PinNumberInvalidConfiguration,
    GPIO_PinOutputTypeInvalidConfiguration,
    GPIO_PinValueInvalidConfiguration,
    GPIO_LockKeyBitInvalidConfiguration,
}GPIO_Error_t;

// Linking-Time Configuration
GPIO_Error_t MGPIO_voidOutputPinConfig(GPIO_OutputPin_t * Copy_pGPIO_OutputPinObj);
GPIO_Error_t MGPIO_voidInputPinConfig(GPIO_InputPin_t * Copy_pGPIO_InputPinObj);
// Post-Build Configuration
GPIO_Error_t MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode);
GPIO_Error_t MGPIO_voidSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputType);
GPIO_Error_t MGPIO_voidSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputSpeed);
GPIO_Error_t MGPIO_voidSetPinPullUpPullDown(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinPullUpPullDown);
GPIO_Error_t MGPIO_voidSetPinAlternativeFunction(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinAlternativeFunction);

GPIO_Error_t MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue);
GPIO_Error_t MGPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 * Copy_pu8PinValue);
GPIO_Error_t MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif /* GPIO_INTERFACE_H */
