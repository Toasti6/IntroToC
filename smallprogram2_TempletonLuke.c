//Luke Templeton
//Dr. Steinberg
//COP3223 Section 2
//Small Program 2

#include <stdio.h>
#include <math.h>

double Hypotenuse(double a, double b); //protypes for each required function
void ParkingCharge();
void Population(int year);
double FactorialApprox(int n);

int main(void)
{
	//QUESTION 1
	double a, b; //variables for retrieving and hypotenuse data

	printf("\nPlease enter a value for side a: "); //user input for sides a and b
	scanf("%lf", &a);
	printf("Please enter a value for side b: ");
	scanf("%lf", &b);

	double resultHypotenuse = Hypotenuse(a, b); //calls hypotenuse function

	printf("The Hypotenuse of your triangle is: %f\n", resultHypotenuse); //displays hypotenuse

	//QUESTION 2
	ParkingCharge(); //calls parking charge func

	//QUESTION 3
	int year; //variable for year input

	printf("\nPlease enter a year after 1990: "); //user input for year after 1990
	scanf("%d", &year);

	Population(year); //calls population func

	//QUESTION 4
	int n;

	printf("\nEnter a value for n: "); //user input for n
	scanf("%d", &n);

	double resultApprox = FactorialApprox(n); //calls factorial func and assigns it to resultApprox

	printf("%d! is approximately %f\n", n, resultApprox); //prints answer for n!

	return 0;
}

double Hypotenuse(double a, double b)
{
	double step1 = pow(a, 2) + pow(b, 2); //adds a sqrd and b sqrd
	double result = sqrt(step1); //finds the sqrt of previous equation

	return result;
}

void ParkingCharge()
{
	double hours;

	printf("\nHow many hours are you expected to remain parked? "); //collects amount of hours user plans on being parked
	scanf("%lf", &hours);

	double totalCharge = 2.49 * hours; //parking charge calculation

	printf("Your estimated total is $%.2f\n", totalCharge); //total charge message
}

void Population(int year)
{
	double step1 = 2.184 * year; //steps of population equation
	double step2 = step1 + 52.966; 
	int totalP = step2 * 1000; //converts number to exact population amount

	printf("Predicted Gotham City population for %d: %d\n",year, totalP); //displays population
}

double FactorialApprox(int n)
{
	const double pi = 3.14159265; //pi

	double step1 = 2 * n + (1/3); //steps for finding factorial of n
	double step2 = step1 * pi;
	double resultApprox = pow(n, n) * exp(-n) * sqrt(step2);

	return resultApprox; //returns result
}