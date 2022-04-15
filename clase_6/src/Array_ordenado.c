/*
 * Array_ordenado.c
 *
 *  Created on: 8 abr. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "Array_ordenado.h"

int arrayImpri(int *array, int limite) {
	int i;
	int retorno = 1;

	if (array != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			printf("\nEl indice es %d y su Valor es %d", array[i], i);

			retorno = 0;
		}

	}
	return retorno;
}
int arrayOrden(int *arrayOr, int limite) {
	int flag;
	int i;
	int aux;
	int contador = 0;
	int retorno = -1;
	if (arrayOr != NULL && limite > 0) {
		do {
			flag = 0;
			for (i = 0; i < limite - 1; i++) {
				if (arrayOr[i] > arrayOr[i + 1]) {
					flag = 1;
					aux = arrayOr[i];
					arrayOr[i] = arrayOr[i + 1];
					arrayOr[i + 1] = aux;
				}
				contador++;
			}
		} while (flag);
		retorno = contador;
	}
	return retorno;
}
