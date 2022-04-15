/*
 ============================================================================
 Name        : CodigoFcilito.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct
{
	char nombre[20];
	char *Pname;
}dog;

int main(void) {
	setbuf(stdout, NULL);

dog perros[2];
int size;

//fflush(stdin);

for(int i=0;i<2; i++)
{
	printf("Ingrese el nombre del perro: ");
	fgets(perros[i].nombre, 20, stdin); // nueva linea usando fgets en vez de scanf
	size = strlen(perros[i].nombre);
	printf("EL tamaño es %d\n", size);
	perros[i].Pname= malloc(size * sizeof(char)); // asigno memoria
	if(NULL == perros[i].nombre)
	{
		printf("No se pudo reservar memoria");
	}
	else
	{
		strcpy(perros[i].Pname, perros[i].nombre);
	}
}
for(int i = 0;i<2; i++)
{
	printf("El nombre del perros es %s\n", perros[i].Pname);
	free(perros->Pname); // libero espacio
}
	return EXIT_SUCCESS;
}*/
typedef struct
{
	char *nombre;
	struct nodo *sig;
}nodo;
nodo *listaLibro(nodo *lista)
{
	lista = NULL;
	return lista;
}
int main(void) {
	nodo *lista = listaLibro(lista);
	printf("%p\n", lista);
	return EXIT_SUCCESS;
}
