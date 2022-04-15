/*
 ============================================================================
 Name        : Borrar.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3
#define CUBO(a) a*a*a
//int resta();
/*void cubo (int *n);
void saludos()
{
	printf("Funcion VOID\n");
	return;
}
long factorial(long numero);*/
/*int main(void) {
	setbuf(stdout, NULL);*/

	/*int suma;
	suma = PI +3;*/

	/*int a=3;
	printf("El cubo de la varianles a es: %d", CUBO(a));*/

	//TIPOS DE DATOS//
	/*char c ='y';  // tamaño de 1 byte y su rango es del 0 al 255 segun la tabla ASCII
	printf("%c",c);
	int a = 20; // 2  bytes y va del -32768 al 32767

	short e = -1;// 2bytes y su rango -128 hats 127, es entero corto, su mascara es d.
	unsigned int u = 25; //2 bytes y su rango va desde 0 hasta 65535 es un entero, no incluye los negativos, su mascara es d.
	long l = 5932; // 4 bytes u su rango es desde -2147483648 hasta 2147483647, su mascara es li.
	float f = 72.534; // 4 bytes ,su mascar es f o .2f.
	double d = 12323.877658;// 8 bytes, su mascara es f o lf o .2lf.*/

	//PALABRAS RESERVADAS Y CONVERSION DE TIPOS DE DATOS//
	/*int a = 80;
	float f = 45.3;
	float suma = (float)a+f;
	printf("Entero: %d\nFlotante: %.2f\nDouble: %.3f\nCaracter: %c\n", a,(float)a, (double)a, (char)a);
    printf("El resultado es: %.2f", suma);*/

	//CICLO FOR//
	/*int i;
	for(i = 5; i<=10 ; i++)
	{
	printf("Mi i vale: %d\n", i);
	}*/

	//CICLO WHILE //
	/*int contador = 0;

	while(contador <= 10)
	{
		printf("El contador es: %d\n",contador);
		contador++;
	}*/
	//CICLO DO WHILE//
	/*int contador = 1;

	do{
		printf("El contador es: %d\n",contador);
		contador++;
	}while(contador <= 10);*/

	/////////BREAK AND CONTINUE ////////////////////
	/*int contador = 0;

	do
	{
		//contador++;
		if(contador == 5)
		{
		//continue;
		break;
		}
		//contador++;
		printf("El contador es: %d\n", contador);
		contador++;
	}while(contador<=10);*/

/////////////////SWITCH///////////////
	/*int casos;
	printf("Ingrese un numero: \n");
	scanf("%d",&casos);
	switch(casos)
	{
	case 1:
		printf("Ingreso al primer caso.\n");
		break;
	case 2:
		printf("Ingreso al segundo caso.\n");
			break;
	case 3:
		printf("Ingreso al tercer caso.\n");
			break;
	case 4:
		printf("Ingreso al cuarto caso.\n");
			break;
	default:
		printf("No esta entre las opciones.\n");
		break;
	}*/

	////////////////ARREGLOS//////////////
	/*int sizeA;

	printf("Ingrese el tamaño: \n");
	scanf("%d", &sizeA);
	int edad[sizeA];

	for(int i = 0; i< sizeA; i++)
	{
		printf("Ingrese un valor: \n");
		scanf("%d", &edad[i]);
	}

	for(int i = 0; i<sizeA; i++)
	{
		printf("La edades ingresadas son: %d\n", edad[i]);
	}*/
/////////////////ARRAY MULTIDIMENCIONALES/////////////
/*	int multi [2][3] = {{3,6,9},{2,4,6}};
	printf("%d",multi [1][0]);*/

////////////////////////FUNCIONEAS BASICAS //////////////////////////

/*int num1;
int num2;
saludos();
printf("Ingresa el primer valor: \n");
scanf("%d",&num1);
printf("Ingresa el primer valor: \n");
scanf("%d",&num2);
printf("La resta es: %d", resta(num1, num2));

	return EXIT_SUCCESS;
}
int resta(int num1, int num2)
{
	int resta = num1-num2;
	return resta;
}*/
	/////////////////////FUNCIONES RECURSIVAS//////////////////
/*	int num1;
	printf("Ingresa un numero: \n");
	scanf("%d",&num1);
	for(int i=0; i<=num1;i++)
	{
	printf("%li\n", factorial(i));
	}

	return EXIT_SUCCESS;
}
long factorial(long numero)
{
	if(numero<=1)
	{
		return 1;
	}
	else
	{
		return(numero*factorial(numero-1));
	}
}*/
	///////////////////PUNTEROS//////////////
	/*int a = 2;
	int *puntero = &a;
	printf("El valor es: %d\n",*puntero);
	printf("La direccion es: %p\n",puntero);*/

/*	int num = 5;
	printf("El valos original es: %d\n", num);
	cubo(&num);
	printf("El valor actual es: %d\n", num);
	return EXIT_SUCCESS;
}
void cubo (int *n)
{
	*n = *n * *n * *n;
}*/
	/*typedef struct{
	char nombre[30];
	int edad;
	float peso;
	}perro1;

int main(void) {
	setbuf(stdout, NULL);
	perro1 dog;

	printf("Ingrese nombre del perros: ");
	scanf("%s", &dog.nombre);

	printf("Ingrese edad: ");
	scanf("%d",&dog.edad);

	printf("Ingrese peso: ");
	scanf("%f", &dog.peso);

	printf("Usted ingreso:\nNombre: %s.\nEdad: %d.\nPeso: %.2f", dog.nombre, dog.edad, dog.peso);


	return EXIT_SUCCESS;
}*/
/*typedef struct
{
	char nombre[30];
	int edad;
	float peso;
}perro2;
int main(void) {
	setbuf(stdout, NULL);
	perro2 perros[3];

	for(int i = 0; i<3; i++)
	{
		printf("%i-Ingrese el NOMBRE del perro: ",i+1);
		scanf("%s",perros[i].nombre);
		printf("%i-Ingrese la EDAD del perro: ",i+1);
		scanf("%d",&perros[i].edad);
		printf("%i-Ingrese el PESO del perro: ",i+1);
		scanf("%f",&perros[i].peso);
	}
	for(int i = 0; i<3; i++)
	{
		printf("%d-El NOMBRE del perro: %s\n", i+1, perros[i].nombre);
		printf("%d-El EDAD del perro: %d\n", i+1, perros[i].edad);
		printf("%d-El PESO del perro: %.2f\n",i+1,  perros[i].peso);

	}

	return EXIT_SUCCESS;
}*/
/*typedef struct
{
	char nombre[20];
	char direccion[20];
}dueno;

typedef struct
{
	char nombre[20];
	int edadmeses;
	float peso;
	dueno propietario;
}perro3;

int main(void) {
	setbuf(stdout, NULL);

	perro3 perros[2];

	for(int i=0; i<2; i++)
	{
		printf("%i-Nombre del perro: ", i+1);
		scanf("%s",perros[i].nombre);

		printf("%i-Edad del perro: ", i+1);
		scanf("%d",&perros[i].edadmeses);

		printf("%i-Peso del perro: ", i+1);
		scanf("%f",&perros[i].peso);

		printf("%i-Nombre del dueño: ", i+1);
		scanf("%s",perros[i].propietario.nombre);

		printf("%i-Direccion del propietario: ", i+1);
		scanf("%s", perros[i].propietario.direccion);
	}

	for(int i = 0; i<2; i++)
	{
		printf("\n%i-El NOMBRE del perro es %s\n",i+1, perros[i].nombre);
		printf("%i-EDAD en meses del perro es %d\n",i+1, perros[i].edadmeses);
		printf("%i-PESO del perro es %.2f\n",i+1, perros[i].peso);
		printf("%i-NOMBRE del dueño es %s\n",i+1, perros[i].propietario.nombre);
		printf("%i-DIRECCION del dueño %s\n",i+1, perros[i].propietario.direccion);
	}

	return EXIT_SUCCESS;
}*/
typedef struct
{
	char nombre[20];
	char *Pname;
}dog;
int main(void) {
dog perros[2];
int size;
fflush(stdin);

for(int i=0;i<2; i++)
{
	fflush(stdin);

	printf("Ingrese el nombre del perro: \n");
	scanf("%s",perros[i].nombre);
	size = strlen(perros[i].nombre);
	printf("EL tamaño es %d\n", size);
	perros[i].Pname= malloc(size * sizeof(char));
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

}


	return EXIT_SUCCESS;
}

