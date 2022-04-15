/*
 ============================================================================
 Name        : Clase_5.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define indice 5

void imprimirArray(int listaDeNumeros[], int largo);
float promedioArray(int listaDeNumeros[], int largo, float *division);

int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int arrayNum[indice];
	int i;
	float promedio;

	for (i = 0; i < indice; i++) {
		if (getNumero(&numero, 0, 99, "Ingrese un numero:",
				"El numero ingresado NO es correcto\n", 2) == 0) {
			arrayNum[i] = numero;
		} else {
			printf("SE terminaron tus intentos, regrese luego");
		}
	}

	imprimirArray(arrayNum, indice);
	promedioArray(arrayNum, indice, &promedio);
	printf("\nEl promedio es: %.2f", promedio);

	return EXIT_SUCCESS;
}
void imprimirArray(int listaDeNumeros[], int largo) {
	int i;

	for (i = 0; i < largo; i++) {
		printf("%d,", listaDeNumeros[i]);
	}

}
float promedioArray(int listaDeNumeros[], int largo, float *pDivision) {
	int i;
	int acumulador = 0;

	for (i = 0; i < largo; i++) {
		acumulador = acumulador + listaDeNumeros[i];
	}
	*pDivision = (float) acumulador / largo;

	return 0;
}
