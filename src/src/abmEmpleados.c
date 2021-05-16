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

#define TAM 4



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
				if(ordenarEmpleadosDescendente(nomina,TAM)){
					printf("Orden Descendente de los empleados exitoso\n");
				}
				else{
					printf("ERROR. Hubo un problema con el ordenamiento\n");
				}
				break;
			case 4:
				if(totalADepositar(nomina,TAM)){
					printf("Carga total de sueldos de todos los empleados exitosa\n");
				}
				else{
					printf("ERROR. Problema al cargar el total de los sueldos\n");
				}
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


