/*
 ============================================================================
 Name        : clase_9.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct S_Producto{
	char marca[30];
	char descripcion[32];
	float precio;
	int flagIsEmpy;

};
typedef struct S_Producto Producto;

void inicializarArray(Producto array[], int limite)
{
	int i;

	for(i=0; i<limite;i++)
	{
		// solucion 1
		array[i].marca[0] = 0;
		array[i].descripcion[0] = 0;
		array[i].precio = 0.0;
		/*Solucion dos
		array[i].flagIsEmpy =1;*/
	}
}
int main(void) {

	Producto productos[200];

	inicializarArray(productos, 200);

	return EXIT_SUCCESS;
}
