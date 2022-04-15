/*
 ============================================================================
 Name        : TP_1.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculadora.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);

	float valor1;
	float valor2;
	float resultado;
	char opcion;
	char seguir;
	int estadoDato1;
	int estadoDato2;

	do {
		estadoDato1 = pedirFlotante(&valor1,3,"Ingresar 1er operando: ","ERROR no ingreso un numero valido");
		estadoDato2 = pedirFlotante(&valor2,3,"Ingresar 2do operando: ","ERROR no ingreso un numero valido");

		if(estadoDato1 == 1 && estadoDato2 == 1)
		{
			do {
				printf( "a) Calcular la suma (A+B)\n"
					    "b) Calcular la resta (A-B)\n"
						"c) Calcular la division (A/B)\n"
						"d) Calcular la multiplicacion (A*B)\n"
						"e) Calcular la factorial (A!) Ingrese !\n"
						"f) Calcular todas las opciones\n\n");
				printf("Ingrese el signo de la Operacion a realizar: ");
				scanf("%s", &opcion);
				} while (opcion != '+' && opcion != '-' && opcion != '*'&& opcion != '/' && opcion != '!');


		switch (opcion) {
		case '+':
			if (suma(&valor1, &valor2, &resultado,"El resultado de la Suma A+B es:") == 0)
			{
			}
			else
			{
				printf("ERROR");
			}

			break;
		case '-':
			if (resta(&valor1, &valor2, &resultado,"El resultado de la Resta A-B es:") == 0)
			{
			}
			else
			{
				printf("ERROR");
			}

			break;

		case '*':
			if (multiplicacion(&valor1, &valor2, &resultado,"El resultado de la Multiplicacion A*B es:") == 0)
			{
			}
			else
			{
				printf("ERROR");
			}
			break;

		case '/':
			if(division(&valor1, &valor2, &resultado,"El resultado de la Division A/B es:","ERROR, no se puede dividir por 0.") == 0)
			{
			}
			else
				{
				printf("\nERROR");
				}
			break;

		case '!':
			if (factorialA(&valor1, &resultado, "El factorial de A! ") == 0)
			{
			}
			else
			{
				printf(
						"ERROR ingresaste un valor de A negativo o superior a 20\n");
			}

			if (factorialB(&valor2, &resultado, "El factorial de B! ") == 0)
			{
			}
			else
			{
				printf(
						"ERROR ingresaste un valor de B negativo o superior a 20\n");
			}

			break;
		}
		}
		printf("\nDesea seguir operando? s/n: ");
		scanf("%s", &seguir);
		fflush(stdin);
		seguir = toupper(seguir);
	} while (seguir == 'S');

	return EXIT_SUCCESS;
}
