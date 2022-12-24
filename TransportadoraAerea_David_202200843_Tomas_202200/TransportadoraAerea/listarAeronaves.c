#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aeronave.h"
#include "Passageiros.h"
#include "general.h"

int listingPlanes()
{
	FILE *file;
	typeAirplane airplane;
	char *formater = "";
	int i;

	//open aeronaves.txt
	file = fopen ("data/aeronaves.txt", "r");
	if (file == NULL){
		fprintf(stderr, "\n\nERROR: Unable to open the file\n");
		exit (1);
	}
    printf("\n\t|ID%-8s|CAPACITY%-2s|TOTAL FLIGHTS%-1s|STATUS%-8s|Location%-8s|Destination%-8s|", formater, formater, formater, formater, formater, formater);
	//read file contents
	while(fread(&airplane, sizeof(typeAirplane), 1, file)){

        /*for (i = 0; i < airplane.capacity; i++) {
            printf("%d \n", airplane.passengerId[i]);
        }*/
        printf ("\n\t|%-10d|%-10d|%-14d|%-14s|%-16s|%-19s|", airplane.id, airplane.capacity, airplane.totalFlights, airplane.currentState, airplane.location, airplane.destiny);
    }
    closeFile(file);
    goBack();
}


