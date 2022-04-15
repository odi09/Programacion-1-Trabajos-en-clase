/*
 ============================================================================
 Name        : clase_6.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Array_ordenado.h"

int arrayImpri(int *array, int limite);
int arrayOrden(int *arrayOr, int limite);

#define tam 5

int main(void) {
	setbuf(stdout, NULL);

	int arrayNum[tam] = { 15, 9, 21, 18, 5 };
	int respuesta;

	arrayImpri(arrayNum, tam);
	respuesta = arrayOrden(arrayNum, tam);
	if (respuesta > 0) {
		printf("\n\nIteraciones %d\n\n", respuesta);
	}
	arrayImpri(arrayNum, tam);

	return EXIT_SUCCESS;
}


