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
	rules(); //displays rules once at startup

	char answer[SIZE], starword[SIZE];
	int p = 1; //initializes p to 1 to play
	int *play;

	double status; //to determine if eof is reached
	int inputStatus;

	play = &p; //pointer is assigned to p

	FILE *inp;
	inp = fopen("words.txt", "r"); //opens word bank file

	inputStatus = fscanf(inp, "%lf", &status); //returns -1 is eof is reached

	while(inputStatus != -1) //quits when eof is reached
	{
		while(*play == 1) //executes if user chooses to play again
		{
			fscanf(inp, " %s\n", &answer[0]); //scans word on line and moves to next line
			int size = strlen(answer); //size is the length of the answer
			answer[size] = '\0'; //so no funny characters pop up

			maskWord(starword, size); //masks word using size

			int win = playRound(starword, answer); //returns win condition

			if(win == 1) //executes if user won
			{
				printf("====================================================\n");
				printf("Congrats, you won!\n");
			}
			else if(win == 0) //executes if user lost
			{
				printf("====================================================\n");
				printf("You used all your strikes!\n");
				printf("The answer was: %s\n", answer);
			}

			inputStatus = fscanf(inp, "%lf", &status); //reassigns value every loop
			if(inputStatus == -1)
			{
				break; //quits if eof is reached
				printf("\n\nYou went through all available words!\n\n");
			}

			playAgain(play); //asks to play again
		}
	}

	fclose(inp); //closes file
	return 0;
}

void rules(void)
{
	printf("====================================================\n");
	printf("		Welcome to hangman! \n");
	printf(" The goal of the game is to guess the word provided\n"); //rules
	printf("    The word provided is repesented by stars\n");
	printf("  If you guess a letter correctly, it is revealed\n");
	printf("   If you guess a letter incorrectly, you recieve\n");
	printf("		    a strike.\n");
	printf("	 6 strikes will result in a loss\n");
	printf("====================================================\n");
}

void maskWord (char starword[], int size)
{
	for(int i = 0; i < size; i++) //traverses starword array with max size times
	{
		starword[i] = '*'; //sets each character in answer to an *
	}

	starword[size] = '\0'; //no funny characters
}

int playRound(char starword[], char answer[])
{
	int win = 0; //win status
	int count = 0; //keeps track of round count for displaying guessed chars
	int star = 0; //used in determining if user won
	int guessWin = 0; //0 if user guesses incorrectly
	int strikes = 0; //resets game at beginning of round
	char userguess;
	char guessTotal[SIZE] = "\0";

	printf("\nWelcome to the round! Good luck!\n\n");

	while(strikes < STRIKES) //executes if user hasn't gone over strike limit
	{
		printf("====================================================\n");
		printf("You currently have %d strikes.\n", strikes); //informs user of strike status
		printf("Letter(s) you have guessed: %s\n", guessTotal); //lists guessed letters
		printf("\n %s\n", starword); //displays stars
		printf("Enter your guess: "); //prompts and recieves guess
		scanf(" %c", &userguess);

		userguess = tolower(userguess); //lowercase only

		if(userguess >= 97 && userguess <= 122) //executes if lowercase 
		{
			for(int j = 0; j < SIZE; j++)
			{
				guessWin = 0; //resets guess correct status
				if(answer[j] == userguess) //executes if user guess correctly
				{
					printf("\nThe letter %c is in the word\n\n", userguess);

					updateStarWord(starword, answer, userguess);

					guessWin = 1; //user won the guess
					j = SIZE; //exits for loop
				}
			}
			if(guessWin == 0) //default condition, user did not win the guess
			{
			printf("\nThe letter %c is not in the word\n\n", userguess);
			strikes++; //adds strike to total
			}

		}
		else //if user does not enter lowercase
		{
			printf("Invalid input, please try again.\n\n");
		}

		star = 0; //resets star counter every guess
		for(int j = 0; j < SIZE; j++)
		{
			if(starword[j] == '*') //executes the amount of times there is a * in the starword[]
			{
				star++; //adds one count to star
			}
		}
		
		if(star == 0) //executes if there are no *'s in starword[]
		{
			win = 1; //user win
			break; //breaks while loop
		}
		else //executes if no *'s in starword[]
		{
			win = 0; //user lost or has not won yet
		}

		guessTotal[count] = userguess; //adds to guessed char list
		guessTotal[count + 1] = '\0';
		count++; //increases round count
	}
	return win;
}

int occurancesInWord(char userguess, char answer[])
{
	int occurences = 0; //resets occurences of word

	for(int i = 0; i < SIZE; i++) //traverses array
	{
		if(answer[i] == userguess) //executes for every occurance in answer[]
		{
			occurences++; //adds to occurance counter
		}
	}
	return occurences; //returns amount of occurences
}

void updateStarWord(char starword[], char answer[], char userguess)
{
	int occurences = occurancesInWord(userguess, answer); //retrieves amount of occurences

	while(occurences > 0) //only executes if there are occurences
	{
		for(int i = 0; i < SIZE; i++) //traverses array
		{
			if(answer[i] == userguess) //executes if the user guesses correctly and for every occurance
			{
				starword[i] = answer[i]; //sets starword * to char in answer[]
				occurences--;
			}
		}
	}
}

void playAgain(int *play)
{
	printf("Would you like to play again?\n");
	printf("1 for yes, 2 for no: "); //prompts and recieves users desire to replay
	scanf(" %d", play);
	printf("\n");

	while(*play > 2 || *play < 1) //executes if user does not enter 1 or 2
	{
		printf("Invalid input. Try again.\n");
		playAgain(play); //calls playAgain(again)
	}

}