#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDoble.h"

typedef struct
{
     nodoDoble* inicio;
     nodoDoble* fin;
} Fila;

void inicFila(Fila* fila);

void mostrarFila(Fila* fila);

void agregar(Fila* fila, stPelicula );

stPelicula extraer(Fila* fila);

void leerFila(Fila* fila);

stPelicula primero(Fila* fila);

int filaVacia(Fila* fila);

void pasarDeArchivoToFila(char [],Fila* );
#endif // FILA_H_INCLUDED
