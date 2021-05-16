/*
 * Empleados.c
 *
 *  Created on: 13 may. 2021
 *      Author: maxim
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleados.h"

int initEmployees(Employee* list, int len)
{
	int disponible = -1;

	for(int i= 0; i < len; i++){
		if(list[i].isEmpty == 0){
			disponible = 0;
			break;
		}
		else{
			disponible = -1;
		}
	}

	return disponible;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int todoOk = -1;
    Employee nuevoEmpleado;


    printf("Id: %d",nuevoEmpleado.id);
    if(!list->isEmpty){

    	printf("Ingrese El Nombre: ");
        fflush(stdin);
        gets(name);

        printf("Ingrese Su Apellido: ");
        fflush(stdin);
        gets(lastName);

        printf("Ingrese el Sueldo: ");
        scanf("%f",salary);

        printf("Ingrese el Id del sector: ");
        scanf("%d",sector);

        nuevoEmpleado.id = id;

        todoOk = 0;
    }

	return todoOk;
}

int findEmployeeById(Employee* list, int len,int id)
{

	return -1; //NULL;
}

int removeEmployee(Employee* list, int len, int id)
{

	return -1;
}

int sortEmployees(Employee* list, int len, int order)
{

	return 0;
}

int printEmployees(Employee* list, int length)
{

	return 0;
}

