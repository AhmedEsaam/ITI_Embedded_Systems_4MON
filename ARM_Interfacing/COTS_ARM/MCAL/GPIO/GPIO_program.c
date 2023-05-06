/*
 * ----------------------------------------------------------------------------------
 * Filename     :	GPIO_program.c
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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


GPIO_Error_t MGPIO_voidOutputPinConfig(GPIO_OutputPin_t * Copy_pGPIO_OutputPinObj)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Checking Port Name, Pin Number, Output Type, Output Speed, Alternate Function */
    if( Copy_pGPIO_OutputPinObj->PortName           >   GPIO_PORTC              ||
        Copy_pGPIO_OutputPinObj->PinNum             >   GPIO_PIN15              ||
        Copy_pGPIO_OutputPinObj->OutputType         >   GPIO_OUTPUT_OPEN_DRAIN  ||
        Copy_pGPIO_OutputPinObj->OutputSpeed        >   GPIO_VERY_HIGH_SPEED
        )
    {
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_OutputPinInvalidConfiguration;
    }
    else
    {
        /* Check for The Port Name */
        switch (Copy_pGPIO_OutputPinObj->PortName)
        {
        case GPIO_PORTA:
            /* Set The Mode Bits of the Specific Pin to Be Output */
            (GPIOA->MODER) &= ~((MODER_BIT_MASK)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));
            (GPIOA->MODER) |=  ((GPIO_OUTPUT)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));

            /* Check For Pin Output Type */
            switch (Copy_pGPIO_OutputPinObj->OutputType)
            {
            case GPIO_OUTPUT_PUSH_PULL:
                /* Set Pin Output Type To 'Push/Pull' */
                CLR_BIT(GPIOA->OTYPER, Copy_pGPIO_OutputPinObj->PinNum);
                break;

            case GPIO_OUTPUT_OPEN_DRAIN:
                /* Set Pin Output Type To 'Open Drain' */
                SET_BIT(GPIOA->OTYPER, Copy_pGPIO_OutputPinObj->PinNum);
                break;
            
            default:
                /* Change Error State */
                Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
                break;
            }

            /* Set Pin Specific Output Speed by Changing Output Speed Bits */
            (GPIOA->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));
            (GPIOA->OSPEEDR) |=  ((Copy_pGPIO_OutputPinObj->OutputSpeed)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));

        break;

        case GPIO_PORTB:
            /* Set The Mode Bits of the Specific Pin to Be Output */
            (GPIOB->MODER) &= ~((MODER_BIT_MASK)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));
            (GPIOB->MODER) |=  ((GPIO_OUTPUT)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));

            /* Check For Pin Output Type */
            switch (Copy_pGPIO_OutputPinObj->OutputType)
            {
            case GPIO_OUTPUT_PUSH_PULL:
                /* Set Pin Output Type To 'Push/Pull' */
                CLR_BIT(GPIOB->OTYPER, Copy_pGPIO_OutputPinObj->PinNum);
                break;

            case GPIO_OUTPUT_OPEN_DRAIN:
                /* Set Pin Output Type To 'Open Drain' */
                SET_BIT(GPIOB->OTYPER, Copy_pGPIO_OutputPinObj->PinNum);
                break;
            
            default:
                /* Change Error State */
                Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
                break;
            }

            /* Set Pin Specific Output Speed by Changing Output Speed Bits */
            (GPIOB->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));
            (GPIOB->OSPEEDR) |=  ((Copy_pGPIO_OutputPinObj->OutputSpeed)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));

        break;

        case GPIO_PORTC:
            /* Set The Mode Bits of the Specific Pin to Be Output */
            (GPIOC->MODER) &= ~((MODER_BIT_MASK)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));
            (GPIOC->MODER) |=  ((GPIO_OUTPUT)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));

            /* Check For Pin Output Type */
            switch (Copy_pGPIO_OutputPinObj->OutputType)
            {
            case GPIO_OUTPUT_PUSH_PULL:
                /* Set Pin Output Type To 'Push/Pull' */
                CLR_BIT(GPIOC->OTYPER, Copy_pGPIO_OutputPinObj->PinNum);
                break;

            case GPIO_OUTPUT_OPEN_DRAIN:
                /* Set Pin Output Type To 'Open Drain' */
                SET_BIT(GPIOC->OTYPER, Copy_pGPIO_OutputPinObj->PinNum);
                break;
            
            default:
                /* Change Error State */
                Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
                break;
            }

            /* Set Pin Specific Output Speed by Changing Output Speed Bits */
            (GPIOC->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));
            (GPIOC->OSPEEDR) |=  ((Copy_pGPIO_OutputPinObj->OutputSpeed)<<(Copy_pGPIO_OutputPinObj->PinNum * 2));

        break;
        
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
            break;
        }
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_voidInputPinConfig(GPIO_InputPin_t * Copy_pGPIO_InputPinObj)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Checking Port Name, Pin Number, Output Type, Output Speed, Alternate Function */
    if( Copy_pGPIO_InputPinObj->PortName           >   GPIO_PORTC       ||
        Copy_pGPIO_InputPinObj->PinNum             >   GPIO_PIN15       ||
        Copy_pGPIO_InputPinObj->PullUpPullDown     >   GPIO_PULL_DOWN
        )
    {
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_InputPinInvalidConfiguration;
    }
    else
    {
        /* Check for The Port Name */
        switch (Copy_pGPIO_InputPinObj->PortName)
        {
        case GPIO_PORTA:
            /* Set The Mode Bits of the Specific Pin to be Input */
            (GPIOA->MODER) &= ~((MODER_BIT_MASK)<<(Copy_pGPIO_InputPinObj->PinNum * 2));
            (GPIOA->MODER) |=  ((GPIO_INPUT)<<(Copy_pGPIO_InputPinObj->PinNum * 2));

            /* Set Pin Input PullUp/PullDown Configuration */
            (GPIOA->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_pGPIO_InputPinObj->PinNum * 2));
            (GPIOA->PUPDR) |=  ((Copy_pGPIO_InputPinObj->PullUpPullDown)<<(Copy_pGPIO_InputPinObj->PinNum * 2));

        break;

        case GPIO_PORTB:
            /* Set The Mode Bits of the Specific Pin to be Input */
            (GPIOB->MODER) &= ~((MODER_BIT_MASK)<<(Copy_pGPIO_InputPinObj->PinNum * 2));
            (GPIOB->MODER) |=  ((GPIO_INPUT)<<(Copy_pGPIO_InputPinObj->PinNum * 2));

            /* Set Pin Input PullUp/PullDown Configuration */
            (GPIOB->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_pGPIO_InputPinObj->PinNum * 2));
            (GPIOB->PUPDR) |=  ((Copy_pGPIO_InputPinObj->PullUpPullDown)<<(Copy_pGPIO_InputPinObj->PinNum * 2));

        break;

        case GPIO_PORTC:
            /* Set The Mode Bits of the Specific Pin to be Input */
            (GPIOC->MODER) &= ~((MODER_BIT_MASK)<<(Copy_pGPIO_InputPinObj->PinNum * 2));
            (GPIOC->MODER) |=  ((GPIO_INPUT)<<(Copy_pGPIO_InputPinObj->PinNum * 2));

            /* Set Pin Input PullUp/PullDown Configuration */
            (GPIOC->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_pGPIO_InputPinObj->PinNum * 2));
            (GPIOC->PUPDR) |=  ((Copy_pGPIO_InputPinObj->PullUpPullDown)<<(Copy_pGPIO_InputPinObj->PinNum * 2));

        break;
        
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
            break;
        }
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for The Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set The Mode Bits of the Specific Pin */
        (GPIOA->MODER) &= ~((MODER_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOA->MODER) |=  ((Copy_u8PinMode)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTB:
        /* Set The Mode Bits of the Specific Pin */
        (GPIOB->MODER) &= ~((MODER_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOB->MODER) |=  ((Copy_u8PinMode)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTC:
        /* Set The Mode Bits of the Specific Pin */
        (GPIOC->MODER) &= ~((MODER_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOC->MODER) |=  ((Copy_u8PinMode)<<(Copy_u8Pin * 2));
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_voidSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputType)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Check For Pin Output Type */
        switch (Copy_u8PinOutputType)
        {
        case GPIO_OUTPUT_PUSH_PULL:
            /* Set Pin Output Type To 'Push/Pull' */
            CLR_BIT(GPIOA->OTYPER, Copy_u8Pin);
            break;

        case GPIO_OUTPUT_OPEN_DRAIN:
            /* Set Pin Output Type To 'Open Drain' */
            SET_BIT(GPIOA->OTYPER, Copy_u8Pin);
            break;
        
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
            break;
        }
        break;

    case GPIO_PORTB:
        /* Check For Pin Output Type */
        switch (Copy_u8PinOutputType)
        {
        case GPIO_OUTPUT_PUSH_PULL:
            /* Set Pin Output Type To 'Push/Pull' */
            CLR_BIT(GPIOB->OTYPER, Copy_u8Pin);
            break;

        case GPIO_OUTPUT_OPEN_DRAIN:
            /* Set Pin Output Type To 'Open Drain' */
            SET_BIT(GPIOB->OTYPER, Copy_u8Pin);
            break;
        
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
            break;
        }
        break;

    case GPIO_PORTC:
        /* Check For Pin Output Type */
        switch (Copy_u8PinOutputType)
        {
        case GPIO_OUTPUT_PUSH_PULL:
            /* Set Pin Output Type To 'Push/Pull' */
            CLR_BIT(GPIOC->OTYPER, Copy_u8Pin);
            break;

        case GPIO_OUTPUT_OPEN_DRAIN:
            /* Set Pin Output Type To 'Open Drain' */
            SET_BIT(GPIOC->OTYPER, Copy_u8Pin);
            break;
        
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
            break;
        }
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_voidSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputSpeed)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Pin Specific Output Speed by Changing Output Speed Bits */
        (GPIOA->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOA->OSPEEDR) |=  ((Copy_u8PinOutputSpeed)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTB:
        /* Set Pin Specific Output Speed by Changing Output Speed Bits */
        (GPIOB->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOB->OSPEEDR) |=  ((Copy_u8PinOutputSpeed)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTC:
        /* Set Pin Specific Output Speed by Changing Output Speed Bits */
        (GPIOC->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOC->OSPEEDR) |=  ((Copy_u8PinOutputSpeed)<<(Copy_u8Pin * 2));
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_voidSetPinPullUpPullDown(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinPullUpPullDown)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Pin Input PullUp/PullDown Configuration */
        (GPIOA->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOA->PUPDR) |=  ((Copy_u8PinPullUpPullDown)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTB:
        /* Set Pin Input PullUp/PullDown Configuration */
        (GPIOB->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOB->PUPDR) |=  ((Copy_u8PinPullUpPullDown)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTC:
        /* Set Pin Input PullUp/PullDown Configuration */
        (GPIOC->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOC->PUPDR) |=  ((Copy_u8PinPullUpPullDown)<<(Copy_u8Pin * 2));
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_voidSetPinAlternativeFunction(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinAlternativeFunction)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* If Pin Number is from 0 to 7, Use AFRL Register */
        if (Copy_u8Pin <= 7)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOA->AFRL) &= ~((AFR_BIT_MASK)<<(Copy_u8Pin * 4));
            (GPIOA->AFRL) |=  ((Copy_u8PinAlternativeFunction)<<(Copy_u8Pin * 4));
        }
        /* If Pin Number is from 8 to 15, Use AFRH Register */
        else if (Copy_u8Pin > 7)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOA->AFRH) &= ~((AFR_BIT_MASK)<<(Copy_u8Pin * 4));
            (GPIOA->AFRH) |=  ((Copy_u8PinAlternativeFunction)<<(Copy_u8Pin * 4));
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinNumberInvalidConfiguration;
        }
        break;

    case GPIO_PORTB:
        /* If Pin Number is from 0 to 7, Use AFRL Register */
        if (Copy_u8Pin <= 7)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOB->AFRL) &= ~((AFR_BIT_MASK)<<(Copy_u8Pin * 4));
            (GPIOB->AFRL) |=  ((Copy_u8PinAlternativeFunction)<<(Copy_u8Pin * 4));
        }
        /* If Pin Number is from 8 to 15, Use AFRH Register */
        else if (Copy_u8Pin > 7)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOB->AFRH) &= ~((AFR_BIT_MASK)<<(Copy_u8Pin * 4));
            (GPIOB->AFRH) |=  ((Copy_u8PinAlternativeFunction)<<(Copy_u8Pin * 4));
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinNumberInvalidConfiguration;
        }
        break;

    case GPIO_PORTC:
        /* If Pin Number is from 0 to 7, Use AFRL Register */
        if (Copy_u8Pin <= 7)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOC->AFRL) &= ~((AFR_BIT_MASK)<<(Copy_u8Pin * 4));
            (GPIOC->AFRL) |=  ((Copy_u8PinAlternativeFunction)<<(Copy_u8Pin * 4));
        }
        /* If Pin Number is from 8 to 15, Use AFRH Register */
        else if (Copy_u8Pin > 7)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOC->AFRH) &= ~((AFR_BIT_MASK)<<(Copy_u8Pin * 4));
            (GPIOC->AFRH) |=  ((Copy_u8PinAlternativeFunction)<<(Copy_u8Pin * 4));
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinNumberInvalidConfiguration;
        }
        break;

    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Check for Pin Value */
        switch (Copy_u8PinValue)
        {
        case HIGH:
            /* Change Pin Output Value To High */
            SET_BIT(GPIOA->ODR, Copy_u8Pin);
            // GPIOA->BSRR = Global_u32SetPin[Copy_u8Pin];
            break;
        case LOW:
            /* Change Pin Output Value To Low */
            CLR_BIT(GPIOA->ODR, Copy_u8Pin);
            break;
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinValueInvalidConfiguration;
            break;
        }
        break;
    
    case GPIO_PORTB:
        /* Check for Pin Value */
        switch (Copy_u8PinValue)
        {
        case HIGH:
            /* Change Pin Output Value To High */
            SET_BIT(GPIOB->ODR, Copy_u8Pin);
            break;
        case LOW:
            /* Change Pin Output Value To Low */
            CLR_BIT(GPIOB->ODR, Copy_u8Pin);
            break;
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinValueInvalidConfiguration;
            break;
        }
        break;

    case GPIO_PORTC:
        /* Check for Pin Value */
        switch (Copy_u8PinValue)
        {
        case HIGH:
            /* Change Pin Output Value To High */
            SET_BIT(GPIOC->ODR, Copy_u8Pin);
            break;
        case LOW:
            /* Change Pin Output Value To Low */
            CLR_BIT(GPIOC->ODR, Copy_u8Pin);
            break;
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinValueInvalidConfiguration;
            break;
        }
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 * Copy_pu8PinValue)
{
    /* Create Varibale To Store Pin Value */
    u8 Local_u8PinValue;    

    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;
    
    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Read Pin Value */
        Local_u8PinValue = GET_BIT(GPIOA->ODR, Copy_u8Pin);
        break;

    case GPIO_PORTB:
        /* Read Pin Value */
        Local_u8PinValue = GET_BIT(GPIOB->ODR, Copy_u8Pin);
        break;

    case GPIO_PORTC:
        /* Read Pin Value */
        Local_u8PinValue = GET_BIT(GPIOC->ODR, Copy_u8Pin);
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* Update PinValue Pointer Dereferenced Value */
    *Copy_pu8PinValue = Local_u8PinValue;

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    /* Create Variables To Help With Word-Accessing The LCKR Register */
    u32 Local_u32LockRegister;
    u32 Local_u32LockRegisterLCKK0;
    u32 Local_u32LockRegisterLCKK1;
    u32 Local_u32LCKKBitValue;
    
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Make a Copy Of the LCKR Register */
        Local_u32LockRegister = GPIOA->LCKR;
        SET_BIT(Local_u32LockRegister, Copy_u8Pin);
        /* Make a Copy Of The Register With LCKK bit set to 0*/
        Local_u32LockRegisterLCKK0 = Local_u32LockRegister;
        CLR_BIT(Local_u32LockRegisterLCKK0, LCKR_LCKK);
        /* Make a Copy Of The Register With LCKK bit set to 1*/
        Local_u32LockRegisterLCKK1 = Local_u32LockRegister;
        SET_BIT(Local_u32LockRegisterLCKK1, LCKR_LCKK);

        /* Start The Lock Key Write Sequence */
        GPIOA->LCKR = Local_u32LockRegisterLCKK1;
        GPIOA->LCKR = Local_u32LockRegisterLCKK0;
        GPIOA->LCKR = Local_u32LockRegisterLCKK1;
        Local_u32LockRegister = GPIOA->LCKR;
        Local_u32LCKKBitValue = GET_BIT(GPIOA->LCKR, LCKR_LCKK);
        /* Check if The LCKK key bit is 1 */
        if(Local_u32LCKKBitValue == 1)
        {
            /* Do Nothing*/
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_LockKeyBitInvalidConfiguration;
        }
        break;

    case GPIO_PORTB:
        /* Make a Copy Of the LCKR Register */
        Local_u32LockRegister = GPIOB->LCKR;
        SET_BIT(Local_u32LockRegister, Copy_u8Pin);
        /* Make a Copy Of The Register With LCKK bit set to 0*/
        Local_u32LockRegisterLCKK0 = Local_u32LockRegister;
        CLR_BIT(Local_u32LockRegisterLCKK0, LCKR_LCKK);
        /* Make a Copy Of The Register With LCKK bit set to 1*/
        Local_u32LockRegisterLCKK1 = Local_u32LockRegister;
        SET_BIT(Local_u32LockRegisterLCKK1, LCKR_LCKK);

        /* Start The Lock Key Write Sequence */
        GPIOB->LCKR = Local_u32LockRegisterLCKK1;
        GPIOB->LCKR = Local_u32LockRegisterLCKK0;
        GPIOB->LCKR = Local_u32LockRegisterLCKK1;
        Local_u32LockRegister = GPIOB->LCKR;
        Local_u32LCKKBitValue = GET_BIT(GPIOB->LCKR, LCKR_LCKK);
        /* Check if The LCKK key bit is 1 */
        if(Local_u32LCKKBitValue == 1)
        {
            /* Do Nothing*/
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_LockKeyBitInvalidConfiguration;
        }
        break;
    
    case GPIO_PORTC:
        /* Make a Copy Of the LCKR Register */
        Local_u32LockRegister = GPIOC->LCKR;
        SET_BIT(Local_u32LockRegister, Copy_u8Pin);
        /* Make a Copy Of The Register With LCKK bit set to 0*/
        Local_u32LockRegisterLCKK0 = Local_u32LockRegister;
        CLR_BIT(Local_u32LockRegisterLCKK0, LCKR_LCKK);
        /* Make a Copy Of The Register With LCKK bit set to 1*/
        Local_u32LockRegisterLCKK1 = Local_u32LockRegister;
        SET_BIT(Local_u32LockRegisterLCKK1, LCKR_LCKK);

        /* Start The Lock Key Write Sequence */
        GPIOC->LCKR = Local_u32LockRegisterLCKK1;
        GPIOC->LCKR = Local_u32LockRegisterLCKK0;
        GPIOC->LCKR = Local_u32LockRegisterLCKK1;
        Local_u32LockRegister = GPIOC->LCKR;
        Local_u32LCKKBitValue = GET_BIT(GPIOC->LCKR, LCKR_LCKK);
        /* Check if The LCKK key bit is 1 */
        if(Local_u32LCKKBitValue == 1)
        {
            /* Do Nothing*/
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_LockKeyBitInvalidConfiguration;
        }
        break;

    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    } 

    /* return Error State */
    return Local_u8GPIOErrorState;
}

