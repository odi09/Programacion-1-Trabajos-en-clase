/*
 * employee.c
 *
 *  Created on: 15 oct. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "utn.h"
#include "employee.h"
static int IdEmpleado(void);

/**\brief Inicializa todas las posiciones colocando un 0 de ocupado.
 * param arrayIni[] la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int iniLista(eEmpleado arrayIni[], int tamano)
{
	int i;
	int retorno = 0;

	if (arrayIni != NULL && tamano > 0)
	{
		retorno = 1;
		for (i = 0; i < tamano; i++)
		{
			arrayIni[i].isEmpty = 1;
		}
	}
	return 	retorno;
}
/**\brief Busca un espacio libre.
 * param arrayIni[] la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param auxEspacio la direccion de memoria de un espacio disponible.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int unEspaLibre(eEmpleado arrayIni[], int tamano, int* auxEspacio)
{
	int i;
	int retorno = 0;
	if(arrayIni != NULL && tamano > 0 && auxEspacio != NULL)
	{
		for(i = 0; i < tamano; i++)
		{
			if(arrayIni[i].isEmpty == 1)
			{
				*auxEspacio = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
/**\brief Pide al usuario cargar los datos.
 * param arrayIni[] la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int cargaEmpleado(eEmpleado arrayIni[], int tamano)
{
	int retorno = 0;
	int auxSector;
	char auxNombre[tamano];
	char auxApellido[tamano];
	float auxSalario;


	if (arrayIni != NULL && tamano > 0)
	{
		if(pedirCadenaDeSoloLetras(auxNombre, sizeof(auxNombre), 3, "Ingrese Nombre: ", "ERROR no es nombre no valido") == 1)
		{
			if(pedirCadenaDeSoloLetras(auxApellido, sizeof(auxApellido), 3, "Ingrese Apellido: ", "ERROR no es Apellido no valido") == 1)
			{
				if(pedirFlotante(&auxSalario, 0, 999999, 3, "Ingrese Salario: ", "ERROR no es valido") == 1)
				{
					if(pedirEntero(&auxSector, 0, 10, 3, "Ingrese Sector: ", "ERROR no es valido") == 1)
						{
						strncpy(arrayIni->nombre, auxNombre,sizeof(arrayIni->nombre));
						strncpy(arrayIni->apellido, auxApellido,sizeof(arrayIni->apellido));
						arrayIni->salario = auxSalario;
						arrayIni->sector = auxSector;
						arrayIni->isEmpty = 0;
						arrayIni->id = IdEmpleado();
						retorno = 1;
						}

				}
			}
		}

	}
	return retorno;
}
/**\brief Busca un id.
 * param arrayIni[] la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param auxId es el id que desea buscar el usuario.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int buscarId(eEmpleado arrayEmpl[], int tamano, int auxId)
{
	int i;
	int retorno = 0;

	if (arrayEmpl != NULL && tamano > 0 && auxId > 0)
	{
		for (i = 0; i < tamano; i++)
		{
			if (arrayEmpl[i].isEmpty == 0 && arrayEmpl[i].id == auxId)
			{
				retorno = i;
				break;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}
/**\brief Modifica los datos del un empleado.
 * param arrayIni[] la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param id es el id del empleado que se desea modificar.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int modificarEmpleado(eEmpleado arrayIni[], int tamano, int id)
{
	int retorno = 0;
	int posicion;
	int auxSector;
	char auxNombre[tamano];
	char auxApellido[tamano];
	float auxSalario;

	if(arrayIni != NULL && tamano > 0 && id > 0)
	{
		posicion = buscarId(arrayIni, tamano, id);
	  if(posicion  >= 0)
	  {
				if (pedirCadenaDeSoloLetras(auxNombre, sizeof(auxNombre), 3,"Ingrese Nombre: ", "ERROR no es nombre no valido") == 1)
				{
					if (pedirCadenaDeSoloLetras(auxApellido, sizeof(auxApellido), 3, "Ingrese Apellido: ", "ERROR no es Apellido no valido") == 1)
					{
						if (pedirFlotante(&auxSalario, 0, 999999, 3, "Ingrese Salario: ", "ERROR no es valido")	== 1)
						{
							if (pedirEntero(&auxSector, 0, 10, 3, "Ingrese Sector: ", "ERROR no es valido")	== 1)
							{
								strncpy(arrayIni[posicion].nombre, auxNombre, sizeof(arrayIni[posicion].nombre));
								strncpy(arrayIni[posicion].apellido, auxApellido, sizeof(arrayIni[posicion].apellido));
								arrayIni[posicion].salario = auxSalario;
								arrayIni[posicion].sector = auxSector;
								retorno = 1;
							}
						}
					}
				}

	  }
	  else
	  {
		  printf("El Id no esta dado de alta.\n\n");
	  }
	  retorno = 1;
	}
	return retorno;
}
/**\brief Da de baja a un empleado.
 * param arrayIni[] la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param id es el id del empleado que se desea dar de baja.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int bajaEmpleado(eEmpleado arrayIni[], int tamano, int id)
{
	int retorno = 0;
	int i;

	if (arrayIni != NULL && tamano > 0 && id > 0 && buscarId(arrayIni, tamano, id) >= 0)
	{
		for (i = 0; i < tamano; i++)
		{
			if (arrayIni[i].isEmpty == 0 && arrayIni[i].id == id)
			{
				arrayIni[i].isEmpty = 1;
				retorno = 1;
				break;
			}
		}
	}
	else
	{
		printf("\nID no encontrado.\n");
	}
	return retorno;
}
/**\brief Muestra lo empleados dados de alta.
 * param arrayIni[] la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int impriEmpleado(eEmpleado arrayIni[], int tamano)
{
	int retorno = 0;
		int contador = 0;
		int i;

		if(arrayIni != NULL && tamano > 0)
		{
			for(i = 0; i < tamano; i++)
				{

				if(arrayIni[i].isEmpty == 0)
					{
					contador++;
					printf("%d_Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d - Id: %d\n"
							,contador, arrayIni[i].nombre, arrayIni[i].apellido, arrayIni[i].salario, arrayIni[i].sector, arrayIni[i].id);
					retorno = 1;
					}
				}
		}
		return retorno;
}
/**\brief Ordena la lista de empleados.
 * param arrayIni[]. la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param order. recibe el numero de lo que se quiere ordenar.
 * param Retorna 0 si sale todo bien o -1 si no.
 */
int ordenarEmpleado(eEmpleado arrayApe[],int tamno, int order)
{
	int retorno=-1;
	int i,j;
	eEmpleado aux;

	if(arrayApe!= NULL && tamno >0 && (order == 1 || order == 0 ||order == 2))
	{
		retorno=0;
		for(i=0; i<tamno-1; i++)
		{
			for(j=i+1; j<tamno; j++)
			{
				if(strcmp(arrayApe[i].apellido,arrayApe[j].apellido)<0 && order==1)
				{
					aux=arrayApe[i];
					arrayApe[i]=arrayApe[j];
					arrayApe[j]=aux;
				}
				else if(strcmp(arrayApe[i].apellido,arrayApe[j].apellido) > 0 && order==0)
				{
					aux=arrayApe[i];
					arrayApe[i]=arrayApe[j];
					arrayApe[j]=aux;
				}
				else if (arrayApe[i].sector > arrayApe[j].sector && order == 2)
				{
					aux = arrayApe[i];
					arrayApe[i] = arrayApe[j];
					arrayApe[j] = aux;
				}
			}
		}
	}

	return retorno;
}
/**\brief Suma los sueldo sde los empleados dados de alta.
 * param sumSuelEmp[]. la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param Retorna la suma.
 */
float sumaSueldos(eEmpleado sumSuelEmp[],int tamno)
{
	float retorno = 0;
	int i;
	float acumSueldos = 0;

	if(sumSuelEmp != NULL && tamno > 0)
	{
		for(i = 0; i< tamno; i++)
		{
			if(sumSuelEmp[i].isEmpty == 0)
			{
				acumSueldos = sumSuelEmp[i].salario + acumSueldos;
			}
		}
		retorno = acumSueldos;
	}
	return retorno;
}
/**\brief Cuenta la cantidad de empleados dados de alta.
 * param cantiEmple[]. la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param Retorna la cantidad de empleados.
 */
int CantidadEmpleado(eEmpleado cantiEmple[],int tamno)
{
	int retorno;
	int i;
	int contaEmple = 0;

	if(cantiEmple != NULL && tamno > 0)
	{
		for (i = 0; i < tamno; i++) {
			if (cantiEmple[i].isEmpty == 0)
			{
				contaEmple++;
			}
		}
		retorno = contaEmple;
	}
	return retorno;
}
/**\brief Cuenta la cantidad de empleados dados de alta.
 * param promeEmple[]. la direccion de memoria de un array.
 * param tamano. tamaño del array.
 * param Retorna el promedio de los sueldos.
 */
float promeSueldos(eEmpleado promeEmple[],int tamno)
{
	int cantidad;
	float sueldosTotales;
	float promeSueldos;
	float retorno = 0;
	if(promeEmple != NULL &&  tamno > 0)
	{
		sueldosTotales = sumaSueldos(promeEmple, tamno);
		cantidad = CantidadEmpleado(promeEmple, tamno);
		promeSueldos = sueldosTotales/(float)cantidad;
		retorno = promeSueldos;
	}
	return retorno;
}
/**\brief Genera un Id unico.
  * param No retorna nada ni recibe algo.
 */
static int IdEmpleado(void)
{
	static int contador = 1;
	return contador++;
}


