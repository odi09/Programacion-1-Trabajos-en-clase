/*
 ============================================================================
 Name        : 1.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int myStrLen(char*	 cadena);
void myPuts(char* cadena);

int main(void) {
	setbuf(stdout,NULL);

	char cad[10] = "hola";
	int tamLen;
	//int len;

	tamLen = myStrLen(cad);
	printf("El tamaño es: %d", tamLen);
	myPuts(cad);

	return EXIT_SUCCESS;
}
int myStrLen(char cadena[])
{
	int index = 0;

	while ( cadena[index]!='\0')
	{
		index++;
	}

	return  index;
}

void myPuts(char cadena[])
{
	int contador = 0;
	char aux;

		while ( cadena[contador]!='\0')
		{
			contador++;
			aux = cadena[contador];
		}
	printf("El tamaño es: %c",aux);

}

