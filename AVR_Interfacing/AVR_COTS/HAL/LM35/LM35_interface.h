/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LM35_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	APR 6, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	AVR GCC
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    APR 6, 2023		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

 

typedef struct {
	u8 LM35_u8Channel;
}LM35_t;

void LM35_voidInit(LM35_t* LM35obj);
u8 LM35_u8GetValue(LM35_t* LM35obj);


#endif 
