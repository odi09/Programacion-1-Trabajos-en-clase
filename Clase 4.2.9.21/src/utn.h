/*
 * utn.h
 *
 *  Created on: 7 sep. 2021
 *      Author: ojose
 */

#ifndef UTN_H_
#define UTN_H_

int SumarEnteros(int num1, int num2);
int RestaEnteros(int num1, int num2);
int MultiplicacionEnteros(int num1, int num2);
int DivisionEnteros(int num1, int num2, float* resultado);
int pedirDatos(float* pNumero, float pMin, float pMax, int reintento, char* pTexto, char* pTextoError);
void imprimirResultado(int num1);


#endif /* UTN_H_ */
