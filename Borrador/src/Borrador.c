/*
 ============================================================================
 Name        : Borrador.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char a1;
	int a2;
	float a3;
}Prueba;

int main(void) {
	Prueba.a2 = 2;
	printf("prueba %d", Prueba.a2);
	return EXIT_SUCCESS;
}
