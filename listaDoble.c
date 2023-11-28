#include "listaDoble.h"

nodoDoble * inicListaDoble()
{
    return NULL;
}

nodoDoble * crearNodoDoble(stPelicula dato)
{
    nodoDoble* aux = malloc(sizeof(nodoDoble));
    aux->dato=dato;
    aux->anterior=NULL;
    aux->siguiente=NULL;
    return aux;
}

nodoDoble * agregarAlPrincipioDoble(nodoDoble * lista, nodoDoble * nuevoNodo)
{
    nuevoNodo->siguiente=lista;
    if(lista!=NULL)
    {
        lista->anterior=nuevoNodo;
    }
    return nuevoNodo;
}

// recursivo
nodoDoble * buscarUltimoRDoble(nodoDoble * lista)
{
    nodoDoble * rta=NULL;
    if(lista!=NULL)
    {
        if(lista->siguiente==NULL)
        {
            rta=lista;
        }
        else
        {
            rta=buscarUltimoRDoble(lista->siguiente);
        }
    }
    return rta;
}

nodoDoble * agregarAlFinalDoble(nodoDoble * lista, nodoDoble * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodoDoble * ultimo = buscarUltimoRDoble(lista);
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
    }
    return lista;
}

nodoDoble * insertarNodoDoble(nodoDoble * lista, nodoDoble * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else if (nuevoNodo->dato.anio < lista->dato.anio)
    {
        lista=agregarAlPrincipioDoble(lista, nuevoNodo);
    }
    else
    {

        nodoDoble * anteriorrior=lista;
        nodoDoble * seg=lista->siguiente;

        while(seg!=NULL && seg->dato.anio < nuevoNodo->dato.anio)
        {
            anteriorrior=seg;
            seg=seg->siguiente;
        }

        anteriorrior->siguiente =nuevoNodo;

        nuevoNodo->anterior = anteriorrior;
        nuevoNodo->siguiente=seg;

        if(seg!=NULL)
        {
            seg->anterior= nuevoNodo;
        }
    }
    return lista;
}


stPelicula verPrimero (nodoDoble * lista)
{
    stPelicula rta;

    if(lista)
    {
        rta=lista->dato;
    }
    return rta;

}


nodoDoble * borrarPrimero (nodoDoble * lista)
{
    nodoDoble * aux = lista;;
    if (lista)
    {
        lista=lista->siguiente;
        if(lista)
            lista->anterior=NULL;
        free(aux);
    }
    return lista;
}


void mostrarNodoDoble(nodoDoble * aux)
{
        puts("-------------------------------");
        printf("Nombre Pelicula: %s\n",aux->dato.nombrePelicula);
        printf("Anio           : %d\n",aux->dato.anio);
        printf("Director       : %s\n",aux->dato.director);
        printf("Duracion       : %d\n",aux->dato.duracion);
        printf("Genero         : %s\n",aux->dato.genero);
        puts("-------------------------------");
}

void recorrerYmostrarDoble(nodoDoble * lista)
{
    nodoDoble * seg = lista;
    while (seg != NULL)
    {
        mostrarNodoDoble(seg);
        seg= seg->siguiente;
    }
}

