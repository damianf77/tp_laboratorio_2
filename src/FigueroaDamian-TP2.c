/*
 ============================================================================
 Name        : FigueroaDamian-TP2.c
 Author      : Figueroa Damian
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "validacionesFigueroa.h"
#define TAM 1000

//terminado

int main()
{
	setbuf(stdout, NULL);
    int flagFirstEntry = 0;
    int auxId;
    int nextId = 1000;
    char keep = 's';
    int id;
    int auxInit;
    eEmployee lista[TAM];

    auxInit = initEmployees(lista,TAM); //Inicializo el vector y si hubo error, devuelve -1.

    if(auxInit != 0)
    {
        printf("Error initializing the arrays");
    }
    else
    {
        do
        {
            if(verifyIfArrayIsEmpty(lista,TAM)==0)
            {
                flagFirstEntry = 0;
            }

            switch(menu())
            {
            case 1 :
                employeeRegistration(lista,TAM,&nextId,&flagFirstEntry);
                break;
            case 2:
                if(flagFirstEntry == 0)
                {
                    printf("System empty, an employee must be registered at least.\n");
                    system("pause");
                }
                else
                {
                    updateEmployee(lista,TAM);
                }
                break;
            case 3:
                if(flagFirstEntry == 0)
                {
                    printf("System empty, an employee must be registered at least.\n");
                    system("pause");
                }
                else
                {
                    //El minimo es 1000 ya que la primer id es 1000, y en el maximo se pongo un numero grande que nunca se alcanzara.
                    if(utn_getNumero(&id,"Enter the id to remove: \n","Error, please enter a valid id.\n",1000,20000000,3)==-1)
                    {
                        printf("ERROR, no tries left.");
                        system("pause");
                    }
                    else
                    {
                        auxId=id;
                        removeEmployee(lista,TAM,auxId);
                    }

                }
                break;
            case 4:
                if(flagFirstEntry == 0)
                {
                    printf("System empty, an employee must be registered at least\n");
                    system("pause");
                }
                else
                {
                    reports(lista,TAM);
                }
                break;
            case 5:
                keep = 'n';
                printf("See you soon.\n");
                system("pause");
                break;
            default:
                printf("Wrong option, please enter a valid option.\n\n");
                system("pause");
                break;
            }
        }
        while(keep == 's');

    }
    return 0;
}

