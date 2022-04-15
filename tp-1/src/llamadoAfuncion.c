/*
 * llamadoAfuncion.c
 *
 *  Created on: 14 abr. 2022
 *      Author: ojose
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculo_costo.h"
#include "llamadoAfuncion.h"
/**
 * \brief Llama a las funciones de la biblioteca calculo_costo.
 * \param  pKm recibe el puntero de un float.
 * \param  pPrecioAero recibe la direccion en memoria de un float.
 * \param  pPrecioLatam recibe la direccion en memoria de un float.
 * \param  pPrecioBitcoin recibe la direccion en memoria de un float.
 * \param  pResultado0 recibe la direccion en memoria donde se guardara el resultado la funcion tarjetaDeDebito.
 * \param  pResultado1 recibe la direccion en memoria donde se guardara el resultado la funcion tarjetaDeCredito.
 * \param  pResultado2 recibe la direccion en memoria donde se guardara el resultado la funcion precioConBitcoin.
 * \param  pResultado3 recibe la direccion en memoria donde se guardara el resultado la funcion precioPorKm.
 * \param  pResultado4 recibe la direccion en memoria donde se guardara el resultado la funcion tarjetaDeDebito.
 * \param  pResultado5 recibe la direccion en memoria donde se guardara el resultado la funcion tarjetaDeCredito.
 * \param  pResultado6 recibe la direccion en memoria donde se guardara el resultado la funcion precioConBitcoin.
 * \param  pResultado7 recibe la direccion en memoria donde se guardara el resultado la funcion precioPorKm.
 * \param  pResultado recibe la direccion en memoria donde se guardara el resultado la funcion diferenciaDePrecios.
 * \return retorna 1 si sale todo bien, si no, devuelve 0.
 */
int llamadoAFuciones(float* pKm, float* pPrecioAero, float* pPrecioLatam, float* pPrecioBitcoin,
		             float* pResultado0, float* pResultado1, float* pResultado2, float* pResultado3,
					 float* pResultado4, float* pResultado5, float* pResultado6, float* pResultado7, float* pResultado8){

	int estado;

	if(pKm!=NULL && pPrecioAero!=NULL && pPrecioLatam!=NULL && pPrecioBitcoin!=NULL &&
	   pResultado0!=NULL && pResultado1!=NULL && pResultado2!=NULL && pResultado3!=NULL &&
	   pResultado4!=NULL && pResultado5!=NULL && pResultado6!=NULL && pResultado7!=NULL && pResultado8!=NULL)
		{

			if(tarjetaDeDebito(pKm, pPrecioAero, pResultado0)               ==1
			  && tarjetaDeCredito(pKm, pPrecioAero, pResultado1)            ==1
			  && precioConBitcoin(pPrecioAero, pPrecioBitcoin, pResultado2) ==1
			  && precioPorKm(pKm, pPrecioAero, pResultado3)                 ==1
			  && tarjetaDeDebito(pKm, pPrecioLatam, pResultado4)            ==1
			  && tarjetaDeCredito(pKm, pPrecioLatam, pResultado5)           ==1
			  && precioConBitcoin(pKm, pPrecioBitcoin, pResultado6)         ==1
			  && precioPorKm(pKm, pPrecioLatam, pResultado7)                ==1
			  && diferenciaDePrecios(pPrecioLatam, pPrecioAero, pResultado8)==1)
				{
					estado = 1;
				}
		}
	else
		{
			estado = 0;
		}
	return estado;
}
