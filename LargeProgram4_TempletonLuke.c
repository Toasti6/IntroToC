//Luke Templeton
//Dr. Steinberg
//COP3223 Section 2
//Large Program 4

#include <stdio.h>
#include <string.h>

#define MAX 30

typedef struct{
	char make[MAX];
	char model[MAX];
	int id;
	int year;
}database;

database hardSix(database *carlist);
database insert(database *carlist, int *size, int *greatestSize);
void display(database *carlist, int *size);
void delete(database *carlist, int *size, int *greatestSize);

int main(void)
{
	database carlist[MAX];

	carlist[MAX] = hardSix(carlist);

	int size = 6, greatestSize = 6, menu = 1;

	while(menu == 1)
	{
		int option;

		printf("Select a menu option below.\n");
		printf("1 - Insert a record.\n");
		printf("2 - Remove a record.\n");
		printf("3 - Display records.\n");
		printf("4 - Sort by year.\n");
		printf("5 - Search.\n");
		printf("6 - Exit.\n");
		printf(":");
		scanf(" %d", &option);

		if(option == 1)
		{
			carlist[size] = insert(carlist, &size, &greatestSize);
		}
		if(option == 2)
		{
			delete(carlist, &size, &greatestSize);
		}
		if(option == 3)
		{
			display(carlist, &size);
		}
		if(option == 6)
		{
			printf("Exiting...\n");
			menu = 0;
		}
	}

	return 0;
}

database hardSix(database *carlist)
{
	carlist[0].id = 1;
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
	*size += 1;
	*greatestSize += 1;

	printf("Please enter the vehicle info.\n");
	printf("Year:");
	scanf("%d", &carlist[*size].year);
	printf("Make:");
	scanf(" %s", carlist[*size].make);
	printf("Model:");
	scanf(" %s", carlist[*size].model);
	carlist[*size].id = *greatestSize;

	return carlist[*size];
}

void display(database *carlist, int *size)
{
	printf("Displaying full vehicle records.\n");
	printf("--------------------------------\n");

	for(int i = 0; i < *size; i++)
	{
		printf("Id:\t%d\n", carlist[i].id);
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
	printf(":");
	scanf(" %d", &index);

	if(index < 0 || index > *greatestSize)
	{
		printf("Not a valid index.\n");
	}
	else
	{
		for(int i = index - 1; i < *size; i++)
		{
			carlist[i] = carlist[i + 1];
		}

		*size-= 1;
	}

}