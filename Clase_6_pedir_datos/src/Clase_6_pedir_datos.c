 /*
 ============================================================================
 Name        : Clase_6_pedir_datos.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "array_pedir.h"
# define TAM 5

int main(void) {
setbuf(stdout, NULL);

int numero;

pedirNumero(&numero, "Ingrese un numero: ");

	return EXIT_SUCCESS;
}
