/*
 ============================================================================
 Name        : Parcial.c
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
#include "utn.h"
#include "album.h"
#include "Hardcode.h"
#define TAMCHAR 51
#define TAM1 3
#define TAM2 15
#define TAM3 2

int main(void) {
	setbuf(stdout, NULL);
	eAlbum album[TAM1];
	eGenero genero[TAM2];
	eArtista artista[TAM2];
	eTipoArt tipo[2];
	int alta;
	int direccion;
	int totalImportes;
	float promedioImportes;
	int cantMayPromedio;
	int cantMayorFecha;
	int anio;
	int flag = 0;
	int opcion;
	int subMenu;

	if(inicializarArray(album, TAM1) == 1)
	{
		harcodeoGenero(genero, TAM2);
		harcodeoArtista(artista, TAM2);
		harcodeoTipo(tipo, 2);

		do{
			if(pedirEntero(&opcion, 0, 5, 3, "Ingrese una Opcion:\n1.Dar de Alta un Album.\n2.Modificar un album.\n3.Dar de baja un Album.\n"
				                             "4.Infomenes.\n5.Listar\n0.Salir.\n","La opcion que ingreso no es correcta.")!=1)
			{
				printf("ERROR!! Algo salio mal.\n");
			}
			switch(opcion)
			{
			case 1:
				direccion = buscarPosicLibre(album, TAM1);
				if(direccion>=0)
				{
					alta=altaAlbum(&album[direccion],TAMCHAR,artista,TAM2,genero,TAM2,tipo,TAM3);
					if(alta == 1)
					{
						flag = 1;
					}
				}
				else
				{
					printf("No hay mas espacio.\n");
				}
				break;
			case 2:
				if(flag ==1 && (imprimirIdAlbum(album,TAM1)==1))
				{
					if(modificar(album, TAM1)==1)
					{
						printf("Lo que se cargo es %s\n", album[direccion].nombreAlbum);
						printf("Lo que se cargo como importe es %.2f\n", album[direccion].importe);
						printf("La fecha ingresada es %d-%d-%d\n", album[direccion].fechaAlbum.dia, album[direccion].fechaAlbum.mes, album[direccion].fechaAlbum.anio);
						printf("El ID es %d\n", album[direccion].idAlbum);
					}
				}
				else
				{
					printf("No puedes modificar sin dar por lo menos un Alta.\n");

				}
				break;
			case 3:
				if(flag == 1 && (imprimirIdAlbum(album,TAM1)==1))
				{
					if(bajaAlbum(album, TAM1)==1)
						{
							printf("El estado es %d\n", album[direccion].estado);
							printf("El ID es %d\n", album[direccion].idAlbum);
						}
				}
				else
				{
					printf("No puedes dar de Baja sin dar por lo menos un Alta.\n");
				}
				break;
			case 4:
				do{
					if(pedirEntero(&subMenu,6,8, 3,
								   "Ingrese una opcion:\n  6.Para Totalizar y Promediar la cantidad de Albumes.\n  7.Cantidad de Albumes anterior a 1/1/2000.\n"
								   "  8.Salir\n","Error! no esta entre las opciones.\n")==1)
					{
						switch (subMenu)
						{
						case 6:
							totalImportes = sumaDeImportes(album, TAM1);
							promedioImportes = promedioImporte(album, TAM1);
							cantMayPromedio = cantidadDeAlbumesQueSuperaElPromedio(album, TAM1);
							if(totalImportes!=0 && promedioImportes!=0 && cantMayPromedio!=0)
							{
								printf("El Total de los Importes es %d, su Promedio es %.2f y la cantidad de Albumes que superan el promedio es %d.\n",
										totalImportes,promedioImportes,cantMayPromedio);
							}
							else
							{
								printf("Error, no se pudo hacer el calculo.\n");
							}
							break;
						case 7:
							cantMayorFecha = cantidadAlbumesQueSuperaUnaFechaDeterminada(album, TAM1);
							if(cantMayorFecha!=0)
							{
								printf("Cantidad de Albumes publicados antes de 1/1/2000 es de %d.\n",cantMayorFecha);
							}
							else
							{
								printf("Error, no se pudo hacer el calculo.\n");
							}
							break;
						}
					}
				}while(subMenu != 8);
				break;
			case 5:
				listarAlbumesDeCdaArtista(album,TAM1,artista,TAM2);
				listarGeneros(genero,TAM2);
				listarTiposDeArtista(tipo,2);
				listarArtistas(artista,TAM2);
				if(alta==1)
				{
					if(listarAlbumes(album,TAM1)!=1)
					{
						printf("No hay Albumes para Listar\n");
					}
					if(listaAlbumesQueSuperaUnaFechaDeterminada(album,TAM1)!=1)
					{
						printf("No hay Albumes para Listar que supere el 1/1/2000.\n");
					}
					if(listaDeAlbumesQueSuperaElPromedio(album,TAM1)!=1)
					{
						printf("No hay Albumes para Listar que supere el promedio.\n");
					}
					if(pedirEntero(&anio, 1900, 2022, 3, "Ingrese Año:","Error en el Añio.\n")==1)
					{
						if(listaAlbumesDeUnAnioDeterminado(album,TAM1, anio)!=1)
						{
							printf("No se encontro Albumes publicado ese año.\n");
						}
					}
					listarImporMaximos(album,TAM1);
				}
				else
				{
					printf("No hay Albumes para imprimir.\n");
				}
				break;
			}
		}while(opcion != 0);
	}
	return EXIT_SUCCESS;
}
