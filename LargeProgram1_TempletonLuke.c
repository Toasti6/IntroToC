//Luke Templeton
//Dr. Steinberg
//COP 3223 Section 2
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
	int seed = 3; //sets random seed to 3

	Greeting(); //greets user

	SetSeed(seed); //sets seed to 3

	for (int game = 1; game <= ROUNDS; game++)
	{
		int lower = 65; //lowest ascii value (A)
		int upper = 90; //highest ascii value (Z)

		char answer = (rand() % (upper - lower + 1)) + lower; //sets limit for ascii value (65-90)

		PlayRound(answer, game);

	}

	return 0;
}

void Greeting()
{
	printf("=======================================================\n"); //greeting message
	printf("      Welcome to the Character guessing game!\n");
	printf("Over 5 rounds, you must guess the randomized character.\n");
	printf(" You will have 5 tries each round, I will tell you if\n");
	printf("    your guess is higher or lower than the answer! \n");
	printf("                    Good luck!\n");
	printf("=======================================================\n");
}

void SetSeed(int seed)
{
	srand(seed); //sets seed to 3
}

int PlayRound(char answer, int round)
{
	int result;

	printf("\nRound %d\n", round); //displays round name

	for (int chance = 1; chance <= 5; chance++) //gives user 5 chances
	{		
		char guess = GetGuess();

		result = CompareLetters(guess, answer);

		// printf("YOUR GUESS IS %c\n", guess); use for debug

		if(result == 1) //breaks the for loop if answer is correct
		{
			chance = 5;
		}
	}

	RoundResult(result, answer);
}

char GetGuess()
{
	char guess;

	printf("Enter your answer:"); //recieves guess from user
	scanf(" %c", &guess);

	guess = toupper(guess); //sets the users guess to captial letter

	return guess;
}

int CompareLetters(char guess, char answer)
{
	int result;

	if(guess == answer) //compares guess to answer, gives response if its too high, low, or correct.
	{
		result = 1;
	}	
	else if(guess < answer && 65 < guess) //only allows uppercase leters
	{
		printf("The answer is closer to Z!\n");
		result = 0;
	}
	else if(guess > answer && 90 > guess)
	{
		printf("The answer is closer to A!\n");
		result = 0;
	}
	else
	{
		printf("Invalid answer!\n");
		result = 0;
	}

	return result;

}

void RoundResult(int result, char answer)
{
	if(result == 1) //if the answer is correct, the statement is printed
	{
		printf("Congrats, you won!\n");
	}
	else //if user is incorrect, the statement is printed
	{
		printf("You ran out of guesses! The answer was %c\n", answer);
	}

}