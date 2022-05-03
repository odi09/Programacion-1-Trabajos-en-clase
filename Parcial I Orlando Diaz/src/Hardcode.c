/*
 * Hardcode.c
 *
 *  Created on: 1 may. 2022
 *      Author: ojose
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "album.h"
#include "Hardcode.h"
#define LIBRE 0
static int IdGenero(void);
static int IdArtista(void);
static int IdTipo(void);

/**\brief Harcodea los Genero Musicales.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array que se le pasa a las fuciones que piden caracteres.
 * param retorno  Retorna 1 se logra copian todos los datos y 0 si No lo logra.
 */
int  harcodeoGenero(eGenero lista[], int tam)
{
	int retorno =0;
	//int  auxiIdGenero[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	char auxiGenero[][51]= {"Musica Clasica","Blues","Jazz","Rock and Roll","Gospel","Soul","Rock","Metal","Disco","House","Reggae","Salsa","Flamenco","Hip Hop","Reggaeton"};

	if(lista != NULL && tam > 0)
	{
		for(int i =0;i<tam; i++)
		{
			lista[i].idGenero = IdGenero();
			strncpy(lista[i].descripGenero, auxiGenero[i], sizeof(lista[i].descripGenero));
			retorno = 1;
		}
	}
return retorno;
}
/**\brief Harcodea los Nombre de los Artistas.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array que se le pasa a las fuciones que piden caracteres.
 * param retorno  Retorna 1 se logra copian todos los datos y 0 si No lo logra.
 */
int  harcodeoArtista(eArtista lista[], int tam)
{
	int retorno =0;
	char auxiArtista[][51]= {"Mana","Adele","Amy Winehouse","Elvis Presley","Oscar de Leon","Metalica","Gustavo Cerati","Daddy Yankee",
			                 "Luis Miguel","Juan Gabriel","Rosali","Chayanne","Miranda","Madero Show","Billie Eilish"};

	if(lista != NULL && tam > 0)
	{
		for(int i =0;i<tam; i++)
		{
			lista[i].idArtista = IdArtista();
			strncpy(lista[i].nombreArtista, auxiArtista[i], sizeof(lista[i].nombreArtista));
			retorno = 1;
		}
	}
return retorno;
}

int  harcodeoTipo(eTipoArt lista[], int tam)
{
	int retorno =0;
	char auxiTipo[][10]={"Solista","Banda"};
	if(lista!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			lista[i].idTipoArt = IdTipo();
			strncpy(lista[i].descripTipo, auxiTipo[i], sizeof(lista[i].descripTipo));
			retorno = 1;
		}
	}
return retorno;
}
static int IdGenero(void)
  {
  	static int contador = 1;
  	return contador++;
  }
 static int IdArtista(void)
   {
   	static int contador = 1;
   	return contador++;
   }
 static int IdTipo(void)
    {
    	static int contador = 1;
    	return contador++;
    }

