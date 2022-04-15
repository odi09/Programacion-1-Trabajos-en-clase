/*
 ============================================================================
 Name        : Clase2_ejercicio.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 2

int main(void) {
	    int numero;
		int acumulador = 0;
		int contador = 0;
		float promedio;
		int i;

		for(i=0; i< TAM; i++){
		printf("Ingrese un numero: \n");
		scanf("%d", &numero);
		acumulador=acumulador+numero;
		contador++;
		}

		promedio = (float)acumulador/contador;

		printf("El promedio es: %.2f\n", promedio);

	return EXIT_SUCCESS;
}
