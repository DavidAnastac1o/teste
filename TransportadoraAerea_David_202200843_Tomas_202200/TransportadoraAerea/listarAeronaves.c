#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aeronave.h"
#include "general.h"

int listingPlanes()
{
	FILE *File;
	typeAirplane Airplane;

	//open aeronaves.txt
	File = fopen ("data/aeronaves.txt", "r");
	if (File == NULL){
		fprintf(stderr, "\n\nERROR: Unable to open the file\n");
		exit (1);
	}
    printAirplane(Airplane, File);
    closeFile(File);
    goBack();
}

void printAirplane(typeAirplane airplane, FILE *file){
    char *formater = "";
	int i, temporary[1][4];
    printf("\n\t|ID%-8s|CAPACITY%-2s|TOTAL FLIGHTS%-1s|STATUS%-8s|Location%-8s|Destination%-8s|Passengers Id's%-5s|", formater, formater, formater, formater, formater, formater, formater);
	//read file contents
	while(fread(&airplane, sizeof(typeAirplane), 1, file)){
	    temporary[0][0] = airplane.passengerId1;
        temporary[0][1] = airplane.passengerId2;
        temporary[0][2] = airplane.passengerId3;
        temporary[0][3] = airplane.passengerId4;

        printf ("\n\t|%-10d|%-10d|%-14d|%-14s|%-16s|%-19s|", airplane.id, airplane.capacity, airplane.totalFlights, airplane.currentState, airplane.location, airplane.destiny);

        for (i = 0; i < airplane.capacity; i++) {
            printf(" %d", temporary[0][i]);
            if (i != airplane.capacity-1)
                printf(",");
        }
    }
}
