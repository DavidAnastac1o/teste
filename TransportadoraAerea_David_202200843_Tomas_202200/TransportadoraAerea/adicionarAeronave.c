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
	char *formater = "";

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
        airplane[i].passengerId = malloc(2 * sizeof(*airplane[i].passengerId));
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
        while(fread(&passengers, sizeof(typeAirplane), 1, file2))
            printf ("\n|%-10d|%-12s %-25s|", passengers.id, passengers.firstName, passengers.lastName);

        //changing the size of the array tmp is a temporary variable
        int **tmp = realloc(airplane[i].passengerId, airplane[i].capacity * sizeof(*airplane[i].passengerId));
        airplane[i].passengerId = tmp;
        //getting passengers
        for(k=0; k < airplane[i].capacity; k++){
            printf("\nType the Passenger's id to add him on the airplane: ");
            scanf("%d", &airplane[i].passengerId[k]);
            fflush(stdin);
        }

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
