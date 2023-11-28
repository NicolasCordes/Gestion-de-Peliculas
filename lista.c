#include "lista.h"
//** Libreria de listas *//





void escribirSimple(nodo*aux)
{
    puts("-------------------------------");
    printf("Nombre Pelicula: %s\n",aux->dato.nombrePelicula);
    printf("Anio           : %d\n",aux->dato.anio);
    printf("Director       : %s\n",aux->dato.director);
    printf("Duracion       : %d\n",aux->dato.duracion);
    printf("Genero         : %s\n",aux->dato.genero);
    puts("-------------------------------");
}

void recorrerYmostrarSimple(nodo*lista)
{
    nodo*seg=lista;
    while(seg!=NULL)
    {
        escribirSimple(seg);
        seg=seg->siguiente;
    }
}

nodo* agregarPpioSimple(nodo* lista,nodo*nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }

    return lista;
}

nodo * crearNodoSimple(stPelicula dato)
{
    nodo*aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente=NULL;
    return aux;
}


nodo* inicListaSimple() ///funcion que inicializa la lista
{
    return NULL;
}

nodo * buscarUltimoSimple(nodo * lista)
{
    nodo * seg = lista;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}

/*
nodo * buscarNodoSimple(nodo * lista, char nombre[20])
{
    //busca un nodo por nombre y retorna su posici n de memoria
    //si no lo encuentra retorna NULL.

    nodo * seg;  //apunta al nodo de la lista que est  siendo procesado
    seg = lista; //con esto evito cambiar el valor de la variable
    //lista, que contiene un puntero al primer nodo de la
    //lista vinculada

    while ((seg != NULL) && ( strcmp(nombre, seg->personita.nombre)!=0 ))
    {
//busco mientras me quede lista por recorrer y no haya encontrado el nombre
        seg=seg->siguiente; //avanzo hacia el siguiente nodo.
    }
//en este punto puede haber fallado alguna de las dos condiciones
//del while. si falla la primera es debido a que no encontr  lo
//que buscaba (seg es NULL), si falla la segunda es debido a que se
//encontr  el nodo buscado.
    return seg;
}
*/

nodo * agregarFinalSimple(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimoSimple(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}



nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if (nuevoNodo->dato.anio < lista->dato.anio)
        {
            lista = agregarPpioSimple(lista, nuevoNodo);
        }
        else
        {

            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while((seg != NULL)&&(seg->dato.anio < nuevoNodo->dato.anio))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }
    return lista;
}


nodo * borrarTodaLaListaSimple(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;  //tomo la dir del siguiente.
        free(seg);                 //borro el actual.
        seg = proximo;             //actualizo el actual con la dir del
        //siguiente, para avanzar.
    }
    return seg; // retorna NULL a la variable lista del main()
}

///----------------------------------|LISTA INT|-------------------------------------------


void escribirSimpleInt(nodoInt*aux)
{
    puts("-------------------------------");
    printf("| %i |", aux->dato);
    puts("-------------------------------");
}

void recorrerYmostrarSimpleInt(nodoInt*lista)
{
    nodoInt*seg=lista;
    while(seg!=NULL)
    {
        escribirSimpleInt(seg);
        seg=seg->siguiente;
    }
}

nodoInt* agregarPpioSimpleInt(nodoInt* lista,nodoInt*nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }

    return lista;
}

nodoInt * crearNodoSimpleInt(int dato)
{
    nodoInt*aux = (nodoInt*)malloc(sizeof(nodoInt));
    aux->dato = dato;
    aux->siguiente=NULL;
    return aux;
}


nodoInt* inicListaSimpleInt()
{
    return NULL;
}

nodoInt * buscarUltimoSimpleInt(nodoInt * lista)
{
    nodoInt * seg = lista;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}

nodoInt * borrarTodaLaListaSimpleInt(nodoInt * lista)
{
    nodoInt * proximo;
    nodoInt * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;  //tomo la dir del siguiente.
        free(seg);                 //borro el actual.
        seg = proximo;             //actualizo el actual con la dir del
        //siguiente, para avanzar.
    }
    return seg; // retorna NULL a la variable lista del main()
}
