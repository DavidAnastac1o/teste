#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "menu.h"

int menu(){
    int choice = 0;
    char confirmation = 'n';
    while (confirmation != 'y'){

        menuPrinter(&choice);
        if(choice < 0 || choice > 12){
            //getchar() used to wait for user to click on enter to proceed
            printf("\n\n\tERROR: The number %d isn't in the range of 0 and 12. Press enter to continue.\n\t>", choice);
            getchar();
            continue;
        }

        //confirmation if you want that option
        verifier(&confirmation);
        if (confirmation != 'y' && confirmation != 'n'){
            printf("\n\n\tERROR: The character '%c' isn't a valid character. Press enter to continue.\n\t>", confirmation);
            getchar();
            fflush(stdin);
        }

    }

    //return user input to the main file
    system("cls");
    return choice;
}

void verifier(char *Confirmation){
    scanf("%c", &*Confirmation);
    fflush(stdin);
    //put the variable in lowercases
    *Confirmation = tolower(*Confirmation);
}

void menuPrinter(int *Choice){
    //clean console
    system("cls");

    //menu
    printf("\n\n\t----------------------Menu----------------------\n\n");
    printf("\t\t1.\tListar Aeronaves\n");
    printf("\t\t2.\tListar Aeronaves Prontas\n");
    printf("\t\t3.\tListar Aeronaves no Aguardo\n");
    printf("\t\t4.\tConsultar Aeronave\n");
    printf("\t\t5.\tAdicionar Aeronave\n");
    printf("\t\t6.\tEliminar Aeronave\n");
    printf("\t\t7.\tEditar Aeronave\n");
    printf("\t\t8.\tAutorizar Voo\n");
    printf("\t\t9.\tCancelar Voo\n");
    printf("\t\t10.\tGravar Listagem\n");
    printf("\t\t11.\tAdicionar Passageiros\n");
    printf("\t\t12.\tListar Passageiros\n\n");
    printf("\t\t0.\tSair\n\n");
    printf("\t------------------------------------------------\n\t> ");
    scanf("%d", &*Choice);
    fflush(stdin);
    printf("\n\n\tAre you sure you want to execute option number %d? (y/n)\n\t> ", *Choice);
}
