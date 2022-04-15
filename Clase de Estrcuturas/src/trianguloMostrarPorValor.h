/*
 * trianguloMostrarPorValor.h
 *
 *  Created on: 28 sep. 2021
 *      Author: ojose
 */

#ifndef TRIANGULOMOSTRARPORVALOR___H_
#define TRIANGULOMOSTRARPORVALOR___H_

typedef struct{
	int lado1;
	int lado2;
	int lado3;
}eTrianguloEscaleno;

void trianguloMostrarPorValor(eTrianguloEscaleno lado);
void trianguloMostrarPorReferencia(eTrianguloEscaleno *pLado);
int trianguloCarga(eTrianguloEscaleno *pLado);
int trianguloPerimetro(eTrianguloEscaleno *pLado);
int trianguloArea(eTrianguloEscaleno *pLado, int altura);

#endif /* TRIANGULOMOSTRARPORVALOR___H_ */
