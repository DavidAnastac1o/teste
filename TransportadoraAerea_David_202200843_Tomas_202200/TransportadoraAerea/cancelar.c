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

    int FlightsVerifier, id = askInt("\n\nWrite the ID of the airplane to cancel the flight: ");
    replacePlaneStr(id, "currentState", "Authorization");


    goBack();
    return 1;
}

