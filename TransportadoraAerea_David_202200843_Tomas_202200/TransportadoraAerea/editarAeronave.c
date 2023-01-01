#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aeronave.h"
#include "general.h"

int editPlane() {
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
    FILE *File, *Tmp;
    typeAirplane Airplane;

    // Open aeronaves.txt and tmp.txt in read-write mode
    File = fopen("data/aeronaves.txt", "r+");
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
            }
        }

        // Write the modified or original structure to the temporary file
        fwrite(&Airplane, sizeof(typeAirplane), 1, Tmp);
    }

    // Close both files
    fclose(File);
    fclose(Tmp);

    // Delete the original file
    remove("data/aeronaves.txt");

    // Rename the temporary file to the original file name
    rename("data/tmp.txt", "data/aeronaves.txt");
}
