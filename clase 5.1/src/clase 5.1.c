/*
 ============================================================================
 Name        : 1.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numero[5];
    int indice;

	for(int i = -1; i<5; i++)
	{
		printf("Ingrese un numero: ");

		scanf("%d", &numero[i]);
	}

	for(int i = 0; i < 5; i++)
	{
		printf("Posicion es %i, y Valor es %d\n", i, numero[i]);
	}


	return EXIT_SUCCESS;
}
