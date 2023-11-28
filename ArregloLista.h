#ifndef ARREGLOLISTA_H_INCLUDED
#define ARREGLOLISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArregloLista.h"
#include "lista.h"

typedef struct
{
    char genero[30];
    nodo* nodoListaPelicula;
}celda;

int buscarPosEnArreglo(celda adl[], int validos, char genero[]);

int agregarGenero(celda adl[], int validos, nodoArbol* aux);

int pasarDeArbolToArregloDeListas(nodoArbol *arbol, celda adl[], int validos, int dimension);

void mostrarLista(nodo *lista);

void mostrarArregloDeListas(celda adl[], int validos);

void guardarEnArchivo(char archivo[], celda adl[], int validos);

void mostrarStPelicula(stPelicula dato);

void mostrarArchivo(char nombreArchivo[]);

void borrarDatoArchivo(char archivo[], char datoABorrar[]);

void borrarNodoEnArreglo(celda adl[], int validos, char genero[], char nombrePelicula[]);

void eliminarPeliculaDeArregloDeListas(celda adl[], char pelicula[]);

void mostrarArchivoGenero(char nombreArchivo[],char genero[]);

void mostrarArchivoDirector(char nombreArchivo[],char director[]);

void mostrarArchivoTitulo(char nombreArchivo[],char titulo[]);

#endif // ARREGLOLISTA_H_INCLUDED
