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

	int numero1;
	int numero2;
	float promedio;
	int resultado;
	float impuestos;
	float impuestoRultado;

	printf("Ingrese numero 1: ");
	scanf("%d",&numero1);

	printf("Ingrese numero 2: \n");
	scanf("%d",&numero2);

	resultado = numero1 + numero2;
	promedio = (float)resultado/2;

	printf("El promedio es %.2f \n", promedio);

	printf("Ingrese los impuestos \n");
	scanf("%f",&impuestos);
	impuestoRultado = impuestos + resultado;
	printf("El resultado es %f\n", impuestoRultado);

	return EXIT_SUCCESS;
}
