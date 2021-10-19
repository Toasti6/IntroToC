#include <stdio.h>
#include <ctype.h>

void Greeting();//welcome the user to their dining account
void DisplayMenu();//display food menu
void Purchase(double *balance);//user will make a purchase
void ViewAccount(double *balance);//display current account balance of user
void Transaction(double *balance,double price);//transaction with user account
void Reload(double *balance);//reload your account balance

int main(void)
{
	double balance = 0;

	Greeting();

	char input;

	do
	{
		printf("****************************************************\n");
		printf("Please select one of the following:\n");
		printf("P: Make a Purchase at Knightstop");
		printf("V: View your account balance\n");
		printf("B: Browse Inventory at Knightstop\n");
		printf("R: Reload Knight's Account\n");
		printf("E: Exit\n");
		printf(":");
		scanf(" %c", &input);

		input = toupper(input);

		if(input == 'P')
		{
			Purchase(&balance);
		}
		else if(input == 'V')
		{
			ViewAccount(&balance);
		}
		else if(input == 'B')
		{
			DisplayMenu();
		}
		else  if(input == 'R')
		{
			Reload(&balance);
		}
	}
	while(input != 'E');
	

	return 0;
}

void Greeting()
{
	printf("****************************************************\n");
	printf("		  Welcome to the UCF Knightstop!\n");
	printf("	At Knightstop, you can manage your account,\n");
	printf("browse the Knightstop inventory, and make purchases.\n");
}

void DisplayMenu()
{
	printf("%s\n", );
}