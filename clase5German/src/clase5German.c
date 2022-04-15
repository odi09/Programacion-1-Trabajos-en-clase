/*
 ============================================================================
 Name        : clase5German.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	/*int vector[5];
	int acumulador = 0;
	for(int i=0;i<5;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&vector[i]);

	}
	for(int i=0;i<5;i++)
	{
		printf("%d\n", vector[i]);
		acumulador =acumulador +vector[i];
	}
	printf("La suma es %d", acumulador);*/

	int vector[3];
	int acumulador = 0;
	int acumulador1 = 0;
	int acumulador2 = 0;



	for(int i=0;i<3;i++)
	{
		printf("Ingrese un numero entre el -1000 y 1000: ");
		scanf("%d",&vector[i]);

		if(vector[i] >= -1000 && vector[i] <= 1000)
		{
			if(vector[i] >= -1000 && vector[i] <= -1)
			{
				acumulador1 = acumulador1+vector[i];
			}
			else
			{
				acumulador2 = acumulador2+vector[i];
			}
		}
		else
		{
			printf("Intente de vuelta\n");
		}

	}
	for(int i=0;i<3;i++)
	{
	if(vector[i]>= -1000 && vector[i]<=1000)
		{
		printf("%d\n", vector[i]);
		acumulador =acumulador +vector[i];
		}

	}
	printf("La suma es %d\n", acumulador);
	printf("La cantidad de positivos es %d y negativos es %d", acumulador1, acumulador2);

	return EXIT_SUCCESS;
}
