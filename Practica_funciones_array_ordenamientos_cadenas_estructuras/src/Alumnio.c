/*
 * Alumnio.c
 *
 *  Created on: 26 abr. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Alumno.h"

int imprimirArrayAlumno(Alumno* pArray, int limite)
{
	int i;
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for(i=0; i<limite; i++)
		{
			if(pArray[i].isEmpty == 0)
			{
				printf("\nLegajo:%d, Edad:%d, Apellido:%s",pArray[i].legajo,pArray[i].edad,pArray[i].apellido);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int inicializoArrayAlumno(Alumno* pArray, int limite)
{
	int i;
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for(i=0; i<limite; i++)
		{
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

