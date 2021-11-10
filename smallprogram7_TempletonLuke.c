//Luke Templeton
//Dr. Steinberg
//COP3223 Section 2
//Small Program 7

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 30

void deblank(char input[], char output[]);
void pluralize(char plural[]);

int main(void)
{
	char input[SIZE], output[SIZE]; //input and output arrays

	deblank(input, output);

	char plural[SIZE];

	pluralize(plural);	

	return 0;
}

void deblank(char input[], char output[])
{
	int j = 0; //secondary counter
	printf("\nEnter a string: "); //prompts user for input string
	fgets(input, SIZE, stdin);

	for(int i = 0; i < SIZE; i++) //moves through input string
	{
		if(isspace(input[i]) == 0) //executes if i is not a white space
		{
			output[j++] = input[i]; //copies input to output char by char
		}
	}

	printf("Your word with no whitespace is: %s\n", output);//displays output string
}

void pluralize(char plural[])
{
	printf("\nEnter a word to be pluralized:");
	fgets(plural, SIZE, stdin);

	int l = strlen(plural);

	if(plural[l - 2] == 'y')
	{
		plural[l - 2] = 'i';
		plural[l - 1] = 'e';
		plural[l] = 's';
	}
	else if(plural[l - 3] == 's'|| plural[l - 3] == 'c' && plural[l - 2] == 'h' || plural[l - 3] == 's' && plural[l - 2] == 'h')
	{
		plural[l - 1] = 'e';
		plural[l] = 's';
	}
	else
	{
		plural[l - 1] = 's';
	}

	printf("Your pluralized word is: %s", plural);
}