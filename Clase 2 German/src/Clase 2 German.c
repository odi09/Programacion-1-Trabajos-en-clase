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
	setbuf(stdout, NULL);
	///	Ejercicio 2-1
	int numero;
	int auxiliar = 0;
	int i;
	float resultado;
	for(i = 0; i<5; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&numero);
		auxiliar = auxiliar + numero;
	}
	resultado = (float)auxiliar/i;
	printf("El promedio es %.2f", resultado);

	/*int numDos;
	int i;
	int resultado;

	for(i = 0; i < 2; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&numDos);
		if(numDos % 2 == 0)
		{

		}
	}*/


	return EXIT_SUCCESS;
}
