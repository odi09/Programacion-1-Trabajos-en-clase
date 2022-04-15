/*
 * trianguloMostrarPorValor.c
 *
 *  Created on: 28 sep. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"
#include "trianguloMostrarPorValor.h"

void trianguloMostrarPorValor(eTrianguloEscaleno lado)
{
	printf("El datos ingresado es: %d %d %d\n", lado.lado1, lado.lado2, lado.lado3);
}

void trianguloMostrarPorReferencia(eTrianguloEscaleno *pLado)
{
	printf("El datos ingresado es: %d %d %d\n", pLado->lado1, pLado->lado2, pLado->lado3);
}

int trianguloCarga(eTrianguloEscaleno *pLado)
{
	int retorno = 0;

	if(pLado != NULL)
	{
		pedirEntero(&pLado->lado1,1,100,1,"Ingrese el lado A del Triangulo: ","ERROR, el dato ingresado no es valido");
		//scanf("%d", &pLado->lado1);
		//printf("El datos ingresado es: %d \n", pLado->lado1);

		pedirEntero(&pLado->lado2,1,100,1,"Ingrese el lado B del Triangulo: ","ERROR, el dato ingresado no es valido");
		/*printf("Ingrese el lado B del Triangulo: ");
		scanf("%d", &pLado->lado2);*/

		pedirEntero(&pLado->lado3,1,100,1,"Ingrese el lado C del Triangulo: ","ERROR, el dato ingresado no es valido");
		/*printf("Ingrese el lado C del Triangulo: ");
		scanf("%d", &pLado->lado3);*/

		retorno = -1;
	}

	else
	{
		printf("ERROR");
	}


	return retorno;
}
int trianguloPerimetro(eTrianguloEscaleno *pLado)
{
	int resultado;

	if(pLado != NULL)
	{
	resultado = pLado->lado1 + pLado->lado2 + pLado->lado3;
	}
	return resultado;
}
int trianguloArea(eTrianguloEscaleno *pLado, int altura)
{
	int resultado;

	if(pLado != NULL && altura > 0)
	{
	resultado = (pLado->lado3 * altura)/2;
	}

	return resultado;
}

