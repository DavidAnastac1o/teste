#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

struct aeronave{
	int id;
	int capacity;
    int totalFlights;

	char currentState[20];
	char location[20];
	char destiny[20];

	//passengers
    int** passengerId;

    //last fights using 3 variables because its easier to manipulate
	char lastFlight1[20];
	char lastFlight2[20];
	char lastFlight3[20];
};

int listingPlanes()
{
	FILE *file;
	struct aeronave airplane;
	char *formater = "";
	int i, repeatTimes;

	//open aeronaves.txt
	file = fopen ("data/aeronaves.txt", "r");
	if (file == NULL){
		fprintf(stderr, "\n\nERROR: Unable to open the file\n");
		exit (1);
	}

	printf("%d", airplane.passengerId[1]);
	repeatTimes = sizeof(airplane.passengerId);
    printf("\n\t|ID%-8s|CAPACITY%-2s|TOTAL FLIGHTS%-1s|STATUS%-8s|Location%-8s|Destination%-8s|", formater, formater, formater, formater, formater, formater);
	//read file contents
	while(fread(&airplane, sizeof(struct aeronave), 1, file)){
        printf ("\n\t|%-10d|%-10d|%-14d|%-14s|%-16s|%-19s|", airplane.id, airplane.capacity, airplane.totalFlights, airplane.currentState, airplane.location, airplane.destiny);
    }


	//close the file
	fclose (file);
	getchar();

	return 0;
}

