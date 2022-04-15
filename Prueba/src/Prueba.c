/*
 ============================================================================
 Name        : Prueba.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int suma(int num1,int num2, float* sResultado);
int resta(int num1,int num2, float* rResultado);
int multiplicar(int num1,int num2, float* rResultado);
float division(int num1, int num2, float* dResultado);

int main()
{
    int valor1;
    int valor2;
    float resultado;
    char operacion;

    setbuf(stdout, NULL);

    printf("Ingrese el primer valor:");
    scanf("%d",&valor1);

    printf("Ingrese el segundo valor:");
    scanf("%d",&valor2);

    do{
    printf("Ingrese que la operacion: suma(s), resta(r), multiplicacion(m), division(d): ");
    fflush(stdin);
    scanf("%s",&operacion);
    }while(operacion != 's' && operacion != 'r' && operacion != 'm' && operacion != 'd');

    switch(operacion)
    {
    case 's':
        suma(valor1,valor2,&resultado);
        break;
    case 'r':
        resta(valor1,valor2,&resultado);
        break;
    case 'm':
        multiplicar(valor1,valor2,&resultado);
        break;
    case 'd':
        if(division(valor1,valor2, &resultado)== 0)
        {
        }
        else
        {
            printf("Error");
        }
        break;
    }

    printf("El resultado es %.2f", resultado);

    system("pause");
    return 0;
}

int suma(int num1,int num2, float* sResultado)
{
    *sResultado=num1+num2;
    return 0;
}

int resta(int num1,int num2, float* rResultado)
{
    *rResultado=num1-num2;
    return 0;
}

int multiplicar(int num1,int num2, float* rResultado)
{
    *rResultado=num1*num2;
    return 0;
}

float division(int num1, int num2, float* dResultado)
{
	int retorno = -1;
    if(dResultado != NULL && num2!=0)
    {
        *dResultado=(float)num1/num2;
        retorno = 0;
    }

    return retorno;
}
