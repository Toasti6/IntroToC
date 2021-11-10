//Luke Templeton
//Dr. Steinberg
//COP3223 Section 2
//Small Program 7

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 30

void deblank(char input[], char output[]);

int main(void)
{
	char input[SIZE], output[SIZE];

	deblank(input, output);

	return 0;
}

void deblank(char input[], char output[])
{
	printf("\nEnter a string: ");
	fgets(input, SIZE, stdin);

	for(int i = 0; i < SIZE; i++)
	{
		if(isspace(input[i]) != 0)
		{
			input[i] = ???;
		}
	}

	strcpy(output, input);

	puts(output);
}