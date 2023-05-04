/*
 * ----------------------------------------------------------------------------------
 * Name      	: Pointers_Assignment_2.c
 *
 * Created on	: Mar 9th, 2023
 * Author    	: Ahmed Essam El-Mogy
 * Description	: Swapping pointers
 * ----------------------------------------------------------------------------------
 */

#include <stdio.h>

void main(void)
{
	int x, y, z;
	int *p, *q, *r;
	
	x = 3;
	y = 4;
	z = 0;
	
	p = &x;
	q = &y;
	r = &z;
	
	// Values before swapping
	printf("Values before swapping are:\n");
	printf("x: %d\ny: %d\nz: %d\np: %p\nq: %p\nr: %p\n*p: %d\n*q: %d\n*r: %d\n\n"
		, x, y, z, p, q, r, *p, *q, *r);
	
	// Swapping
	printf("Swapping pointers:\n");
	r = p;
	p = q;
	q = r;
	
	// Values after swapping
	printf("Values after swapping are:\n");
	printf("x: %d\ny: %d\nz: %d\np: %p\nq: %p\nr: %p\n*p: %d\n*q: %d\n*r: %d\n"
		, x, y, z, p, q, r, *p, *q, *r);
	
}


