/*
 * Alumno.h
 *
 *  Created on: 26 abr. 2021
 *      Author: ojose
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

typedef struct
{
	int legajo;
	int edad;
	char apellido[60];
	int isEmpty;
}Alumno;

int imprimirArrayAlumno(Alumno* pArray, int limite);
int inicializoArrayAlumno(Alumno* pArray, int limite);

#endif /* ALUMNO_H_ */
