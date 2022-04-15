/*
 ============================================================================
 Name        : Prctica.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int* puntero1;
	int** punteroDePuntero;
	int variable1;
	variable1 = 10;

	puntero1 = &variable1;
	punteroDePuntero = &puntero1;

	printf("Posicion 5 del array es %d",**punteroDePuntero);





	return EXIT_SUCCESS;
}
