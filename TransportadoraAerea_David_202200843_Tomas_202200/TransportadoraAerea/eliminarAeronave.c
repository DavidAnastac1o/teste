#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aeronave.h"
#include "general.h"

void deletePlane(int id) {
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
    // If the ID does not match, write the structure to the temporary file
    if (Airplane.id != id) {
      fwrite(&Airplane, sizeof(typeAirplane), 1, Tmp);
    }
  }

  // Close both files
  fclose(File);
  fclose(Tmp);

  // Delete the original file
  remove("data/aeronaves.txt");

  // Rename the temporary file to the original file name
  rename("data/tmp.txt", "data/aeronaves.txt");
}

