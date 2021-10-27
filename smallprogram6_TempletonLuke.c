#include <stdio.h>

#define SIZE 5

void meanMinMax(int meanArr[]);
void organize(int meanArr[]);
void duplicate(int meanArr[], int newArr[]);
int locate(int meanArr[], int value, int size);

int main(void)
{
	int meanArr[SIZE], newArr[SIZE]; //the two arrays being used

	for(int i = 0; i < SIZE; i++) //array counter
	{
		printf("Enter a value for meanArr[%d]:", i); //prompts and recieves values for meanArr
		scanf(" %d", &meanArr[i]);
	}

	meanMinMax(meanArr);

	organize(meanArr);

	duplicate(meanArr, newArr);

	printf("\n"); //new line for formatting

	for(int i = 0; i < SIZE; i++) //array counter
	{
		printf("newArr[%d] = %d\n", i, newArr[i]); //displays array elements
	}

	int value; //value user enters

	printf("\nEnter a value to find:"); //prompts and recieves value to find
	scanf(" %d", &value);

	int size = sizeof(meanArr)/sizeof(meanArr[0]); //initializes size to size of array

	int location = locate(meanArr, value, size); //initializes location to returned value

	if(location == -1) //executes if value is not found
	{
		printf("Value not found\n");
	}
	else //executs if value is found
	{
		printf("Value was found at meanArr[%d]\n", location);
	}

	return 0;
}

void meanMinMax(int meanArr[])
{
	int  min = meanArr[0], max = meanArr[0], total = 0;
	double mean = meanArr[0];

	for(int i = 0; i < SIZE; i++) //array counter
	{
		if(meanArr[i] < min) //sets smallest array element to min
		{
			min = meanArr[i];
		}
		if(meanArr[i] > max) //sets largest array to max
		{
			max = meanArr[i];
		}
		total += meanArr[i]; //adds array
	}

	mean = total/SIZE; //find mean of array

	printf("min = %d\n", min);
	printf("max = %d\n", max);
	printf("mean = %.2f\n\n", mean);

}

void organize(int meanArr[])
{
	int x;

	for(int i = 0; i < SIZE; i++) //array counter
	{
		for(int j = i + 1; j < SIZE; j++) //secondary counter
		{
			if(meanArr[i] > meanArr[j]) //executes if former array element is greater than the latter
			{
				x = meanArr[j]; //swaps array elements
				meanArr[j] = meanArr[i];
				meanArr[i] = x;
			}
		}
	}
	for(int i = 0; i < SIZE; i++) //array counter
	{
		printf("meanArr[%d] = %d\n", i, meanArr[i]); //dsiplays array elements
	}
}

void duplicate(int meanArr[], int newArr[])
{
	for(int i = 0; i < SIZE; i++) //array counter
	{
		newArr[i] = meanArr[i]; //copies old array to new array
	}
}

int locate(int meanArr[], int value, int size)
{
	int check = 0, i = 0;

	for(i = 0; i < size; i++) //array counter
	{
		if(meanArr[i] == value) //executes if array element is equal to user input
		{
			return i; //returns array index
			check = 1;
		}
	}

	if(check == 0) //executes if value is not found within array
	{
		i = -1;
	}
}