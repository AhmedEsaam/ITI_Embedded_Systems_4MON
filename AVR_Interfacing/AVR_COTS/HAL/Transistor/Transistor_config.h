/*
 * ----------------------------------------------------------------------------------
 * Filename     :	Transistor_config.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	01 SEP, 2021
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU AVR-GCC
 * Controller   :   ATmega32 (8-bit Architecture)
 * Layer        :   HAL (ECUAL)
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0         SEP 01, 2021        Ahmed Essam El-Mogy    Initial Creation
 * ----------------------------------------------------------------------------------
 */
#ifndef TRANSISTOR_CONFIG_H
#define TRANSISTOR_CONFIG_H


#define     TRANSISTOR_PORT             DIO_PORT_A
#define     TRANSISTOR_PIN              PIN0
#define     TRANSISTOR_TYPE             TRANSISTOR_NPN
#define     TRANSISTOR_INITIAL_STATE    TRANSISTOR_SATURATION


#endif
