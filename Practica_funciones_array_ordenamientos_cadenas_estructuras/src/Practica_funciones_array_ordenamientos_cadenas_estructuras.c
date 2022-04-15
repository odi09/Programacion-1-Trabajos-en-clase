/*
 ============================================================================
 Name        : Practica_funciones_array_ordenamientos_cadenas_estructuras.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Alumno.h"
#define TAM 5

int main(void) {
setbuf(stdout, NULL);

Alumno auxiliarAlumno;
Alumno arrayAlumnos[TAM];

inicializoArrayAlumno(arrayAlumnos, TAM);
auxiliarAlumno.legajo = 99;
auxiliarAlumno.edad = 33;
strncpy(auxiliarAlumno.apellido,"Perez",sizeof(auxiliarAlumno.apellido));
auxiliarAlumno.isEmpty = 0;

arrayAlumnos[2] = auxiliarAlumno;

imprimirArrayAlumno(arrayAlumnos, TAM);

	return EXIT_SUCCESS;
}

