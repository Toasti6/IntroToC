//Luke Templeton
//Dr. Steinberg
//COP3223 Section 2
//Small Program 3

#include <stdio.h>

void Coordinates(double x, double y);
void Hurricane(double mph);
void Menu(void);
void NumSolutions(void);

void main(void)
{
	double x, y; //coordinates
	double mph; //windspeed

	printf("Please enter an X coordinate: "); //prompt for coordinate input
	scanf(" %lf", &x); //coordinate input
	printf("Please enter an Y coordinate: ");
	scanf(" %lf", &y);

	Coordinates(x, y); //calls coordinate funcion with x and y

	printf("\nPlease enter the windspeed of the hurricane you're in the middle of (mph): "); //prompts for mph input
	scanf(" %lf", &mph); //mph input

	Hurricane(mph); //calls hurricane function with mph

	Menu();

	NumSolutions(); 

	return;
}

void Coordinates(double x, double y)
{
	if(x == 0 && y == 0) //compares x and y values to 0, determines the quadrant
	{
		printf("(%.1f, %.1f) is on the origin.\n", x, y);
	}
	else if(x == 0)
	{
		printf("(%.1f, %.1f) is on the y-axis.\n", x, y);
	}
	else if(y == 0)
	{
		printf("(%.1f, %.1f) is on the x-axis.\n", x, y);
	}
	else if(x > 0 && y > 0)
	{
		printf("(%.1f, %.1f) is in Quadrant 1.\n", x, y);
	}
	else if(x < 0 && y > 0)
	{
		printf("(%.1f, %.1f) is in Quadrant 2.\n", x, y);
	}
	else if(x < 0 && y < 0)
	{
		printf("(%.1f, %.1f) is in Quadrant 3.\n", x, y);
	}
	else if(x > 0 && y < 0)
	{
		printf("(%.1f, %.1f) is in Quadrant 4.\n", x, y);
	}
	return;
}

void Hurricane(double mph)
{
	if(mph < 75) //compares mph to hurricane wind speeds
	{
		printf("You are not in a hurricane!\n");
	}
	else if(mph < 95)
	{
		printf("Category 1 - normal FL weather, you'll be fine.\n");
	}
	else if(mph < 111)
	{
		printf("Category 2 - windy FL day, probably should stay inside.\n");
	}
	else if(mph < 130)
	{
		printf("Category 3 - seek shelter and consider using the hurricane shutters you thought you'd never use.\n");
	}
	else if(mph < 157)
	{
		printf("Category 4 - board windows and strap roof to house\n");
	}
	else if(mph > 157)
	{
		printf("Category 5 - good luck.\n");
	}

	return;
}

void Menu(void)
{
	int option;

	printf("\n1: Red\n"); //displays options for user
	printf("2: Blue\n");
	printf("3: Yellow\n");
	printf("4: Green\n");
	printf("Select an option:");
	scanf("%d", &option); //prompts option input from user

	switch(option)
	{
		case 1: //determines what input user gave and responds with corresponding color
			printf("User selected red\n");
			break;

		case 2:
			printf("User selected blue\n");
			break;

		case 3:
			printf("User selected yellow.\n");
			break;

		case 4:
			printf("User selected green.\n");
			break;

	}

	return;
}

void NumSolutions(void)
{
	double a, b, c; //discriminant values

	printf("\nEnter a:");
	scanf(" %lf", &a);
	printf("Enter b:");
	scanf(" %lf", &b);
	printf("Enter c:");
	scanf(" %lf", &c);

	double step1 = b * b; //step 1 of equation
	double result = step1 - (4 * a * c); //gets result of equation

	if(result == 0) //determines if result is positive, negative, or 0 and gives corresponding solution amount.
	{
		printf("\nOne solution\n");
	}
	else if(result > 0)
	{
		printf("\nTwo solutions\n");
	}
	else if(result < 0)
	{
		printf("\nNo solutions.\n");
	}


	return;
}