/*
 * subMenu.c
 *
 *  Created on: 14 abr. 2022
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "subMenu.h"
/**
 * \brief Es un subMenu.
 * \param pTexto1 recibe la direccion en memoria de una cadena.
 * \param pTexto2 recibe la direccion en memoria de una cadena.
 * \param pTexto3 recibe la direccion en memoria de una cadena.
 * \param pTexto4 recibe la direccion en memoria de una cadena.
 * \param pTexto5 recibe la direccion en memoria de una cadena.
 * \param pTexto6 recibe la direccion en memoria de una cadena.
 * \param pMensajeError recibe la direccion de memoria de una cadela.
 * \param pPrecio1 recibe la direccion en memoria de un float.
 * \param pPrecio2 recibe la direccion en memoria de un float.
 * \return retorna 1 si sale todo bien, si no, devuelve 0.
 */
int subMenu(char* pTexto1, char* pTexto2, char* pTexto3, char* pTexto4, char* pTexto5, char* pTexto6, char* pMensajeError,float* pPrecio1, float* pPrecio2)
{
	int estado;
	char opcion2;
	int flag = 0;

	if(pTexto1!=NULL && pTexto2!=NULL && pTexto3!=NULL && pTexto4!=NULL && pTexto5!=NULL && pTexto6!=NULL && pMensajeError!=NULL && pPrecio1!=NULL && pPrecio2!=NULL)
		{
			do{
				printf("%s\n", pTexto5);
				printf("%s\n",pTexto1);
				printf("%s\n", pTexto2);
				scanf("%c",&opcion2);
				fflush(stdin);

				if(opcion2 == 'a' && flag == 0)
					{
							if(pedirFlotante(pPrecio1, 1, 3, pTexto3, pTexto6 )!=1)
								{
									printf("%s", pMensajeError);
								}
							flag =1;
					}
				else if(flag == 1 && opcion2 == 'b')
					{
						if(pedirFlotante(pPrecio2, 1, 3, pTexto4, pTexto6)!=1)
							{
								printf("%s", pMensajeError);
							}
						flag = 2;
					}
				else if(opcion2 == 'b' && flag == 0)
					{
						printf("Comience con la opcion 'a'.\n");
					}
		 //fflush(stdin);
			}while(flag != 2);
			estado = 1;
		}
	else
		{
			printf("Hubo un error con la validacion de las variables P\n");
			estado = 0;
		}
	return estado;
}
