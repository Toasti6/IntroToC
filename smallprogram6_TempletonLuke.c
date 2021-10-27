#include <stdio.h>

#define SIZE 5

void meanMinMax(int meanArr[]);
void organize(int meanArr[]);
void duplicate(int meanArr[], int newArr[]);
int locate(int meanArr[], int value, int size);

int main(void)
{
	int meanArr[SIZE], newArr[SIZE];

	for(int i = 0; i < SIZE; i++)
	{
		printf("Enter a value for meanArr[%d]:", i);
		scanf(" %d", &meanArr[i]);
	}

	meanMinMax(meanArr);

	organize(meanArr);

	duplicate(meanArr, newArr);

	printf("\n");

	for(int i = 0; i < SIZE; i++)
	{
		printf("newArr[%d] = %d\n", i, newArr[i]);
	}

	int value, size;

	printf("\nEnter a value to find:");
	scanf(" %d", &value);

	size = sizeof(meanArr)/sizeof(meanArr[0]);

	int location = locate(meanArr, value, size);

	if(location == -1)
	{
		printf("Value not found\n");
	}
	else
	{
		printf("Value was found at meanArr[%d]\n", location);
	}

	return 0;
}

void meanMinMax(int meanArr[])
{
	int  min = meanArr[0], max = meanArr[0], total = 0;
	double mean = meanArr[0];

	for(int i = 0; i < SIZE; i++)
	{
		if(meanArr[i] < min)
		{
			min = meanArr[i];
		}
		if(meanArr[i] > max)
		{
			max = meanArr[i];
		}
		total += meanArr[i];
	}

	mean = total/SIZE;

	printf("min = %d\n", min);
	printf("max = %d\n", max);
	printf("mean = %.2f\n\n", mean);

}

void organize(int meanArr[])
{
	int x;

	for(int i = 0; i < SIZE; i++)
	{
		for(int j = i + 1; j < SIZE; j++)
		{
			if(meanArr[i] > meanArr[j])
			{
				x = meanArr[j];
				meanArr[j] = meanArr[i];
				meanArr[i] = x;
			}
		}
	}
	for(int i = 0; i < SIZE; i++)
	{
		printf("meanArr[%d] = %d\n", i, meanArr[i]);
	}
}

void duplicate(int meanArr[], int newArr[])
{
	for(int i = 0; i < SIZE; i++)
	{
		newArr[i] = meanArr[i];
	}
}

int locate(int meanArr[], int value, int size)
{
	int check = 0, i = 0;

	for(i = 0; i < size; i++)
	{
		if(meanArr[i] == value)
		{
			return i;
			check = 1;
		}
	}

	if(check == 0)
	{
		i = -1;
	}
}