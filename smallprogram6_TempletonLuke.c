#include <stdio.h>

#define SIZE 5

void meanMinMax(int meanArr[]);
void organize(int meanArr[]);
void duplicate(int meanArr[], int newArr[]);
void locate();

int main(void)
{
	int meanArr[SIZE];

	for(int i = 0; i < SIZE; i++)
	{
		printf("Enter a value for meanArr[%d]:", i);
		scanf(" %d", &meanArr[i]);
	}

	meanMinMax(meanArr);

	organize(meanArr);

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