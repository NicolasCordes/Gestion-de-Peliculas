#include "fila.h"

void inicFila(Fila* fila)
{
    fila->inicio=inicListaDoble();
    fila->fin=inicListaDoble();
}

void mostrarFila(Fila* fila)
{
    if(fila->inicio!=NULL)
    {
        printf("Inicio\n");
        recorrerYmostrarDoble(fila->inicio);
        printf("Fin\n");
    }
    else
    {
        printf("Tu fila esta vacia.\n");
    }
}

/// agrega al final de la fila
void agregar(Fila* fila, stPelicula dato)
{
    nodoDoble * nuevo = crearNodoDoble(dato);

    fila->fin=agregarAlFinalDoble(fila->fin, nuevo);

    if(fila->inicio==NULL)
    {
        fila->inicio=fila->fin;
    }
    fila->fin=nuevo;
}


stPelicula extraer(Fila* fila)
{
    stPelicula resp;

    if(fila->inicio!=NULL)
    {
        resp=verPrimero(fila->inicio);

        fila->inicio=borrarPrimero(fila->inicio);

        if(fila->inicio==NULL)
            fila->fin=inicListaDoble();
    }
    return resp;
}

void leer(Fila* fila)
{
    stPelicula a;
    printf("Ingrese un valor:");
    scanf("%d", &a);
    agregar(fila, a);
}

stPelicula primero(Fila* fila)
{
    stPelicula resp;
    if(fila->inicio!=NULL)
    {
        resp=verPrimero(fila->inicio);
    }
    return resp;
}

int filaVacia(Fila* fila)
{
    int resp=0;
    if(fila->inicio==NULL)
        resp=1;
    return resp;
}

void pasarDeArchivoToFila(char archivo[], Fila* fila)
{
    FILE* archi = fopen(archivo, "rb");
    stPelicula peli;
    char nombrePeli[30];

    int flag = 0;
    if (archi != NULL)
    {
        printf("Ingrese el nombre de la pelicula que desea agregar: ");
        fflush(stdin);
        gets(nombrePeli);
        while (fread(&peli, sizeof(stPelicula), 1, archi) > 0)
        {
            if (strcmpi(peli.nombrePelicula, nombrePeli) == 0)
            {
                agregar(fila, peli);
                flag=1;
            }
        }

        fclose(archi);
    }

    if(!flag)
    {
        printf("La pelicula: %s no se encuentra en el catalogo.\n",nombrePeli);
    }
}


