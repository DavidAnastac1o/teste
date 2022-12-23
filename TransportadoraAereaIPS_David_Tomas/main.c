#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
    int choice;

    while(1){
        //call the function
        choice = menu();

        switch (choice){
            case 0:
                printf("\n\tProgram finishing executing...\n\n\n");
                exit(0);
            case 1:
                break;
            case 2:
                break;
            case 3:
                listingPlanes();
                break;
            case 4:
                break;
            case 5:
                addPlane();
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                addPassenger();
                break;
            case 12:
                listingPassengers();
                break;
        }
    }
}
