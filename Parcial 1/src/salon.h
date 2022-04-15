/*
 * salon.h
 *
 *  Created on: 17 oct. 2021
 *      Author: ojose
 */

#ifndef SALON_H_
#define SALON_H_
typedef struct
{
	char nombre[128];
	char direccion[128];
	int tipo;
	int id;
}eSalon;

eSalon* salon_malloc();
int initSalon(eSalon* pSalon[], int largo);
int alta(eSalon* pSalon, char nombre[], char direccion[], int tipo);
int posicionLibre(eSalon* pSalon[], int largo, int* auxPosicion);
int baja(eSalon* pSalon[], int largo, int id, char* pMensaje);
int buscarId(eSalon* pSalon[], int largo, int id);
int imprimirUnSalon(eSalon* pSalon);
int imprimirTodaslasSalas(eSalon* pSalon[], int largo);
int hayAlgunSalon(eSalon* pSalon[], int largo);

//int alta_forzada(eSalon* salon[], char nombre[], char direccion[], int tipo);

#endif /* SALON_H_ */
