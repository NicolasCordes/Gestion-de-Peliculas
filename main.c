#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaDoble.h"
#include "pila.h"
#include "fila.h"
#include "arboles.h"
#include "ArregloLista.h"
#define MAX_GEN 100

typedef struct
{
    char nombre[50];
    char contrasena[50];
} user;

typedef struct
{
    int id;
    char banner[100];
} Publicidad;

void mostrarMenuAdministrador();
void mostrarMenuCliente();
void registrarClienteYAdmin(char[], int);
void registrarUsuario(char[], char[], int);
int iniciarSesion(char[]);
void pausarEjecucion();
int verificarCuenta(char archivo[],char nombre[]);
void mostrarPublicidad();

int main()
{
    char archivo[] = {"peliculas.bin"};
    char archivoClientes[] = "clientes.bin";
    char archivoAdmins[] = "admins.bin";
    int clienteOAdmin = 0;
    int inicioValido = 0;
    char opcionAdmin;
    int cerrarSesion = 1;
    int aux;
    nodoArbol* arbol = inicArbol();
    celda adl[MAX_GEN];
    int validos = 0;
    Fila peliculasFila;
    inicFila(&peliculasFila);
    char datoABorrar[30];
    char opcion = '\0';
    stPelicula peli;
    PilaInt oportunidades;
    inicPilaInt(&oportunidades);

    do
    {
        system("cls");
        printf("Bienvenido a PelisFlix!\n");

        while(!pilavaciaInt(&oportunidades))
        {
            aux = desapilarInt(&oportunidades);
        }
        apilarInt(&oportunidades, 1);
        apilarInt(&oportunidades, 1);
        apilarInt(&oportunidades, 1);

        clienteOAdmin = 0;

        opcion = '0';

        while ((opcion != '1') && (opcion != '2') && (opcion != '3'))
        {
            printf("1. Iniciar sesion.\n");
            printf("2. Crear una cuenta.\n");
            printf("3. Opciones de administrador.\n");
            printf("Ingresa una opcion: ");
            fflush(stdin);
            scanf(" %c", &opcion);
            system("cls");
            inicioValido = 0;
        }

        switch(opcion)
        {
        case '1':
            clienteOAdmin = 1;
            while (inicioValido != 1 && !pilavaciaInt(&oportunidades))
            {
                inicioValido = iniciarSesion(archivoClientes);
                if(inicioValido != 1)
                {
                    aux = desapilarInt(&oportunidades);
                }
            }

            break;
        case '2':
            clienteOAdmin = 1;
            registrarClienteYAdmin(archivoClientes, clienteOAdmin);
            break;
        case '3':
            opcionAdmin = '\0';
            clienteOAdmin = 2;
            while (opcionAdmin != '1' && opcionAdmin != '2')
            {
                printf("1. Iniciar sesion como administrador.\n");
                printf("2. Crear una cuenta de administrador.\n");
                printf("Ingresa una opcion: ");
                fflush(stdin);
                scanf(" %c", &opcionAdmin);
                system("cls");
                inicioValido = 0;
            }
            switch(opcionAdmin)
            {
            case '1':
                while (inicioValido != 1 && !pilavaciaInt(&oportunidades))
                {
                    inicioValido = iniciarSesion(archivoAdmins);
                    if(inicioValido != 1)
                    {
                        aux = desapilarInt(&oportunidades);
                    }
                }
                break;
            case '2':
                registrarClienteYAdmin(archivoAdmins, clienteOAdmin);
                break;
            }


            break;
        default:
            printf("Opcion no valida. Ingresa nuevamente.\n");
            break;
        }

        if(pilavaciaInt(&oportunidades))
        {
            puts("---------------------------------------------------");
            printf("Demasiados intentos, no se ha iniciado la sesion.\n");
            puts("---------------------------------------------------");
            system("PAUSE");
            cerrarSesion = 1;
        }
        else
        {
            if(clienteOAdmin == 2)
            {
                do
                {
                    opcion = '\0';
                    mostrarMenuAdministrador();
                    printf("Ingresa una opcion: ");
                    fflush(stdin);
                    scanf(" %c", &opcion);
                    system("cls");
                    cerrarSesion = 0;

                    switch (opcion)
                    {
                    case '1':
                        arbol = ingresarPeliculaArbol(arbol, archivo);
                        validos = pasarDeArbolToArregloDeListas(arbol, adl, validos, MAX_GEN);
                        guardarEnArchivo(archivo, adl, validos);
                        break;

                    case '2':
                        mostrarArchivo(archivo);
                        break;

                    case '3':
                        mostrarArchivo(archivo);
                        printf("Ingresa el nombre de la pelicula que deseas borrar: ");
                        fflush(stdin);
                        gets(datoABorrar);
                        borrarDatoArchivo(archivo, datoABorrar);
                        break;
                    case '4':
                        cerrarSesion = 1;
                        printf("Cerrando la sesion.\n");
                        break;

                    case '0':
                        printf("Saliendo del programa.\n");
                        break;

                    default:
                        printf("Opcion no valida. Ingresa nuevamente.\n");
                        break;
                    }

                    printf("Presiona 's' para continuar, '0' para salir: ");
                    scanf(" %c", &opcion);
                    system("cls");

                }
                while (opcion != '0');
            }
            else
            {
                do
                {
                    mostrarMenuCliente();
                    printf("Ingresa una opcion: ");
                    scanf(" %c", &opcion);
                    system("cls");
                    cerrarSesion = 0;
                    switch (opcion)
                    {
                    case '1':
                        mostrarPublicidad();
                        int opcion;
                        printf("Ingrese 1 si desea ver las peliculas por genero.\n");
                        printf("Ingrese 2 si desea ver las peliculas por director.\n");
                        printf("Ingrese 3 si desea ver la pelicula por titulo.\n");
                        printf("Ingrese 4 si desea ver todo el catalogo de peliculas.\n");
                        scanf("%i",&opcion);
                        system("cls");
                        if(opcion == 1)
                        {
                            mostrarPublicidad();
                            char genero[20];
                            printf("Ingrese el genero que desea ver: ");
                            fflush(stdin);
                            gets(genero);
                            system("cls");
                            mostrarArchivoGenero(archivo,genero);
                        }
                        else if(opcion == 2)
                        {
                            mostrarPublicidad();
                            char director[20];
                            printf("Ingrese el director que desea ver: ");
                            fflush(stdin);
                            gets(director);
                            system("cls");
                            mostrarArchivoDirector(archivo,director);
                        }
                        else if(opcion == 3)
                        {
                            mostrarPublicidad();
                            char titulo[20];
                            printf("Ingrese el titulo que desea ver: ");
                            fflush(stdin);
                            gets(titulo);
                            system("cls");
                            mostrarArchivoTitulo(archivo,titulo);
                        }
                        else if (opcion == 4)
                        {
                            mostrarPublicidad();
                            mostrarArchivo(archivo);
                        }
                        else
                        {
                            printf("El dato ingresado es incorrecto");
                        }
                        break;

                    case '2':
                        mostrarPublicidad();
                        mostrarArchivo(archivo);
                        pasarDeArchivoToFila(archivo, &peliculasFila);
                        break;

                    case '3':
                        mostrarPublicidad();
                        mostrarFila(&peliculasFila);
                        break;
                    case '4':
                        mostrarPublicidad();
                        mostrarFila(&peliculasFila);
                        if (!filaVacia(&peliculasFila))
                        {
                            peli = extraer(&peliculasFila);
                            nodoDoble* aux = crearNodoDoble(peli);
                            printf("Pelicula extraida:\n");
                            mostrarNodoDoble(aux);
                        }
                        else
                        {
                            printf("La fila esta vacia. No se puede extraer una pelicula.\n");

                        }
                        break;
                    case '5':
                        mostrarPublicidad();
                        cerrarSesion = 1;
                        printf("Cerrando la sesion.\n");
                        break;

                    case '0':
                        printf("Saliendo del programa.\n");
                        break;

                    default:
                        printf("Opcion no valida. Ingresa nuevamente.\n");
                        break;
                    }

                    printf("Presiona 's' para continuar, '0' para salir: ");
                    scanf(" %c", &opcion);
                    system("cls");

                }
                while (opcion != '0');
            }
        }


    }
    while(cerrarSesion != 0);


    return 0;
}

void mostrarMenuAdministrador()
{
    system("cls");
    printf("### Menu Administrador ###\n");
    printf("1. Agregar Pelicula\n");
    printf("2. Mostrar Archivo\n");
    printf("3. Borrar Pelicula\n");
    printf("4. Cerrar sesion\n");
    printf("0. Salir\n");
}

void mostrarMenuCliente()
{
    system("cls");
    printf("### Menu Cliente ###\n");
    printf("1. Mostrar Catalogo de Peliculas\n");
    printf("2. Agregar Peliculas a mi Fila\n");
    printf("3. Mostrar Peliculas de mi Fila\n");
    printf("4. Extraer Pelicula de mi Fila\n");
    printf("5. Cerrar sesion\n");
    printf("0. Salir\n");
}

void registrarUsuario(char clientes[], char admins[], int clienteOAdmin)
{
    FILE* archi;
    if (clienteOAdmin == 1)
    {
        registrarClienteYAdmin(clientes, clienteOAdmin);
    }
    else
    {
        registrarClienteYAdmin(admins, clienteOAdmin);
    }
}

void registrarClienteYAdmin(char usuario[], int tipo)
{
    system("cls");
    FILE* archi = fopen(usuario, "ab");
    user datos;
    int flag = 0;
    if (archi == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    do
    {
        printf("### Registro Nuevo Usuario ###\n");
        printf("Ingresa el nombre de usuario: ");
        fflush(stdin);
        fgets(datos.nombre, sizeof(datos.nombre), stdin);
        flag = verificarCuenta(usuario,datos.nombre);
    }
    while(flag==1);

    printf("Ingresa la contrasena: ");
    fflush(stdin);
    fgets(datos.contrasena, sizeof(datos.contrasena), stdin);

    fwrite(&datos, sizeof(user), 1, archi);
    fclose(archi);

    printf("Usuario registrado exitosamente.\n");
    pausarEjecucion();
    printf("-----------------------------\n");
}

int verificarCuenta(char archivo[],char nombre[])
{
    FILE* archi = fopen(archivo,"rb");
    user usuario;
    int flag = 0;
    while (fread(&usuario, sizeof(user), 1, archi) > 0)
    {
        if ((strcmp(usuario.nombre, nombre) == 0))
        {
            printf("\nNombre de usuario en uso. Porfavor ingrese otro.\n");
            flag = 1;
            pausarEjecucion();
            system("cls");
            break;
        }
    }
    return flag;
}

int iniciarSesion(char archivo[])
{
    user usuarioGuardado, usuarioIngresado;
    int encontrado = 0;
    FILE* archi = fopen(archivo, "rb");

    if (archi == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 0;
    }

    printf("### Inicio de Sesion ###\n");
    printf("Ingresa el nombre de usuario: ");
    fflush(stdin);
    fgets(usuarioIngresado.nombre, sizeof(usuarioIngresado.nombre), stdin);

    printf("Ingresa la contrasena: ");
    fflush(stdin);
    fgets(usuarioIngresado.contrasena, sizeof(usuarioIngresado.contrasena), stdin);

    while (fread(&usuarioGuardado, sizeof(user), 1, archi) > 0)
    {
        if ((strcmp(usuarioGuardado.nombre, usuarioIngresado.nombre) == 0) &&
                (strcmp(usuarioGuardado.contrasena, usuarioIngresado.contrasena) == 0))
        {
            printf("\nInicio de sesion exitoso.\n");
            pausarEjecucion();
            encontrado = 1;
            break;
        }
    }

    if (encontrado != 1)
    {
        printf("\nDatos incorrectos. No se ha iniciado la sesion.\n");
        pausarEjecucion();
    }
    printf("-------------------------\n");
    system("cls");
    fclose(archi);
    return encontrado;
}

void pausarEjecucion()
{
#ifdef _WIN32
    system("pause");
#else
    printf("Presiona Enter para continuar...");
    while (getchar() != '\n'); // Limpiar el b fer de entrada
#endif
}


void mostrarPublicidad()
{
    Publicidad publicidades[5] =
    {
        {1, "Descubre las ultimas novedades en tecnologia."},
        {2, "Oferta especial:  Compre uno y lleve dos!"},
        {3, " Prueba nuestro nuevo menu de hamburguesas gourmet!"},
        {4, "No te pierdas el estreno de la pelicula del ano."},
        {5, "Registrate ahora y recibe un regalo exclusivo."}
    };

    srand(time(NULL));

    int probabilidad = rand() % 2;

    if (probabilidad == 0)
    {
        int indicePublicidad = rand() % 5;
        char *banner = publicidades[indicePublicidad].banner;
        int longitudBanner = strlen(banner);
        int longitudTotal = longitudBanner + 4;

        int caracteresDecorativos = (80 - longitudTotal) / 2;


        printf("\n  %.*s\n", 80, "********************************************************************************");


        printf("  **----------   %-*.*s %.*s **\n",
               longitudBanner,
               longitudBanner,
               banner,
               caracteresDecorativos,
               "---------------------------------------------------------------------------");


        printf("  %.*s\n", 80, "********************************************************************************");
    }
}


