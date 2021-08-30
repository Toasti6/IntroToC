#include <stdio.h>

char operation; //users preffered operation

double input1; //first number in operation
double input2; //second number in operation

double result; // result of operation

int inputF() //
{
	printf("\nEnter the first value of your operation:"); //prompt for value1
	scanf(" %lf", &input1);

	printf("\nEnter the second value of your operation:"); //prompt for value2
	scanf(" %lf", &input2);
}

int main(void)
{
	
	printf("Please specify an operation (a, s, m ,d):"); //user selects addition, subtraction, etc
	scanf(" %c", &operation);
	
	if(operation == 'a') //addition operation

	{
		inputF();

		result = input1 + input2; 

		printf("Result = %f", result);
	}

	else if(operation == 's') //subtraction operation
	{
		inputF();

		result = input1 - input2; 

		printf("Result = %f", result); 
	}

	else if(operation == 'm') //miltiplication operation
	{
		inputF();

		result = input1*input2; 

		printf("Result = %f", result);
	}

	else if(operation == 'd') //division operation
	{
		inputF();

		result = input1/input2; 

		printf("Result = %f", result);
	}

	else
	{
		printf("Not a valid operation. Please enter a, s, m, or d. \n"); //if user gives unwanted input

		main();
	}

	return 0;
}


