#include <stdio.h>

int main(void)
{
	int i; //counter QUESTION 1 BEGIN

	for (int i = 0; i < 4; ++i) //displays top of T 4 times
	{
		printf("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT");
	}

	for (int i = 0; i < 12; ++i) //Displays vertical T line 12 times
	{

		printf("\n              TTTTTTTTTTTTTTT");
	} //QUESTION 1 END


	double Mileage1; //Starting mileage QUESTION 2 BEGIN
	double Mileage2; //Ending mileage
	double reimbursementPerMile = 0.35; //Reimbursment per mile
	double reimbursementTotal; //Total amount user recieves

	printf("\n\nWelcome to the mileage reimbursement calculator.\n");

	printf("Please enter your original mileage:"); //user input for og mileage
	scanf("%lf", &Mileage1);

	printf("Please enter you current mileage:"); //user input for ending mileage
	scanf("%lf", &Mileage2);

	reimbursementTotal = (Mileage2 - Mileage1) * reimbursementPerMile; //calculates total reimbursement

	printf("Your total reimbursement is $%.2f\n",reimbursementTotal); //QUESTION 2 END


	int hours; //hours of downtime QUETSION 3 BEGIN
	double minutes; //minutes of downtime
	double t; 
	double temp; //freezer temp

	printf("\n\nWelcome to the freezer temperature estimator.\n");

	printf("Please enter the amount of hours the freezer has been down:"); //user enters hours 
	scanf("%d", &hours);

	printf("Please enter the amount of minutes the freezer has been down:"); //user enters minutes
	scanf("%lf", &minutes);

	t = hours + (minutes / 60);

	temp = ((t * t * 4) / t + 2) - 20; //Temp equation

	printf("Your freezer is an estimated %.2f C\n", temp); //QUESTION 3 END




	return 0;
}