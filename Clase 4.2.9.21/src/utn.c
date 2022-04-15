/*
 * utn.c
 *
 *  Created on: 7 sep. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int getInt(float * pResultado)
{
	char buffer[64];
	int ret = -1;
	scanf ("%s",buffer);
	if(esNumerica(buffer))
	{
		*pResultado = atoi(buffer);
		ret = 1;
	}
	return ret;
}

static int esNumerica(char* cadena)
{
	int i = 0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno =0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int SumarEnteros(int num1, int num2)
{
	int retorno;

	retorno = num1 + num2;

	return retorno;
}

int RestaEnteros(int num1, int num2)
{
	int retorno;

    	retorno = num1 - num2;

	return retorno;
}
int MultiplicacionEnteros(int num1, int num2)
{
	int retorno;

	retorno = num1 * num2;

	return retorno;
}
int DivisionEnteros(int num1, int num2, float* resultado)
{
	int retorno;

    if (num2 != 0)
    {
    	*resultado = (float)num1 / num2;
    	retorno = 0;
    }
    else
    {
    	retorno = 1;
    }

	return retorno;
}
int pedirDatos(float* pNumero, float pMin, float pMax, int reintento, char* pTexto, char* pTextoError)
{
	int auxRetorno;
	int retorno;
	float auxNumero;

	if(pNumero != NULL && pMin<pMax && reintento>=0 && pTexto != NULL && pTextoError != NULL)
	{
		for(int i=0; i <= reintento; i++)
		{
			printf("%s", pTexto);
			if(getInt(&auxNumero) == 1)
				{
				if(auxNumero >= pMin && auxNumero <= pMax)
					{
					*pNumero = auxNumero;
					auxRetorno = 0;
					break;
					}
				}
			else
				{
				printf("%s\n", pTextoError);
				reintento--;
				auxRetorno = 1;
				}
			fflush(stdin);
		}
	}

	retorno = auxRetorno;
	return retorno;
}
void imprimirResultado(int num1)
{
	printf("El resultado es %d \n", num1);
}


