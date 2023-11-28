#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

typedef struct
{
    stPelicula dato;
    struct nodoDoble * anterior;
    struct nodoDoble * siguiente;
} nodoDoble;

nodoDoble * inicListaDoble();

nodoDoble * crearNodoDoble(stPelicula dato);

nodoDoble * agregarAlPrincipioDoble(nodoDoble * lista, nodoDoble * nuevoNodo);
// recursivo
nodoDoble * buscarUltimoRDoble(nodoDoble * lista);

nodoDoble * agregarAlFinalDoble(nodoDoble * lista, nodoDoble * nuevoNodo);

nodoDoble * insertarNodoDoble(nodoDoble * lista, nodoDoble * nuevoNodo);

stPelicula verPrimero (nodoDoble * lista);

nodoDoble * borrarPrimero (nodoDoble * lista);

void mostrarNodoDoble(nodoDoble * aux);

void recorrerYmostrarDoble(nodoDoble * lista);

nodoDoble * cargarListaDoble(nodoDoble * lista);

#endif // LISTADOBLE_H_INCLUDED
