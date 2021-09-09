#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c;

	printf("\nEnter a value for a: ");
	scanf("%lf", &a);
	printf("\nEnter a value for b: ");
	scanf("%lf", &b);
	printf("\nEnter a value for c: ");
	scanf("%lf", &c);

	double exp1 = pow(b, 2) - 4 * a * c;
	double exp2 = sqrt(exp1);
	double exp3 = -b + (exp2);
	double exp4 = -b - (exp2);
	
	double result1 = exp3 / (2 * a);
	double result2 = exp4 / (2 * a);

	printf("Result: %2.3f, %2.3f\n", result1, result2);

	return 0;
}