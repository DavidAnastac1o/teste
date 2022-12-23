#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

struct Passenger
{
	int id;
	int nif;
	char firstName[20];
	char lastName[20];
};

int listingPassengers()
{
	FILE *file;
	struct Passenger passengers;
	char *formater = "";

	//open Passenger.txt
	file = fopen ("data/passenger.txt", "r");
	if (file == NULL){
		fprintf(stderr, "\n\nERROR: Unable to open the file\n");
		exit (1);
	}
    printf("\n\t|ID%-8s|NIF%-12s|NAME%-34s|", formater, formater, formater);
	//read file contents
	while(fread(&passengers, sizeof(struct Passenger), 1, file))
        printf ("\n\t|%-10d|%-15d|%-12s %-25s|", passengers.id, passengers.nif, passengers.firstName, passengers.lastName);

	//close the file
	fclose (file);
	printf("\n\n\tPress enter to go back!");
	getchar();
	return 0;
}


