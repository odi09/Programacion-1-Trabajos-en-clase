/*
 ============================================================================
 Name        : Proyecto.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int pedirCharAUsuario(char* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError);

int main(void) {
	setbuf(stdout,NULL);

	char letra;
	int salidaFuncion;

	salidaFuncion = pedirCharAUsuario(&letra,65,90,3,"Ingrese una letra:  \n","Error! No es una letra");

	if(salidaFuncion==0)
	{
		printf("el caracter es %c",letra);
	}

	else
		{
		printf("error");
		}

		return EXIT_SUCCESS;
	}

int pedirCharAUsuario(char* pResultado, int min, int max, int reintentos, char* variableTexto, char* textoError)
{
	char buffer;
	int retorno=-1;
	int i;
	char salidaScanf;

	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
		{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			salidaScanf=scanf("%c", &buffer);
			printf("\nLa salida del scanf es : %d\n\n",salidaScanf);

			if (salidaScanf>0 && buffer>=min && buffer<=max)
				{
				retorno = 0; // OK
				*pResultado=buffer;
				break;
				}
			else
				{
				retorno=-1;
				printf("\n  %s",textoError);
				}
			fflush(stdin);
			}
		}
	return retorno;
}
