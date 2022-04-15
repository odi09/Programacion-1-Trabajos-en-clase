/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: ojose
 */

#ifndef UTN_H_
#define UTN_H_

int pedirDatos( int* pNum1, int* pNum2, char* pTexto1, char* pTexto2);
int pedirOperacion(char* pOperacion,char* pTexto3);
int suma(int* pNum1,int* pNum2, float* pResultado);
int resta(int* pNum1,int* pNum2, float* pResultado);
int multiplicacion(int* pNum1,int* pNum2, float* pResultado);
float division(int pNum1, int pNum2, float* pResultado);

#endif /* UTN_H_ */
