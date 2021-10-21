#include <stdio.h>
#include <ctype.h>

void Greeting();//welcome the user to their dining account
void DisplayMenu();//display food menu
void Purchase(double *balance);//user will make a purchase
void ViewAccount(double *balance);//display current account balance of user
void Transaction(double *balance, double price);//transaction with user account
void Reload(double *balance);//reload your account balance

int main(void)
{
	double balance = 0; //balance is set to 0

	Greeting(); //displays greeting at beginning

	char input; //input for main menu

	do //displays menu first time
	{
		printf("****************************************************\n");
		printf("Please select one of the following:\n"); //displays menu options
		printf("P: Make a Purchase at Knightstop\n");
		printf("V: View your account balance\n");
		printf("B: Browse Inventory at Knightstop\n");
		printf("R: Reload Knight's Account\n");
		printf("E: Exit\n");
		printf(":");
		scanf(" %c", &input); //prompts input

		input = toupper(input); //sets input to uppercase for if statements

		if(input == 'P') 
		{
			Purchase(&balance); //calls purchase func if user selects P
		}
		else if(input == 'V') //calls viewaccount func if user selects v
		{
			ViewAccount(&balance); //calls viewaccount func if user selects v
		}
		else if(input == 'B')
		{
			DisplayMenu(); //repeats
		}
		else  if(input == 'R')
		{
			Reload(&balance);
		}
	}
	while(input != 'E'); //exits program
	
	printf("****************************************************\n"); //exit message
	printf("  You have chosen to exit the application.\n");
	printf("	Your final balance is $%.2f.\n", balance);
	printf("		Have a great day!\n");

	return 0;
}

void Greeting()
{
	printf("****************************************************\n"); //greeting message
	printf("	  Welcome to the UCF Knightstop!\n");
	printf("    At Knightstop, you can manage your account,\n");
	printf("browse the Knightstop inventory, and make purchases.\n");
}

void DisplayMenu()
{
	printf("****************************************************\n"); //displays menu options
	printf("Items listed are currently available for purchase:\n");
	printf("1. Bottled Water...............................$1.00\n");
	printf("2. Chips.......................................$2.13\n");
	printf("3. Soda........................................$1.12\n");
	printf("4. Wrap........................................$5.31\n");
	printf("5. Candy Bag...................................$3.21\n");
	printf("6. Cheese Pizza................................$6.24\n");
	printf("7. Chocolate Brownie...........................$1.23\n");
	printf("8. Chocolate Chip Cookie.......................$1.15\n");

}	

void Purchase(double *balance)
{
	double water = 1, chips = 2.13, soda = 1.12, wrap = 5.31, candy = 3.21, pizza = 6.24, brownie = 1.23, cookie = 1.15; //sets item prices
	double price; //
	int option;

	DisplayMenu(); //displays menu for someone making a purchase

	printf("Please select an option:\n"); //prompts and recieves menu choice
	printf(":");
	scanf(" %d", &option);

	switch(option)
	{
		case 1: //if user selects 1, it notifies them
			printf("You have selected Water Bottle. Total = $1.00\n");
			price = water; //sets price equal to the menu option
			break;

		case 2: //if user selects 2, it notifies them
			printf("You have selected Chips. Total = $2.13\n");
			price = chips; //sets price equal to the menu option
			break;
		case 3: //repeats
			printf("You have selected Soda. Total = $1.12\n");
			price = soda;
			break;
		case 4:
			printf("You have selectd Wrap. Total = $5.31\n");
			price = wrap;
			break;
		case 5:
			printf("You have selected Candy. Total = $3.21\n");
			price = candy;
			break;
		case 6:
			printf("You have selected Cheese Pizza. Total = $3.21\n");
			price = pizza;
			break;
		case 7:
			printf("You have selected Chocolate Brownie. Total = $3.21\n");
			price = brownie;
			break;
		case 8:
			printf("You have selected Chocolate Chip Cookie. Total = $3.21\n");
			price = cookie;
			break;
	}

	printf("Your account balance before transaciton: $%.2f\n", *balance); //notifies user initial balance

	Transaction(balance, price); //calls transaction using the balance and price of selected option
}

void ViewAccount(double *balance)
{
	printf("****************************************************\n");
	printf("Your current balance is $%.2f\n", *balance); //displays account balance
}

void Transaction(double *balance, double price)
{
	printf("\nBeginning transaction process...\n"); //notifies user transaction is starting and how much it is
	printf("Billing $%.2f to your account...\n", price);

	if(*balance >= price) //only executs if user has enough money
	{
		*balance -= price; //subtracts price from balance
		printf("Transaction complete!\n");
		printf("Your new balance is $%.2f\n", *balance); //notifies user
	}
	else //executes if user does not have enough money
	{
		printf("Insufficient funds.\n"); //notifies user
		printf("Please reload your account balance.\n");
		Reload(balance); //calls reload because user does not have enough funds
	}

}

void Reload(double *balance)
{
	int option; //menu optoin

	printf("****************************************************\n");
	printf("Please select an amount to reload.\n"); //displays amounts user can increase by
	printf("1. $1.00\n");
	printf("2. $5.00\n");
	printf("3. $10.00\n");
	printf("4. Cancel.\n");
	printf(":");
	scanf(" %d", &option);

	switch(option)
	{
		case 1: //menu option 1
			printf("Adding $1.00 to your balance...\n"); //notifies user
			*balance += 1; //adds to balance
			printf("Your new balance is $%.2f\n", *balance); //displays new balance
			break;
		case 2: //menu option 2
			printf("Adding $5.00 to your balance...\n"); //notifies user
			*balance += 5; //adds to balance
			printf("Your new balance is $%.2f\n", *balance); //displays new balance
			break;
		case 3: //repeats
			printf("Adding $10.00 to your balance...\n");
			*balance += 10;
			printf("Your new balance is $%.2f\n", *balance);
			break;
		case 4:
			printf("Cancelling reload...\n");
			break;
	}



}