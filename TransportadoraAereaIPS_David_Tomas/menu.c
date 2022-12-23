#include <stdio.h>
#include <conio.h>
#include "functions.h"

int menu(){
    int choice;
    char confirmation;
    do{
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
        printf("\t\t10.\tGravar Listagem de Aeronaves\n");
        printf("\t\t11.\tAdicionar Passageiros\n");
        printf("\t\t12.\tListar Passageiros\n\n");
        printf("\t\t0.\tSair\n\n");
        printf("\t------------------------------------------------\n\t> ");

        scanf("%d", &choice);
        fflush(stdin);

        if(choice < 0 || choice > 12){
            //getchar() used to wait for user to click on enter to proceed
            system("cls");
            printf("\n\n\tERROR: The number %d isn't in the range of 0 and 12. Press enter to continue.\n\t>", choice);
            getchar();
            continue;
        }

        //confirmation if you want that option
        printf("\n\n\tAre you sure you want to execute option number %d? (y/n)\n\t> ", choice);
        scanf("%c", &confirmation);
        fflush(stdin);

        //put the variable in lowercases
        confirmation = tolower(confirmation);

        if (confirmation == 'y'){
            break;
        }
        else if (confirmation == 'n'){
            continue;
        }
        else{
            printf("\n\n\tERROR: The character '%c' isn't a valid character. Press enter to continue.\n\t>", confirmation);
            getchar();
            continue;
        }

    }while (1);

    //return user input to the main file
    system("cls");
    return choice;
}
