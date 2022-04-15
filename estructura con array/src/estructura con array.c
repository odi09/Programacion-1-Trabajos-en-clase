/*
 ============================================================================
 Name        : estructura.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "pantalla.h"
#include "contratar.h"
#include "informes.h"
#include "utn.h"
#define DISPLAYS_LEN 100
#define CONTRACT_LEN 1000

int main(void) {
	setbuf(stdout, NULL);

	eDisplay displayList[DISPLAYS_LEN];
	eContract contractList[CONTRACT_LEN];
	int inicializarPant;
	int inicializarContra;
	int posicionLibre;
	int opcion;
	char auxCuit[128];

	inicializarPant = disp_initList(displayList, DISPLAYS_LEN);
	inicializarContra = contra_initList(contractList, CONTRACT_LEN);

	do{
		if(inicializarPant == 1 && inicializarContra == 1)
		{
			if(pedirEntero(&opcion, 0, 10, 3, "\nSeleccione una opcion: \n"
			"                          1.Alta de pantalla.\n"
			"                          2.Modificar datos de la pantalla.\n"
			"                          3.Baja de la pantalla.\n"
			"                          4.Imprimir pantalla.\n"
			"                          5.Contratar publicidad.\n"
			"                          6.Cancelar publicidad.\n"
			"                          7.consultar facturacion.\n"
			"                          8.Imprimir las contrataciones.\n"
			"                          9.Imprimir infomenes.\n"
			"                          0.Salir\n", "ERROR ingreso una opcion invalida.")== 1)
				{
				switch(opcion)
				{
				case 1:
					disp_isFree(displayList, DISPLAYS_LEN, &posicionLibre);
					disp_loadDisplay(&displayList[posicionLibre]);
					break;
				case 2:
					disp_modiDateDisp(displayList, DISPLAYS_LEN);
					break;
				case 3:
					unsubDisplay(displayList, DISPLAYS_LEN);
					break;
				case 4:
					printDisplays(displayList, DISPLAYS_LEN);
					break;
				case 5:
					printDisplays(displayList, DISPLAYS_LEN);
					contra_loadContract(contractList);
					break;
				case 6:
					//printDisplays(displayList, DISPLAYS_LEN);
					info_imprimirPantContraPorCuit(contractList, CONTRACT_LEN, displayList, DISPLAYS_LEN, &auxCuit);
					break;

				}
				}
			}
		}while(opcion != 0);
	return EXIT_SUCCESS;
}
