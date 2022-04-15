/*
 * funcion Array.c
 *
 *  Created on: 5 abr. 2022
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
int esPar(int num)
{
	int retorno = 0;
	if(num % 2 == 0)
	{
		retorno = 1;
	}
	return retorno;
}
int cargarArray(int array[], int size, char* texto)
{
	int i;
	int estado=0;
	for(i = 0; i<size; i++)
	{
		printf("%s", texto);
		scanf("%d", &array[i]);
		estado = 1;
	}
return estado;
}

int sumaDePositivos(int array[], int size)
{
	int acumulador = 0;
	for(int i = 0; i<size; i++)
	{
		if(array[i] >=0)
		{
			acumulador++;
		}

	}
	return acumulador;
}
int sumaDeNegativo(int array[], int size)
{
	int acumulador = 0;
	for(int i = 0; i<size; i++)
	{
		if(array[i] < 0)
		{
			acumulador++;
		}

	}
	return acumulador;
}
int sumaPares(int array[], int size)
{
	int contador=0;
	for(int i = 0; i<size; i++)
	{
		if(array[i] % 2 == 0)
		{
			contador = contador+array[i];
		}
	}
	return contador;
}
int mayorImpares(int array[], int size)
{
	int numMayor;
	numMayor = array[0];
	for(int i = 0; i<size; i++)
	{
		if(!(esPar(array[i])))
		{
			if(numMayor<array[i])
			{
				numMayor = array[i];
			}
		}
	}
	return numMayor;
}
void listas(int array[], int size, char* texto)
{
	for(int i = 0; i<size; i++)
	{
		printf("%s %d.\n",texto, array[i]);
	}
}
void listarNumPar(int array[], int size, char* texto)
{

	for(int i = 0; i<size; i++)
	{
		if(esPar(array[i]))
		{
			printf("%s %d.\n",texto, array[i]);
		}
	}

}
void listarNumImpar(int array[], int size, char* texto)
{
	for(int i = 0; i<size; i++)
	{
		if(i % 2 != 0)
		{
			printf("%s %d.\n",texto, array[i]);
		}
	}

}

