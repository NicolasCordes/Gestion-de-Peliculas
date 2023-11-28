#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

typedef struct
{
    stPelicula dato;
    struct nodo* siguiente; /// Direccion de memoria del nodo siguiente
} nodo;

typedef struct
{
    int dato;
    struct nodoInt* siguiente;
} nodoInt;

void escribirSimple(nodo*);

void recorrerYmostrarSimple(nodo*);

nodo* agregarPpioSimple(nodo*,nodo*);

nodo * crearNodoSimple(stPelicula);

nodo* inicListaSimple();

nodo * buscarUltimoSimple(nodo *);

nodo * buscarNodoSimple(nodo *, char[]);

nodo * agregarFinalSimple(nodo *, nodo *);

nodo * agregarEnOrdenSimple(nodo *, nodo *);

nodo * borrarTodaLaListaSimple(nodo *);

void escribirSimpleInt(nodoInt*aux);

void recorrerYmostrarSimpleInt(nodoInt*lista);

nodoInt* agregarPpioSimpleInt(nodoInt* lista,nodoInt*nuevoNodo);

nodoInt * crearNodoSimpleInt(int dato);

nodoInt* inicListaSimpleInt();

nodoInt * buscarUltimoSimpleInt(nodoInt * lista);

nodoInt * borrarTodaLaListaSimpleInt(nodoInt * lista);

#endif // LISTA_H_INCLUDED
