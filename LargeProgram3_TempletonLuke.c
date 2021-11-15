//Luke Templeton
//Dr. Steinberg
//COP 3223 Section 2
//Large Program 3

#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
	int p = 1;
	int *play;

	play = &p;

	FILE *inp;
	inp = fopen("words.txt", "r");

	while(*play == 1)
	{
		fscanf(inp, " %s\n", &answer[0]);
		int size = strlen(answer);
		answer[size] = '\0';

		maskWord(starword, size);

		int win = playRound(starword, answer);

		if(win == 1)
		{
			printf("Congrats, you won!\n");
		}
		else if(win == 0)
		{
			printf("You used all your strikes!\n");
			printf("The answer was: %s\n", answer);
		}

		playAgain(play);
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

	starword[strlen(starword) - 1] = '\0';
}

int playRound(char starword[], char answer[])
{
	int win, count, star, guessWin, strikes = 0;
	char userguess;
	char guessTotal[SIZE] = "\0";

	printf("\nWelcome to the round! Good luck!\n\n");

	while(strikes < STRIKES)
	{
		printf("========================================\n");
		printf("You currently have %d strikes.\n", strikes);
		printf("Letter(s) you have guessed: %s\n", guessTotal);
		printf("\n %s\n", starword);
		printf("Enter your guess: ");
		scanf(" %c", &userguess);

		userguess = tolower(userguess);

		if(userguess >= 97 && userguess <= 122)
		{
			for(int j = 0; j < SIZE; j++)
			{
				guessWin = 0;
				if(answer[j] == userguess)
				{
					printf("You guessed correctly!\n");

					updateStarWord(starword, answer, userguess);

					guessWin = 1;
					j = SIZE;
				}
			}
			if(guessWin == 0)
			{
			printf("You guessed incorrectly!\n");
			strikes++;
			}

		}
		else
		{
			printf("Invalid input, please enter a valid character.\n");
		}

		star = 0;
		for(int j = 0; j < SIZE; j++)
		{
			if(starword[j] == '*')
			{
				star++;
			}
		}
		
		if(star == 0)
		{
			win = 1;
			break;
		}
		else
		{
			win = 0;
		}

		guessTotal[count] = userguess;
		guessTotal[count + 1] = '\0';
		count++;
	}
	return win;
}

int occurancesInWord(char userguess, char answer[])
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

void updateStarWord(char starword[], char answer[], char userguess)
{
	int occurances = occurancesInWord(userguess, answer);

	for(int i = 0; i < SIZE; i++)
	{
		if(answer[i] == userguess)
		{
			starword[i] = answer[i];
		}
	}
}

void playAgain(int *play)
{
	printf("Would you like to play again?\n");
	printf("1 for yes, 2 for no: ");
	scanf(" %d", play);
}