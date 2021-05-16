/*
 * Empleados.h
 *
 *  Created on: 14 may. 2021
 *      Author: Maximiliano Arias
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;

#endif /* EMPLEADOS_H_ */


int menu();
int subMenu();
int menuModificar();
void inicializarEmpleados(Employee lista[], int tam);
int buscarLibre(Employee lista[], int tam);
int buscarEmpleado(Employee lista[], int tam, int id);
int altaEmpleado(Employee lista[], int tam, int *pLegajo);
int bajaEmpleado(Employee lista[], int tam);
int modificarEmpleado(Employee lista[], int tam);
void mostrarEmpleado(Employee unEmpleado);
void mostrarEmpleados(Employee lista[], int tam);
int ordenarEmpleadosAscendente(Employee lista[], int tam);
int ordenarEmpleadosDescendente(Employee lista[], int tam);
int totalADepositar(Employee lista[], int tam);
