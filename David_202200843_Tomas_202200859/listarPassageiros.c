#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Passageiros.h"
#include "general.h"

int listingPassengers(){
    setlocale(LC_ALL, "");
	FILE *File;
	typePassenger Passengers;

    //open Passenger.txt
	File = fopen ("data/passenger.txt", "r");
	if (File == NULL){
		fprintf(stderr, "\n\nERROR: Unable to open the file\n");
		exit (1);
	}

	printPassangers(Passengers, File);
	closeFile(File);
	goBack();
	return 1;
}

void printPassangers(typePassenger passengers, FILE *file){
    char *formater = "";
    printf("\n\t|ID%-8s|NIF%-12s|NAME%-34s|", formater, formater, formater);
    //read file contents
    while(fread(&passengers, sizeof(typePassenger), 1, file))
        printf ("\n\t|%-10d|%-15d|%-12s %-25s|", passengers.id, passengers.nif, passengers.firstName, passengers.lastName);
}

void closeFile(FILE *file){
	//close the file
    fclose (file);
}

void goBack(){
    printf("\n\n\tPress enter to go back!");
	getchar();
}
