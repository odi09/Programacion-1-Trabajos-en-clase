/*
 ============================================================================
 Name        : Clase.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Ejercicio 1:
 * crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 * Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia
 * del mes. Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 */
#include <stdio.h>
#include <stdlib.h>
#include "char.h"
#define LARGO 31
void inicializarArray(int array[], int len);
void cargarArray(int TempDias[], int posicion, int temperatura);
void imprimirArray(int TempDias[], int len, char* pTexto1, char* pTexto2);

int main(void) {
	setbuf(stdout,NULL);

	int arrayTempDias[LARGO];
	int opcion;
	int dia;
	int min = 1;
	int max = 31;
	int min1 = 100;
	int max1 = 200;
	int temperatura;
	int reintentos = 3;

	inicializarArray(arrayTempDias,LARGO);

	do
	{
	printf("Ingrese una opcion:\n1 Para Imprimir.\n2 Para Cargar.\n3 Para Salir.");
    scanf("%d",&opcion);

	if(opcion == 1)
		imprimirArray(arrayTempDias,LARGO, "El dia es: ", "Y la temperatura es:");

	if(opcion == 2)
		{
		pedirEntero(&dia, min, max, reintentos, "Ingrese una dia: ", "Error, el dia es incorrecto");
		pedirEntero(&temperatura, min1, max1, reintentos, "Ingrese un temperatura: ", "Error, la temperatira es incorrecto");
		cargarArray(arrayTempDias, dia, temperatura);
		}

	}while(opcion != 3);

	return EXIT_SUCCESS;
}
void inicializarArray(int array[], int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		array[i]=0;
	}

}
void imprimirArray(int TempDias[], int len, char* pTexto1, char* pTexto2)
{
	int i;

	for(i=0; i< len ; i++)
	{
		printf("%s %d %s %d \n", pTexto1,i+1,pTexto2,TempDias[i]);
	}

}

void cargarArray(int TempDias[], int posicion, int temperatura)
{
	int resultado;
			resultado=posicion-1;
			TempDias[resultado] = temperatura;
}

