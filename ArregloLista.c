#include "ArregloLista.h"



int buscarPosEnArreglo(celda adl[], int validos, char genero[])
{
    int pos = -1;
    int i = 0;
    while (i < validos && pos == -1)
    {
        if (strcmpi(adl[i].genero, genero) == 0)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

int agregarGenero(celda adl[], int validos, nodoArbol* aux)
{
    strcpy(adl[validos].genero, aux->dato.genero);
    adl[validos].nodoListaPelicula = inicListaSimple();
    validos++;

    return validos;
}


int pasarDeArbolToArregloDeListas(nodoArbol *arbol, celda adl[], int validos, int dimension)
{
    if (arbol != NULL)
    {
        int posicion = buscarPosEnArreglo(adl, validos, arbol->dato.genero);

        if (posicion == -1)
        {
            validos = agregarGenero(adl, validos, arbol);
            posicion = validos - 1;
        }

        nodo *nuevoNodo = crearNodoSimple(arbol->dato);
        adl[posicion].nodoListaPelicula = agregarEnOrden(adl[posicion].nodoListaPelicula, nuevoNodo);

        validos = pasarDeArbolToArregloDeListas(arbol->izq, adl, validos, dimension);
        validos = pasarDeArbolToArregloDeListas(arbol->der, adl, validos, dimension);
    }

    return validos;
}

void mostrarLista(nodo *lista)
{
    while (lista != NULL)
    {
        puts("-------------------------------");
        printf("Nombre Pelicula: %s\n",lista->dato.nombrePelicula);
        printf("Anio           : %d\n",lista->dato.anio);
        printf("Director       : %s\n",lista->dato.director);
        printf("Duracion       : %d\n",lista->dato.duracion);
        printf("Genero         : %s\n",lista->dato.genero);
        puts("-------------------------------");
        lista = lista->siguiente;
    }
}


void mostrarArregloDeListas(celda adl[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        if(adl[i].nodoListaPelicula != NULL)
        {
            printf("Genero: %s\n", adl[i].genero);
            printf("Lista de Peliculas:\n");
            mostrarLista(adl[i].nodoListaPelicula);
            printf("\n");
        }
    }
}


void guardarEnArchivo(char archivo[], celda adl[], int validos)
{
    FILE *archi = fopen(archivo, "ab");

    if (archi != NULL)
    {
        for (int i = 0; i < validos; i++)
        {
            nodo *actual = adl[i].nodoListaPelicula;
            while (actual != NULL)
            {
                if (!buscarPelicula(archivo, actual->dato.nombrePelicula))
                {
                    fwrite(&(actual->dato), sizeof(stPelicula), 1, archi);
                }
                actual = actual->siguiente;
            }
        }
        fclose(archi);
    }
}


void mostrarStPelicula(stPelicula dato)
{
    puts("-------------------------------");
    printf("Nombre Pelicula: %s\n",dato.nombrePelicula);
    printf("Anio           : %d\n",dato.anio);
    printf("Director       : %s\n",dato.director);
    printf("Duracion       : %d\n",dato.duracion);
    printf("Genero         : %s\n",dato.genero);
    puts("-------------------------------");
}

void mostrarArchivo(char nombreArchivo[])
{
    FILE *archi=fopen(nombreArchivo,"rb");
    stPelicula peli;

    fseek(archi, 0, SEEK_END);
    if (ftell(archi) == 0)
    {
        printf("Catalogo vacio.\n");
    }
    rewind(archi);

    if(archi!=NULL)
    {

        while(!feof(archi))
        {
            fread(&peli,sizeof(stPelicula),1,archi);
            if(!feof(archi))
            {
                mostrarStPelicula(peli);

            }
        }
        fclose(archi);
    }
}


void borrarDatoArchivo(char archivo[], char datoABorrar[])
{
    FILE *archivoOriginal = fopen(archivo, "rb");
    FILE *archivoTemporal = fopen("temporal.bin", "wb");

    if (archivoOriginal == NULL || archivoTemporal == NULL)
    {
        perror("Error al abrir catalogo");
        exit(EXIT_FAILURE);
    }

    stPelicula registro;
    int datoEncontrado = 0;


    while (fread(&registro, sizeof(stPelicula), 1, archivoOriginal) == 1)
    {

        if (strcmp(registro.nombrePelicula, datoABorrar) != 0)
        {

            fwrite(&registro, sizeof(stPelicula), 1, archivoTemporal);
        }
        else
        {
            datoEncontrado = 1;
        }
    }

    fclose(archivoOriginal);
    fclose(archivoTemporal);

    if (!datoEncontrado)
    {
        printf("La pelicula a borrar no se encontro en el catalogo.\n");
    }
    else
    {
        printf("La pelicula a borrar se borro del catalogo.\n");
        remove(archivo);
        rename("temporal.bin", archivo);
    }
}



void borrarNodoEnArreglo(celda adl[], int validos, char genero[], char nombrePelicula[])
{
    int posicion = buscarPosEnArreglo(adl, validos, genero);

    if (posicion != -1)
    {
        nodo* actual = adl[posicion].nodoListaPelicula;
        nodo* anterior = NULL;

        while (actual != NULL && strcmp(actual->dato.nombrePelicula, nombrePelicula) != 0)
        {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual != NULL)
        {

            if (anterior == NULL)
            {
                adl[posicion].nodoListaPelicula = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }

            free(actual);
            printf("Nodo borrado exitosamente.\n");
        }
        else
        {
            printf("La pelicula con nombre %s no existe en la lista de genero %s.\n", nombrePelicula, genero);
        }
    }
    else
    {
        printf("El genero %s no existe en el arreglo.\n", genero);
    }
}


void eliminarPeliculaDeArregloDeListas(celda adl[], char pelicula[])
{
    for (int i = 0; i < 100; i++)
    {
        nodo* actual = adl[i].nodoListaPelicula;
        nodo* anterior = NULL;

        while (actual != NULL)
        {
            if (strcmp(actual->dato.nombrePelicula, pelicula) == 0)
            {

                if (anterior == NULL)
                {

                    adl[i].nodoListaPelicula = actual->siguiente;
                }
                else
                {

                    anterior->siguiente = actual->siguiente;
                }

                free(actual);
                printf("Pelicula eliminada exitosamente.\n");
                return;
            }

            anterior = actual;
            actual = actual->siguiente;
        }
    }


    printf("La pelicula no se encuentra en el arreglo de listas.\n");
}

void mostrarArchivoGenero(char nombreArchivo[],char genero[])
{
    FILE *archi=fopen(nombreArchivo,"rb");
    stPelicula peli;

    fseek(archi, 0, SEEK_END);
    if (ftell(archi) == 0)
    {
        printf("Catalogo vacio.\n");
    }
    rewind(archi);

    int flag = 0;
    if(archi!=NULL)
    {

        while(!feof(archi))
        {
            fread(&peli,sizeof(stPelicula),1,archi);
            if(!feof(archi))
            {
                if(strcmpi(peli.genero,genero) == 0)
                {
                    mostrarStPelicula(peli);
                    flag = 1;
                }
            }
        }
        fclose(archi);
    }

    if (!flag) {
        printf("No se encontraron peliculas con el genero \"%s\".\n", genero);
    }
}

void mostrarArchivoDirector(char nombreArchivo[],char director[])
{
    FILE *archi=fopen(nombreArchivo,"rb");
    stPelicula peli;

    fseek(archi, 0, SEEK_END);
    if (ftell(archi) == 0)
    {
        printf("Catalogo vacio.\n");
    }
    rewind(archi);
    int flag = 0;
    if(archi!=NULL)
    {

        while(!feof(archi))
        {
            fread(&peli,sizeof(stPelicula),1,archi);
            if(!feof(archi))
            {
                if(strcmpi(peli.director,director) == 0)
                {
                    mostrarStPelicula(peli);
                    flag = 1;
                }
            }
        }
        fclose(archi);
    }
    if (!flag) {
        printf("No se encontraron peliculas con el director \"%s\".\n", director);
    }
}

void mostrarArchivoTitulo(char nombreArchivo[],char titulo[])
{
    FILE *archi=fopen(nombreArchivo,"rb");
    stPelicula peli;

    fseek(archi, 0, SEEK_END);
    if (ftell(archi) == 0)
    {
        printf("Catalogo vacio.\n");
    }
    rewind(archi);
    int flag = 0;
    if(archi!=NULL)
    {

        while(!feof(archi))
        {
            fread(&peli,sizeof(stPelicula),1,archi);
            if(!feof(archi))
            {
                if(strcmpi(peli.nombrePelicula,titulo) == 0)
                {
                    mostrarStPelicula(peli);
                    flag = 1;
                }
            }
        }
        fclose(archi);
    }
    if (!flag) {
        printf("No se encontraron peliculas con el titulo \"%s\".\n", titulo);
    }
}
