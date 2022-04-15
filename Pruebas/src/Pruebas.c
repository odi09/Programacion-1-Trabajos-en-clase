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
#include <string.h>
#define TAM_NOMBRE  100

static int getString(char* cadena, int limite);
static int validarNombre(char* cadena, int limite):

int utn_getNombre(char* pNombre, char* pMensaje, char* pMensajeError);

static int getString(char* cadena, int limite)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && limite > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL)
	{
		__fpurge(stdin);
		if(bufferString[strlen(bufferString) - 1] == '\n')
		{
			bufferString[strlen(bufferString) - 1] = '\0';
		}
		strncpy(cadena, bufferString, limite);
		retorno = 0;
	}

	return retorno;
}
static int validarNombre(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if((i == 0 || cadena[i - 1] == ' ') && cadena[i] >= 'A' && cadena[i] <= 'Z')
			{
				continue;
			}
			if((cadena[i] < 'a' || cadena[i] > 'z') && cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
int main(void) {

	char nombre;

	utn_getNombre(&nombre, "Ingrese un datos", "ERROR, no ingreso un datos valido");
	return EXIT_SUCCESS;
}

int utn_getTexto(char* pString, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_NOMBRE];

	printf("%s", pMensaje);
	fflush(stdin);
	if(pNombre != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarNombre(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pNombre, bufferString, TAM_NOMBRE);
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}
