/*
 * char.h
 *
 *  Created on: 7 sep. 2021
 *      Author: ojose
 */

#ifndef CHAR_H_
#define CHAR_H_

char pedirCaracter(char* pChar, char pMin, char pMax, int reintento, char* pTexto, char* pTextoError);
int pedirEntero(int* pInt, int min, int max, int reintento, char* pTexto, char* pTextoError);
float pedirFlotante(float* pFloat, int min, int max, int reintento, char* pTexto, char* pTextoError);


#endif /* CHAR_H_ */
