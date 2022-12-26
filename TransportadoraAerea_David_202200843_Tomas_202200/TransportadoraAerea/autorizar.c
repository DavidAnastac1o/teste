#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aeronave.h"
#include "general.h"

int authorizePlane()
{
	FILE *File;
	typeAirplane Airplane;

	//open aeronaves.txt
	File = fopen ("data/aeronaves.txt", "r+");
	if (File == NULL){
		fprintf(stderr, "\n\nERROR: Unable to open the file\n");
		exit (1);
	}
	authorize(Airplane, File);
    closeFile(File);
    rename("data/tmp.txt", "data/aeronaves.txt");
    goBack();
}

void authorize(typeAirplane airplane, FILE *file){
    int id = 2;
    while(fread(&airplane, sizeof(typeAirplane), 1, file)){
        if(airplane.id == id){
            airplane.deleted = 1;
        }
    }

    fwrite (&airplane, sizeof(typeAirplane), 1, file);

}

