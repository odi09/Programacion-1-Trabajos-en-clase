/*
 ============================================================================
 Name        : Practica.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
char nombre[30];
char apellido[40];
int identificador;
int saldo;
}cuenta;

void imprimir_datos(cuenta* b)
{
printf("El nombre del cliente es %s, su apellidos es %s, su Id es %d y su saldo es %d", b->nombre,b->apellido, b->identificador, b->saldo);
}

int main(void) {
setbuf(stdout, NULL);

cuenta c;

strcpy(c.nombre, "Jose");
strcpy(c.apellido, "Garcia");
c.identificador = 123;
c.saldo = 400;
imprimir_datos(&c);
return EXIT_SUCCESS;
}
