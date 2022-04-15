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
int SumarEnteros(int num1, int num2);
int RestaEnteros(int num1, int num2);
int MultiplicacionEnteros(int num1, int num2);
int DivisionEnteros(int* num1, int* num2, float* resultado);
void imprimirResultado(int num1);

int main(void) {
	setbuf(stdout,NULL);

	int numero1;
	int numero2;
	//float promedio;
	float resultado;
	//int resultado2;
	//int resultado3;
	int resultado4;
	//float impuestos;
	//float impuestoRultado;

	printf("Ingrese numero 1: ");
	scanf("%d",&numero1);
	printf("Ingrese numero 2: ");
	scanf("%d",&numero2);

	//resultado = SumarEnteros(numero1, numero2);
	//resultado2 = RestaEnteros(numero1, numero2);
	//resultado3 = MultiplicacionEnteros(numero1, numero2);
	resultado4 = DivisionEnteros(&numero1, &numero2, &resultado);

	//imprimirResultado(resultado);
	//imprimirResultado(resultado2);
	//imprimirResultado(resultado3);

	if(resultado4 == 1)
		printf("No se puede dividir por 0 \n");

	else
		printf("La division es %.2f \n", resultado);

	//promedio = (float)resultado/2;

	//printf("El promedio es %.2f \n", promedio);

	//printf("Ingrese los impuestos: ");
	//scanf("%f",&impuestos);

	//impuestoRultado = impuestos + resultado;
	//printf("El resultado es %.2f\n", impuestoRultado);


	return EXIT_SUCCESS;
}

int SumarEnteros(int num1, int num2)
{
	int retorno;

	retorno = num1 + num2;

	return retorno;
}

int RestaEnteros(int num1, int num2)
{
	int retorno;

    	retorno = num1 - num2;

	return retorno;
}
int MultiplicacionEnteros(int num1, int num2)
{
	int retorno;

	retorno = num1 * num2;

	return retorno;
}
int DivisionEnteros(int* num1, int* num2, float* resultado)
{
	int retorno = 0;

    if (*num2 != 0)
    {
    	*resultado = (float)*num1 / *num2;
    }
    else
    {
    	retorno = 1;
    }

	return retorno;
}

void imprimirResultado(int num1)
{
	printf("El resultado es %d \n", num1);
}
