/*
 * contratar.c
 *
 *  Created on: 13 oct. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "pantalla.h"
#include "contratar.h"
#include "informes.h"
#include "utn.h"
static int idContract(void);

int contra_initList(eContract contractList[], int len)
{
	int i;
	int retorno = 0;
	if(contractList != NULL && len >0)
	{
		for(i = 0; i < len; i++)
			{
			contractList[i].isEmpty = 1;
				retorno = 1;
			}
	}
	return retorno;
}

int contra_loadContract(eContract contractList[])
{
	int auxIdPant;
	int retorno = 0;
	int auxDias;
	char auxCuit[128];
	char auxNomArch[128];


	if(contractList != NULL)
	{
		setbuf(stdout, NULL);


		if (pedirEntero(&auxIdPant, 0, 1000, 3, "_Ingrese ID de la pantalla que desea contratar: ", "ERROR ingrese un ID ERRADO") == 1)
		{
			if(pedirEntero(&auxDias, 0, 100, 3, "_Ingrese cantidad de Dias que desea contratar la publicidad: ", "ERROR los dias no son Validos")== 1)
				{
				if(pedirDireccion(auxCuit,sizeof(auxCuit), 3, "_Ingrese CUIT del cliente: ", "ERROR ingrese un CUIT ERRADO") == 1)
					{
					if(pedirDireccion(auxNomArch, sizeof(auxNomArch), 3, "_Ingrese nombre del Archivo: ", "ERROR el nombre ingrasado es incorrecto") == 1)
						{
						contractList->idPatalla = auxIdPant;
						contractList->idContratacion = idContract();
						contractList->cantDias = auxDias;
						strncpy(contractList->cuit, auxCuit, sizeof(contractList->cuit));
						strncpy(contractList->nomArchivo, auxNomArch, sizeof(contractList->nomArchivo));
						contractList->isEmpty = 0;
						retorno = 1;
						}
					}
				}
			}
		}

return retorno;
}

/*
int printDisplays(Contract contractList[], int len)
{
	int retorno = 0;
	int contador = 0;
	int i;

	if(displaysList != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
			{
			contador++;
			if(displaysList[i].flagEmpty == 0)
				{
				printf("%d_La Patalla seleccionada es: %d\n%d_El Precio es: %.2f\n%d_La Direccion es: %s\n%d_El ID de la pantalla es: %d\n%d_El nombre del clIente es: %s"
						,contador, displaysList[i].type,contador, displaysList[i].price,contador, displaysList[i].address,contador, displaysList[i].id,contador, displaysList[i].name);
				retorno = 1;
				}
			}
	}
	return retorno;
}
*/
/*
int unsubDisplay(eContract contractList[], int len)
{
	int retorno = 0;
	int auxId;
	int i;


		if(pedirEntero(&auxId, 0, 100, 2, "Seleccione ID de la pantalla que desea dar de baja: ", "ERROR ingrese una ID valida")==1)
			{
			for(i = 0; i < len; i++)
				{
				if(contractList[i].idContratacion == 0 && contractList[i].idPatalla == auxId)
					{
					contractList[i].idContratacion = 1;
					break;
					retorno = 1;
					}
				}
			}

	return retorno;

}*/
static int idContract(void)
{
	static int contador = 1;
	return contador++;
}
