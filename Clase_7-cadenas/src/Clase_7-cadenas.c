/*
 ============================================================================
 Name        : Clase_7-cadenas.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Cadena(char* pArray)
{
	int i=0;
while(pArray[i]!=0)
       {
		printf("%c",pArray[i]);
		i++;
		}
}

int main(void) {
	setbuf(stdout, NULL);
int i;
int j;
	char texto[]={'A','B','C','D',0};//SIEMPRE en comillas ''.
// \0 es el 0 numerico
	Cadena(texto);
	i = strlen(texto);
	j = sizeof(texto);

	printf("%d\n",i);// devuelve el tamaño del array hastaa encontrar el \0 o 0
	printf("%d\n",j);// devuelve la cantica bite, es decir el tamaño de la variable

	return EXIT_SUCCESS;
}
