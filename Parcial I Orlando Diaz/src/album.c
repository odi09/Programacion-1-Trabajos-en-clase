/*
 * album.c
 *
 *  Created on: 30 abr. 2022
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "album.h"
#include "Hardcode.h"
#define LIBRE 0 // Si es 0 aun no esta cargado
#define TAMCHAR 51
static int IdAlbum(void);

/**\brief Inicializa el Array en el compronete ESTADO pone 0 para indicar que esta vacio.
 * param album[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array album[].
 * param retorno Retorna 1 si se Inicializa y 0 si No lo logra.
 */
int inicializarArray(eAlbum album[], int tam)
{
	int retorno = 0;
	if(album != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			album[i].estado = LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}
/**\brief Busca una posicion libre y la retorna.
 * param album[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array album[].
 * param retorno Retorna la posicion Libre que encontro y si No devuelve -1.
 */
int buscarPosicLibre(eAlbum album[], int tam)
{
	int retorno;

	if(album != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(album[i].estado == LIBRE)
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
/**\brief Busca un ID y devuelve su posicion.
 * param album[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array album[].
 * param idBuscar es el ID que se va a buscar.
 * param retorno Retorna la posicion donde esta el ID y 0 si no encuentra nada.
 */
int buscarId(eAlbum album[], int tam, int idBuscar)
{
	int retorno = 0;
	if(album!=NULL && tam>0 && idBuscar>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(album[i].estado==!LIBRE && album[i].idAlbum == idBuscar)
			{
				retorno = i;
			}
		}
	}
	return retorno;
}
/**\brief Pide al usuario cargar los datos y le asigna un ID al generar el alta.
 * param album[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array album[].
 * param artistas[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam1 Es el tamaño del array artistas[].
 * param generos[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam2 Es el tamaño del array generos[].
 * param tiposArt[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam3 Es el tamaño del array tiposArt[].
 * param retorno  Retorna 1 si logra dar el Alta y 0 si No lo logra.
 */
int altaAlbum(eAlbum album[], int tam, eArtista artistas[],int tam1,eGenero generos[],int tam2,eTipoArt tiposArt[], int tam3)
 {
	 int retorno = 0;
	 char auxNombre[TAMCHAR];
	 float auxImporte;
	 int auxDia;
	 int auxMes;
	 int auxAnio;
	 int auxIdArt;
	 int auxIdGene;
	 int auxIdtipo;

	 if(album!=NULL && tam>0)
	 {
		 if(pedirCadenaDeSoloLetras(auxNombre, TAMCHAR, 3, "Ingrese Nombre del Album: ", "Error con el nombre de Album que trata de ingresar.\n") == 1)
			 {
				 if(pedirFlotante(&auxImporte, 0, 3,"Ingrese el Importe del Album: ","Error con el importe que trata de ingresar.\n")==1)
				 {
					 if(pedirEntero(&auxDia, 1, 31, 3, "Ingrese la Fecha del Album.\nDia:","Error con el Dia que trata de ingresar.\n")==1)
					 {
						 if(pedirEntero(&auxMes, 1, 12, 3, "Mes:","Error con el Mes que trata de ingresar.\n")==1)
						 {
							 if(pedirEntero(&auxAnio, 1900, 2022, 3, "Año:","Error con el Año que trata de ingresar.\n")==1)
							 {
								 if(listarArtistasConID(artistas, tam1)==1)
								 {
									 if(pedirEntero(&auxIdArt, 1, 15, 3, "Ingrese ID del Artista:","Error con el ID que trata de ingresar.\n")==1)
									 {
										 if(listarGeneroConID(generos, tam2)==1)
										 {
											 if(pedirEntero(&auxIdGene, 1, 15, 3, "Ingrese ID del Genero:","Error con el ID que trata de ingresar.\n")==1)
											 {
												 if(listarTiposArtistaConID(tiposArt, tam3)==1)
												 {
													 if(pedirEntero(&auxIdtipo, 1, 15, 3, "Ingrese ID del Tipo de Artista:","Error con el ID que trata de ingresar.\n")==1)
													 {
														 strncpy(album->nombreAlbum, auxNombre, sizeof(album->nombreAlbum));
														 album->importe=auxImporte;
														 album->fechaAlbum.dia=auxDia;
														 album->fechaAlbum.mes=auxMes;
														 album->fechaAlbum.anio=auxAnio;
														 album->idArtis=auxIdArt;
														 album->idArtis=auxIdGene;
														 album->idTipoArt=auxIdtipo;
														 album->idAlbum=IdAlbum();
														 album->estado=!LIBRE;
														 retorno = 1;
													 }
												 }
											 }
										 }
									 }
								 }
							 }
						 }
					 }
				 }
			 }
	 }
	 return retorno;
 }
 /**\brief Modifica los datos de un Album que ya esta cargado buscando su ID.
  * param album[] La direccion de memoria del array que se le pasa a la fucnion.
  * param tam Es el tamaño del array album[].
  * param retorno  Retorna 1 se logra Modificar y 0 si No lo logra.
  */
int modificar(eAlbum album[],int tam)
{
	int retorno=0;
	int idAlbum;
	char auxNombre[TAMCHAR];
	float auxImporte;
	int auxDia;
	int auxMes;
	int auxAnio;
	int auxIdArt;
	int auxIdBuscar;

	if(album!=NULL && tam>0)
	{
		if(pedirEntero(&idAlbum, 1, 100, 3, "Ingrese el ID del Album a Modificar:","Error! El ID que ingresa no es valido\n")==1)
		{
			auxIdBuscar = buscarId(album,tam, idAlbum);
			if(pedirCadenaDeSoloLetras(auxNombre, TAMCHAR, 3, "Ingrese el nuevo nombre del Album: ", "Error con el nombre de Album que trata de ingresar.\n") == 1)
				 {
					 if(pedirFlotante(&auxImporte, 0, 3,"Ingrese el nuevo importe del Album: ","Error con el importe que trata de ingresar.\n")==1)
					 {
						 if(pedirEntero(&auxDia, 1, 31, 3, "Ingrese la nueva Fecha del Album.\nDia:","Error con el Dia que trata de ingresar.\n")==1)
						 {
							 if(pedirEntero(&auxMes, 1, 12, 3, "Mes:","Error con el Mes que trata de ingresar.\n")==1)
							 {
								 if(pedirEntero(&auxAnio, 1900, 2022, 3, "Año:","Error con el Año que trata de ingresar.\n")==1)
								 {
									 if(pedirEntero(&auxIdArt, 1, 15, 3, "Ingrese ID de Artista","Error con el ID que trata de ingresar.\n")==1)
									 {
										 strncpy(album[auxIdBuscar].nombreAlbum, auxNombre, sizeof(album[auxIdBuscar].nombreAlbum));
										 album[auxIdBuscar].importe=auxImporte;
										 album[auxIdBuscar].fechaAlbum.dia=auxDia;
										 album[auxIdBuscar].fechaAlbum.mes=auxMes;
										 album[auxIdBuscar].fechaAlbum.anio=auxAnio;
										 album[auxIdBuscar].idArtis=auxIdArt;
										 album[auxIdBuscar].estado=!LIBRE;
										 retorno = 1;
									 }

								 }
							 }
						 }
					 }
				 }


			}
	}
	return retorno;
}
/**\brief Da la Baja un Album que ya esta cargado buscando su ID.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna 1 se logra Modificar y 0 si No lo logra.
 */
int bajaAlbum(eAlbum album[],int tam)
{
	int retorno=0;
	int idAlbum;
	if(album!=NULL && tam>0)
	{
		if(pedirEntero(&idAlbum, 1, 100, 3, "Ingrese el ID del Album a dar de Baja:","Error! El ID que ingresa no es valido\n")==1)
		{
			for(int i=0; i<tam; i++)
			{
				if(album[i].idAlbum==idAlbum)
				{
					album[i].estado=LIBRE;
					retorno = 1;
					break;
				}
			}
		}
	}
	return 	retorno;
}
/**\brief Imprime los Albumes dados de alta con su ID.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna 1 si salio todo bion y 0 si No lo logra.
 */
int imprimirIdAlbum(eAlbum album[],int tam)
{
	int retorno = 0;
	if(album != NULL && tam>0)
	{
		printf("Los Albumes dados de alta son:\n");
		for(int i =0; i<tam; i++)
		{
			if(album[i].estado==!LIBRE)
			{
				printf("-Nombre del Album %s y su ID es %d.\n", album[i].nombreAlbum, album[i].idAlbum);
				retorno = 1;
			}
		}
	}
	return retorno;
}

////////////////////////////////////////////INFORMENES Y LISTAR//////////////////////////////////////////////////////////

/**\brief Suma los importe de los Albumes y lo retora la suma.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna la suma de los importes y 0 si No lo logra.
 */
int sumaDeImportes(eAlbum album[],int tam)
{
	int retorno=0;
	int acumulador=0;
	if(album!=NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(album[i].estado==!LIBRE)
			{
				acumulador = album[i].importe+acumulador;
			}
		}
		retorno = acumulador;
	}
	return 	retorno;
}
/**\brief Realiza el promedio de los importes.
 * param album[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna el promedio de los importes y 0 si No lo logra.
 */
float promedioImporte(eAlbum album[],int tam)
{
	float retorno = 0;
	int totaImporte;
	int contador=0;
	if(album!=NULL && tam>0)
	{
		totaImporte=sumaDeImportes(album, tam);
		for(int i=0; i<tam; i++)
		{
			if(album[i].estado==!LIBRE)
			{
				contador++;
			}
		}
		retorno=(float)totaImporte/contador;
	}
	return retorno;
}
/**\brief Recibe el promedio de los importe y suma la cantidad de Albumes que supera el promedio.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna la cantidad de Albumes que supera y 0 si No lo logra.
 */
int cantidadDeAlbumesQueSuperaElPromedio(eAlbum album[],int tam)
{
	int retorno = 0;
	float promedioImportes;
	int contador=0;

	if(album!=NULL && tam>0)
	{
		promedioImportes=promedioImporte(album, tam);
		for(int i=0; i<tam; i++)
		{
			if(album[i].estado==!LIBRE)
			{
				if(album[i].importe >= promedioImportes)
				{
					contador++;
				}
			}
		}
		retorno = contador;
	}
	return retorno;
}
/**\brief Suma la cantidad de Albumes que supera una fecha determinada y retorna la suma.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna la cantidad de Albumes que supera cierta fecha y 0 si No lo logra.
 */
int cantidadAlbumesQueSuperaUnaFechaDeterminada(eAlbum album[],int tam)
{
	int retorno=0;
	int contador=0;

	if(album!=NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(album[i].estado==!LIBRE)
			{
				if(album[i].fechaAlbum.anio<2000)
				{
					contador++;
				}
			}
		}
		retorno=contador;
	}
	return retorno;
}
/**\brief Imprime todo los generos.
 * param genero[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array genero[].
 * param retorno  Retorna 1 si salio todo bien o 0 No lo logra.
 */
int listarGeneros(eGenero genero[],int tam)
{
	int retorno = 0;
	if(genero!=NULL && tam>0)
	{
		printf("Lista de Generos:\n");
		for(int i = 0; i < tam; i++)
		{
			printf("  -%s.\n",genero[i].descripGenero);
			retorno = 1;
		}
	}
	return retorno;
}
/**\brief Imprime todo los Generos con sus ID.
 * param genero[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array genero[].
 * param retorno  Retorna 1 si salio todo bien o 0 No lo logra.
 */
int listarGeneroConID(eGenero genero[], int tam1)
{
	int retorno=0;
	if(genero!=NULL && tam1>0)
	{
		printf("Lista de Generos con sus ID:\n");
		for(int i = 0; i < tam1; i++)
		{
			printf("  -%s - %d.\n",genero[i].descripGenero, genero[i].idGenero);
			retorno = 1;
		}
	}
	return retorno;
}

/**\brief Imprime todo los Tipos de artistas.
 * param tipoArtista[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array tipoArtista[].
 * param retorno  Retorna 1 si salio todo bien o 0 No lo logra.
 */
int listarTiposDeArtista(eTipoArt tipoArtista[],int tam)
{
	int retorno = 0;
	if(tipoArtista!=NULL && tam>0)
		{
		printf("Tipos de Artistas:\n");
			for(int i = 0; i < tam; i++)
			{
				printf("  -%s.\n",tipoArtista[i].descripTipo);
				retorno = 1;
			}
		}
	return retorno;
}
/**\brief Imprime todo los tipos de Artistas con su ID.
 * param tipoArtista[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array tipoArtista[].
 * param retorno  Retorna 1 si salio todo bien o 0 No lo logra.
 */
int listarTiposArtistaConID(eTipoArt tipoArtista[],int tam)
{
	int retorno=0;
	if(tipoArtista!=NULL && tam>0)
	{
	printf("Tipos de Artistas con ID:\n");
		for(int i = 0; i < tam; i++)
		{
			printf("  -%s - %d.\n",tipoArtista[i].descripTipo,tipoArtista[i].idTipoArt);
			retorno = 1;
		}
	}
	return retorno;
}

/**\brief Imprime todo los Artistas.
 * param artistas[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array artistas[].
 * param retorno  Retorna 1 si salio todo bien o 0 No lo logra.
 */
int listarArtistas(eArtista artistas[],int tam)
{
	int retorno=0;
	if(artistas!=NULL && tam>0)
		{
		printf("Lista de Artistas:\n");
			for(int i = 0; i < tam; i++)
			{
				printf("  -%s.\n",artistas[i].nombreArtista);
				retorno = 1;
			}
		}
	return retorno;
}
/**\brief Imprime todo los Artistas con sus ID.
 * param artistas[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array artistas[].
 * param retorno  Retorna 1 si salio todo bien o 0 No lo logra.
 */
int listarArtistasConID(eArtista artistas[],int tam)
{
	int retorno=0;
	if(artistas!=NULL && tam>0)
		{
		printf("Lista de Artistas con su ID:\n");
			for(int i = 0; i < tam; i++)
			{
				printf("  -%s-ID %d.\n",artistas[i].nombreArtista, artistas[i].idArtista);
				retorno = 1;
			}
		}
	return retorno;
}
/**\brief Imprime todo los Arbumes.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna 1 si salio todo bien o 0 No lo logra.
 */
int listarAlbumes(eAlbum albumes[],int tam)
{
	int retorno=0;
	if(albumes!=NULL && tam>0)
		{
		printf("Lista de Albumes:\n");
			for(int i = 0; i < tam; i++)
			{
				if(albumes[i].estado==!LIBRE)
				{
					printf("  -%s.\n",albumes[i].nombreAlbum);
					retorno = 1;
				}
			}
		}
	return retorno;
}
/**\brief Lista los Albumes que supera una fecha que esta Harcodeada.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna 1 si sale todo bien y 0 si No lo logra.
 */
int listaAlbumesQueSuperaUnaFechaDeterminada(eAlbum album[],int tam)
{
	int retorno=0;

	if(album!=NULL && tam>0)
	{
		printf("Los Albumes publicados antes del 1/1/2000 son:\n");
		for(int i=0; i<tam; i++)
		{
			if(album[i].estado==!LIBRE)
			{
				if(album[i].fechaAlbum.anio<2000)
				{
					printf("  -%s\n",album[i].nombreAlbum);
					retorno=1;
				}
			}
		}
	}
	return retorno;
}
/**\brief Recibe el promedio de los importe y lista la cantidad de Albumes que supera el promedio.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna 1 si sale todo bien y 0 si No lo logra.
 */
int listaDeAlbumesQueSuperaElPromedio(eAlbum album[],int tam)
{
	int retorno = 0;
	float promedioImportes;

	if(album!=NULL && tam>0)
	{
		printf("Lista de Albumes que superan el promedio.\n");
		promedioImportes=promedioImporte(album, tam);
		for(int i=0; i<tam; i++)
		{
			if(album[i].estado==!LIBRE)
			{
				if(album[i].importe >= promedioImportes)
				{
					printf("  -%s\n",album[i].nombreAlbum);
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}
/**\brief Lista los Albumes de una fecha especifica que ingresa el usuario.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna 1 si sale todo bien y 0 si No lo logra.
 */
int listaAlbumesDeUnAnioDeterminado(eAlbum album[],int tam, int anio)
{
	int retorno=0;

	if(album!=NULL && tam>0 && anio>1500)
	{
		printf("Los Albumes publicados en el Año ingresado son:\n");
		for(int i=0; i<tam; i++)
		{
			if(album[i].estado==!LIBRE)
			{
				if(album[i].fechaAlbum.anio==anio)
				{
					printf("  -%s\n",album[i].nombreAlbum);
					retorno=1;
				}
			}
		}
	}
	return retorno;
}
/////////////////// OJO /////////////////////
int recorrerArrayAlbum(eAlbum albumes[],int tam)
{
	int retorno=0;
	if(albumes!=NULL && tam>0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(albumes[i].estado==!LIBRE)
			{
				retorno = i;
			}
		}
	}
	return retorno;
}
/**\brief Lista los Albumes de los Artistas.
 * param album[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam Es el tamaño del array album[].
 * param artista[] La direccion de memoria del array que se le pasa a la fucnion.
 * param tam1 Es el tamaño del array artista[].
 * param retorno  Retorna 1 si sale todo bien y 0 si No lo logra.
 */
int listarAlbumesDeCdaArtista(eAlbum albumes[],int tam, eArtista artista[], int tam1)
{
	int retorno=0;
	//int id;
	if(albumes!=NULL && tam>0 && artista!=NULL && tam1>0)
		{
		printf("Lista de Albumes de cada Artista:\n");
			for(int i = 0; i < tam; i++)
			{
				if(albumes[i].estado==!LIBRE)
				{///id=recorrerArrayAlbum(albumes,tam);
					for(int j=0; j<tam1; j++)
					{
						if(albumes[i].idArtis==artista[j].idArtista)
						{
							printf("  %s- Album %s.\n",artista[j].nombreArtista,albumes[i].nombreAlbum);
						}
						retorno = 1;
                   }
				}
			}
		}
	return retorno;
}
/**\brief Busca el mayor de los importes y lo retorna.
 * param album[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna el mayor de los importes y 0 si No lo logra.
 */
int buscarAlbumConMayorImpor(eAlbum albumes[],int tam)
{
	int retorno=0;
	int flag = 0;
	int imporMaximo;
	if(albumes!=NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(albumes[i].estado==!LIBRE)
			{
				if(flag==0 || albumes[i].importe>=imporMaximo)
				{
					imporMaximo = albumes[i].importe;
				}
			}
		}
		retorno=imporMaximo;
	}
	return retorno;
}
/**\brief Lista el mayor de los  importes.
 * param album[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna 1 si sale todo bien y 0 si No lo logra.
 */
int listarImporMaximos(eAlbum albumes[],int tam)
{
	int retorno=0;
	int importeMax;
	if(albumes!=NULL && tam>0)
	{
		importeMax = buscarAlbumConMayorImpor(albumes,tam);
		printf("Los Importes Maximos son: \n");
		for(int i=0;i<tam;i++)
		{
			if(albumes[i].importe==importeMax)
			{
				printf("%10s%10.2f\n",albumes[i].nombreAlbum,albumes[i].importe);
				retorno=1;
			}
		}
	}
	return retorno;
}
/**\brief Realiza el ordenamiento de los Importe de forma Descendente.
 * param album[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna 1 si sale todo bien y 0 si No lo logra.
 */
int ordenamientoAlbum(eAlbum albumes[],int tam)
{
	int retorno = 0;
	int flagSwap;
	eAlbum buffer;

	if(albumes!=NULL && tam>0 )
	{
		retorno = 1;
		do
		{
		flagSwap = 0;
		tam--;
			for(int i=0; i<tam; i++)
			{
				if(albumes[i].importe < albumes[i+1].importe)
				{
					buffer = albumes[i];
					albumes[i]=albumes[i+1];
					albumes[i+1]=buffer;
					flagSwap = 1;

				}
				if(albumes[i].importe == albumes[i+1].importe)
				{
					if(strcmp(albumes[i].nombreAlbum,albumes[i+1].nombreAlbum) > 0)
						{
							buffer = albumes[i];
							albumes[i]=albumes[i+1];
							albumes[i+1]=buffer;
							flagSwap = 1;
						}
				}
			}
		}while(flagSwap);
	}
	return retorno;
}


/*int ordenamientoAscendentedeTitulos(eAlbum albumes[],int tam)
{
	int retorno = -1;
	int flagSwap;
	char bufferChar[15];

	if(albumes!=NULL && tam>0)
	{
		retorno=1;
		do
		{
		flagSwap = 0;
		tam--;
		for(int i=0;i< tam-1; i++)
		{
			for(int j=i+1;j< tam; j++)
			{
				if(strcmp(albumes[i].nombreAlbum,albumes[j].nombreAlbum) > 0)
				{
					strcpy(bufferChar , albumes[j].nombreAlbum);
					strcpy(albumes[j].nombreAlbum , albumes[i].nombreAlbum);
					strcpy(albumes[i].nombreAlbum , bufferChar);
					//bufferChar[i] = albumes[j].nombreAlbum;
					//albumes[j].nombreAlbum = albumes[i].nombreAlbum;
					//albumes[i].nombreAlbum = bufferChar;
				}
			}
		}
		}while(flagSwap);
	}
	return retorno;
}*/

/**\brief Imprime la Lista de Albumes con sus importes.
 * param album[] La direccion de memoria del array que se le pasa a la funcion.
 * param tam Es el tamaño del array album[].
 * param retorno  Retorna 1 si sale todo bien y 0 si No lo logra.
 */
int listarAlbumeseImporte(eAlbum albumes[],int tam)
{
	int retorno=1;
	if(albumes!=NULL && tam>0)
	{
		ordenamientoAlbum(albumes, tam);
		printf("Lista de Albumes con sus Importes:\n");
		for(int i = 0; i < tam; i++)
		{
			if(albumes[i].estado==!LIBRE)
			{
				printf("  -%10s-%10.2f.\n",albumes[i].nombreAlbum, albumes[i].importe);
				retorno = 1;
			}
		}
	}
	return retorno;

}
/**\brief Genera un ID sin repetirlo.
 * param No recibe nada.
 * param retorno  No retorna nada.
 */
 static int IdAlbum(void)
 {
 	static int contador = 1;
 	return contador++;
 }
