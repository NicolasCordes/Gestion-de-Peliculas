#include "pila.h"

void inicPila(Pila* p)
{
    p->lista = inicListaSimple();
}

void apilar(Pila* p,stPelicula peli)
{
    nodo* aux = crearNodoSimple(peli);
    p->lista = agregarPpioSimple(p->lista,aux);

}

/*
void leerPila(Pila* p)
{
    int aux = 0;
    printf("Ingrese un valor entero: ");
    fflush(stdin);
    scanf("%d", &aux);
    apilar(p, aux);
}
*/

int tope(Pila* p)
{
    if(p->lista != NULL)
    {
        return p->lista->dato.anio;
    }
}

int pilavacia(Pila * p)
{
    return (p->lista == NULL);
}

int desapilar(Pila* p)
{
    nodo* aux = p->lista;
    int dato1 = aux;
    p->lista = p->lista->siguiente;
    free(aux);
    return dato1;
}

void mostrarPila(Pila* p)
{

    printf("\nBase .............................................. Tope\n\n");
    recorrerYmostrarSimple(p->lista);
    printf("\n\nBase .............................................. Tope\n\n");
}


///----------------------------------|PILA INT|-------------------------------------------


void inicPilaInt(PilaInt* p)
{
    p->lista = inicListaSimpleInt();
}

void apilarInt(PilaInt* p,int dato)
{
    nodoInt* aux = crearNodoSimpleInt(dato);
    p->lista = agregarPpioSimpleInt(p->lista,aux);

}


void leerPilaInt(PilaInt* p)
{
    int aux = 0;
    printf("Ingrese un valor entero: ");
    fflush(stdin);
    scanf("%d", &aux);
    apilarInt(p, aux);
}


int topeInt(PilaInt* p)
{
    if(p->lista != NULL)
    {
        return p->lista->dato;
    }
}

int pilavaciaInt(PilaInt * p)
{
    return (p->lista == NULL);
}

int desapilarInt(PilaInt* p)
{
    nodoInt* aux = p->lista;
    int dato1 = aux;
    p->lista = p->lista->siguiente;
    free(aux);
    return dato1;
}

void mostrarPilaInt(PilaInt* p)
{

    printf("\nBase .............................................. Tope\n\n");
    recorrerYmostrarSimpleInt(p->lista);
    printf("\n\nBase .............................................. Tope\n\n");
}
