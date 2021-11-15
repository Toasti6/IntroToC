//Luke Templeton
//Dr. Steinberg
//COP 3223 Section 2
//Large Program 3

#include <stdio.h>
#include <string.h>
#define SIZE 20
#define STRIKES 6

void rules(void); //display rules of the game 
void maskWord (char starword[], int size); //mask the word with stars to display to user in game 
int playRound(char starword[], char answer[]); //function that plays a round of hangman. returns 1 if user won 
int occurancesInWord(char userguess, char answer[]); //number of times letter occurs in word. Greater than 0 means letter exist 
void updateStarWord(char starword[], char answer[], char userguess); //update starword. replace respective * character with respective letter 
void playAgain(int *play); //ask user if to play again. 1 is yes 2 is no 

int main(void)
{
	rules();

	char answer[SIZE], starword[SIZE];
	int *play;
	*play = 1;

	FILE *inp;
	inp = fopen("words.txt", "r");

	while(*play == 1)
	{
		fscanf(inp, " %s\n", &answer[0]);
		int size = strlen(answer);

		maskWord(starword, size);

		int win = playRound(starword, answer);
	}

	fclose(inp);
	return 0;
}

void rules(void)
{
	printf("========================================\n");
	printf("		Welcome to hangman! \n");
	printf(" Play this as you would play a regular\n"); //REDO THIS
	printf("  hangman game. The asteriks represent\n");
	printf(" the letters you have not guessed yet.\n");
	printf("========================================\n");
}

void maskWord (char starword[], int size)
{
	for(int i = 0; i < size; i++)
	{
		starword[i] = '*';
	}
}

int playRound(char starword[], char answer[])
{
	int win, guessWin, strikes = 0;
	char userguess, guessTotal[SIZE];

	printf("\nWelcome to the round! Good luck!\n\n");

	while(int strikes < STRIKES)
	{
		guessWin = 0;

		printf("========================================\n");
		printf("You currently have %d strikes.\n", strikes);
		printf("Letter(s) you have guessed: %s\n", guessTotal);
		printf("\n %s\n" starword);
		printf("Enter your guess: ");
		scanf(" %c", userguess);

		userguess = tolower(userguess);

		if(userguess >= 97 && userguess <= 122)
		{
			for(int j = 0; j < SIZE; j++)
			{
				if(answer[j] == userguess)
				{
					printf("You guessed correctly!\n");

					updateStarWord(starword, answer, userguess);

					guessWin = 1;
					j = SIZE;
				}
			}
			if(guessWin = 0)
			{
				printf("You guessed incorrectly!\n");
				strikes++;
			}
		}
		else
		{
			printf("Invalid input, please enter a valid character.\n", );
		}
	}

	return win;
}

int occurancesInWord(char userguess, char answer[]);
{
	int occurances = 0;

	for(int i = 0; i < SIZE; i++)
	{
		if(answer[i] == userguess)
		{
			occurances++;
		}
	}

	return occurances;
}

void updateStarWord(char starword[], char answer[], char userguess);
{
	int occurances = occurancesInWord();

	for(int i = 0; i < SIZE; i++)
	{
		if(answer[i] == userguess)
		{
			starword[i] = answer[i];
		}
	}
}