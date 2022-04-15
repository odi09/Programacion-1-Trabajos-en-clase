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

int main(void) {
//* *************************Caso 1*******************************
	float* pDireccion  = (float*) malloc(sizeof(float)); //el

	printf("Me dio la direccion 1: %p\n", pDireccion);

	*pDireccion = 3.14;

	printf("Me dio el valor que esta guardado 2: %f\n", *pDireccion);
	printf("Me dio la direccion 3: %p\n", pDireccion);


// ******************************************Caso 2*********************
	/*float* pDireccion  = (float*) malloc(sizeof(float)*10);

	pDireccion[3] = 3.14;
    *(pDireccion +3) = // pDireccion[3] = 3.14;

	printf("Me dio la direccion 4: %d\n", pDireccion);
	printf("Me dio la direccion 5: %d\n", pDireccion+1);*/

/* ******************************************Caso 2*********************
	int variableLocal;
	int pVariableDinamica = malloc(sizeof(int));

	printf("Direccion de la variable Local: %d\n", &variableLocal);
	printf("Direccion de la variable Dinamica: %d\n", pVariableDinamica);

// ******************************************Caso 3*********************

	int* pNuevoEspacio = realloc(pVariableDinamica, sizeof(int)*5); //  devuelve NULL si no se puede agrandar el espacio

	if(pNuevoEspacio != NULL)
	{
		pVariableDinamica = pNuevoEspacio;
	}
// ******************************************Caso 4 Liberar Espacio*********************

	free (pVariableDinamica); // el espacio de esta memoria ya esta liberado
	// se borra la variable
	pVariableDinamica = NULL;
// ******************************************Caso 5 Convertir una estructura a dinamica*********************
 eDisplay*  pDisplay = (pDisplay*)malloc(sizeof(pDisplay));
*/
	return EXIT_SUCCESS;
}
