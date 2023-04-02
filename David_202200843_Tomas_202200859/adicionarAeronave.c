#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Aeronave.h"
#include "Passageiros.h"
#include "general.h"

int addPlane(){
    //setup
    setlocale(LC_ALL, "");
	FILE *File;
    int RepeatTimes = askInt("Type the number of airplanes you pretend to insert: ");
    typeAirplane Airplane[RepeatTimes];

	//open file for writing
	File = fopen ("data/aeronaves.txt", "r+");
	if (File == NULL){
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}

	writeinFileAirplane(Airplane, File, RepeatTimes);
	closeFile(File);
	goBack();
	return 1;
}

void writeinFileAirplane(typeAirplane *airplane, FILE *file, int repeatTimes){
    int i = 0, counter = 0, numberChoice, aux, id, maxAeronaves;
    FILE *IdFile;

	//gets the last id value
    while(fread(&*airplane, sizeof(typeAirplane), 1, file)){
        counter++;
    }
    maxAeronaves = repeatTimes + counter;
    if(counter <= 10 && maxAeronaves <= 10){
        for (i = 0; i<repeatTimes; i++){
            IdFile = fopen("data/idFile.txt", "r+");
            fscanf(IdFile, "%d", &id);
            id++;
            //get the airplane default info
            airplane[i].id = id;
            airplane[i].totalFlights = 0;
            airplane[i].capacity = 0;
            airplane[i].passengerId1 = 0;
            airplane[i].passengerId2 = 0;
            airplane[i].passengerId3 = 0;
            airplane[i].passengerId4 = 0;
            memcpy(airplane[i].lastFlight1, "None", 40);
            memcpy(airplane[i].lastFlight2, "None", 40);
            memcpy(airplane[i].lastFlight3, "None", 40);
            memcpy(airplane[i].currentState, "In preparation", 40);
            IdFile = freopen("data/idFile.txt", "w", IdFile);
            fprintf(IdFile, "%d", id);
            closeFile(IdFile);

            //getting capacity
            while(airplane[i].capacity < 2 || airplane[i].capacity > 4){
                printf("\nType the airplane capacity(2-4): ");
                scanf("%d", &airplane[i].capacity);
                fflush(stdin);
                if(airplane[i].capacity < 2 || airplane[i].capacity > 4)

                    printf("\n\nERROR: Capacity out of range.");
            }

            //getting location
            numberChoice = 0;
            while(numberChoice < 1 || numberChoice > 3){
                printf("\nChoose the current location of the airplane(1 - Vila Real, 2 - Tires, 3 - Portim�o): ");
                scanf("%d", &numberChoice);
                fflush(stdin);
                switch(numberChoice){
                    case 1:
                        memcpy(airplane[i].location, "Vila Real", 10);
                        break;
                    case 2:
                        memcpy(airplane[i].location, "Tires", 10);
                        break;
                    case 3:
                        memcpy(airplane[i].location, "Portim�o", 10);
                        break;
                    default:
                        printf("\n\nERROR: Choice out of range.");
                        break;
                }
                aux = numberChoice;
            }

            //getting destination
            numberChoice = 0;
            while(numberChoice < 1 || numberChoice > 3){
                printf("\nChoose the current destination of the airplane(1 - Vila Real, 2 - Tires, 3 - Portim�o): ");
                scanf("%d", &numberChoice);
                fflush(stdin);
                switch(numberChoice){
                    case 1:
                        memcpy(airplane[i].destiny, "Vila Real", 10);
                        break;
                    case 2:
                        memcpy(airplane[i].destiny, "Tires", 10);
                        break;
                    case 3:
                        memcpy(airplane[i].destiny, "Portim�o", 10);
                        break;
                    default:
                        printf("\n\nERROR: Choice out of range.");
                        break;
                }
                if(numberChoice == aux){
                    printf("\n\nERROR: The destination can not be the same of the location.");
                    numberChoice = 0;
                }
            }

            //write structure to the file
            fwrite (&airplane[i], sizeof(typeAirplane), 1, file);
        }
    }
    else{
        printf("\n\n\tERROR: The mas number of airplanes was already reached");
    }

}
