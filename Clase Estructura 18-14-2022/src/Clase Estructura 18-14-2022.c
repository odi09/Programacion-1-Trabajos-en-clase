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

typedef struct
	{
		int codigo;
		char nombre[20];
		char apellido[20];
		int horarioSalida;
	}eTicker;

eTicker pedirDatos();
void MostrarUnTicker( eTicker unTicker);

int main(void) {
	setbuf(stdout, NULL);


	eTicker unVuelo = {1000, "Juan", "Gomez", 17}; // esta harcodeado
	eTicker uVuelo;

	MostrarUnTicker(unVuelo);

	uVuelo = pedirDatos();
	MostrarUnTicker(uVuelo);

	return EXIT_SUCCESS;
}

eTicker pedirDatos()
{
	eTicker unTicker;
	printf("Ingrese codigo del vuelo: ");
	scanf("%d",&unTicker.codigo );

	printf("Ingrese nombre del vuelo: ");
	fflush(stdin);
	scanf("%s",unTicker.nombre );

	printf("Ingrese apellido del vuelo: ");
	fflush(stdin);
	scanf("%s",unTicker.apellido );

	printf("Ingrese horario de salida: ");
	scanf("%d",&unTicker.horarioSalida );

	return unTicker;
}

void MostrarUnTicker(eTicker unTicker)
{
	printf("%d %s %s %d\n",unTicker.codigo, unTicker.nombre, unTicker.apellido, unTicker.horarioSalida);
}
