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

int menu(){
	int opcion;

	printf("Bienvenido a ABMEmpleados\n");
	printf("----------------------------------\n");
	printf("Que desea hacer?\n");
	printf("1-Alta Empleados\n");
	printf("2-Modificar Empleados\n");
	printf("3-Baja Empleados\n");
	printf("4-Informes\n");
	printf("5-Salida\n");
	scanf("%d",&opcion);

	return opcion;
}
int subMenu(){
	int opcion;

	printf("**** Menu de Informes ****\n");
	printf("------------------------------------------\n");
	printf("Que desea hacer con los informes?\n");
	printf("1-Mostrar listado de empleados\n");
	printf("2-Listar Empleados por Apellidos y Sectores Ascendente\n");
	printf("3-Listar Empleados por Apellidos y Sectores Descendente\n");
	printf("4-Salario Total de los empleados\n");
	printf("5-Promedio total de los salarios de los empleados\n");
	printf("6-Empleados que superan el promedio de los salarios\n");
	scanf("%d",&opcion);

	return opcion;
}

int menuModificar(){
	int opcion;

	printf("****  Menu de Modificaciones  ****\n");
	printf("--------------------------------------------------------\n");
	printf("Que modificaciones desea hacer al empleado\n");
	printf("1-Modificar Nombre\n");
	printf("2-Modificar Apellido\n");
	printf("3-Modificar Salario\n");
	printf("4-Modificar Sector\n");
	scanf("%d",&opcion);

	return opcion;
}


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

int ordenarEmpleadosDescendente(Employee lista[], int tam){
	int todoOk = -1;
	Employee auxEmpleado;

	    for(int i=0; i < tam-1; i++)
	    {
	        for(int j= i+1; j < tam; j++)
	        {
	            if(lista[i].sector < lista[j].sector || (lista[i].sector == lista[j].sector && strcmp(lista[i].lastName,lista[j].lastName)>0))
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
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {

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

        printf("%d      %s      %s       %9.2f     %d\n",unEmpleado.id, unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, unEmpleado.sector);

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
	float auxFloat;

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
            switch(menuModificar(lista[indice],tam)){
            case 1:
            	printf("Ingrese el nuevo Nombre: \n");
            	fflush(stdin);
            	gets(lista[indice].name);
            	break;
            case 2:
            	printf("Ingrese el nuevo Apellido: \n");
            	fflush(stdin);
            	gets(lista[indice].lastName);
            	break;
            case 3:
            	printf("Ingrese el nuevo Sueldo: \n");
            	scanf("%2f",&auxFloat);
            	auxFloat = lista[indice].salary;
            	break;
            case 4:
            	printf("Ingrese el nuevo Sector: \n");
            	scanf("%d",&lista[indice].sector);
            	break;
            default:
            	printf("Opcion incorrecta. Ingrese la opcion correcta\n");
            }

            todoOk = 1;
            }
            else
            {
            	printf("Modificacion cancelada por un error\n");
            }
	    }

	return todoOk;
}

int totalADepositar(Employee lista[], int tam)
{
	int todoOk = -1;
    float totalSueldos = 0;

    printf("   Total Sueldos de empleados\n\n");
    for(int i=0; i < tam; i++)
    {
        totalSueldos = totalSueldos + lista[i].salary;
        todoOk = 1;
    }
        printf("Total Sueldos: $ %.2f\n", totalSueldos);

    return todoOk;
}
