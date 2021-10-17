/*
 ============================================================================
 Name        : FigueroaDamian-TP2.c
 Author      : Figueroa Damian
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validacionesFigueroa.h"

int menu()
{
    int option;
    system("cls");
    printf("*********** Employee Managment ***********\n");
    printf("1-Employee registration\n");
    printf("2-Update employee\n");
    printf("3-Remove employee\n");
    printf("4-Reports\n");
    printf("5.Exit\n");
    utn_getNumero(&option,"Enter an option: ","Error, wrong opcion.\n",1,5,3);
    return option;
}

int initEmployees(eEmployee* lista, int len)
{
    int succes = -1;
    if(lista != NULL && len > 0)
    {
        for (int i = 0; i <  len; i++)
        {
            lista[i].isEmpty = 1;
            succes= 0;
        }
    }

    return succes;
}

int findEmployeeById(eEmployee* lista, int len, int id)
{
    int indice = -1;
    if(lista != NULL && len > 0)
    {
        for(int i = 0; i<len; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty==0)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int findFreeIndex(eEmployee* lista, int len)
{
    int index = -1;
    for(int i = 0; i < len; i++)
    {
        if(lista[i].isEmpty)
        {
            index = i;
            break;
        }
    }
    return index;
}

int employeeRegistration(eEmployee* lista, int len,int* nextId,int* flagFirstEntry)
{
    int succes = -1;
    int nameFlag = 0;
    int lastNameFlag = 0;
    int salaryFlag = 0;
    int sectorFlag = 0;

    if(lista != NULL && len > 0)
    {
        int exist;
        int id;

        eEmployee auxEmployee;

        id=*nextId;


        exist = findFreeIndex(lista,len);

        if(exist == -1)
        {
            printf("System full.\n");
            system("pause");
        }
        else
        {
            system("cls");
            printf("****Employee registration****\n\n");
            if(utn_getNombre(auxEmployee.name,51,"Enter name: ","Error, you can digit letters only and one name without spaces.\n",3)==0)
            {
                nameFlag = 1;
            }
            if(utn_getNombre(auxEmployee.lastName,51,"Enter lastname: ","Error, you can type letters only and one lastname without spaces.\n",3)==0)
            {
                lastNameFlag = 1;
            }
            //El sueldo maximo sera de 100000.
            if(utn_getNumeroFlotante(&auxEmployee.salary,"Enter salary: ","Error, you can digit numbers and must be higher than zero.\n",0,100000,3)==0)
            {
                salaryFlag = 1;
            }
            if(utn_getNumero(&auxEmployee.sector,"Enter sector (1 to 5): ","Error, 1 to 5 only.\n",1,5,3)==0)
            {
                sectorFlag = 1;
            }
            if(nameFlag && lastNameFlag && salaryFlag && sectorFlag)
            {
                if(addEmployee(lista,len,id,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector) == -1)
                {
                    printf("Data loading error.\n");
                    system("pause");
                }
                else
                {
                    (*nextId)++;
                    (*flagFirstEntry)=1;
                    succes = 0;
                    system("pause");

                }

            }
            else
            {
                printf("Error, fail to load data");
                system("pause");
            }

        }

    }
    return succes;
}

int addEmployee(eEmployee* lista, int len, int id, char name[],char lastname[],float salary, int sector)
{
    int succes = -1;
    int freeIndex;
    freeIndex = findFreeIndex(lista,len);

    if(lista != NULL && len > 0 && freeIndex != -1)
    {

        eEmployee auxEmployee;

        auxEmployee.id = id;
        strcpy(auxEmployee.name,name);
        strcpy(auxEmployee.lastName,lastname);
        auxEmployee.salary = salary;
        auxEmployee.sector = sector;
        auxEmployee.isEmpty = 0;

        lista[freeIndex] = auxEmployee;
        succes = 0;
    }
    return succes;
}



void showEmployeeInfo(eEmployee employee)
{
    printf("%d          %20s             %20s                   %.2f         %d\n",employee.id,employee.name,employee.lastName,employee.salary,employee.sector);
}

int printEmployees(eEmployee* lista, int length)
{
    system("cls");
    int flag = 0;
    printf("******** Employee list **********\n\n");
    printf("Id                          Name                         Lastname                   Salary         Sector\n\n");
    for(int i = 0; i<length; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            showEmployeeInfo(lista[i]);
            flag = 1 ;
        }
    }
    if(flag == 0)
    {
        printf("No employees to list\n\n");
    }
    system("pause");
    return 0;
}


int removeEmployee(eEmployee* lista, int len, int id)
{
    int succes = -1;
    int index = -1;

    index = findEmployeeById(lista,len,id);

    if(index == -1)
    {
        printf("No employee registered with id: %d .\n",id);
        system("pause");
    }
    else
    {
        showEmployeeInfo(lista[index]);

        lista[index].isEmpty = 1;
        printf("Employee removed succesfully!!\n");
        succes = 0;
        system("pause");
    }
    return succes;
}

int subMenuOrder()
{
    system("cls");
    int option;

    printf("1- Employee reports sorted by last name and sector.\n");
    printf("2- Total and average of the salaries, and how many exceed the salary average.\n");
    utn_getNumero(&option,"Enter an option: ","ERROR, please enter a valid option.\n",1,2,3);

    return option;
}
int menuOpcionOrder()
{
    system("cls");
    int option;

    printf("1- Ascending order.\n");
    printf("2- Descending order.\n");
    utn_getNumero(&option,"Enter an option: ","ERROR, please enter a valid option.\n",1,2,3);

    return option;
}

void reports(eEmployee* lista, int len)
{
    int option;
    int optionOrder;
    option = subMenuOrder();
    if(option == 1)
    {
        optionOrder = menuOpcionOrder();
        if(optionOrder==1)
        {
            sortEmployees(lista,len,1);
            printEmployees(lista,len);
            system("pause");

        }
        else if (optionOrder == 2)
        {
            sortEmployees(lista,len,0);
            printEmployees(lista,len);
            system("pause");
        }
    }
    else if(option == 2)
    {
        reportTotalSalary(lista,len);
    }
}

int sortEmployees(eEmployee* lista, int len, int order)
{
    int succes = -1;
    if(lista != NULL && len > 0)
    {

        eEmployee auxEmpleado;
        if(order == 1)
        {
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(strcmp(lista[i].lastName,lista[j].lastName)<0)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                    }
                    else if (strcmp(lista[i].lastName,lista[j].lastName) == 0 && lista[i].sector > lista[j].sector)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                    }
                }
            }
        }
        else if (order == 0)
        {
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(strcmp(lista[i].lastName,lista[j].lastName)>0)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                    }
                    else if (strcmp(lista[i].lastName,lista[j].lastName) == 0 && lista[i].sector < lista[j].sector)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                    }
                }
            }
        }
        succes = 0;
    }

    return succes;
}

void reportTotalSalary(eEmployee* lista, int tam)
{
    int firstEntry = 0;
    float totalSalary =0;
    int contSalary = 0;
    float salaryAverage;
    int contHigherSalaryAverage = 0;
    system("cls");
    printf("\n***** Salary reports *****\n\n");
    for(int i=0; i<tam; i++)
    {
        if (lista[i].isEmpty ==0)
        {
            totalSalary += lista[i].salary;
            contSalary++;
            firstEntry = 1;
        }
    }
    salaryAverage = (float)totalSalary/contSalary;
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0 && lista[i].salary > salaryAverage)
        {
            contHigherSalaryAverage++;
        }
    }
    if(firstEntry == 1)
    {
        printf("Total salary : %.2f\n",totalSalary);
        printf("Average salary : %.2f\n",salaryAverage);
        printf("Number of people who surpass the average salary: %d\n",contHigherSalaryAverage);

        system("pause");
    }
    else
    {
        printf("Error, There are no salaries to calculate.\n");
    }

}

int updateEmployee(eEmployee* lista, int len)
{
    int succes = -1;
    if(lista != NULL && len > 0)
    {
        int id;
        int index = -1;
        char newName[51];
        char newLastName[51];
        float newSalary;
        int newSector;

        system("cls");
        printf("***** Update Employee ***** \n \n");

        //El minimo es 1000 ya que la primer menor id que puede existir es 1000, y en el maximo se pongo un numero grande que nunca se alcanzara.
        if(utn_getNumero(&id,"Enter the id of the employee: ","Error.",1000,100000,2)==-1)
        {
            printf("Canceled operation.\n");
            system("pause");
        }
        else
        {
            index = findEmployeeById(lista,len,id);

            if (index == -1)
            {
                printf("No employee registered with id: %d . \n", id);
                system("pause");
            }
            else
            {
                showEmployeeInfo(lista[index]);

                switch(subMenuUpdates())
                {
                case 1:
                    if(utn_getNombre(newName,51,"Enter new name: ","Error, you can digit letters only and one name without spaces.\n",3)== -1)
                    {
                        printf("ERROR, no tries left.\n");
                        printf("Canceled operation.\n");
                        system("pause");
                    }
                    else
                    {
                        strcpy(lista[index].name,newName);
                        printf("Updated successfully. \n");
                        system("pause");

                    }

                    break;
                case 2:
                    if(utn_getNombre(newLastName,51,"Enter new lastname: ","Error, you can digit letters only and one lastname without spaces.\n",3)==-1)
                    {
                        printf("Error, no tries left.\n");
                        printf("Canceled operation.\n");
                        system("pause");
                    }
                    else
                    {
                        strcpy(lista[index].lastName,newLastName);
                        printf("Updated successfully.\n");
                        system("pause");

                    }
                    break;
                case 3:
                    if(utn_getNumeroFlotante(&newSalary,"Enter new salary: ","Error, you can digit",0,100000,3)==-1)
                    {
                        printf("Error, no tries left.\n");
                        printf("Canceled operation.\n");
                        system("pause");
                    }
                    else
                    {
                        lista[index].salary = newSalary;
                        printf("Updated successfully. \n");
                        system("pause");

                    }
                    break;
                case 4:
                    if(utn_getNumero(&newSector,"Ingrese nuevo sector (1 al 5): ","Error, solo debe digitar numeros del 1 al 5.\n",1,5,3)==-1)
                    {
                        printf("Error, no tries left.\n");
                        printf("Canceled operation.\n");
                        system("pause");
                    }
                    else
                    {
                        lista[index].sector = newSector;
                        printf("Updated successfully. \n");
                        system("pause");
                    }
                    break;
                default:
                    printf("Wrong option.\n");
                    system("pause");
                    break;
                }
                succes = 1;
            }
        }

    }


    return succes;

}

int subMenuUpdates()
{
    int option;
    printf("What do you want to update? \n");
    printf("1. Name.\n");
    printf("2. Lastname.\n");
    printf("3. Salary.\n");
    printf("4. Sector.\n");
    utn_getNumero(&option,"Enter an option: ","ERROR, wrong option.\n",1,4,3);
    system("pause");
    return option;
}

int verifyIfArrayIsEmpty(eEmployee* lista,int len)
{
    int succes = 0;
    if(lista != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                succes = -1;
                break;
            }
        }
    }
    return succes;
}

