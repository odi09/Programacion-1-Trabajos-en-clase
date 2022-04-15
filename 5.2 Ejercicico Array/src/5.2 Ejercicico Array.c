/*
 ============================================================================
 Name        : 2.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones Array.h"
#define SIZE  4
int main(void) {
	setbuf(stdout, NULL);
	int numero[SIZE];
	int positivos;
	int negativos;
	int sumaPosi;
	int numImpar;

	cargarArray(numero, SIZE, "Ingrese un numero:");
	positivos = sumaDePositivos(numero, SIZE);
	printf("La cantidad de positivos es %d.\n", positivos);
	negativos = sumaDeNegativo(numero, SIZE);
	printf("La cantidad de negativos es %d.\n", negativos);
	sumaPosi = sumaPares(numero, SIZE);
	printf("La suma de los numero pares es %d.\n",sumaPosi);
	numImpar = mayorImpares(numero, SIZE);
	printf("El mayor de los numero Impares es %d.\n", numImpar);
	listas(numero, SIZE, "El numero ingresado es");
	listarNumPar(numero, SIZE, "Los numero pares son ");
	listarNumImpar(numero, SIZE, "Los numeros que estan una posicion impar son ");

	return EXIT_SUCCESS;
}
