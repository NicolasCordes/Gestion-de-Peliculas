#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombrePelicula[30];
    int anio;
    char director[30];
    int duracion;
    char genero[30];
}stPelicula;

typedef struct
{
    stPelicula dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
} nodoArbol;

nodoArbol* inicArbol();

nodoArbol* crearNodoArbol(stPelicula);

nodoArbol* buscar(nodoArbol*,nodoArbol*);

nodoArbol* insertar(nodoArbol*, nodoArbol*);

nodoArbol* ingresarPeliculaArbol(nodoArbol*,char  []);

nodoArbol* leerArchivo(char [],nodoArbol* );

void mostrarArbol(nodoArbol* );

void preorder(nodoArbol* );

void inorder(nodoArbol* );

void postorder(nodoArbol* );

nodoArbol* ingresarPeliculaArbol(nodoArbol* arbol, char archivo[]);

int esSoloLetras(char cadena[]);

void limpiarBuffer();

nodoArbol* leerArchivo(char archivo[],nodoArbol* arbol);

int buscarPelicula (char nombreArchivo[],char pelicula[]);

nodoArbol* cargarDatosAArbol(char archivo[]);

nodoArbol* nodoMasIzq(nodoArbol* arbol);

nodoArbol* nodoMasDer(nodoArbol* arbol);

nodoArbol* borrarNodo(nodoArbol* arbol, char dato[]);

#endif // ARBOLES_H_INCLUDED
