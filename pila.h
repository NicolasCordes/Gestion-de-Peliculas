#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
typedef struct
{
    nodo * lista;
} Pila;

typedef struct
{
    nodoInt * lista;
} PilaInt;

void inicPila(Pila* );

void apilar(Pila*,stPelicula );

void mostrar(Pila* );

void leer (Pila*);

int tope(Pila* );

int pilavacia(Pila *);

int desapilar(Pila* );

///----------------------------------|PILA INT|-------------------------------------------

void inicPilaInt(PilaInt*);

void apilarInt(PilaInt*, int);

void leerPilaInt(PilaInt*);

int topeInt(PilaInt*);

int pilavaciaInt(PilaInt *);

int desapilarInt(PilaInt*);

void mostrarPilaInt(PilaInt*);

#endif // PILA_H_INCLUDED
