#include <stdio.h>
#include <math.h>

double calculator(double a, double b, double c, double d, double e, double f, double x);

void main(void)
{
	double a, b, c, d, e, f, x;

	printf("\nWelcome to the limit calculator, please enter your values as such:\n");
	printf("ax^5+bx^4+cx^3+dx^2+ex+f\n");

	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);
	printf("d = ");
	scanf("%lf", &d);
	printf("e = ");
	scanf("%lf", &e);
	printf("f = ");
	scanf("%lf", &f);

	printf("x = ");
	scanf("%lf", &x);

	double result = calculator(a, b, c, d, e, f, x);

	printf("The limit of %.1fx^5+%.1fx^4+%.1fx^3+%.1fx^2+%.1fx+%.1f as x approaches %.1f = %.4f", a, b, c, d, e, f, x, result);

	return;
}

double calculator(double a, double b, double c, double d, double e, double f, double x)
{
	a = pow(x, 5) * a;
	b = pow(x, 4) * b;
	c = pow(x, 3) * c;
	d = pow(x, 2) * d;
	e = x * e;

	double result = a + b + c + d + e + f; 

	return result;
}