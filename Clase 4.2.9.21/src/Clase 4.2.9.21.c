/*
 ============================================================================
 Name        : 21.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define REINTENTOS 3

int main(void) {
	setbuf(stdout,NULL);

	float num1;
	float num2;
	float pMin = 0.0;
	float pMax = 1000.0;
	//float promedio;
	float resultado;
	//int resultado2;
	//int resultado3;
	int resultado4;
	int estado;
	int estado2;
	//float impuestoRultado;

	estado = pedirDatos(&num1, pMin, pMax, REINTENTOS, "Ingrese Dividendo: ", "Error, numero incorrecto");

	if(estado== 0)
		{
		estado2 = pedirDatos(&num2, pMin, pMax, REINTENTOS, "Ingrese Divisor: ", "Error, numero incorrecto");

		if(estado2== 0)
			{
			resultado4 = DivisionEnteros(num1, num2, &resultado);

			if(resultado4 == 1)
				printf("No se puede dividir por 0 \n");

			else
				printf("La division es %.2f \n", resultado);
			}
		}
	else
		printf("No se ingreso un numero valido \n");



	//resultado = SumarEnteros(numero1, numero2);
	//resultado2 = RestaEnteros(numero1, numero2);
	//resultado3 = MultiplicacionEnteros(numero1, numero2);

	//imprimirResultado(resultado);
	//imprimirResultado(resultado2);
	//imprimirResultado(resultado3);



	//promedio = (float)resultado/2;

	//printf("El promedio es %.2f \n", promedio);

	//printf("Ingrese los impuestos: ");
	//scanf("%f",&impuestos);

	//impuestoRultado = impuestos + resultado;
	//printf("El resultado es %.2f\n", impuestoRultado);


	return EXIT_SUCCESS;
}
