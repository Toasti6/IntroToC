#include <stdio.h>

int main(void)
{
	float gasPrice; // dollars per gallon
	int tankSize; // size of gas tank in gallons
	float tankRemaining; //percentage (0-100)
	float totalCost; //total cost for user

	printf("\nPlease enter the price of gas (dollars per gallon):"); 
	scanf("%f", &gasPrice);

	printf("\nPlease enter the size of your gas tank (gallons):");
	scanf("%d", &tankSize);

	printf("\nPlease enter the amount of fuel left in your tank (percentage):");
	scanf("%f", &tankRemaining);

	totalCost = (1 - (tankRemaining / 100)) * tankSize * gasPrice;

	printf("\nGas will cost you $%.2f\n", totalCost);


	return 0;
}