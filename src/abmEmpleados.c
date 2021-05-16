/*
 ============================================================================
 Name        : abmEmpleados.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmpleados.h"

#define TAM 2

int menu();
int subMenu();
int menuModificar();

int main(void) {
	setvbuf(stdout, NULL, _IONBF, BUFSIZ);
	Employee nomina[TAM];
	int nextId = 0;
	char salida = 'n';
	int flagAltaEmpleado = 0;
	inicializarEmpleados(nomina,TAM);

	do{
		switch(menu()){
		case 1:
			if(altaEmpleado(nomina, TAM, &nextId)){
				printf("Alta Exitosa\n");
				flagAltaEmpleado = 1;
			}
			else{
				printf("ERROR. Hubo problemas al hacer el alta\n");
			}
			break;
		case 2:
			if(flagAltaEmpleado && modificarEmpleado(nomina,TAM)){
				printf("Modificacion de empleado exitosa\n");
			}
			else{
				printf("ERROR. Hubo problemas al modificar al empleado\n");
			}
			break;
		case 3:
			if(flagAltaEmpleado && bajaEmpleado(nomina,TAM)){
				printf("Baja Exitosa\n");
			}
			else{
				printf("ERROR. Hubo problemas al dar de baja al empleado\n");
			}
			break;
		case 4:
			switch(subMenu()){
			case 1:
				mostrarEmpleados(nomina, TAM);
				break;
			case 2:
				if(ordenarEmpleadosAscendente(nomina,TAM)){
					printf("Orden Ascendente de los empleados exitoso\n");
				}
				else{
					printf("ERROR. Hubo un problema con el ordenamiento\n");
				}
				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			default:
				printf("ERROR, OPCION INCORRECTA. Reingrese la opcion correcta\n");
			}
			break;
		case 5:
			printf("Estas seguro que desea salir (s/n): \n");
			fflush(stdin);
			salida = getchar();
			break;
		default:
			printf("ERROR, OPCION INCORRECTA. Reingrese la opcion correcta\n");
		}

	}while(salida == 'n');

	return EXIT_SUCCESS;
}


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
