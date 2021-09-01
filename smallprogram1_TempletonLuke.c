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

	printf("\nYour total reimbursement is $%.2f\n",reimbursementTotal); //QUESTION 2 END


	int hours;

	return 0;
}