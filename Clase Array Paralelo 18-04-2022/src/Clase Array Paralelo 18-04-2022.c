/*
 ============================================================================
 Name        : Clase.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define COLUMNAS 50
#define FILA 3

void cargarVector(char vNombre[][COLUMNAS], char vApellindo[][COLUMNAS], int hora[], int tam);
void mostarVector(char vNombre[][COLUMNAS], char vApellindo[][COLUMNAS], int hora[], int tam);
void ordenarVector(char vNombre[][COLUMNAS], char vApellindo[][COLUMNAS], int vHora[], int tam);

int main(void) {
	setbuf(stdout, NULL);

	char nombreCliente[FILA][COLUMNAS];
	char apellidoCliente[FILA][COLUMNAS];
	int horaReserva[FILA];

	cargarVector(nombreCliente, apellidoCliente, horaReserva, FILA);
	ordenarVector(nombreCliente, apellidoCliente, horaReserva, FILA);
	mostarVector(nombreCliente, apellidoCliente, horaReserva, FILA);

	return EXIT_SUCCESS;
}
void cargarVector(char vNombre[][COLUMNAS], char vApellindo[][COLUMNAS], int hora[], int tam)
{
	for(int i=0; i<tam; i++)
		{
			printf("Ingrese nombre del cliente: ");
			fflush(stdin);
			scanf("%s",vNombre[i]);

			printf("Ingrese apellido del cliente: ");
			fflush(stdin);
			scanf("%s",vApellindo[i]);
			fflush(stdin);

			printf("Ingrese hora de la reserva: ");
			scanf("%d",&hora[i]);
		}
}
void mostarVector(char vNombre[][COLUMNAS], char vApellindo[][COLUMNAS], int hora[], int tam)
{
	for(int i=0; i<tam; i++)
		{
			printf("El cliente es %s, %s, %d\n", vNombre[i], vApellindo[i], hora[i]);
		}
}
void ordenarVector(char vNombre[][COLUMNAS], char vApellindo[][COLUMNAS], int vHora[], int tam)
{
	char auxiApellidos[30];
	char auxiNombre[30];
	int auxiHora[30];
	for(int i=0; i<tam; i++)
		{
		for(int j = i+1; j<tam; j++)
			{
				if(strcmp(vApellindo[i], vApellindo[j]) > 0)
				{
					strcpy(auxiApellidos, vApellindo[i]);
					strcpy(vApellindo[i], vApellindo[j]);
					strcpy(vApellindo[j], auxiApellidos);
					strcpy(auxiNombre, vNombre[i]);
					strcpy(vNombre[i], vNombre[j]);
					strcpy(vNombre[j], auxiNombre);
					auxiHora[i] = vHora[i];
					vHora[i] = vHora[j];
					vHora[j] = auxiHora[i];
				}
			}
		}
}
