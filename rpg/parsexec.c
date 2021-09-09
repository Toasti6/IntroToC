#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool parseAndExecute(char *input)
{
	char *verb = strtok(input, " \n");
	char *noun = strtok(NULL, "\n");
	if (verb != NULL)
	{
		if (strcmp(verb, "quit") == 0)
		{
			return false;
		}
		else if (strcmp(verb, "look") == 0)
		{
			printf("Darkness surrounds you.\n");
		}
		else if (strcmp(verb, "go") == 0)
		{
			printf("YOU CAN'T SEE ANYTHING! HOW ARE YOU GOING ANYWHERE?\n");
		}
		else
		{
			printf("NOT QUITE SURE HOW TO DO THAT ONE.\n");
		}
	}
	return true;
}