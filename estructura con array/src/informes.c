/*
 * informes.c
 *
 *  Created on: 14 oct. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "pantalla.h"
#include "contratar.h"
#include "utn.h"

int info_imprimirPantContraPorCuit(eContract arrayContract[], int lenContract, eDisplay arrayDisplay[], int lenDisp, char* auxCuit)
{
	int retorno = 0;
	int indexArrayDisplay;
    int i;
	if(arrayContract != NULL && lenContract > 0 && arrayDisplay != NULL && lenDisp > 0 && auxCuit != NULL)
	{
		for(i = 0; i < lenContract; i++)
		{
			if(strncmp(arrayContract[i].cuit, auxCuit, lenContract) == 0)
			{
				indexArrayDisplay = searchIdDisplays(arrayDisplay,lenDisp, arrayContract[i].idPatalla);
				printf("Archivo: %s - Cuit: %s - Dias: %d - IdPantalla: %d", arrayContract[i].nomArchivo, arrayContract[i].cuit, arrayContract[i].cantDias, arrayContract[i].idPatalla);
			}
		}

	}

return retorno;
}
