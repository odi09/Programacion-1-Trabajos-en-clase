/*
 * salon.c
 *
 *  Created on: 17 oct. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "utn.h"
#include "salon.h"
#define LEN_ARRAY_SALON 100
static int generarId(void);

eSalon* salon_malloc ()
{
	eSalon* pSalon;
	pSalon = (eSalon*)malloc(sizeof(eSalon));
	return pSalon;
}
/**\brief Inicializa todas las posiciones colocando un 0 de ocupado.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int initSalon(eSalon* pSalon[], int largo)
{
	int retorno = 0;
	int i;
	if(pSalon != NULL && largo > 0)
	{
		for(i = 0; i < largo; i++)
		{
			pSalon[i] = NULL;
		}
		retorno = 1;
	}

	return retorno;
}
/**\brief Busca un espacio libre.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param auxEspacio. La direccion de memoria de un espacio disponible.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int posicionLibre(eSalon* pSalon[], int largo, int* auxPosicion)
{
	int retorno = 0;
	int i;
	if( pSalon != NULL && auxPosicion != NULL && largo > 0)
	{
		for(i = 0; i < largo; i++)
		{
			if(pSalon[i] == NULL)
			{
				*auxPosicion = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
/**\brief Pide al usuario cargar los datos.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param auxNombre[]. La direccion de memoria de un array.
 * param auxDireccion[]. La direccion de memoria de un array.
 * param auxTipo. Recibe el tipo de sala.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int alta(eSalon* pSalon, char nombre[], char direccion[], int tipo)
{
	int retorno = 0;
	if(pSalon != NULL && nombre != NULL && direccion != NULL && tipo > 0 )
	{
		pSalon->id = generarId();
		pSalon->tipo = tipo;
		strncpy(pSalon->nombre, nombre, LEN_ARRAY_SALON);
		strncpy(pSalon->direccion, direccion, LEN_ARRAY_SALON);
		retorno = 1;
	}
	return retorno;
}
/**\brief Da de baja a una sala.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Largo del array.
 * param id es el id del empleado que se desea dar de baja.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int baja(eSalon* pSalon[], int largo, int id, char* pMensaje)
{
	int retorno = 0;
	int i;
	if(pSalon != NULL && largo > 0 && id > 0 && buscarId(pSalon, largo, id)>= 0 )
	{
		for(i = 0; i < largo; i++)
		{
			if(pSalon[i] != NULL && pSalon[i]->id == id)
			{
				free(pSalon[i]);
				printf("%s", pMensaje);
				retorno = 1;
				pSalon[i]= NULL;
				break;
			}
		}
	}
	else
	{
		printf("ID no encontrado.\n");
	}
	return 	retorno;
}
/**\brief Busca un id.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Largo del array.
 * param id. Es el id que desea buscar el usuario.
 * param Retorna la posicion del del id que se busca.
 */
int buscarId(eSalon* pSalon[], int largo, int id)
{
	int retorno = 0;
	int i;
	if(pSalon != NULL && largo > 0 && id > 0)
	{
		retorno = -1;
		for(i = 0; i < largo; i++)
		{
			if(pSalon[i] != NULL && pSalon[i]->id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/**\brief Muestra solo una sala dado de alta.
 * param salon[]. La direccion de memoria de una posicion del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int imprimirUnSalon(eSalon* pSalon)
{
	int retorno = 0;

	if (pSalon != NULL)
	{
		printf("-Nombre: %s - Direccion: %s - Tipo de Sala: %d - Id: %d\n\n",
				pSalon->nombre, pSalon->direccion, pSalon->tipo, pSalon->id);
		retorno = 1;
	}
	return retorno;
}
/**\brief Muestra todas las sala dado de alta.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int imprimirTodaslasSalas(eSalon* pSalon[], int largo)
{
	int retorno=0;
	int i;
	if(pSalon != NULL && largo > 0)
	{
		for(i=0;i<largo;i++)
		{

			if(pSalon[i] != NULL)
			{
				printf("%d_Nombre de la Sala: %s - Direccion: %s - Tipo de Sala: %d - Id: %d\n"
						,i+1, pSalon[i]->nombre, pSalon[i]->direccion, pSalon[i]->tipo, pSalon[i]->id);
				retorno = 1;
			}
		}
	}
	return retorno;
}
/**\brief .
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int hayAlgunSalon(eSalon* pSalon[], int largo)
{
	int retorno=0;
	int i;
	if(pSalon != NULL && largo > 0)
	{
		for(i=0;i<largo;i++)
		{

			if(pSalon[i] != NULL)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
/*int alta_forzada(eSalon salon[], char nombre[], char direccion[], int tipo)
{
	int retorno = 0;

	if(salon != NULL && nombre != NULL && direccion != NULL && tipo > 0 )
	{
		salon->id = generarId();
		salon->isEmpty = 1;
		salon->tipo = tipo;
		strncpy(salon->nombre, nombre, LEN_ARRAY_SALON);
		strncpy(salon->direccion, direccion, LEN_ARRAY_SALON);
		retorno = 1;
	}
	return retorno;
}*/

static int generarId(void)
{
	static int contador = 1;
	return contador++;
}


