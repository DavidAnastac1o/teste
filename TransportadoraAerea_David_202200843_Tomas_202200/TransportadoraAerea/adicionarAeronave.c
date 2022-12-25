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
	FILE *file;
	FILE *file2;
    int repeatTimes = 0, i = 0, k = 0, counter = 0, numberChoice, aux;
    printf("Type the number of airplanes you pretend to insert: ");
    scanf("%d", &repeatTimes);
    typeAirplane airplane[repeatTimes];
    typePassenger passengers;
	char *formater = "", text[100];

	//open file for writing
	file = fopen ("data/aeronaves.txt", "r+");
	if (file == NULL){
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}

	file2 = fopen ("data/passenger.txt", "r");
	if (file2 == NULL)
	{
		fprintf(stderr, "\nError opening file\n");
		exit (1);
	}

	//gets the last id value
    while(fread(&airplane, sizeof(typeAirplane), 1, file)){
        counter++;
    }

	for (i = 0; i<repeatTimes; i++){
        //get the airplane default info
        counter++;
        airplane[i].id = counter;
        airplane[i].totalFlights = 0;
        airplane[i].capacity = 0;
        airplane[i].passengerId1 = 0;
        airplane[i].passengerId2 = 0;
        airplane[i].passengerId3 = 0;
        airplane[i].passengerId4 = 0;
        memcpy(airplane[i].lastFlight1, "None", 10);
        memcpy(airplane[i].lastFlight2, "None", 10);
        memcpy(airplane[i].lastFlight3, "None", 10);
        memcpy(airplane[i].currentState, "Authorization", 20);

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
            printf("\nChoose the current location of the airplane(1 - Vila Real, 2 - Tires, 3 - Portimão): ");
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
                    memcpy(airplane[i].location, "Portimão", 10);
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
            printf("\nChoose the current destination of the airplane(1 - Vila Real, 2 - Tires, 3 - Portimão): ");
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
                    memcpy(airplane[i].destiny, "Portimão", 10);
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

        //printing table
        printf("\n|ID%-8s|NAME%-34s|", formater, formater);
        //read file contents
        while(fread(&passengers, sizeof(typePassenger), 1, file2))
            printf ("\n|%-10d|%-12s %-25s|", passengers.id, passengers.firstName, passengers.lastName);

        //getting passengers
        if(airplane[i].capacity >= 1)
            airplane[i].passengerId1 = askInt("Write Passenger 1 id:");

        if(airplane[i].capacity >= 2)
            airplane[i].passengerId2 = askInt("Write Passenger 2 id:");

        if(airplane[i].capacity >= 3)
            airplane[i].passengerId3 = askInt("Write Passenger 3 id:");

        if(airplane[i].capacity >= 4)
            airplane[i].passengerId4 = askInt("Write Passenger 4 id:");

        //write structure to the file
        fwrite (&airplane[i], sizeof(typeAirplane), 1, file);
    }

	if(fwrite != 0)
		printf("\nContents were written to the file successfully !\n");
	else
		printf("\nError writing file contents!\n");

	closeFile(file);
	closeFile(file2);
	goBack();
}
