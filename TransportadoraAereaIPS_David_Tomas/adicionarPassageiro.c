#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

//structure to read and write
typedef struct Passengers{
	int id;
	int nif;
	char firstName[20];
	char lastName[20];
};

int addPassenger(){
    FILE *file;
    int repeatTimes = 0, i = 0, counter = 0;
    printf("Type the number of passenger's you pretend to insert: ");
    scanf("%d", &repeatTimes);
    struct Passengers person[repeatTimes];

	//open file for writing
	file = fopen ("data/passenger.txt", "r+");
	if (file == NULL){
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}

	//gets the last id value
    while(fread(&person, sizeof(struct Passengers), 1, file))
    {
        counter++;
    }

	for (i = 0; i<repeatTimes; i++)
    {
        //get the passenger info
        counter++;
        person[i].id = counter;
        printf("\nType the Passengers's nif: ");
        scanf("%d", &person[i].nif);
        fflush(stdin);
        printf("\nType the Passengers's name: ");
        gets(person[i].firstName);
        fflush(stdin);
        printf("\nType the Passenger's last name: ");
        gets(person[i].lastName);
        fflush(stdin);
        //write structure to the file
        fwrite (&person[i], sizeof(struct Passengers), 1, file);
    }

	if(fwrite != 0)
		printf("\nContents were written to the file successfully !\n");
	else
		printf("\nError writing file contents!\n");

	// close file
	fclose (file);
    printf("\n\nPress enter to go back!");
	getchar();
	return 0;
}
