/*
 * Empleados.c
 *
 *  Created on: 14 may. 2021
 *      Author: Maximiliano Arias
 */

#include "ArrayEmpleados.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int buscarLibre(Employee lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            return i;

        }
    }

    return -1;
}

int ordenarEmpleadosAscendente(Employee lista[], int tam)
{
// ordenar empleados por legajo ascendente
    Employee auxEmpleado;
    int todoOk = -1;

    for(int i=0; i < tam-1; i++)
    {
        for(int j= i+1; j < tam; j++)
        {
            if(lista[i].sector > lista[j].sector || (lista[i].sector == lista[j].sector && strcmp(lista[i].lastName,lista[j].lastName)>0))
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;

                todoOk = 1;

            }

        }
    }

    return todoOk;
}

int altaEmpleado(Employee lista[], int tam, int* pLegajo)
{
    int todoOk = -1;
    Employee nuevoEmpleado;
    int indice;

    printf("    Alta Empleado\n");
    printf("Legajo: %d \n",*pLegajo);
    if(lista!=NULL && tam > 0 && pLegajo!=NULL && lista->name != NULL  && lista->lastName != NULL)
    {
        indice = buscarLibre(lista,tam);
        printf("%d", indice);
        if(indice == -1)
        {
        	printf("pasa por el sin lugar\n");
            printf("No hay lugar en el sistema\n");
        }
        else
        {
        	printf("pasa para cargar datos\n");

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.name);

            printf("Ingrese Apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.lastName);

            printf("Ingrese sueldo: ");
            scanf("%f",&nuevoEmpleado.salary);

            printf("Ingrese el Id del sector: ");
            scanf("%d",&nuevoEmpleado.sector);

            nuevoEmpleado.id = *pLegajo;
            nuevoEmpleado.isEmpty = 0;
            *pLegajo = *pLegajo + 1;
            lista[indice] = nuevoEmpleado;
            todoOk = 1;
        }

    }

    return todoOk;
}

void inicializarEmpleados(Employee lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}

void mostrarEmpleado(Employee unEmpleado)
{

        printf("%d      %s      %s       %.2f     %d\n",unEmpleado.id, unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, unEmpleado.sector);

}

void mostrarEmpleados(Employee lista[], int tam)
{
    int flag = 1;

    printf("****  Listado de Empleados  ****\n");
    printf("Id     Nombre      Apellido     Sueldo      Sector\n");
    printf("----------------------------------------------------------------------------\n");
    for(int i=0; i < tam; i++)
    {
        if(!lista[i].isEmpty )
        {
            mostrarEmpleado(lista[i]);
            flag = 0;
        }
    }
    printf("-----------------------------------------------------------------------------\n");

    if(flag)
    {
        printf("No hay empleados que mostrar\n");
    }
    printf("\n\n");
}

int bajaEmpleado(Employee lista[], int tam)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    printf("     Baja De Empleado\n");
    mostrarEmpleados(lista, tam);
    printf("Ingrese Id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(lista, tam, id);

    if(indice == -1)
    {
        printf("No hay ningun empleado registrado con el id: %d\n",id);
    }
    else
    {
        mostrarEmpleado(lista[indice]);
        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma == 's')
        {
            lista[indice].isEmpty = 1;
            todoOk = 1;
        }
        else
        {
            printf("baja cancelada por un error\n");
        }
    }

    return todoOk;
}

int buscarEmpleado(Employee lista[], int tam, int id)
{
    int indice= -1;
    for(int i=0; i < tam; i++)
    {
        if(lista[i].id == id && !lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;

}

int modificarEmpleado(Employee lista[], int tam){
	int todoOk = 1;
	int id;
	int indice;
	char confirma;

	 printf("     Modificacion De Empleado\n");
	    mostrarEmpleados(lista, tam);
	    printf("Ingrese Id: ");
	    scanf("%d", &id);

	    indice = buscarEmpleado(lista, tam, id);

	    if(indice == -1)
	    {
	    	printf("No hay ningun empleado registrado con el id: %d\n",id);
	    }
	    else
	    {
	    	mostrarEmpleado(lista[indice]);
	        printf("Confirma Modificacion?: ");
	        fflush(stdin);
            scanf("%c",&confirma);
            if(confirma == 's'){
            printf("Que desea modificar del empleado\n");


            todoOk = 1;
            }
            else
            {
            	printf("Modificacion cancelada por un error\n");
            }
	    }

	return todoOk;
}
