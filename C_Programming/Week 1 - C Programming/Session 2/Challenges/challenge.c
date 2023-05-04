#include <stdio.h>

void main(void)
{
	int x = 5;
	x ^= (1<<3);
	printf("%d\n", x);
}

