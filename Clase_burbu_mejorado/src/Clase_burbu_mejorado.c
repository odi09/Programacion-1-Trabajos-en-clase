/*
 ============================================================================
 Name        : Clase_burbu_mejorado.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int array_ordenar(int array[], int limite);

int main(void) {
	setbuf(stdout, NULL);

	int array[5]={20,58,1,0,100};
	for(int i = 0; i<5; i++)
	{
		array_ordenar(array,5);
		printf("INGRESO: %d\n",array[i]);
	}


    array_ordenar(array,5);

	return EXIT_SUCCESS;
}
int array_ordenar(int array[], int limite)
{
	int retorno = -1;
	int flagSwap;
	int bufferInt;
	if(array != NULL && limite>0)
	{
		retorno = 0;
		do
		{
		flagSwap = 0;
		limite--;
		for(int i=0; i<limite; i++)
		{
			if(array[i] < array[i+1])
			{
				bufferInt = array[i];
				array[i]=array[i+1];
				array[i+1]=bufferInt;
				flagSwap = 1;
				//retorno++; para sabeer cuantas interacciones se hicieron
			}
		}
		}while(flagSwap);
	}
	return retorno;
}
