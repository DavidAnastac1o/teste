#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aeronave.h"
#include "general.h"

int cancelPlane() {
    FILE *File;
    typeAirplane Airplane;
    File = fopen("data/aeronaves.txt", "r+");
    printAirplane(Airplane, File);
    closeFile(File);

    int id = askInt("\n\nWrite the ID of the airplane to cancel the flight: ");
    cancelUpdateInfo(id);

    goBack();
    return 1;
}

void cancelUpdateInfo(int Id){
    FILE *File, *Tmp;
    typeAirplane Airplane;

    // Open aeronaves.txt and tmp.txt in read-write mode
    File = fopen("data/aeronaves.txt", "r+");
    Tmp = fopen("data/tmp.txt", "w");

    // Read the file line by line
    while (fread(&Airplane, sizeof(typeAirplane), 1, File)) {
        // If the ID matches, update the field of the structure with the new value
        if (Airplane.id == Id && strcmp(Airplane.currentState, "Ready for authorization") == 0) {
            memcpy(Airplane.currentState, "In preparation", 20);
            memcpy(Airplane.destiny, "None", 5);
            Airplane.passengerId1 = -1;
            Airplane.passengerId2 = -1;
            Airplane.passengerId3 = -1;
            Airplane.passengerId4 = -1;
            Airplane.capacity = 0;
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

