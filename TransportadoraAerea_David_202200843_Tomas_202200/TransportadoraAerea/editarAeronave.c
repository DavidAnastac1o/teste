#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#include "Aeronave.h"
#include "Passageiros.h"
#include "general.h"

int editPlane() {
    setlocale(LC_ALL, "");
    FILE *File;
    typeAirplane Airplane;
    File = fopen("data/aeronaves.txt", "r+");
    printAirplane(Airplane, File);
    closeFile(File);

    int id = askInt("\n\nWrite the ID of the airplane to edit ");

    editAirplane(id);


    goBack();
    return 1;
}

void editAirplane(int id){
    FILE *File, *Tmp, *file;
    typeAirplane Airplane;
    typePassenger Passengers;

    // Open aeronaves.txt and tmp.txt in read-write mode
    File = fopen("data/aeronaves.txt", "r+");
    file = fopen ("data/passenger.txt", "r");
    Tmp = fopen("data/tmp.txt", "w");
    int limit = 0;
    char confirmation = ' ';

    // Read the file line by line
    while (fread(&Airplane, sizeof(typeAirplane), 1, File)) {
        // If the ID matches, update the field of the structure with the new value
        if (Airplane.id == id) {
            if(strcmp(Airplane.currentState, "Authorization") == 0){
                while(limit < 2 || limit > 4){
                    limit = askInt("\nType the new airplane capacity(2-4): ");
                    if(limit < 2 || limit > 4)
                        printf("\n\nERROR: Capacity out of range.");
                }
                Airplane.capacity = limit;

                while (confirmation != 'y' && confirmation != 'n'){
                    printf("Do you want to reset the flights? (y/n)\n");
                    verifier(&confirmation);
                    if(confirmation == 'y'){
                        Airplane.totalFlights = 0;
                    }
                    else if(confirmation == 'n'){
                        break;
                    }
                    else{
                        printf("\n\n\tERROR: The character '%c' isn't a valid character. Press enter to continue.\n\t>", confirmation);
                        getchar();
                        fflush(stdin);
                    }
                }
            }
            else if(strcmp(Airplane.currentState, "Ready") == 0){
                int numberChoice = 0, passengerChoice = 0, changeChoice = 0, changeAux = 0;
                while(numberChoice < 1 || numberChoice > 3){
                    printf("\nChoose the new destination of the airplane(1 - Vila Real, 2 - Tires, 3 - Portimão): ");
                    scanf("%d", &numberChoice);
                    fflush(stdin);
                    switch(numberChoice){
                        case 1:
                            memcpy(Airplane.destiny, "Vila Real", 10);
                            break;
                        case 2:
                            memcpy(Airplane.destiny, "Tires", 10);
                            break;
                        case 3:
                            memcpy(Airplane.destiny, "Portimão", 10);
                            break;
                        default:
                            printf("\n\nERROR: Choice out of range.");
                            break;
                    }
                    printf("%s", Airplane.destiny);
                    if(strcmp(Airplane.location, Airplane.destiny) == 0){
                        printf("\n\nERROR: The destination can not be the same of the location.");
                        numberChoice = 0;
                    }
                }

                while(passengerChoice < 1 || passengerChoice > 3){
                    subMenu();
                    passengerChoice = askInt("> ");
                    printPassangers(Passengers, file);

                    //edit
                    if(passengerChoice == 1){
                        while(changeChoice < 1 || changeChoice > Airplane.capacity)
                            changeChoice = askInt("\nChoose a passenger ID to edit: ");
                        changeAux = askInt("\nChoose the passenger ID you want to place in the previous position: ");
                        if(Airplane.passengerId1 == changeChoice)
                            Airplane.passengerId1 = changeAux;
                        else if(Airplane.passengerId2 == changeChoice)
                            Airplane.passengerId2 = changeAux;
                        else if(Airplane.passengerId3 == changeChoice)
                            Airplane.passengerId3 = changeAux;
                        else if(Airplane.passengerId4 == changeChoice)
                            Airplane.passengerId4 = changeAux;
                    }

                    //add
                    else if(passengerChoice == 2){
                        changeAux = askInt("\nChoose the passenger ID you want to add: ");
                        changeChoice = -1;
                        if(Airplane.passengerId1 == changeChoice)
                            Airplane.passengerId1 = changeAux;
                        else if(Airplane.passengerId2 == changeChoice)
                            Airplane.passengerId2 = changeAux;
                        else if(Airplane.passengerId3 == changeChoice)
                            Airplane.passengerId3 = changeAux;
                        else if(Airplane.passengerId4 == changeChoice)
                            Airplane.passengerId4 = changeAux;
                        else{
                            printf("\nERROR: There is no free spots");
                        }
                    }

                    //remove
                    else if(passengerChoice == 3){
                        while(changeChoice < 1 || changeChoice > Airplane.capacity)
                            changeChoice = askInt("\nChoose a passenger ID to remove from the airplane: ");
                        changeAux = -1;
                        if(Airplane.passengerId1 == changeChoice)
                            Airplane.passengerId1 = changeAux;
                        else if(Airplane.passengerId2 == changeChoice)
                            Airplane.passengerId2 = changeAux;
                        else if(Airplane.passengerId3 == changeChoice)
                            Airplane.passengerId3 = changeAux;
                        else if(Airplane.passengerId4 == changeChoice)
                            Airplane.passengerId4 = changeAux;
                    }

                }
            }
        }

        // Write the modified or original structure to the temporary file
        fwrite(&Airplane, sizeof(typeAirplane), 1, Tmp);
    }

    // Close both files
    fclose(File);
    fclose(Tmp);
    fclose(file);

    // Delete the original file
    remove("data/aeronaves.txt");

    // Rename the temporary file to the original file name
    rename("data/tmp.txt", "data/aeronaves.txt");
}

void subMenu(){
    system("cls");
    printf("\n\n\t----------------------Menu----------------------\n\n");
    printf("\t\t1.\tEdit Passenger\n");
    printf("\t\t2.\tAdd Passenger\n");
    printf("\t\t3.\tRemove Passenger\n");
    printf("\t------------------------------------------------\n\t");
}
