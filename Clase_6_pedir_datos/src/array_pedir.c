/*
 * array_pedir.c
 *
 *  Created on: 8 abr. 2021
 *      Author: ojose
 */

#include <stdio.h>
#include <stdlib.h>
#include "array_pedir.h"

int pedirNumero(int* pNum, int* pArray, int tamano, char* pTexto)
{
	int retorno = 1;
if(pNum!=NULL && pArray!=NULL && tamano>0 && pTexto!=NULL )
do{
	printf("%s", pTexto);

	if(scanf("%d",pNum)==1)
	{
		retorno=0;
	}

}while(retorno==0);

	return retorno;
}
