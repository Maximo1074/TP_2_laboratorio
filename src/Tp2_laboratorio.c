/*
 ============================================================================
 Name        : Tp2_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleados.h"

#define TAM 2

int menu();

int main(void) {
	setvbuf(stdout, NULL, _IONBF, BUFSIZ);
	Employee nomina[TAM];
	int nextId = 0000;

	char salida = 'n';
	int flagAlta = 0;

	do{
		switch(menu()){
		case 1:
			initEmployees(nomina, TAM);
			addEmployee(nomina, TAM, &nextId);
			flagAlta = 1;
			break;
		case 2:
			if(flagAlta == 1){

			}
			else{
				printf("No podes modificar al empleado si no hay nadie cargado\n");
			}
			break;
		case 3:

			if(flagAlta == 1){

			}
			else{
				printf("No podes dar de baja a un empleado si no hay nadie cargado\n");
			}
			break;
		case 4:

			if(flagAlta == 1){

			}

			break;
		case 5:
			printf("Estas seguro de querer salir (s/n): \n");
			fflush(stdin);
			getchar();
			break;
		default:
			printf("Error Opcion incorrecta. Reingrese opcion correcta\n: ");
		}


	}while(salida == 'n');

	return EXIT_SUCCESS;
}

int menu(){

	int opcion;

	printf("**** Bienvenidos al menu de empleados ****\n");
	printf("---------------------------------------------\n");
	printf("Que desea hacer?\n");
	printf("1-Alta Empleados\n");
	printf("2-Modificar Empleados\n");
	printf("3-Baja Empleados\n");
	printf("4-Informes\n");
	printf("5-Salir\n");
	scanf("%d",&opcion);

	return opcion;
}
