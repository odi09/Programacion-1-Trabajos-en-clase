/*
 * calculo_costo.c
 *
 *  Created on: 3 abr. 2022
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
/**
 *
 */
int ingresoDeKilometros(char* pTexto1, float* pNumero)
{
	int estado;
	if(pTexto1!=NULL && pNumero!=NULL)
	{
		if(pedirFlotante(pNumero, 1, 3, pTexto1, "El numero que ingreso no es valido.\n"))
			{
			estado = 1;
			}
		else
			{
				estado = 0;
			}
	}
	else
		{
		    estado = 0;
			printf("Error! No esta funcionando de manera correcta.\n");
		}

	return estado;
}
int ingresoPrecio(char* pTexto1, float* pNumero)
{
	int estado;
	if(pTexto1!=NULL && pNumero!=NULL)
		{
			if(pedirFlotante(pNumero, 1, 3, pTexto1, "El numero que ingreso no es valido.\n")==1)
				{
					estado = 1;
				}
			else
				{
					estado = 0;
				}
		}
	else
		{
		 estado = 0;
		 printf("Error! No esta funcionando de manera correcta.\n");
		}
	return estado;
}
/**
 * \brief Calcula el costo con TDD con el 10% de descuento.
 * \param pKm recibe la direccion en memoria de una variable float que guarda los KM.
 * \param pPrecio recibe la direccion en memoria de una variable float que guarda el precio.
 * \param pResultado recibe la direccion en memoria de una variable float donde se guardara el resultado de la operacion.
 * \return retorna 1 si salio todo bien, si no, devuelve 0.
 */
int tarjetaDeDebito(float* pKm, float* pPrecio,float* pResultado)
{
	int estado;
	float precio;
	float km;
	float result;

	if(pKm!=NULL && pPrecio!=NULL && pResultado!=NULL)
		{
			precio = *pPrecio;
			km = *pKm;
			result= (km*precio)*0.9;
			*pResultado = result;
			estado = 1;
		}
	else
		{
			printf("Error! No esta funcionando de manera correcta.\n");
			estado = 0;
		}
	return estado;
}
/**
 * \brief Calcula el costo con TDC con un recargo del 25%.
 * \param pKm recibe la direccion en memoria de una variable float que guarda los KM.
 * \param pPrecio recibe la direccion en memoria de una variable float que guarda el precio.
 * \param pResultado recibe la direccion en memoria de una variable float donde se guardara el resultado de la operacion.
 * \return retorna 1 si salio todo bien, si no, devuelve 0.
 */
int tarjetaDeCredito(float* pKm, float* pPrecio,float* pResultado)
{
	int estado;
	float precio;
	float km;
	float result;

	if(pKm!=NULL && pPrecio!=NULL && pResultado!=NULL)
		{
			precio = *pPrecio;
			km = *pKm;
			result= (km*precio)*1.25;
			*pResultado = result;
			estado = 1;
		}
	else
		{
			printf("Error! No esta funcionando de manera correcta.\n");
			estado = 0;
		}
	return estado;
}
/**
 * \brief Calcula la diferecnia entre pPrecio1 y pPrecio2.
 * \param pPrecio1 recibe la direccion en memoria de una variable float que guarda el precio.
 * \param pPrecio2 recibe la direccion en memoria de una variable float que guarda el precio.
 * \param pResultado recibe la direccion en memoria de una variable float donde se guardara el resultado de la operacion.
 * \return retorna 1 si salio todo bien, si no, devuelve 0.
 */
int diferenciaDePrecios(float* pPrecio1, float* pPrecio2,float* pResultado)
{
	int estado;
	float precio1;
	float precio2;
	float result;

	if(pPrecio1!=NULL && pPrecio2!=NULL && pResultado!=NULL)
		{
			precio1 = *pPrecio1;
			precio2 = *pPrecio2;
			result= (precio2-precio1);
			*pResultado = result;
			estado = 1;
		}
	else
		{
			printf("Error! No esta funcionando de manera correcta.\n");
			estado = 0;
		}

	return estado;
}
/**
 * \brief Calcula el precio por km.
 * \param pKm recibe la direccion en memoria de una variable float que guarda los KM.
 * \param pPrecio recibe la direccion en memoria de una variable float que guarda el precio.
 * \param pResultado recibe la direccion en memoria de una variable float donde se guardara el resultado de la operacion.
 * \return retorna 1 si salio todo bien, si no, devuelve 0.
 */
int precioPorKm(float* pKm, float* pPrecio,float* pResultado)
{
	int estado;
	float precio;
	float km;
	float result;

	if(pKm!=NULL && pPrecio!=NULL && pResultado!=NULL)
		{
			precio = *pPrecio;
			km = *pKm;
			result= (precio/km);
			*pResultado = result;
			estado = 1;
		}
	else
		{
			printf("Error! No esta funcionando de manera correcta.\n");
			estado = 0;
		}
	return estado;
}
/**
 * \brief Calcula el precio en Bitcoin.
 * \param pPrecio recibe la direccion en memoria de una variable float que guarda el precio.
 * \param pPrecioBitcoin recibe la direccion en memoria de una variable float que guarda el precio de 1 BTC en pesos.
 * \param pResultado recibe la direccion en memoria de una variable float donde se guardara el resultado de la operacion.
 * \return retorna 1 si salio todo bien, si no, devuelve 0.
 */
int precioConBitcoin(float* pPrecio, float* pPrecioBitcoin,float* pResultado)
{
	int estado;
	float precio;
	float bitcoin;
	float result;

	if(pPrecio!=NULL && pPrecioBitcoin!= NULL && pResultado!=NULL)
		{
			precio = *pPrecio;
			bitcoin = *pPrecioBitcoin;
			result= precio/bitcoin;
			*pResultado = result;
			estado = 1;
		}
	else
		{
			printf("Error! No esta funcionando de manera correcta.\n");
			estado = 0;
		}
	return estado;
}
