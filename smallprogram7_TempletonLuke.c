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
void fact(char output[]);
int substring(char large[], char small[]);

int main(void)
{
	char input[SIZE], output[SIZE]; //input and output arrays

	deblank(input, output);

	char plural[SIZE];

	pluralize(plural);

	fact(output);

	char small[SIZE], large[SIZE];

	printf("\nEnter a word:");
	fgets(large, SIZE, stdin); //prompts and recieves large string

	printf("\nEnter a smaller word:");
	fgets(small, SIZE, stdin); //prompts and recieves small string

	int result = substring(large, small); //assigns result to address

	printf("The address with a matching character is large[%d]\n", result); //prints address

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
	fgets(plural, SIZE, stdin); //prompts and recieves user input

	int l = strlen(plural); //finds length of string

	if(plural[l - 2] == 'y') //executes if last letter is y
	{
		plural[l - 2] = 'i'; //changes the ending to its plural form
		plural[l - 1] = 'e';
		plural[l] = 's';
	}
	else if(plural[l - 3] == 's'|| plural[l - 3] == 'c' && plural[l - 2] == 'h' || plural[l - 3] == 's' && plural[l - 2] == 'h') //executes if last letters are s, ch, or sh
	{
		plural[l - 1] = 'e'; //changes the ending to plural form
		plural[l] = 's';
	}
	else
	{
		plural[l - 1] = 's'; //changes the ending to plural form
	}

	printf("Your pluralized word is: %s", plural); //prints new word
}

void fact(char output[])
{
	char letter[2]; //new string that will contain first letter

	strncpy(letter, output, 1); //copies first letter

	printf("\n%s starts with %s.", output, letter);
}

int substring(char large[], char small[])
{
	int result;
	int l = strlen(large); //string lengths of each word given
	int s = strlen(small);

	for(int i = 0; i < (l - 1); i++) //traverses large string
	{
		for(int j = 0; j < (s - 1); j++) //traverses small string
		{
			if(large[i] == small[j]) //executes if char is the same
			{
				result = i; //assigns result to address
				i = l;
				j = s;
			}
		}
	}
	return result; //returns address
}