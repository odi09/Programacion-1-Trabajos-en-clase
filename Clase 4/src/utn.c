/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: ojose
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int getInt(int *pNum);
static int esNumero(char* cadena, int longitud);
static int getFloat(float *pNum);
static int esFloat(char* cadena, int longitud);
static char getChar(char* pTexto);
static char esTexto(char* cadena, int longitud);

static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4100];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
			{
				if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
				{
					bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
				}
				if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
				{
					strncpy(cadena,bufferString,longitud);
					retorno=0;
				}
			}
	}
	return retorno;
}

///////////////////////////////////////////Es Float///////////////////////////////////////////
static int getFloat(float *pNum)
{
	int retorno=-1;
	char bufferString[50];
	if(pNum != NULL)
	{
		if(myGets(bufferString,sizeof(bufferString)) == 0)
		{
			if(esFloat(bufferString,sizeof(bufferString)))
			{
				retorno=0;
				*pNum=atof(bufferString);
			}
		}
	}
	return retorno;
}
static int esFloat(char* cadena, int longitud)
{
	int retorno = 1; // verdadero
	int i;
	int contaPuntos=0;
	for(i=0;i<longitud && cadena[i] != '\0';i++)
	{
		if(cadena[i] == '.')
		{
			contaPuntos++;
		}
		if(( (i == 0 && (cadena[i] == '+' ||cadena[i] == '-' )) ||(cadena[i] <= '9' && cadena[i] >= '0') || cadena[i] == '.') && contaPuntos < 2)
		{
			continue; //pide que se haga una interaccion mas del for
		}
		else
		{
			retorno = 0;
			break;
		}

	}
	return retorno;
}
///////////////////////////////////////////Es Int /////////////////////////////////////
static int getInt(int *pNum)
{
	int retorno=-1;
	char bufferString[50];
	if(pNum != NULL)
	{
		if(myGets(bufferString,sizeof(bufferString)) == 0)
		{
			if(esNumero(bufferString,sizeof(bufferString)))
			{
				retorno=0;
				*pNum=atoi(bufferString);
			}
		}
	}
	return retorno;
}
static int esNumero(char* cadena, int longitud)
{
	int retorno = 1; // verdadero
	int i;
	for(i=0;i<longitud && cadena[i] != '\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue; //pide que se haga una interaccion mas del for
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
////////////////////////////////// Es Char////////////////////////////////

static char getChar(char* pTexto)
{
	int retorno=-1;
	char bufferString[50];
	if(pTexto != NULL)
	{
		if(myGets(bufferString,sizeof(bufferString)) == 0)
		{
			if(esTexto(bufferString,sizeof(bufferString)))
			{
				retorno=0;
				strcpy(pTexto,bufferString);
			}
		}
	}
	return retorno;
}
static char esTexto(char* cadena, int longitud)
{
	int retorno = 1; // verdadero
	int i;
	for(i=0;i<longitud && cadena[i] != '\0';i++)
	{
		if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief
 *
 *  \param
 *  \return
 *
 */
int getNumero(int *pNum, int minimo, int maximo, char *pTexto, char *pError,int reintentos)
{
	setbuf(stdout, NULL);
	int retorno = -1;
	int bufferInt;
	if (pNum != NULL && pTexto != NULL && pError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", pTexto);
			fflush(stdin);
			if (getInt(&bufferInt) == 0 &&
				bufferInt >= minimo     &&
				bufferInt <= maximo)
			{
				retorno = 0;
				*pNum = bufferInt;
				break;
			}
			printf("%s",pError);
		} while (reintentos >= 0);
	}
	return retorno;
}

/** \brief
 *
 *  \param
 *  \return
 *
 */
float getNumFlotante(float *pNum, float minimo, float maximo, char *pTexto, char *pError, int reintentos)
{
	setbuf(stdout, NULL);
	int retorno = -1;
	float buffer;
	if (pNum != NULL && pTexto != NULL && pError != NULL && minimo <= maximo && reintentos >= 0)
	{
      do
      {
			printf("%s", pTexto);
			fflush(stdin);
			if (getFloat(&buffer)== 0 && buffer >= minimo && buffer <= maximo)
				{
					retorno = 0;
					*pNum=buffer;
					break;
				}
				printf("%s", pError);
		} while (reintentos >= 0);
    }

	return retorno;
}

/** \brief
 *
 *  \param
 *  \return
 *
 */
char getLetra(char *pLetra, char minimo, char maximo, char *pTexto,	char *pError, int reintentos)
{
	int retorno = -1;
	char buffer;
	if (pLetra != NULL && pTexto != NULL && pError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", pTexto);
			fflush(stdin);
			if (getChar(&buffer) == 0  && buffer >= minimo && buffer <= maximo)
				{
					*pLetra = buffer;
					retorno = 0;
					break;
				}
				printf("%s", pError);
		} while (reintentos >= 0);
	}
	return retorno;
}
