//Luke Templeton
//Dr. Steinberg
//COP3223 Section 2
//Large Program 4

#include <stdio.h>
#include <string.h>

#define MAX 30

typedef struct{
	char make[MAX]; //car make
	char model[MAX]; // car model
	int id; //id of car, used to identify
	int year; //car year
}database;

database hardSix(database *carlist); //six initial cars
database insert(database *carlist, int *size, int *greatestSize); //insert a car into database
void display(database *carlist, int *size); //display entire database
void delete(database *carlist, int *size, int *greatestSize); //deletes database entry
void searchId(database *carlist, int *size); //seearches database by Id
void searchMake(database *carlist, int *size); //displays all car of the same make (try with multiple of the same make!!)

int main(void)
{
	database carlist[MAX];

	carlist[MAX] = hardSix(carlist); //initializes first 6 cars

	int size = 6, greatestSize = 6, menu = 1; //size is current size, greatest size is the largest it has been

	while(menu == 1)
	{
		int option;

		printf("Select a menu option below.\n");
		printf("1 - Insert a record.\n");
		printf("2 - Remove a record.\n");
		printf("3 - Display records.\n");
		printf("4 - Search by Id.\n");
		printf("5 - Search by make.\n");
		printf("6 - Exit.\n");
		printf(":");
		scanf(" %d", &option); //prompts and recieves user menu option

		if(option == 1) //insert option
		{
			//initializes the last position in current array to the new entry
			carlist[size] = insert(carlist, &size, &greatestSize);
		}
		if(option == 2) //remove option
		{
			delete(carlist, &size, &greatestSize);
		}
		if(option == 3) //display option
		{
			display(carlist, &size);
		}
		if(option == 4) //search by Id option
		{
			searchId(carlist, &size);
		}
		if(option == 5) //search by make option
		{
			searchMake(carlist, &size);
		}
		if(option == 6) //exit option
		{
			printf("Exiting...\n");
			menu = 0; //breaks fil loop
		}
	}

	FILE *outp;
	outp = fopen("output.txt", "w"); //creates output file

	for(int i = 0; i < size; i++) //traverses database
	{
		fprintf(outp, "Id:\t%d\n", carlist[i].id); //prints all car info to output.txt
		fprintf(outp, "Year:\t%d\n", carlist[i].year);
		fprintf(outp, "Make:\t%s\n", carlist[i].make);
		fprintf(outp, "Model:\t%s\n", carlist[i].model);
		fprintf(outp, "--------------------------------\n");
	}

	fclose(outp); //closes output file

	return 0;
}

database hardSix(database *carlist)
{
	carlist[0].id = 1; //creates first 6 entries
	carlist[0].year = 2011;
	strcpy(carlist[0].make, "Mini");
	strcpy(carlist[0].model, "Cooper S");

	carlist[1].id = 2;
	carlist[1].year = 2018;
	strcpy(carlist[1].make, "Hyundai");
	strcpy(carlist[1].model, "Elantra Sport");

	carlist[2].id = 3;
	carlist[2].year = 2016;
	strcpy(carlist[2].make, "Hyundai");
	strcpy(carlist[2].model, "Veloster Sport");

	carlist[3].id = 4;
	carlist[3].year = 2016;
	strcpy(carlist[3].make, "Scion");
	strcpy(carlist[3].model, "Tc");

	carlist[4].id = 5;
	carlist[4].year = 2015;
	strcpy(carlist[4].make, "Mazda");
	strcpy(carlist[4].model, "2");

	carlist[5].id = 6;
	carlist[5].year = 2015;
	strcpy(carlist[5].make, "Chevy");
	strcpy(carlist[5].model, "Cruze");

	return *carlist;
}

database insert(database *carlist, int *size, int *greatestSize)
{
	*size += 1; //size and greatest size are raised when an entry is input
	*greatestSize += 1;

	printf("Please enter the vehicle info.\n"); //prompts and recieves car info
	printf("Year:");
	scanf("%d", &carlist[*size].year);
	printf("Make:");
	scanf(" %s", carlist[*size].make);
	printf("Model:");
	scanf(" %s", carlist[*size].model);
	carlist[*size].id = *greatestSize; //sets id to the greatest size of the array so a new id is always given

	return carlist[*size];
}

void display(database *carlist, int *size)
{
	printf("Displaying full vehicle records.\n");
	printf("--------------------------------\n");

	for(int i = 0; i < *size; i++) //traverses database
	{
		printf("Id:\t%d\n", carlist[i].id); //prints car info
		printf("Year:\t%d\n", carlist[i].year);
		printf("Make:\t%s\n", carlist[i].make);
		printf("Model:\t%s\n", carlist[i].model);
		printf("--------------------------------\n");
	}

}

void delete(database *carlist, int *size, int *greatestSize)
{
	int index;

	printf("Select the id of the index to be removed\n");
	printf(":"); //prompts and recieves index to be removed
	scanf(" %d", &index);

	if(index < 0 || index > *greatestSize) //checks if index is within 0 or the last entry
	{
		printf("Not a valid index.\n");
	}
	else
	{
		for(int i = index - 1; i < *size; i++) //traverses database
		{
			carlist[i] = carlist[i + 1]; //moves entry to the back of the database
		}

		*size-= 1; //since size is one less, the entry at the back will never be traversed to
	}

}

void searchId(database *carlist, int *size)
{
	int index;

	printf("Enter the ID you'd like to search for\n");
	printf(":"); //prompts and recieves info for id search
	scanf(" %d", &index);

	for(int i = 0; i < *size; i++) //traverses database
	{
		if(index < 0 || index > *size) //checks if index is within 0 or the last entry
		{
			printf("Invalid index.");
		}
		else if(index == carlist[i].id) //executes when user input matches car id
		{
			printf("Id:\t%d\n", carlist[index - 1].id);
			printf("Year:\t%d\n", carlist[index - 1].year);
			printf("Make:\t%s\n", carlist[index - 1].make);
			printf("Model:\t%s\n", carlist[index - 1].model);
			printf("--------------------------------\n");
		}
	}
}

void searchMake(database *carlist, int *size)
{
	char indexArr[MAX]; //temporary user input
	int find = 0; //by default, a car is not found

	printf("Enter the make you'd like to search for\n:");
	scanf(" %s", indexArr); //prompts and recieves make user wishes to search for

	for(int i = 0; i < *size; i++) //traverses database
	{
		if(strcmp(indexArr, carlist[i].make) == 0) //executes if the make a make in the database
		{
			printf("Id:\t%d\n", carlist[i].id); //displays car info
			printf("Year:\t%d\n", carlist[i].year);
			printf("Make:\t%s\n", carlist[i].make);
			printf("Model:\t%s\n", carlist[i].model);
			printf("--------------------------------\n");

			find = 1; //make was successfully found
		}
	}
	if(find == 0) //executes if make was not found
	{
		printf("Make not found");
	}
}