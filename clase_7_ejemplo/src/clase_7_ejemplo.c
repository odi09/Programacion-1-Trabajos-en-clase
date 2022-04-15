/*
 ============================================================================
 Name        : clase_7_ejemplo.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
setbuf(stdout, NULL);

/*char texto[11];
// scanf("%s",texto); scanf no va usar mas
fgets(texto,11,stdin);
printf("%p", texto);
printf("Ingresastes %s",texto);
*/

char nombre[11]="jose";
char auxiliar[30]="";

strncpy(auxiliar,nombre,sizeof(auxiliar));
//strnlen(auxiliar,sizeof(auxiliar));
//strncat(nombre, "LALA",sizeof(nombre));

//sprintf(auxiliar, "MI SIZE OR ES  %d ",sizeof(auxiliar));

printf("\n%s\n",auxiliar);

printf("SIZE Nombre mide %d----y auxiliar mide %d\n", sizeof(nombre), sizeof(auxiliar));
printf("STRLEN Nombre mide %d----y auxiliar mide %d", strnlen(nombre, sizeof(nombre)), strnlen(auxiliar, sizeof(auxiliar)));

	return EXIT_SUCCESS;
}
