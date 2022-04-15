/*
 ============================================================================
 Name        : tp-1.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculo_costo.h"
#include "utn.h"
#include "subMenu.h"
#include "llamadoAfuncion.h"
int main(void) {
	setbuf(stdout, NULL);

	int menu;
	float kilometros;
	float precioAero;
	float precioLatam;
	float kmCarga = 7090;
	float precioAeroCarga = 162965;
	float precioLatamCarga = 159339;
	float precioBitcion = 4606954.55;
	float result[9];
	float resultCarga[9];
	int flag = 0;

	do
	{
		if(pedirEntero(&menu, 1, 6, 3
		   ,"Ingrese una opcion.\n1. Ingrese Kilometros.\n2. Ingrese Precios de los Vuelos.\n3. Calcular todos los costos.\n4. Informar Resultados.\n5. Carga forzada de datos.\n6. Salir.\n"
		   ,"****No esta ingresando un numero entre 1 y 6.****\n")== 1)
		{
			fflush(stdin);
			switch(menu)
			{
			case 1:
				if(flag == 0 && (pedirFlotante(&kilometros, 1, 3, "Ingresar Kilometros: \n", "El numero que ingreso no es valido.\n")) == 1)
					{
					flag = 1;
					}
				else
					{
						printf("****No ingreso un numero invalido.****\n\n");
					}
				break;
			case 2:
				if(flag == 1 && (subMenu("a. Precio vuelo Aerolineas. ","b. Precio vuelo Latam. ",
										 "Ingrese Precio en Aerolineas: ", "Ingrese Precio en Latam: ",
										 "Ingrese precio de los vuelos para Aerolineas y Latam.\n",
										 "El numero que ingreso no es valido.\n",
										 "NO se puedo validar el precio\n", &precioAero, &precioLatam) == 1))
					{
						flag = 2;
					}
					else
					{
						printf("****No puede ingresar el precios sin los KM.****\n\n");
					}
				break;
			case 3:
				if((llamadoAFuciones(&kilometros, &precioAero, &precioLatam, &precioBitcion, &result[0], &result[1],
									&result[2], &result[3], &result[4], &result[5], &result[6], &result[7], &result[8]) == 1) && flag == 2)
					{
						printf("****Se calcularon los costo. Puede tomar la opcion 4 para imprimir.****\n\n");
						flag = 3;
					}
					else
					{
						printf("****No puedes calcular sin cargar los DATOS.****\n\n");
					}
				break;
			case 4:
				if(flag == 3)
					{
					printf("KMs Ingresados: %.2f\n", kilometros);
					printf("Precio Aerolineas: $%.2f\n", precioAero);
					printf("a) El precio con tarjeta de debito: $%.2f\n", result[0]);
					printf("b) El precio con tarjeta de credito: $%.2f\n", result[1]);
					printf("c) Precio pagando con bitcoin: %.8f BTC\n", result[2]);
					printf("d) Mostrar precio unitario: $%.2f\n\n", result[3]);
					printf("Precio Latam: $%.2f\n", precioLatam);
					printf("a) El precio con tarjeta de debito: $%.2f\n", result[4]);
					printf("b) El precio con tarjeta de credito: $%.2f\n", result[5]);
					printf("c) Precio pagando con bitcoin: %.8f BTC\n", result[6]);
					printf("d) Mostrar precio unitario: $%.2f\n\n", result[7]);
					printf("La diferencia de precio es: $%.2f\n\n", result[8]);
					}
					else
					{
						printf("****No puedes imprimir sin calcular los DATOS.****\n\n");
					}
				break;
			case 5:
				if(llamadoAFuciones(&kmCarga, &precioAeroCarga, &precioLatamCarga, &precioBitcion, &resultCarga[0],
									&resultCarga[1], &resultCarga[2], &resultCarga[3], &resultCarga[4], &resultCarga[5],
									&resultCarga[6], &resultCarga[7], &resultCarga[8]) == 1)
					{
						printf("KMs Ingresados: %.2f\n", kmCarga);
						printf("Precio Aerolineas: $%.2f\n", precioAeroCarga);
						printf("a) El precio con tarjeta de debito: $%.2f\n", resultCarga[0]);
						printf("b) El precio con tarjeta de credito: $%.2f\n", resultCarga[1]);
						printf("c) Precio pagando con bitcoin: %.8f BTC\n", resultCarga[2]);
						printf("d) Mostrar precio unitario: $%.2f\n\n", resultCarga[3]);
						printf("Precio Latam: $%.2f\n", precioLatamCarga);
						printf("a) El precio con tarjeta de debito: $%.2f\n", resultCarga[4]);
						printf("b) El precio con tarjeta de credito: $%.2f\n", resultCarga[5]);
						printf("c) Precio pagando con bitcoin: %.8f BTC\n", resultCarga[6]);
						printf("d) Mostrar precio unitario: $%.2f\n\n", resultCarga[7]);
						printf("La diferencia de precio es: $%.2f\n\n", resultCarga[8]);
					}
				break;
			case 6:
				printf("Adios!\n");
				break;
			}
		}
	}
	while(menu != 6);

	return EXIT_SUCCESS;
}
