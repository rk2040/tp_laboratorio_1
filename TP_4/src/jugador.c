#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "jugador.h"

static int idJugador = 0;

eJugador* jugador_new()
{

    eJugador* nuevoJugador;

    nuevoJugador = (eJugador*) malloc(sizeof(eJugador));    // Asigno memoria para el nuevo jugador

    return nuevoJugador;
}

eJugador* jugador_newParametrosChar(char* idStr, char* nombreStr, char* apellidoStr, char* posicionStr, char* edadStr)
{
    eJugador* nuevoJugador;
    nuevoJugador = NULL;
    nuevoJugador = jugador_new();

    if(nuevoJugador != NULL)
    {
        if(	jugador_setId(nuevoJugador, atoi(idStr)) ||
        	jugador_setNombre(nuevoJugador, nombreStr) ||
			jugador_setApellido(nuevoJugador, apellidoStr) ||
        	jugador_setPosicion(nuevoJugador, posicionStr)||
            jugador_setEdad(nuevoJugador, atoi(edadStr) )  )
        {
            jugador_delete(nuevoJugador);
            nuevoJugador = NULL;
        }
    }
    return nuevoJugador;

}

eJugador* jugador_newParametrosInt(int id, char* nombre, char* apellido, char* posicion, int edad)
{
    eJugador* nuevoJugador;
    nuevoJugador = NULL;
    nuevoJugador = jugador_new();

    if(nuevoJugador != NULL)
    {
        if(	jugador_setId(nuevoJugador, id) ||
            jugador_setNombre(nuevoJugador, nombre)||
			jugador_setApellido(nuevoJugador, apellido) ||
            jugador_setPosicion(nuevoJugador, posicion)||
            jugador_setEdad(nuevoJugador, edad) )
        {
            jugador_delete(nuevoJugador);
        }
    }

    return nuevoJugador;
}

int jugador_buscarPorId(LinkedList* pArrayListaDeJugadores, int idBuscado)
{
    int retorno = -1;
    int auxId;
    int tam;
    eJugador* auxJugador;

    if(pArrayListaDeJugadores != NULL && idBuscado > 0 )
    {
        tam = ll_len(pArrayListaDeJugadores);
        for(int i=0; i<tam; i++)
        {
            auxJugador = ll_get(pArrayListaDeJugadores, i);

            if(!jugador_getId(auxJugador, &auxId)&& auxId == idBuscado)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}


void jugador_delete(eJugador* this)
{
    free(this);
}

int destroyJugador(eJugador* jugador)
{
    int error = 1;
    if(jugador != NULL)
    {
        free(jugador);
        error = 0;
    }
    return error;
}


int mostrarJugador(eJugador* jugador)
{
    int error = 0;
    int id;
    char nombre[25];
    char apellido[25];
    char posicion[25];
    int edad;

    if(jugador != NULL )
    {
        if(	!jugador_getId(jugador, &id) &&
        	!jugador_getNombre(jugador, nombre) &&
            !jugador_getApellido(jugador, apellido) &&
        	!jugador_getPosicion(jugador, posicion) &&
    		!jugador_getEdad(jugador, &edad) )

        {
            printf("%2d    %10s       %10s       %10s      %2d\n", id, nombre, apellido, posicion, edad);
            error = 1;
        }
    }

    return error;
}


int mostrarJugadores(LinkedList* pArrayListaDeJugadores)
{
    int error = 1;
    eJugador* auxJugador = NULL;
//    int id;
//    char nombre[25];
//    char apellido[25];
//    char posicion[25];
//    int edad;
    int tam;

    tam = ll_len(pArrayListaDeJugadores);

    if(pArrayListaDeJugadores != NULL)
    {
        printf("------------------------------------------------------------\n");
        printf("     Lista de Jugadores de la Scaloneta para Qatar 2022     \n\n");
        printf(" Id      Nombre          Apellido         Posicion     Edad \n");
        printf("------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            auxJugador = ll_get(pArrayListaDeJugadores, i); // recorro la lista y voy tomando jugador por jugador
           /*
            if(auxJugador != NULL &&
               jugador_getId(auxJugador, &id) &&
               jugador_getNombre(auxJugador, nombre) &&
               jugador_getPosicion(auxJugador, posicion) &&
               jugador_getEdad(auxJugador, &edad) &&
               jugador_getAltura(auxJugador, &altura) )
            {
            }*/
                mostrarJugador(auxJugador);
        }
    }

    return error;
}


//--------------- SETTERS -----------------------

int jugador_setId(eJugador* this, int id)
{
    int error = 1;

    if(this != NULL && id>0)
    {
        this->id = id;
        error = 0;
    }
    return error;
}

int jugador_generarId()
{
    return idJugador++;
}


void jugador_setPrimerId(int valorInt)
{
   idJugador = valorInt;
}


int jugador_setNombre(eJugador* this, char* nombre)
{
    int error = 1;

    if(this != NULL && strlen(nombre)>0 && strlen(nombre)<128)
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }
    return error;
}

int jugador_setApellido(eJugador* this, char* apellido)
{
    int error = 1;

    if(this != NULL && strlen(apellido)>0 && strlen(apellido)<128)
    {
        strcpy(this->apellido, apellido);
        error = 0;
    }
    return error;
}


int jugador_setPosicion(eJugador* this, char* posicion)
{
    int error = 1;

    if(this != NULL && strlen(posicion)>0 && strlen(posicion)<128)
    {
        strcpy(this->posicion,posicion);
        error = 0;
    }
    return error;
}

int jugador_setEdad(eJugador* this, int edad)
{
    int error = 1;

    if(this != NULL && edad >= 0)
    {
        this->edad = edad;
        error = 0;
    }
    return error;
}


//--------------- GETTERS -----------------------

int jugador_getId(eJugador* this, int* id)
{
    int error = 1;
    if(this != NULL && id !=NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}


int jugador_getNombre(eJugador* this, char* nombre)
{
    int error = 1;
    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        error = 0;
    }
    return error;
}

int jugador_getApellido(eJugador* this, char* apellido)
{
    int error = 1;
    if(this != NULL && apellido !=NULL)
    {
        strcpy(apellido, this->apellido);
        error = 0;
    }
    return error;
}


int jugador_getPosicion(eJugador* this, char* posicion)
{
    int error = 1;
    if(this != NULL && posicion !=NULL)
    {
        strcpy(posicion, this->posicion);
        error = 0;
    }
    return error;
}

int jugador_getEdad(eJugador* this,int* edad)
{
    int error = 1;
    if(this != NULL && edad !=NULL)
    {
        *edad = this->edad;
        error = 0;
    }
    return error;
}


//--------------- ORDENAMIENTO -----------------------

int jugador_ordenarPorId(void* jug1,void* jug2)
{
    int retorno = 0;
    eJugador* jugadorA = NULL;
    eJugador* jugadorB = NULL;


    if(jug1 != NULL && jug2 != NULL)
    {
        jugadorA = (eJugador*) jug1;
        jugadorB = (eJugador*) jug2;


        if(jugadorA->id > jugadorB->id)
        {
            retorno = 1;
        }
        else
        {
            retorno = -1;
        }
    }

    return retorno;
}


int jugador_ordenarNombre(void* jug1,void* jug2)
{
    int retorno = 0;
    eJugador* jugadorA = NULL;
    eJugador* jugadorB = NULL;

    if(jug1 != NULL && jug2 != NULL)
    {
        jugadorA = (eJugador*) jug1;
        jugadorB = (eJugador*) jug2;

        if(strcmp(jugadorA->nombre,jugadorB->nombre)>0 )
        {
            retorno = 1;
        }
        else
        {
            if(strcmp(jugadorA->nombre,jugadorB->nombre)== 0 )
            {
                retorno = 0;
            }else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}

int jugador_ordenarApellido(void* jug1,void* jug2)
{
    int retorno = 0;
    eJugador* jugadorA = NULL;
    eJugador* jugadorB = NULL;

    if(jug1 != NULL && jug2 != NULL)
    {
        jugadorA = (eJugador*) jug1;
        jugadorB = (eJugador*) jug2;

        if(strcmp(jugadorA->apellido,jugadorB->apellido)>0 )
        {
            retorno = 1;
        }
        else
        {
            if(strcmp(jugadorA->apellido,jugadorB->apellido)== 0 )
            {
                retorno = 0;
            }else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}


int jugador_ordenarPosicion(void* jug1,void* jug2)
{
    int retorno = 0;
    eJugador* jugadorA = NULL;
    eJugador* jugadorB = NULL;

    if(jug1 != NULL && jug2 != NULL)
    {
        jugadorA = (eJugador*) jug1;
        jugadorB = (eJugador*) jug2;

        if(strcmp(jugadorA->posicion,jugadorB->posicion)>0 )
        {
            retorno = 1;
        }
        else
        {
            if(strcmp(jugadorA->posicion,jugadorB->posicion)== 0 )
            {
                retorno = 0;
            }else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}


int jugador_edad(void* jug1,void* jug2)
{
    int retorno = 0;
    eJugador* jugadorA = NULL;
    eJugador* jugadorB = NULL;

    if(jug1 != NULL && jug2 != NULL)
    {
        jugadorA = (eJugador*) jug1;
        jugadorB = (eJugador*) jug2;

        if(jugadorA->edad > jugadorB->edad)
        {
            retorno = 1;
        }
        else
        {
            if(jugadorA->edad == jugadorB->edad)
            {
                retorno = 0;
            }else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}

