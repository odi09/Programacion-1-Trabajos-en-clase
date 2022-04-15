/*
 ============================================================================
 Name        : Clase.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {
setbuf(stdout, NULL);

int numero;
float numero2;
char letra2;

if(getNumero(&numero,0,99,"Ingrese numero: ","Error, Fuera de rango\n",3)==0)
{
 printf("Ingreso: %d\n", numero);
}

if(getNumFlotante(&numero2,0.00,99.99,"Ingrese su estatura: ","Error, Fuera de rango\n",3)==0)
{
 printf("Su estatura es  %.2f\n", numero2);
}

if(getLetra(&letra2,'A','z',"Ingrese la letra A o B: ","Error, letra fuera del rango\n",3)==0)
{
 printf("La letra ingresada es %c",letra2);
 fflush(stdin);
}

	return EXIT_SUCCESS;
}

