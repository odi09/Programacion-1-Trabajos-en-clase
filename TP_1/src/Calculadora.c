/*
 * Calculadora.c
 *
 *  Created on: 10 abr. 2021
 *      Author: ojose
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
#include "utn.h"

/**
 *\brief Suma dos flotantes y devuelve un 0 si esta ok.
 *\param pNum1 recibe la direccion de memoria de un flotante.
 *\param pNum2 recibe la direccion de memoria de un flotante.
 *\param pResultado recibe la direccion de memoria donde se guardara el resultado de la operacion.
 *\param pTexto recibe la direccion de memoria de una cadena.
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
float suma(float* pNum1, float* pNum2, float *pResultado, char *pTexto)
{
	int retorno = 1;

	if (pNum1 != NULL && pNum2 != NULL && pResultado != NULL && pTexto != NULL)
	{
		*pResultado = *pNum1 + *pNum2;
		printf("%s %.2f\n", pTexto, *pResultado);

		retorno = 0;
	}
	return retorno;
}
/**
 *\brief Resta dos flotantes y devuelve un 0 si esta ok.
 *\param pNum1 recibe la direccion de memoria de un flotante.
 *\param pNum2 recibe la direccion de memoria de un flotante.
 *\param pResultado recibe la direccion de memoria donde se guardara el resultado de la operacion.
 *\param pTexto recibe la direccion de memoria de una cadena.
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
float resta(float *pNum1, float *pNum2, float *pResultado, char *pTexto)
{
	int retorno = 1;

	if (pNum1 != NULL && pNum2 != NULL && pResultado != NULL && pTexto != NULL)
	{
		*pResultado = *pNum1 - *pNum2;
		printf("%s %.2f\n", pTexto, *pResultado);
		retorno = 0;
	}
	return retorno;
}
/**
 *\brief Multiplica dos flotantes y devuelve un 0 si esta ok.
 *\param pNum1 recibe la direccion de memoria de un flotante.
 *\param pNum2 recibe la direccion de memoria de un flotante.
 *\param pResultado recibe la direccion de memoria donde se guardara el resultado de la operacion.
 *\param pTexto recibe la direccion de memoria de una cadena.
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
float multiplicacion(float *pNum1, float *pNum2, float *pResultado, char *pTexto)
{
	int retorno = 1;

	if (pNum1 != NULL && pNum2 != NULL && pResultado != NULL && pTexto != NULL)
	{
		*pResultado = (*pNum1) * (*pNum2);
		printf("%s %.2f\n", pTexto, *pResultado);

		retorno = 0;
	}
	return retorno;
}
/**
 *\brief Division dos flotantes y devuelve un 0 si esta ok.
 *\param pNum1 recibe la direccion de memoria de un flotante.
 *\param pNum2 recibe la direccion de memoria de un flotante.
 *\param pResultado recibe la direccion de memoria donde se guardara el resultado de la operacion.
 *\param pTexto recibe la direccion de memoria de una cadena.
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
float division(float* pNum1, float* pNum2, float *pResultado, char *pTexto4,char *pTexto5)
{
	int retorno = 1;

	if (pResultado != NULL && pNum1 != NULL && pNum2 != NULL && pTexto4 != NULL && pTexto5 != NULL && *pNum2 != 0)
	{
		*pResultado = *pNum1 / *pNum2;
		printf("%s %.2f\n", pTexto4, *pResultado);
		retorno = 0;
	}
	else
	{
		printf("%s", pTexto5);
	}
	return retorno;
}
/**
 *\brief
 *\param
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
float factorialA(float *pNum1, float *pResultado, char *pTexto) {
	int retorno = 1;
	int fact = 1;
	int i;

	if (pNum1 != NULL && pResultado != NULL && pTexto != NULL && *pNum1 > 0	&& *pNum1 < 20)
	{

		for (i = 1; i <= *pNum1; i++)
		{
			fact = fact * i;
			retorno = 0;
		}

		*pResultado = fact;

		printf("%s%.2f es %.2f\n", pTexto, *pNum1, *pResultado);

	}
	else
	{
		retorno = -2;
	}

	return retorno;
}
/**
 *\brief
 *\param
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
float factorialB(float *pNum2, float *pResultado, char *pTexto)
{
	int retorno = -1;
	float fact = 1;
	int i;

	if (pNum2 != NULL && pResultado != NULL && pTexto != NULL && *pNum2 > 0	&& *pNum2 < 20)
	{
		for (i = 1; i <= *pNum2; i++)
		{
			fact = fact * i;
			retorno = 0;
		}
		*pResultado = fact;

		printf("%s%.2f es %.2f\n", pTexto, *pNum2, *pResultado);
	}

	else
	{
		retorno = -2;
	}

	return retorno;
}
/**
 *\brief
 *\param
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
