/*
 ============================================================================
 Name        : Pruebas.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char texto;
	char texto1 = 'a';
	printf("Ingrese un mensaje: \n");
	scanf("%c",&texto);
	switch(texto)
		{
		case 'a':
			printf("Ingreso de manera correcta ");
			break;
		}

	return EXIT_SUCCESS;
}
