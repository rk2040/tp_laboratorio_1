/*
 * vuelo.c
 *
 *  Created on: 9 may. 2022
 *      Author: Roberto i3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vuelo.h"



int cargarTipoPasaje(eVuelo vuelos[], int tam, int id, char desc[])
{
    int exito = 0;

    if(vuelos != NULL && desc != NULL )
    {
        for(int i=0; i<tam; i++)
        {
            if(vuelos[i].id == id)
            {
                strcpy(desc, vuelos[i].tipoPasaje);
                exito = 1;
                break;
            }
        }
    }

    return exito;
}

/*
int cargarEstadoPasaje(eVuelo vuelos[], int tam, int id, char desc[])
{
    int exito = 0;

    if(vuelos != NULL && desc != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(vuelos[i].id == id)
            {
                strcpy(desc, vuelos[i].estado);
                exito = 1;
                break;
            }
        }
    }

    return exito;
}
*/

int listarVuelos(eVuelo vuelos[], int tam)
{
    int exito = 0;

    if(vuelos != NULL && tam  > 0)
    {
    	printf(" -------------------------\n");
        printf(" *** Listado de vuelos ***\n");
        printf("    Id      Tipo\n");
        printf(" -------------------------\n");

        for(int i=0; i<tam; i++)
        {
            printf("    %2d     %10s\n", vuelos[i].id, vuelos[i].tipoPasaje);
        }
    }

    return exito;
}



int buscarVuelo(eVuelo vec[], int tam, int id, int* pIndex)
{
    int exito = 0;

    if(vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        exito = 1;
    }

    return exito;
}


int validarIdVuelo(eVuelo vec[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarVuelo(vec, tam, id, &indice))
    {
        if(indice != -1)    // -1 xq la funcion buscarSector() cambia el valor de indice a -1
        {                   // si no encuentra coincidencia de id en el vector cuando lo recorre con el for
            esValido = 1;
        }
    }

    return esValido;
}
