/*
 * pantalla.c
 *
 *  Created on: 7 oct. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "pantalla.h"
//#include "contratar.h"
#include "informes.h"
#include "utn.h"
static int idDisplay(void);

int disp_initList(eDisplay displaysList[], int len )
{
	int i;
	int retorno = 0;
	if(displaysList != NULL && len >0)
	{
		retorno = 1;
		for(i = 0; i < len; i++)
			{
				displaysList[i].flagEmpty = 1;
			}
	}
	return retorno;
}

int disp_isFree(eDisplay Display[], int len, int* spacefree)
{
	int retorno = 0;

	if(Display != NULL && len > 0 && spacefree != NULL)
	{
		for(int i = 0; i < len ; i++)
		{
			if(Display[i].flagEmpty == 1)
			{
				*spacefree = i;
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}
int disp_loadDisplay(eDisplay Display[])
{
	int auxType;
	int retorno = 0;
	float auxPrice;
	char auxName[128];
	char auxAdress[128];

	if(Display != NULL)
	{
		setbuf(stdout, NULL);
			if (pedirEntero(&auxType, 0, 1, 3, "_Ingrese 1 para una pantalla LCD O 0 para una pantalla LED: ", "ERROR ingrese una pantalla valida") == 1)
					{
						if(pedirFlotante(&auxPrice,0,10000, 3, "_Ingrese precio de la pubicidad: ", "ERROR el precio ingresado no es correcto")== 1)
							{
							if(pedirDireccion(auxName, sizeof(auxName), 3, "_Ingrese nombre Cliente: ", "ERROR el nombre es incorrecto") == 1)
								{
								if(pedirDireccion(auxAdress, sizeof(auxAdress), 3, "_Ingrese direccion de la pantalla: ", "ERROR la direccion es incorrecto") == 1)
									{
									Display->type = auxType;
									Display->id = idDisplay();
									Display->price = auxPrice;
									strncpy(Display->name,auxName, sizeof(Display->name));
									strncpy(Display->address, auxAdress, sizeof(Display->address));
									Display->flagEmpty = 0;
									retorno = 1;
									}
								}
							}
						}
		}

return retorno;
}

int searchIdDisplays(eDisplay displaysList[], int len, int auxId)
{
	int retorno = 0;
	int i;

	if(displaysList != NULL && len > 0)
	{

			for(i = 0; i<len ; i++)
			{
				if(displaysList[i].id == auxId && displaysList[i].flagEmpty == 0)
				{
					retorno = i;
				}
				else
				{
					retorno = -1;
				}
			}
	}
	return retorno;
}

int listarId(eDisplay displaysList[], int len)
{
	int retorno = 0;
	int i;

	if(displaysList != NULL && len > 0)
	{
		printf("\n**Lista de ID VALIDOS**\n");

			for(i = 0; i<len ; i++)
			{
				if(displaysList[i].id > 0 && displaysList[i].flagEmpty == 0)
				{
					printf("-%d-\n", displaysList[i].id);
					retorno = 1;
				}
			}
	}
	return retorno;
}

int disp_modiDateDisp(eDisplay displaysList[], int len)
{
	int retorno = 0;
	int auxId;
	int auxType;
	float auxPrice;
	char auxName[128];
	char auxAdress[128];
	int i;

	if(displaysList != NULL && len > 0)
	{
			if(pedirEntero(&auxId, 0, 100, 2, "ID de la pantalla que desea modificar: ", "ERROR ingrese una ID valida")==1)
				{
				if(searchIdDisplays(displaysList, len, auxId) != -1)
				{
					listarId(displaysList, len);
					pedirEntero(&auxId, 0, 100, 2, "ERROR ingrese una ID dado de alta: ", "ERROR ingrese una ID valida");
				}

				for(i = 0; i < len; i++)
					{
							if (pedirEntero(&auxType, 0, 1, 2, "_Ingrese 1 para una pantalla LCD O 0 para una pantalla LED: ", "ERROR ingrese una pantalla valida") == 1)
							{
							if(pedirFlotante(&auxPrice, 0, 10000, 2, "_Ingrese precio de la pubicidad: ", "ERROR el precio ingresado no es correcto")== 1)
								{
								if(pedirDireccion(auxName, sizeof(auxName), 2, "_Ingrese nombre Cliente: ", "ERROR el nombre es incorrecto") == 1)
									{
									if(pedirDireccion(auxAdress, sizeof(auxAdress), 2, "_Ingrese direccion de la pantalla: ", "ERROR la direccion es incorrecto") == 1)
										{
										displaysList->type = auxType;
										displaysList->price = auxPrice;
										strncpy(displaysList->name,auxName, sizeof(displaysList->name));
										strncpy(displaysList->address, auxAdress, sizeof(displaysList->address));
										retorno = 1;
										}
									}
								}
							}

					break;
					}
				}

	}
	return retorno;
}

int unsubDisplay(eDisplay displaysList[], int len)
{
	int retorno = 0;
	int auxId;
	int i;

		if(pedirEntero(&auxId, 0, 100, 2, "Seleccione ID de la pantalla que desea dar de baja: ", "ERROR ingrese una ID valida")==1)
			{
			searchIdDisplays(displaysList, len, auxId);
			for(i = 0; i < len; i++)
				{
				if(displaysList[i].flagEmpty == 0 && displaysList[i].id == auxId)
					{
					displaysList[i].flagEmpty = 1;
					break;
					retorno = 1;
					}
				}
			}

	return retorno;

}

int printDisplays(eDisplay displaysList[], int len)
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
				printOneDisp(&displaysList[i]);
				//printf("%d_La Patalla seleccionada es: %d\n%d_El Precio es: %.2f\n%d_La Direccion es: %s\n%d_El ID de la pantalla es: %d\n%d_El nombre del cliente es: %s"
				//		,contador, displaysList[i].type,contador, displaysList[i].price,contador, displaysList[i].address,contador, displaysList[i].id,contador, displaysList[i].name);
				retorno = 1;
				}
			}
	}
	return retorno;
}

int printOneDisp(eDisplay display[])
{
int retorno = 0;

if(display != NULL)
{
	if( display->flagEmpty== 0)
	{
		printf("_El tipo de Patalla seleccionada es: %d\n_El Precio es: %.2f\n_La Direccion es: %s\n_El ID de la pantalla es: %d\n_El nombre del cliente es: %s\n"
								, display->type, display->price, display->address, display->id, display->name);
	}

}

return retorno;
}

static int idDisplay(void)
{
	static int contador = 1;
	return contador++;
}
