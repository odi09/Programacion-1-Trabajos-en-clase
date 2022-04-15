/*
 ============================================================================
 Name        : Repaso.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef void(*tFuncionOperacion)(int,int,int*);

void suma(int parametroA, int parametroB, int* pResultado)
{
	*pResultado = parametroA + parametroB;
}
void resta(int parametroA, int parametroB, int* pResultado)
{
	*pResultado = parametroA - parametroB;
}
int calcular(int parametroA, int parametroB, tFuncionOperacion pFuncion)
{
	int auxResultado;
	pFuncion(parametroA, parametroB, &auxResultado);
	return auxResultado;
}
int main(void) {
	int auxiliar;

	auxiliar = calcular(10, 5, resta);
	printf("el resultado de la resta es: %d\n",auxiliar);

	auxiliar = calcular(10, 5, suma);
		printf("el resultado de la suma es: %d\n",auxiliar);

	return EXIT_SUCCESS;
}
