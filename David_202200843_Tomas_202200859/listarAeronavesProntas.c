#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Aeronave.h"
#include "Passageiros.h"
#include "general.h"

int listingPlanesReady()
{
    setlocale(LC_ALL, "");
	FILE *File;
	typeAirplane Airplane;

	//open aeronaves.txt
	File = fopen ("data/aeronaves.txt", "r");
    printAirplaneReady(Airplane, File);
    closeFile(File);
    goBack();
    return 1;
}


void printAirplaneReady(typeAirplane airplane, FILE *file){

    char *formater = "";
    printf("\nID%-2s|CAPACITY%-2s|TOTAL FLIGHTS%-1s|STATUS%-17s|Location%-4s|Destination", formater, formater, formater, formater, formater);
    //read file contents
    while(fread(&airplane, sizeof(typeAirplane), 1, file)){
         if(strcmp(airplane.currentState, "Ready for authorization") == 0){
            printf ("\n%-4d|%-10d|%-14d|%-14s|%-12s|%-12s", airplane.id, airplane.capacity, airplane.totalFlights, airplane.currentState, airplane.location, airplane.destiny);
        }
    }
}
