#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "parsexec.h"

static char input[100] = "look around";

static bool getInput(void)
{
	printf("->|\n");
	return fgets(input, sizeof input, stdin) != NULL;
}

int main(void)
{
	printf("\n\nWELCOME TO\n");
	sleep(1);
	printf("RPG TITLE\n\n");
	sleep(1);
	printf("YOU PROBABLY THOUGHT IT WAS BROKEN THERE\n\n");
	printf("DON'T WORRY IT'S PLENTY BROKEN IN OTHER PLACES\n\n");

	while(parseAndExecute(input) && getInput());

	printf("Leaving already?\n");

	return 0;
}