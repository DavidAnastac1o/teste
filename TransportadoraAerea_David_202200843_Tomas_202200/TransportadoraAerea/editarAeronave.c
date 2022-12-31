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
    return 1;
}
