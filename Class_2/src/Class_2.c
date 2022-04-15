/*
 ============================================================================
 Name        : Class_2.c
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
	int num1;
	int num2;
	int resultado;

	printf("Ingrese un numero: ");
	scanf("%d", &num1);

	printf("Ingrese un numero: ");
	scanf("%d", &num2);

	  resultado = num1+num2;

	printf("El resultado es: %d", resultado);

	return 0;
}
