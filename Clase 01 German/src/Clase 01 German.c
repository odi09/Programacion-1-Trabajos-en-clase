/*
 ============================================================================
 Name        : Clase.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
setbuf(stdout, NULL);
/*int numUno;
    int numDos;
    int resultado;
    printf("Ingree el primer numero: ");
    scanf("%d", &numUno);
    printf("Ingrese el segurndo numero: ");
    scanf("%d", &numDos);
    resultado = numUno + numDos;
    printf("La suma entre %d y %d da el resultado %d", numUno, numDos, resultado);*/

    /*int numeUno;
    int numeDos;
    int numeTres;
    printf("Ingrese el primer numero: ");
    scanf("%d",&numeUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d",&numeDos);

    printf("Ingrese el tercero numero: ");
    scanf("%d",&numeTres);

    if(numeUno>numeDos && numeUno>numeTres)
    {
        printf("El mayor de los numeros es el Primero.");
    }
    if(numeDos>numeUno && numeDos>numeTres)
    {
      printf("El mayor de los numeros es el Segundo.");
    }
    else
    {
        printf("El mayor de los numero es el Tercero");
    }*/
    int uno;
    int dos;
    int tres;

    printf("Ingrese el primer numero: ");
    scanf("%d",&uno);

    printf("Ingrese el segundo numero: ");
    scanf("%d",&dos);

    printf("Ingrese el tercero numero: ");
    scanf("%d",&tres);

    if((uno > dos && uno < tres)||(uno < dos && uno > tres))
    {
        printf("%d %d %d el %d es del medio", uno, dos, tres, uno);
    }

    if((dos > uno && dos < tres)|| (dos < uno && dos > tres))
    {
        printf("%d %d %d el %d es del medio", uno, dos, tres, dos);
    }
    if((tres > uno && tres < dos)||(tres < uno && tres > dos))
    {
        printf("%d %d %d el %d es del medio", uno, dos, tres, tres);
    }
    if(uno == dos || uno == tres || dos == uno || dos == tres || tres == uno || tres == dos)
    {
        printf("%d %d %d no hay numero del medio", uno, dos, tres);
    }
	return EXIT_SUCCESS;
}
