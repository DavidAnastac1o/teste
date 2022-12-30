#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aeronave.h"
#include "Passageiros.h"
#include "general.h"

int listingPlanes()
{
	FILE *File;
	typeAirplane Airplane;

	//open aeronaves.txt
	File = fopen ("data/aeronaves.txt", "r");
    printAirplane(Airplane, File);
    closeFile(File);
    goBack();
    return 1;
}


void printAirplane(typeAirplane airplane, FILE *file){
    FILE *File;
    typePassenger Passenger;

    //open aeronaves.txt
    File = fopen ("data/passenger.txt", "r+");
    char *formater = "", name[20], temporary[1][4][40];
    int i;
    printf("\n\t|ID%-8s|CAPACITY%-2s|TOTAL FLIGHTS%-1s|STATUS%-8s|Location%-8s|Destination%-8s|Passengers Id's%-5s|", formater, formater, formater, formater, formater, formater, formater);
    //read file contents
    while(fread(&airplane, sizeof(typeAirplane), 1, file)){
        rewind(File);
        while(fread(&Passenger, sizeof(typePassenger), 1, File)){
            sprintf(name, "%s %s", Passenger.firstName, Passenger.lastName);
            if(airplane.passengerId1 == Passenger.id){
                strcpy(temporary[0][0], name);
            }
            if(airplane.passengerId2 == Passenger.id){
                strcpy(temporary[0][1], name);
            }
            if(airplane.passengerId3 == Passenger.id){
                strcpy(temporary[0][2], name);
            }
            if(airplane.passengerId4 == Passenger.id){
                strcpy(temporary[0][3], name);
            }
        }

        // Sort the temporary array alphabetically
        for (int i = 0; i < airplane.capacity; i++) {
            for (int j = i + 1; j < airplane.capacity; j++) {
                if (strcmp(temporary[0][i], temporary[0][j]) > 0) {
                    char temp[40];
                    strcpy(temp, temporary[0][i]);
                    strcpy(temporary[0][i], temporary[0][j]);
                    strcpy(temporary[0][j], temp);
                }
            }
        }

        printf ("\n\t|%-10d|%-10d|%-14d|%-14s|%-16s|%-19s|", airplane.id, airplane.capacity, airplane.totalFlights, airplane.currentState, airplane.location, airplane.destiny);
        for (i = 0; i < airplane.capacity; i++) {
            printf(" %s", temporary[0][i]);
            if (i != airplane.capacity-1)
                printf(",");
        }
    }
    closeFile(File);
}

