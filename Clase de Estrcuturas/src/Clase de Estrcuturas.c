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
#include "string.h"
#include "trianguloMostrarPorValor.h"

int main(void) {
	setbuf(stdout, NULL);

	eTrianguloEscaleno lados[3];
	int auxCargar[3];
	int auxPerimetro[3];
	int auxArea;
	int altura = 15;
/*
    for(int i = 0; i<3; i++)
    {
    	pedirEntero(&lados[i], );
    }
	lados.lado1 = 20;
	lados.lado2 = 15;
	lados.lado3 = 10;
*/
	//trianguloMostrarPorValor(lados);
	//trianguloMos, trarPorReferencia(lados);
	for(int i = 0; i<3; i++)
	{
		auxCargar[i] = trianguloCarga(&lados[i]);
		auxPerimetro[i] = trianguloPerimetro(&lados[i]);
		//printf("El Perimetro del Triangulo es %d\n", auxPerimetro[i]);


	}


	if(auxCargar[0] == -1 && auxCargar[1] == -1 && auxCargar[2] == -1)
	{
		auxPerimetro[0] = trianguloPerimetro(lados);
		printf("El Perimetro del primer Triangulo es %d\n", auxPerimetro[0]);
		auxPerimetro[1] = trianguloPerimetro(&lados[1]);
		printf("El Perimetro segundo Triangulo es %d\n", auxPerimetro[1]);
		auxPerimetro[2] = trianguloPerimetro(&lados[2]);
		printf("El Perimetro tercero Triangulo es %d\n", auxPerimetro[2]);

		auxArea = trianguloArea(lados, altura);
		printf("El Area es %d", auxArea);
	}

	return EXIT_SUCCESS;
}
