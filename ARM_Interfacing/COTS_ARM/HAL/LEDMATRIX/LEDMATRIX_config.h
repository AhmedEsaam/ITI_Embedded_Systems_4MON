/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LEDMATRIX_config.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 14, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   HAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 14, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef LEDMATRIX_CONFIG_H
#define LEDMATRIX_CONFIG_H

// Columns
#define HLEDMATRIX_C_PORT       GPIO_PORTA

#define HLEDMATRIX_C0_PIN       GPIO_PIN0
#define HLEDMATRIX_C1_PIN       GPIO_PIN1
#define HLEDMATRIX_C2_PIN       GPIO_PIN2
#define HLEDMATRIX_C3_PIN       GPIO_PIN3
#define HLEDMATRIX_C4_PIN       GPIO_PIN4
#define HLEDMATRIX_C5_PIN       GPIO_PIN5
#define HLEDMATRIX_C6_PIN       GPIO_PIN6
#define HLEDMATRIX_C7_PIN       GPIO_PIN7

// Rows
#define HLEDMATRIX_R_PORT       GPIO_PORTB

#define HLEDMATRIX_R0_PIN       GPIO_PIN0
#define HLEDMATRIX_R1_PIN       GPIO_PIN1
#define HLEDMATRIX_R2_PIN       GPIO_PIN2
#define HLEDMATRIX_R3_PIN       GPIO_PIN3
#define HLEDMATRIX_R4_PIN       GPIO_PIN4
#define HLEDMATRIX_R5_PIN       GPIO_PIN5
#define HLEDMATRIX_R6_PIN       GPIO_PIN6
#define HLEDMATRIX_R7_PIN       GPIO_PIN7


#endif /* LEDMATRIX_CONFIG_H */
