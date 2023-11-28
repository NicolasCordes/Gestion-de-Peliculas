#include "arboles.h"

///1.
nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol(stPelicula peli)
{
    nodoArbol * aux = malloc(sizeof(nodoArbol));
    aux->dato = peli;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbol* buscar(nodoArbol* arbol, nodoArbol* nuevo)
{
    nodoArbol* rta = NULL;
    if (arbol != NULL)
    {
        if (strcmpi(nuevo->dato.genero, arbol->dato.genero) == 0)
        {
            rta = arbol;
        }
        else if (strcmpi(nuevo->dato.genero, arbol->dato.genero) < 0)
        {
            rta = buscar(arbol->izq, nuevo);
        }
        else
        {
            rta = buscar(arbol->der, nuevo);
        }
    }
    return rta;
}


nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(nuevo->dato);
    }
    else
    {
        if(nuevo->dato.anio > arbol->dato.anio)
        {
            arbol->der = insertar(arbol->der,nuevo);
        }
        else
        {
            arbol->izq = insertar(arbol->izq,nuevo);
        }
    }
    return arbol;
}

void mostrar(nodoArbol* arbol)
{
    puts("-------------------------------");
    printf("Nombre Pelicula: %s\n",arbol->dato.nombrePelicula);
    printf("Anio           : %d\n",arbol->dato.anio);
    printf("Director       : %s\n",arbol->dato.director);
    printf("Duracion       : %d\n",arbol->dato.duracion);
    printf("Genero         : %s\n",arbol->dato.genero);
    puts("-------------------------------");
}

void preorder(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        mostrar(arbol);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}


void inorder(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        mostrar(arbol);
        inorder(arbol->der);
    }
}

void postorder(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrar(arbol);
    }
}



nodoArbol* ingresarPeliculaArbol(nodoArbol* arbol, char archivo[])
{
    arbol = leerArchivo(archivo, arbol);
    char eleccion = 's';
    stPelicula peli;
    int flag = 1;

    while (eleccion == 's')
    {
        printf("Ingrese el nombre de la pelicula: ");
        fflush(stdin);
        gets(peli.nombrePelicula);


        while (1)
        {
            printf("Ingrese el anio de la pelicula: ");
            fflush(stdin);
            if (scanf("%i", &peli.anio) == 1)
            {
                break;
            }
            else
            {
                printf("Error: Por favor, ingrese un numero valido para el anio.\n");
                limpiarBuffer();
            }
        }

        while (1)
        {
            printf("Ingrese el director de la pelicula: ");
            fflush(stdin);
            if (scanf("%s", peli.director) == 1 && esSoloLetras(peli.director))
            {
                break;
            }
            else
            {
                printf("Error: Por favor, ingrese un nombre valido (solo letras).\n");
                limpiarBuffer();
            }
        }


        while (1)
        {
            printf("Ingrese la duracion de la pelicula: ");
            fflush(stdin);
            if (scanf("%i", &peli.duracion) == 1)
            {
                break;
            }
            else
            {
                printf("Error: Por favor, ingrese un numero valido para la duracion.\n");
                limpiarBuffer();
            }
        }


        while (1)
        {
            printf("Ingrese el genero de la pelicula: ");
            fflush(stdin);
            if (scanf("%s", peli.genero) == 1 && esSoloLetras(peli.genero))
            {
                break;
            }
            else
            {
                printf("Error: Por favor, ingrese un genero valido (solo letras).\n");
                limpiarBuffer();
            }
        }

        flag = buscarPelicula(archivo, peli.nombrePelicula);

        if (flag == 0)
        {
            nodoArbol* nuevo = inicArbol();
            nuevo = crearNodoArbol(peli);
            arbol = insertar(arbol, nuevo);
        }
        else
        {
            printf("La pelicula que ingreso ya esta en el archivo.\n");
        }

        printf("Desea seguir s/n: ");
        fflush(stdin);
        scanf("%c", &eleccion);
    }

    return arbol;
}

int esSoloLetras(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (!((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z')))
        {
            return 0;
        }
    }
    return 1;
}

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

nodoArbol* leerArchivo(char archivo[],nodoArbol* arbol)
{
    FILE* archi = fopen(archivo,"rb");
    stPelicula peli;
    if(archi!=NULL)
    {

        while(fread(&peli,sizeof(stPelicula),1,archi)>0)
        {
            nodoArbol* nuevo = crearNodoArbol(peli);
            arbol = insertar(arbol,nuevo);

        }
        fclose(archi);
    }
    return arbol;
}

int buscarPelicula (char nombreArchivo[],char pelicula[])
{
    FILE *archi=fopen(nombreArchivo,"rb");
    stPelicula peli;
    int flag=0;
    if(archi!=NULL)
    {
        while(!feof(archi) && flag==0)
        {
            fread(&peli,sizeof(stPelicula),1,archi);
            if(!feof(archi))
            {
                if(strcmpi(pelicula,peli.nombrePelicula)==0)
                {
                    flag=1;
                }
            }
        }
        fclose(archi);
    }
    return flag;
}


nodoArbol* cargarDatosAArbol(char archivo[])
{
    nodoArbol* arbol = inicArbol();
    FILE* archi = fopen(archivo, "rb");

    if (archi == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return arbol;
    }


    fseek(archi, 0, SEEK_END);
    int tamanoArchivo;
    tamanoArchivo = ftell(archi);
    fseek(archi, 0, SEEK_SET);


    size_t cantidadElementos = tamanoArchivo / sizeof(stPelicula);


    for (size_t i = 0; i < cantidadElementos; i++)
    {
        stPelicula datosPelicula;
        fread(&datosPelicula, sizeof(stPelicula), 1, archi);
        nodoArbol * nuevo = crearNodoArbol(datosPelicula);
        arbol = insertar(arbol,nuevo);
    }

    fclose(archi);

    return arbol;
}

nodoArbol* nodoMasIzq(nodoArbol* arbol)
{
    if (arbol && arbol->izq)
        arbol = nodoMasIzq(arbol->izq);
    return arbol;
}

nodoArbol* nodoMasDer(nodoArbol* arbol)
{
    if (arbol && arbol->der)
        arbol = nodoMasDer(arbol->der);
    return arbol;
}


nodoArbol* borrarNodo(nodoArbol* arbol, char dato[])
{
    if (arbol)
    {
        if (strcmpi(dato, arbol->dato.nombrePelicula) == 0)
        {
            if (arbol->izq != NULL)
            {
                nodoArbol* masDer = nodoMasDer(arbol->izq);
                arbol->dato = masDer->dato;
                arbol->izq = borrarNodo(arbol->izq, masDer->dato.nombrePelicula);
            }
            else if (arbol->der != NULL)
            {
                nodoArbol* masIzq = nodoMasIzq(arbol->der);
                arbol->dato = masIzq->dato;
                arbol->der = borrarNodo(arbol->der, masIzq->dato.nombrePelicula);
            }
            else
            {
                free(arbol);
                arbol = NULL;
            }
        }
        else if (strcmpi(dato, arbol->dato.nombrePelicula) > 0)
        {
            arbol->der = borrarNodo(arbol->der, dato);
        }
        else
        {
            arbol->izq = borrarNodo(arbol->izq, dato);
        }
    }
    return arbol;
}
