/*
 * ----------------------------------------------------------------------------------
 * Filename     :	SEVEN_SEG_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 28, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAR 28, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_private.h"
#include "SEVEN_SEG_config.h"

u8 Local_u8SevenSegmentValuesComAnode[10] = 
{
	NUM_0_COM_ANDOE,
	NUM_1_COM_ANDOE,
	NUM_2_COM_ANDOE,
	NUM_3_COM_ANDOE,
	NUM_4_COM_ANDOE,
	NUM_5_COM_ANDOE,
	NUM_6_COM_ANDOE,
	NUM_7_COM_ANDOE,
	NUM_8_COM_ANDOE,
	NUM_9_COM_ANDOE,
};

u8 Local_u8SevenSegmentValuesComCathode[10] = 
{
	NUM_0_COM_CATHODE,
	NUM_1_COM_CATHODE,
	NUM_2_COM_CATHODE,
	NUM_3_COM_CATHODE,
	NUM_4_COM_CATHODE,
	NUM_5_COM_CATHODE,
	NUM_6_COM_CATHODE,
	NUM_7_COM_CATHODE,
	NUM_8_COM_CATHODE,
	NUM_9_COM_CATHODE,
};

void SEVEN_SEG_voidInit(SEVEN_SEG_t* Copy_pSEVEN_SEG_t_Obj)
{
	MDIO_voidSetPortDir(Copy_pSEVEN_SEG_t_Obj->SEVEN_SEG_u8PORT, OUTPUT);
}

void SEVEN_SEG_voidSendDigit(SEVEN_SEG_t* Copy_pSEVEN_SEG_t_Obj, u8 Copy_u8Digit)
{
	switch (Copy_pSEVEN_SEG_t_Obj->SEVEN_SEG_u8CONNECTION)
	{
	case COMMON_ANODE:
		MDIO_voidSetPortValue(Copy_pSEVEN_SEG_t_Obj->SEVEN_SEG_u8PORT, Local_u8SevenSegmentValuesComAnode[Copy_u8Digit]);
		break;
	case COMMON_CATHODE:
		MDIO_voidSetPortValue(Copy_pSEVEN_SEG_t_Obj->SEVEN_SEG_u8PORT, Local_u8SevenSegmentValuesComCathode[Copy_u8Digit]);
		break;
	default:
		/* Do Nothing */
		break;
	}	
}

void SEVEN_SEG_voidClrDisplay(SEVEN_SEG_t* Copy_pSEVEN_SEG_t_Obj)
{
	switch (Copy_pSEVEN_SEG_t_Obj->SEVEN_SEG_u8CONNECTION)
	{
	case COMMON_ANODE:
		MDIO_voidSetPortValue(Copy_pSEVEN_SEG_t_Obj->SEVEN_SEG_u8PORT, ALL_OFF_COM_ANODE);
		break;
	case COMMON_CATHODE:
		MDIO_voidClrPortValue(Copy_pSEVEN_SEG_t_Obj->SEVEN_SEG_u8PORT);
		break;
	default:
		/* Do Nothing */
		break;
	}
}

void SEVEN_SEG_voidSendCustomCharacter(SEVEN_SEG_t* Copy_pSEVEN_SEG_t_Obj, u8 Copy_u8CustomCharacter)
{
	MDIO_voidSetPortValue(Copy_pSEVEN_SEG_t_Obj->SEVEN_SEG_u8PORT, Copy_u8CustomCharacter);
}


