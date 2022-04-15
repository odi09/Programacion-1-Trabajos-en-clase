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
#include <string.h>

int main(void) {
	setbuf(stdout,NULL);

	char cadena[500] = "hola";
	//puts(cadena); // es igual que el printf pero le suma un \n y es solo para char
	//puts("perris");
	//printf("%s",cadena);

	int len = strlen(cadena);
	printf("LEN %d\n", len); //  me devuelve la candidad de caracteres que tiene guardados
	printf("LEN %d\n", sizeof(cadena)); // me devuelve el largo de una cadena
    //////////////////////////////////////////////////////
	char cad1[5];
	char cad2[15] = "HOLA mundo";
	strcpy(cad1, cad2);// copia lo que esta en cad2 en cad1, esto se usa en los array
	puts(cad2);
	printf("%s\n", cad1); // al copiar algo con un tamaño mayor a al tamaño de la variable me toma espacio de x variable
	///////////////////////////////////////////////////////
	char cad3[10];
	char cad4[15] = "perris tierra";
	strncpy(cad3,cad4, sizeof(cad3)); //
	cad3[sizeof(cad3)-1] =  '\0';
	printf("%s", cad3);
	///////////////////////////////////////////////////////



	return EXIT_SUCCESS;
}
