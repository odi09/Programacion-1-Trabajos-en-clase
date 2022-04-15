/*
 * contratar.h
 *
 *  Created on: 13 oct. 2021
 *      Author: ojose
 */

#ifndef CONTRATAR_H_
#define CONTRATAR_H_

typedef struct{
	int idContratacion;
	int idPatalla;
	int cantDias;
	int isEmpty;// 0 ocupado y 1 vacio
	char cuit[128];
	char nomArchivo[128];
}eContract;

int contra_initList(eContract contractList[], int len );
int contra_loadContract(eContract contractList[]);

#endif /* CONTRATAR_H_ */
