#include <stdio.h>

//Luke Templeton
//Dr. Steinberg
//COP3223 Section 2
//Small Program 1

int main(void)
{
	//QUESTION 1

	int i; //counter 

	for (int i = 0; i < 4; ++i) //displays top of T 4 times
	{
		printf("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT");
	}

	for (int i = 0; i < 12; ++i) //Displays vertical T line 12 times
	{

		printf("\n              TTTTTTTTTTTTTTT");
	} 

	//QUESTION 2

	double Mileage1; //Starting mileage 
	double Mileage2; //Ending mileage
	double reimbursementPerMile = 0.35; //Reimbursment per mile
	double reimbursementTotal; //Total amount user recieves

	printf("\n\nWelcome to the mileage reimbursement calculator.\n");

	printf("Please enter your original mileage:"); //user input for og mileage
	scanf("%lf", &Mileage1);

	printf("Please enter you current mileage:"); //user input for ending mileage
	scanf("%lf", &Mileage2);

	reimbursementTotal = (Mileage2 - Mileage1) * reimbursementPerMile; //calculates total reimbursement

	printf("Your total reimbursement is $%.2f\n",reimbursementTotal); 

	//QUESTION 3

	int hours; //hours of downtime 
	double minutes; //minutes of downtime
	double t; 
	double temp; //freezer temp

	printf("\n\nWelcome to the freezer temperature estimator.\n");

	printf("Please enter the amount of hours the freezer has been down:"); //user enters hours 
	scanf("%d", &hours);

	printf("Please enter the amount of minutes the freezer has been down:"); //user enters minutes
	scanf("%lf", &minutes);

	t = hours + (minutes / 60);

	temp = ((t * t * 4) / (t + 2)) - 20; //Temp equation

	printf("Your freezer is an estimated %.2f C\n", temp); 

	//QUESTION 4

	double pi = 3.14159; //pi constant 
	double r; //radius
	double d; //diameter
	double c; //circumference
	double a; //area

	printf("\n\nPlease enter the radius of your circle:"); //user input for radius
	scanf("%lf", &r);

	d = r * 2; //equations for d, c, and a
	c = pi * d;
	a = pi * (r * r);

	printf("Diameter:%.2f\nCircumference:%.2f\nArea:%.2f\n", d, c, a); 

	return 0;
}