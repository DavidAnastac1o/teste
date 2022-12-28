#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aeronave.h"
#include "general.h"

int authorizePlane() {
    FILE *File;
    typeAirplane Airplane;
    File = fopen("data/aeronaves.txt", "r+");
    printAirplane(Airplane, File);
    closeFile(File);

    int FlightsVerifier, id = askInt("\n\nWrite the ID of the airplane to authorize the flight: ");

    FlightsVerifier = replacePlaneAddFly(id, "totalFlights");
    if(FlightsVerifier != 1) {
        replacePlaneStr(id, "currentState", "Ready");
        replacePlaneUpdateLastFlights(id, "lastFlight3");
        replacePlaneUpdateLastFlights(id, "lastFlight2");
        replacePlaneUpdateLastFlights(id, "lastFlight1");
    }
    else{
        printf("Fly limit reached");
    }


    goBack();
}

void replacePlaneStr(int id, const char *field, const char *newValue) {
    FILE *File, *Tmp;
    typeAirplane Airplane;

    // Open aeronaves.txt and tmp.txt in read-write mode
    File = fopen("data/aeronaves.txt", "r+");
    Tmp = fopen("data/tmp.txt", "w");

    // Read the file line by line
    while (fread(&Airplane, sizeof(typeAirplane), 1, File)) {
        // If the ID matches, update the field of the structure with the new value
        if (Airplane.id == id) {
            if (strcmp(field, "currentState") == 0) {
                memcpy(Airplane.currentState, newValue, 20);
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

int replacePlaneAddFly(int id, const char *field){
    FILE *File, *Tmp;
    typeAirplane Airplane;
    int total, valueToReturn = 0;

    // Open aeronaves.txt and tmp.txt in read-write mode
    File = fopen("data/aeronaves.txt", "r+");
    Tmp = fopen("data/tmp.txt", "w");

    // Read the file line by line
    while (fread(&Airplane, sizeof(typeAirplane), 1, File)) {
        // If the ID matches, update the field of the structure with the new value
        if (Airplane.id == id) {
            total = Airplane.totalFlights;
            if(Airplane.totalFlights >= 100){
                valueToReturn = 1;
            }
            else if (strcmp(field, "totalFlights") == 0) {
                total++;
                Airplane.totalFlights = total;
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

    return valueToReturn;
}

void replacePlaneUpdateLastFlights(int id, const char *field){
    FILE *File, *Tmp;
    typeAirplane Airplane;
    char newValue[40] = "";

    // Open aeronaves.txt and tmp.txt in read-write mode
    File = fopen("data/aeronaves.txt", "r+");
    Tmp = fopen("data/tmp.txt", "w");

    // Read the file line by line
    while (fread(&Airplane, sizeof(typeAirplane), 1, File)) {

        // If the ID matches, update the field of the structure with the new value
        if (Airplane.id == id) {

            if (strcmp(field, "lastFlight3") == 0) {
                strcat(newValue, Airplane.lastFlight2);
                memcpy(Airplane.lastFlight3, newValue, 40);
            }
            else if (strcmp(field, "lastFlight2") == 0) {
                strcat(newValue, Airplane.lastFlight1);
                memcpy(Airplane.lastFlight2, newValue, 40);
            }
            else if (strcmp(field, "lastFlight1") == 0) {
                strcat(newValue, Airplane.location);
                strcat(newValue, " to ");
                strcat(newValue, Airplane.destiny);
                memcpy(Airplane.lastFlight1, newValue, 40);
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
