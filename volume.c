#include <stdio.h>
#include <math.h>

double quadratic(double a, double b, double c, double side1, double side2);

int main(void)
{
	double side1, side2, a, b, c;

	printf("Enter side 1:\n");
	scanf(" %lf", &side1);
	printf("Enter side 2:\n");
	scanf(" %lf", &side2);

	a = 12;
	b = (side1 * -2) + (side2 * -2);
	b = b * 2;
	c = side1 * side2;

	quadratic(a, b, c, side1, side2);

	return 0;
}

double quadratic(double a, double b, double c, double side1, double side2)
{
	
	double exp1 = pow(b, 2) - 4 * a * c;
	double exp2 = sqrt(exp1);
	double exp3 = -b + (exp2);
	double exp4 = -b - (exp2);
	
	double result1 = exp3 / (2 * a);
	double result2 = exp4 / (2 * a);

	printf("x is either %2.3f or %2.3f\n", result1, result2);

	result1 = (4 * pow(result1, 3)) + ((b/2) * pow(result1, 2)) + (c * result1);
	result2 = (4 * pow(result2, 3)) + ((b/2) * pow(result2, 2)) + (c * result2);

	printf("v is either %2.3f or %2.3f\n", result1, result2);
}

/*double volume(double result1, double result2);
{

}
*/