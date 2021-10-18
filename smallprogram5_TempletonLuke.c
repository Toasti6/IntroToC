#include <stdio.h>

void Change(double *p, double *d);
void MultTable(int *r, int *c);
void Maximum(int *a, int *b);
void IncrementUpdate(int *v);

int main(void)
{
	double paid, due;

	printf("\nEnter amount due:"); //asks and recieves amount due and paid
	scanf(" %lf", &due);
	printf("\nEnter amount paid:");
	scanf(" %lf", &paid);

	Change(&paid, &due);

	int row, column;

	printf("\nEnter number of rows:"); //asks and recieves number of rows and columns
	scanf(" %d", &row);
	printf("\nEnter number of columns:");
	scanf(" %d", &column);

	MultTable(&row, &column);

	int num1, num2;

	printf("\nEnter a number:"); //asks and recieves numbers for maximum comparison
	scanf(" %d", &num1);
	printf("Enter another one:");
	scanf(" %d", &num2);

	Maximum(&num1, &num2);

	int val = 0;
	printf("\nBefore calling IncrementUpdate\n");//displays that val starts at 0
	printf("val = %d\n", val);

	IncrementUpdate(&val);

	printf("\nAfter calling IncrementUpdate\n");//displays val after incrementupdate to show change
	printf("val = %d\n", val);
	
	return 0;
}

void Change(double *p, double *d)
{
	int dollar = 0, quarter = 0, dime = 0, nickel = 0, penny = 0;

	double change = *p - *d; //change is equal to the amount paid minus due
	change = change * 100; //change is converted to pennies

	if (change >= 100) //executes if change is more than a dollar
	{
		dollar = change/100; //sets dollar change amount
		change -= dollar * 100; //change due no longer includes dollars 
	}
	if (change >= 25) //executes if change is more than a quarter
	{
		quarter = change / 25; //sets quarter change amount
		change -= quarter * 25; //change due no longer inlcudes dollars
	}
	if (change >= 10) //repeated
	{
		dime = change / 10;
		change -= dime * 10;
	}
	if (change >= 4.9) //4.9 bc rounding errors
	{
		nickel = change / 4.9;
		change -= nickel * 5;
	}
	if (change >= .5)//.5 bc rounding errors
	{
		penny = change/1 + .5;
	}


	printf("\nChange due:"); //lists change due
	printf("\n%d dollars", dollar);
	printf("\n%d quarters", quarter);
	printf("\n%d dimes", dime);
	printf("\n%d nickels", nickel);
	printf("\n%d pennies", penny);
}

void MultTable(int *r, int *c)
{	
	int x, y;//counters for mult table

	for(int i = 0; i < *c; i++)//executes once for every column
	{
		y = 1;//resets number being multiplied by first coulumn row

		for(int j = 0; j < *r; j++)//executes once for every row
		{			
			x = (i + 1) * y;//row entry equals the first column row times y
			y++;//adds one per row entry
			printf("	%d", x); //prints entry with tab
		}

		printf("\n");//starts a new row
	}
}

void Maximum(int *a, int *b)
{
	if(*a > *b) //if num1 is greater than num2, this executes
	{
		printf("%d is greater than %d\n", *a, *b);//displays that num1 is greater than num2
	}
	else if(*b > *a)//if num2 is greater than num1, this executes
	{
		printf("%d is greater than %d\n", *b, *a);//displays that num2 is greater than num1
	}
	else//if num1 is equal than num2, this executes
	{
		printf("%d is equal to %d\n", *b, *a);//displays that num1 is equal than num2
	}
}

void IncrementUpdate(int *v)
{
	int input; //users option input

	do//executes at least once
	{
		printf("\nUpdating val now...\n");
		printf("If you would like to update enter 0\n");
		printf("otherwise, enter anything else:");
		scanf(" %d", &input);

		*v += 5; //updates val1
	}
	while(input == 0);//keeps executing when user enters 0
}

