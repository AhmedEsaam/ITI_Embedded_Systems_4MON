/*
 * ----------------------------------------------------------------------------------
 * Filename     :	KPD_interface.h
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

#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

void KPD_voidInit(void);
u8 KPD_u8GetPressedKey(void);
#endif /* KPD_INTERFACE_H */
