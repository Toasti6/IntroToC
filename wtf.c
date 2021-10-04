#include <stdio.h>
#include <math.h>

void main(void)
{
	double a = -1;
    double b = -2.5;

    a = abs(a);
    b = abs(b);

    printf("a = %f\n", a);
    printf("abs = %f\n", b);

    double c = abs(b) - abs(a);
    printf("%f", c);

	return;
}