/*
 * ----------------------------------------------------------------------------------
 * Filename     :	LEDMATRIX_interface.h
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

#ifndef LEDMATRIX_INTERFACE_H
#define LEDMATRIX_INTERFACE_H

// typedef struct 
// {
// 	u8 LEDMATRIX_u8PORT;
// 	u8 LEDMATRIX_u8CONNECTION;
// }LEDMATRIX_t;

void  HLEDMATRIX_voidInit(void);
void HLEDMATRIX_voidDisplay(u8 * Copy_pu8Data);

#endif /* LEDMATRIX_INTERFACE_H */

