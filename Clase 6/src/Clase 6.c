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

int main(void) {
	setbuf(stdout,NULL);

	int edades[5];
	int indice;
	int resultado;
	char seguir;

	for(indice = 0; indice<5; indice++)
		{
		edades[indice] = 0;
		}

	do{
		printf("Posicion");
		scanf("%d", &indice);
		resultado=indice-1;

		printf("valor");
		scanf("%d", &edades[resultado]);
		printf("seguir\n");
		scanf("%c", &seguir);

	}while(seguir =='s');


	for(indice = 0; indice<5; indice++)
		{
		printf("El numero es %d y esta en la posicion %d\n", edades[indice], indice+1);
		}

	return EXIT_SUCCESS;
}
