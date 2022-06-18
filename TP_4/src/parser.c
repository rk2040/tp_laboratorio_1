#include <stdio.h>
#include <stdlib.h>

#include "../inc/LinkedList.h"
#include "jugador.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugadores LinkedList*
 * \return int  devuelve 0 si salio todo Ok .  devuelve -1 si algo salio mal
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListJugadores)
{
    int error = -1;
//    char bufferDatos[5][128];	// matriz de datos en lugar de 4 cadenas
    char id[128];
    char nombre[128];
    char apellido[128];
    char posicion[128];
    char edad[128];
    int cantidadElementos;
   // int bufferint;
   // int maxId = -1;
    eJugador* nuevoJugador;
    nuevoJugador = NULL;

    if(pFile != NULL && pArrayListJugadores != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, posicion, edad);	// Lectura fantasma

        do{

            cantidadElementos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, posicion, edad);


            if(cantidadElementos == 5)
            {
                nuevoJugador = jugador_newParametrosChar(id, nombre, apellido, posicion, edad);

                if(nuevoJugador != NULL)
                {
                    ll_add(pArrayListJugadores, nuevoJugador);

                    error = 0;
                }
            }
            else
            {
                break;
            }

        }while(!feof(pFile));

        fclose(pFile);
    }

    return error;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListJugadores LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListJugadores)
{
    int error = -1;
    int cant;
    eJugador* nuevoJugador;
    nuevoJugador = NULL;


    if(pFile != NULL && pArrayListJugadores != NULL)
    {

        do
        {
            nuevoJugador = jugador_new();
            cant = fread(nuevoJugador, sizeof(eJugador), 1, pFile);

            if(nuevoJugador != NULL && cant == 1)
            {
                ll_add(pArrayListJugadores,nuevoJugador);
                error = 0;
            }else
            {
                jugador_delete(nuevoJugador);
                break;
            }
        }while(!feof(pFile));

    }
      fclose(pFile);
    return error;
}


//---------------------------------------------------------------------------------------------------------

int loadFromText(char* path, LinkedList* pArrayListaDeJugadores)
{
    int retorno = -1;
    FILE* f;

    if(path != NULL && pArrayListaDeJugadores != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL && !parser_EmployeeFromText(f, pArrayListaDeJugadores) )
        {
            printf("\nArchivo cargado exitosamente\n");
            retorno = 0;

        }
        else
        {


            printf("\nError al cargar el archivo\n");
        }
    }

    fclose(f);

    return retorno;
}
