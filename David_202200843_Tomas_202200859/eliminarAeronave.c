#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aeronave.h"
#include "general.h"

void deletePlane() {
    FILE *File;
    typeAirplane Airplane;
    File = fopen("data/aeronaves.txt", "r+");

    printAirplane(Airplane, File);
    int ID = askInt("\n\nWrite the number of the ID of the airplane that you want to delete: ");
    deleteAirplane(ID);

    fclose(File);
    // Delete the original file
    remove("data/aeronaves.txt");

    // Rename the temporary file to the original file name
    rename("data/tmp.txt", "data/aeronaves.txt");

    goBack();
}

void deleteAirplane(int id){
  FILE *File, *Tmp;
  typeAirplane Airplane;

  File = fopen("data/aeronaves.txt", "r+");
  Tmp = fopen("data/tmp.txt", "w");

  // Read the file line by line
  while (fread(&Airplane, sizeof(typeAirplane), 1, File)) {
    // If the ID does not match, write the structure to the temporary file
    if (Airplane.id != id) {
      fwrite(&Airplane, sizeof(typeAirplane), 1, Tmp);
    }
  }

  // Close both files
  fclose(File);
  fclose(Tmp);
}

