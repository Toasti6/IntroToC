#include <stdio.h>

int main(void)
{
	int x = 64;
	int *ptr = &x;

	printf("\nAddress of x = %p", &x);
	printf("\nptr points to = %p", ptr);
	printf("\nAdress of ptr = %p", &ptr);


	return 0;
}