/*
 * ----------------------------------------------------------------------------------
 * Filename     :	STD_TYPES.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	Mar 22, 2023
 * Version      :	v1.1
 * C Standard   :	C99
 * Compiler     :	GNU GCC
 * ----------------------------------------------------------------------------------
 */ 

#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Unsigned */
typedef     unsigned char       u8;
typedef     unsigned short int  u16;
typedef     unsigned int        u32;

/* Signed */
typedef     signed char         s8;
typedef     signed short int    s16; 
typedef     signed int          s32;

/* Float */
typedef     float               f32;
typedef     double              f64;

#define     TRUE                1
#define     FALSE               0

#define     NULL                (void *)0

#endif /* STD_TYPES_H */
