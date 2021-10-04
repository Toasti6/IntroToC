//Luke Templeton
//Dr. Steinberg
//COP3223 Section 2
//Small Program 4

#include <stdio.h>

void Triangle(void);
void AdvancedMenu(void);
int Fibonacci(int n);

int main(void)
{
	Triangle(); //calls triangle func

	AdvancedMenu(); //calls menu func

	int n, result; //n for fibonacci

	printf("\nEnter a value greater than or equal to 2:"); //prompt and input for fibonacci number
	scanf(" %d", &n);

	if(n >= 2)
	{
		int result = Fibonacci(n); //calls fibonacci if input is >= 2
	}
	else
	{
		printf("Error. Input was less than 2.\n"); //displays error if less than 2
	}

	printf("Result = %d\n", result); //prints fibonacci result

	return 0;
}

void Triangle(void)
{
	int rows; //amount of rows present in triangle

	printf("How many rows would you like in the triangle?\n"); //prompt and input for row amount
	scanf(" %d", &rows);

	int i; //outer for loop counter

	if(rows >= 3) //rows must be greater than or equal to 3
	{
		for(i = 1; i <= rows; i++) //repeats rows "rows" amount of times
		{
			for(int j = 0; j < i; j++) //prints an additional asterisk every row
			{
				printf("*");
			}
			printf("\n");
		}

	}
	else 
	{
		printf("Error: Number entered was less than 3.\n"); //executed if number is less than 3
	}
}

void AdvancedMenu(void)
{
	int button;

	do
	{
		printf("\n1. Blue Button\n"); //menu options, printed at least once
		printf("2. Green Button\n");
		printf("3. Red Button\n");
		printf("4. Yellow Button\n");
		printf("5. Exit\n");
		printf("Make a selection:");
		scanf(" %d", &button);

		switch(button)
		{
			case 1: //compares button to each case, displays proper button
			{
				printf("Blue Button Pressed.\n");
				break;
			}
			case 2:
			{
				printf("Green Button Pressed.\n");
				break;
			}
			case 3:
			{
				printf("Red Button Pressed.\n");
				break;
			}
			case 4:
			{
				printf("Yellow Button Pressed.\n");
				break;
			}
			case 5:
			{
				printf("Exit.\n");
				break;
			}
		}
	}
	while(button < 5); //keeps looping until user exits


}

int Fibonacci(int n)
{
	int i, result, x, y;

	y = 1;

	for(i = 1; i < n; i++)
	{
		result = x + y;
		x = y;
		y = result;
	}

	return result;
}