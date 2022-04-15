/*
 * char.c
 *
 *  Created on: 7 sep. 2021
 *      Author: ojose
 */

#include <stdio.h>
#include <stdlib.h>
#include "char.h"

char pedirCaracter(char* pChar, char pMin, char pMax, int reintento, char* pTexto, char* pTextoError)
{
	int auxRetorno;
	int retorno;
	char auxChar;

	if(pChar != NULL && pMin<pMax && reintento>=0 && pTexto != NULL && pTextoError != NULL)
	{
		for(int i=0; i < reintento; i++)
		{
			printf("%s", pTexto);

			if(scanf("%c", &auxChar) == 1)
				{
				if(auxChar >= pMin && auxChar <= pMax)
					{
					*pChar = auxChar;
					auxRetorno = 1;
					break;
					}
				}
			else
				{
				printf("%s\n", pTextoError);
				reintento--;
				auxRetorno = 0;
				}
			fflush(stdin);
		}
	}

	retorno = auxRetorno;
	return retorno;
}

int pedirEntero(int* pInt, int min, int max, int reintento, char* pTexto, char* pTextoError)
{
	int auxRetorno;
	int retorno;
	int auxInt;

	if(pInt != NULL && min<max && reintento>=0 && pTexto != NULL && pTextoError != NULL)
	{
		for(int i=0; i < reintento; i++)
		{
			printf("%s", pTexto);

			if(scanf("%d", &auxInt) == 1)
				{
				if(auxInt >= min && auxInt <= max)
					{
					*pInt = auxInt;
					auxRetorno = 1;
					break;
					}
				}
			else
				{
				printf("%s\n", pTextoError);
				reintento--;
				auxRetorno = 0;
				}
			fflush(stdin);
		}
	}

	retorno = auxRetorno;
	return retorno;
}
float pedirFlotante(float* pFloat, int min, int max, int reintento, char* pTexto, char* pTextoError)
{
	int auxRetorno;
	int retorno;
	float auxFloat;

	if(pFloat != NULL && min<max && reintento>=0 && pTexto != NULL && pTextoError != NULL)
	{
		for(int i=0; i < reintento; i++)
		{
			printf("%s", pTexto);

			if(scanf("%f", &auxFloat) == 1)
				{
				if(auxFloat >= min && auxFloat <= max)
					{
					*pFloat = auxFloat;
					auxRetorno = 1;
					break;
					}
				}
			else
				{
				printf("%s\n", pTextoError);
				reintento--;
				auxRetorno = 0;
				}
			fflush(stdin);
		}
	}

	retorno = auxRetorno;
	return retorno;
}
