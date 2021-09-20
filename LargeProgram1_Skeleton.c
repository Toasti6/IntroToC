//Luke Templeton
//Dr. Steinberg
//COP 3223 Section ??
//Large Program 1

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void Greeting(); //display welcome message to user
void SetSeed(int seed); //set the seed of pseudo random generator
int PlayRound(char answer, int round); //play one round
char GetGuess(); //retrieve the user's guess
int CompareLetters(char guess, char answer); //compare the user's guess with the answer
void RoundResult(int result, char answer); //determine if the user won or loss the round

int main()
{
	int round = 1; //sets to round number one
	int seed = 3; //sets random seed to 3

	Greeting(); //greets user

	SetSeed(seed); //sets seed to 3

	for (int game = 1; game <= ROUNDS; game++)
	{
		char answer = 'a';

		round = PlayRound(answer, round); + 1;

	}

	return 0;
}

void Greeting()
{
	printf("=======================================================\n");
	printf("      Welcome to the Character guessing game!\n");
	printf("Over 5 rounds, you must guess the randomized character.\n");
	printf(" You will have 5 tries each round, I will tell you if\n");
	printf("    your guess is higher or lower than the answer! \n");
	printf("                    Good luck!\n");
	printf("=======================================================\n");
}

void SetSeed(int seed)
{
	srand(seed);
}

int PlayRound(char answer, int round)
{
	printf("Round %d\n", round);

	for (int chance = 1; chance <= 5; chance++)
	{		
		
	}
}