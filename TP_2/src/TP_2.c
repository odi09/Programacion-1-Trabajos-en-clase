/*
 ============================================================================
 Name        : TP_2.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "employee.h"

#define LARGO_EMPLEDO 1000

int main(void) {
	setbuf(stdout, NULL);

	eEmpleado empleado[LARGO_EMPLEDO];
	int auxId;
    int posicion;
    int orden;
	int opcion;
	float subMenu;
	float promedioSueldos;


	if (iniLista(empleado, LARGO_EMPLEDO) == 1)
	{
		do {
			if (pedirEntero(&opcion, 0, 10, 3,
					"**Seleccioneuna opcion: \n1.Dar de alta un Empleado.\n2.Modificar datos del empleado.\n3.Dar de baja un Empleado.\n4.Informenes.\n0.Salir. ",
					"ERROR ingrese una opcion Valida") == 1)
			{
				switch (opcion)
				{
				case 1:
					cargaEmpleado(&empleado[posicion], LARGO_EMPLEDO);
					unEspaLibre(empleado, LARGO_EMPLEDO, &posicion);
					break;
				case 2:
					impriEmpleado(empleado, LARGO_EMPLEDO);
					pedirEntero(&auxId, 0, 1000, 3, "Ingrese ID: ", "ERROR ingreso un ID invalido.\n");
					modificarEmpleado(empleado, LARGO_EMPLEDO, auxId);

					break;
				case 3:
					impriEmpleado(empleado, LARGO_EMPLEDO);
					pedirEntero(&auxId, 0, 1000, 3, "Ingrese ID: \n", "ERROR ingreso un ID invalido.\n");
					bajaEmpleado(empleado, LARGO_EMPLEDO,auxId);
					break;
				case 4:
					pedirFlotante(&subMenu, 0, 6, 3, "Seleccioneuna opcion:\n1.Ordenar.\n2.Sumar Sueldos: \n3.Promedio de los sueldos:\n4.Cantidda de sueldos mayores:\n", "ERROR ingrese una opcion validad");
					if(subMenu == 1)
					{
						pedirEntero(&orden, 0, 2, 3,
								"Ingrese 0 para ordenar por Apellido de A - Z o 1 para ordenar de Z - A y 2 por Sector: \n",
								"Ingrese un orden valido");
						ordenarEmpleado(empleado, LARGO_EMPLEDO, orden);
						impriEmpleado(empleado, LARGO_EMPLEDO);
					}
					if(subMenu == 2)
					{
						sumaSueldos(empleado, LARGO_EMPLEDO);
					}
					if(subMenu == 3)
					{
						promedioSueldos = promeSueldos(empleado, LARGO_EMPLEDO);
						printf("El promedio de los sueldos es: %.2f", promedioSueldos);
					}
					if(subMenu == 4)
					{
					}
					break;
				}
			}
		} while (opcion != 0);

	}
	else
	{
		printf("ERROR no se pudo inicializar\n");
	}
	return EXIT_SUCCESS;
}
