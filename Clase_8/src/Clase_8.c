/*
 ============================================================================
 Name        : Clase_8.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD_EMPLEADO 5
// definicion, va en el .h//////////////////////////////////
typedef struct
{
	char nombre[50];
	char apellido[50];
	float altura;
	float peso;

}Persona;
//uso esta, esta va al .c/////////////////////////////////
// int per intArray(Persona aPersonas[], int limite)
//o esta
// int per intArray(Persona* Personas, int limite, )

////////////////////////////////////////////////////////
int main(void) {
 Persona arrayEmpleados[CANTIDAD_EMPLEADO]

	/*Persona arrayPersona[CANTIDAD_PERSONA];

	int i;

	float alturaMaxima;
	int indiceAlturaMaxima;

	float pesoMaximo;
	int indicePesoMaximo;

	strcpy(arrayPersona[0].nombre,"Santy");
	strcpy(arrayPersona[0].apellido,"Leonardi");
	arrayPersona[0].altura=1.71;
	arrayPersona[0].peso=62;

	strcpy(arrayPersona[1].nombre,"lala");
	strcpy(arrayPersona[1].apellido,"papa");
	arrayPersona[1].altura=1.10;
	arrayPersona[1].peso=45;

	strcpy(arrayPersona[2].nombre,"lolo");
	strcpy(arrayPersona[2].apellido,"popo");
	arrayPersona[2].altura=1.93;
	arrayPersona[2].peso=71;

	strcpy(arrayPersona[3].nombre,"lili");
	strcpy(arrayPersona[3].apellido,"pipi");
	arrayPersona[3].altura=1.85;
	arrayPersona[3].peso=88;

	strcpy(arrayPersona[4].nombre,"lulu");
	strcpy(arrayPersona[4].apellido,"pupu");
	arrayPersona[4].altura=1.73;
	arrayPersona[4].peso=70;


	for(i=0;i<CANTIDAD_PERSONA;i++)
		{
			if(i==0 || arrayPersona[i].altura > alturaMaxima)
			{
				alturaMaxima =  arrayPersona[i].altura;
				indiceAlturaMaxima=i;
			}

			if(i==0 ||arrayPersona[i].peso > pesoMaximo)
			{
				pesoMaximo = arrayPersona[i].peso;
				indicePesoMaximo=i;

			}
		}

		printf("La persona mas alta es: %s %s con %.2f M y pesa %.2f KL\n",arrayPersona[indiceAlturaMaxima].nombre,arrayPersona[indiceAlturaMaxima].apellido,arrayPersona[indiceAlturaMaxima].altura,arrayPersona[indiceAlturaMaxima].peso);
		printf("La persona mas pesada es: %s %s con %.2f M y pesa %.2f KL",arrayPersona[indicePesoMaximo].nombre,arrayPersona[indicePesoMaximo].apellido,arrayPersona[indicePesoMaximo].altura,arrayPersona[indicePesoMaximo].peso);
	return EXIT_SUCCESS;
}
