#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Aeronave.h"
#include "Passageiros.h"
#include "general.h"

int listingPlanes()
{
    setlocale(LC_ALL, "");
	FILE *File;
	typeAirplane Airplane;

	//open aeronaves.txt
	File = fopen ("data/aeronaves.txt", "r");
    printAirplane(Airplane, File);
    closeFile(File);
    goBack();
    return 1;
}


int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return y - x;
}


void printAirplane(typeAirplane airplane, FILE *file){
    FILE *File;
    typePassenger Passenger;

    //open aeronaves.txt
    File = fopen ("data/passenger.txt", "r+");
    char *formater = "", name[20], temporary[1][4][40];
    int i = 0, counter = 0, k = 0, j = 0;
    printf("\nID%-2s|CAPACITY%-2s|TOTAL FLIGHTS%-1s|STATUS%-8s|Location%-4s|Destination%-1s|Last Flight 1%-8s|Last Flight 2%-8s|Last Flight 3%-8s|Passengers Name", formater, formater, formater, formater, formater, formater, formater, formater, formater);
    //read file contents
    while(fread(&airplane, sizeof(typeAirplane), 1, file)){
        counter++;
    }
    int numbers[counter], aux[counter];
    rewind(file);
    while(fread(&airplane, sizeof(typeAirplane), 1, file)){
        numbers[i] = airplane.totalFlights;
        aux[i] = 0;
        i++;
    }
    qsort(numbers, counter, sizeof(int), compare);
    while(k < counter-1){
        rewind(file);
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
            for (i = 0; i < airplane.capacity; i++) {
                for (j = i + 1; j < airplane.capacity; j++) {
                    if (strcmp(temporary[0][i], temporary[0][j]) > 0) {
                        char temp[40];
                        strcpy(temp, temporary[0][i]);
                        strcpy(temporary[0][i], temporary[0][j]);
                        strcpy(temporary[0][j], temp);
                    }
                }
            }
            for(j = 0; j < counter; j++){
                if(numbers[k] == airplane.totalFlights && aux[j] != airplane.id){
                    printf ("\n%-4d|%-10d|%-14d|%-14s|%-12s|%-12s|%-21s|%-21s|%-21s|", airplane.id, airplane.capacity, airplane.totalFlights, airplane.currentState, airplane.location, airplane.destiny, airplane.lastFlight1, airplane.lastFlight2, airplane.lastFlight3);
                    for (i = 0; i < airplane.capacity; i++) {
                        printf("%s", temporary[0][i]);
                        if (i != airplane.capacity-1)
                            printf(";\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                  |");
                    }
                    printf(".\n");
                    aux[k] = airplane.id;
                    break;
                }
            }
        }
        k++;
    }
    closeFile(File);
}
