#include <stdio.h>

int main(void)
{
	float gasPrice; // dollars per gallon
	int tankSize; // size of gas tank in gallons
	int tankRemaining; //percentage (0-100)
	float totalCost; //total cost for user

	printf("Please enter the price of gas (dollars per gallon):"); 
	scanf(" %f", &gasPrice);

	printf("\nPlease enter the size of your gas tank (gallons):");
	scanf("%d", &tankSize);

	printf("\nPlease enter the amount of fuel left in your tank (percentage):");
	scanf("%d", &tankRemaining);

	tankRemaining = tankRemaining/100; //tank remaining is converted to percentage pt1

	tankRemaining = 1 - tankRemaining; //pt 2

	tankSize = tankSize*tankRemaining; //tank size converts to gas needed

	totalCost = tankSize * gasPrice; // gas needed multiplied by price

	printf("%f", totalCost);


	return 0;
}