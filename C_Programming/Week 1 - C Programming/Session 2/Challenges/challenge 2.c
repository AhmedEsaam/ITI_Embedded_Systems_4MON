#include <stdio.h>

void main(void)
{
	int x = 5;
	printf("%d\n", x&(1<<2)>>2);
}

