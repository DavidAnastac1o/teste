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

    int id = askInt("\n\nWrite the ID of the airplane to authorize the flight: ");
    replacePlane(id, "currentState", "Ready");
    goBack();
}

void replacePlane(int id, const char *field, const char *newValue) {
  FILE *File, *Tmp;
  typeAirplane Airplane;

  // Open aeronaves.txt and tmp.txt in read-write mode
  File = fopen("data/aeronaves.txt", "r+");
  Tmp = fopen("data/tmp.txt", "w");
  if (File == NULL || Tmp == NULL) {
    fprintf(stderr, "\n\nERROR: Unable to open the file\n");
    exit(1);
  }

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

/*

void replacePlane(int id, const char *field, int newValue) {
  FILE *File, *Tmp;
  typeAirplane Airplane;
  char newValueStr[20];

  // Convert the integer newValue to a string
  sprintf(newValueStr, "%d", newValue);

  // Open aeronaves.txt and tmp.txt in read-write mode
  File = fopen("data/aeronaves.txt", "r+");
  Tmp = fopen("data/tmp.txt", "w");
  if (File == NULL || Tmp == NULL) {
    fprintf(stderr, "\n\nERROR: Unable to open the file\n");
    exit(1);
  }

  // Read the file line by line
  while (fread(&Airplane, sizeof(typeAirplane), 1, File)) {
    // If the ID matches, update the field of the structure with the new value
    if (Airplane.id == id) {
      if (strcmp(field, "currentState") == 0) {
        memcpy(Airplane.currentState, newValueStr, 20);
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
*/


