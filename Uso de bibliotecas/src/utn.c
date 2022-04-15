/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: ojose
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/*//prototipos de funciones privadas
static void funcionAuxiliar(void)*/

int getNumero(int *pNum,int minimo,int maximo,char*pTexto,char*pError,int reintentos)
{
	setbuf(stdout, NULL);
	int retorno=-1;

do
{
	printf("%s",pTexto);
	fflush(stdin);
	if(scanf("%d",pNum)==1)//por parametro el scanf devuelve 1 cuando convierte a numero y 0 cuando no pudo convertirlo
	{

	if((*pNum)>=minimo && (*pNum)<=maximo)
	{
		retorno=0;
		break;
	}
	else
	{
		printf("%s",pError);
		reintentos--;
	}
}
else
{
	printf("%s",pError);
	reintentos--;
}

}while(reintentos>0);

	return retorno;
}

/*float getNumFlotante(float *pNum,float minimo,float maximo,char *pTexto, char *pError,int reintentos)
{
	setbuf(stdout, NULL);

		int retorno = -1;
		//int buffer; opcional

do
{
		printf("%s", pTexto);
		fflush(stdin);
		//scanf("%d",&buffer);otra forma de realizarlo
	if(scanf("%f", pNum)==1) //if(num!=NULL)
	{
	if((*pNum)>=minimo && (*pNum)<=maximo)//if(buffer>=numMin && buffer<=numMax)
	{
	  retorno=0;//*num=buffer;
	  break;
	}

	else
	{
	  printf("%s",pError);
	  reintentos--;
	}
	}
	else
	{
	  printf("%s",pError);
	  reintentos--;
	}
}while(reintentos>0);

		return retorno;
}

char getLetra(char *pLetra, char minimo, char maximo, char *pTexto,  char *pError, int reintentos)
{
int retorno = -1;
char buffer;
do
{
 printf("%s", pTexto);
 fflush(stdin);
 scanf("%c",&buffer);

 if(pLetra != NULL)
{
if(buffer >=minimo && buffer <=maximo )
{
	*pLetra=buffer;
	retorno=0;
	break;
}
else
{
	printf("%s",pError);
	reintentos--;
}
}
else
{
	printf("1%s",pError);
	reintentos--;
}
}while(reintentos>0);

return retorno;
}

/*static void funcionAuxiliar(void)// solo se usa en el .c
{

}*/
