/*
 * album.h
 *
 *  Created on: 30 abr. 2022
 *      Author: ojose
 */

#ifndef ALBUM_H_
#define ALBUM_H_
#define TAM 51

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int idGenero;
	char descripGenero[TAM];
}eGenero;

typedef struct{
	int idArtista;
	char nombreArtista[TAM];
}eArtista;

typedef struct{
	int idTipoArt;
	char descripTipo[TAM];
}eTipoArt;

typedef struct{
	int idAlbum;
	char nombreAlbum[TAM];
	float importe;
	int estado;
	int idTipoArt;
	int idArtis;
	int idGenero;
	eFecha fechaAlbum;
}eAlbum;
int inicializarArray(eAlbum album[], int tam);
int buscarPosicLibre(eAlbum album[], int tam);
int buscarId(eAlbum album[], int tam, int idBuscar);
int altaAlbum(eAlbum album[], int tam, eArtista artistas[],int tam1,eGenero generos[],int tam2,eTipoArt tiposArt[], int tam3);
int modificar(eAlbum album[], int tam);
int bajaAlbum(eAlbum album[], int tam);
int imprimirIdAlbum(eAlbum album[],int tam);
//////////////INFORMENES//////////////////
int sumaDeImportes(eAlbum album[],int tam);
float promedioImporte(eAlbum album[],int tam);
int cantidadDeAlbumesQueSuperaElPromedio(eAlbum album[],int tam);
int cantidadAlbumesQueSuperaUnaFechaDeterminada(eAlbum album[],int tam);
int listarGeneros(eGenero genero[],int tam);
int listarGeneroConID(eGenero genero[], int tam1);
int listarTiposDeArtista(eTipoArt tipoArtista[],int tam);
int listarTiposArtistaConID(eTipoArt tipoArtista[],int tam);
int listarArtistas(eArtista artistas[],int tam);
int listarArtistasConID(eArtista artista[],int tam);
int listarAlbumes(eAlbum albumes[],int tam);
int listaAlbumesQueSuperaUnaFechaDeterminada(eAlbum album[],int tam);
int listaDeAlbumesQueSuperaElPromedio(eAlbum album[],int tam);
int listaAlbumesDeUnAnioDeterminado(eAlbum album[],int tam, int anio);
int listarAlbumesDeCdaArtista(eAlbum albumes[],int tam, eArtista artista[], int tam1);
int recorrerArrayAlbum(eAlbum albumes[],int tam);
int buscarAlbumConMayorImpor(eAlbum albumes[],int tam);
int listarImporMaximos(eAlbum albumes[],int tam);

#endif /* ALBUM_H_ */
