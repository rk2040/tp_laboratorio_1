#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "LinkedList.h"

static int idPasajero = 0;

// Constructor ----------------------------------------------------------------------------------------------------
Passenger* Passenger_new()
{

	Passenger* nuevoPasajero;

	nuevoPasajero = (Passenger*) malloc(sizeof(Passenger));

	if(nuevoPasajero != NULL)
	{
		nuevoPasajero->id = 0;
		strcpy(nuevoPasajero->nombre, "");
		strcpy(nuevoPasajero->apellido, "");
		nuevoPasajero->precio = 0;
		strcpy(nuevoPasajero->codigoVuelo, "");
		nuevoPasajero->tipoPasajero = 0;
		nuevoPasajero->estadoVuelo = 0;
	}

    return nuevoPasajero;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* nuevoPasajero;
	nuevoPasajero = NULL;
	nuevoPasajero = Passenger_new();
	int tipoPasaje ;
	int estadoVuelo ;

    if(nuevoPasajero != NULL)
    {
    	pasarTipoPasajeAInt(tipoPasajeroStr, &tipoPasaje);
    	pasarEstadoVueloAInt(estadoVueloStr, &estadoVuelo);

        Passenger_setId(nuevoPasajero,atoi(idStr));
		Passenger_setNombre(nuevoPasajero, nombreStr);
		Passenger_setApellido(nuevoPasajero, apellidoStr);
		Passenger_setPrecio(nuevoPasajero, atof(precioStr));
		Passenger_setTipoPasajero(nuevoPasajero, tipoPasaje);
		Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr);
		Passenger_setEstadoVuelo(nuevoPasajero, estadoVuelo);

	}

    return nuevoPasajero;
}

Passenger* Passenger_newParametrosInt(int id, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo)
{
	Passenger* nuevoPasajero;
	nuevoPasajero = NULL;
	nuevoPasajero = Passenger_new();

    if(nuevoPasajero != NULL)
    {
        if(		Passenger_setId(nuevoPasajero, id) == 1 ||
                Passenger_setNombre(nuevoPasajero, nombre) == 1 ||
                Passenger_setApellido(nuevoPasajero, apellido) == 1 ||
				Passenger_setPrecio(nuevoPasajero, precio) == 1 ||
				Passenger_setTipoPasajero(nuevoPasajero, tipoPasajero) == 1 ||
				Passenger_setCodigoVuelo(nuevoPasajero, codigoVuelo) == 1 ||
				Passenger_setEstadoVuelo(nuevoPasajero, estadoVuelo) == 1	)
        {
            Passenger_delete(nuevoPasajero);
        }
    }
    return nuevoPasajero;
}

// Destructor ------------------------------------------------------------------------------------------------------
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

//----------------------------------------------------------
void passenger_setPrimerId(int valorInt)
{
	idPasajero = valorInt;
}

// Setters y Getters -----------------------------------------------------------------------------------------------
int Passenger_setId(Passenger* this, int id)
{
    int error = 1;

    if(this != NULL && id > 0)
    {
        this->id = id;
        error = 0;
    }
    return error;
}

int Passenger_getId(Passenger* this, int* id)
{
    int error = 1;

    if(this != NULL && id !=NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}


int Passenger_setNombre(Passenger* this, char* nombre)
{
    int error = 1;

    if(this != NULL && strlen(nombre)>0 && strlen(nombre)<50)
    {
        strcpy(this->nombre,nombre);
        error = 0;
    }
    return error;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
    int error = 1;
    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        error = 0;
    }
    return error;
}


int Passenger_setApellido(Passenger* this, char* apellido)
{
    int error = 1;

    if(this != NULL && strlen(apellido)>0 && strlen(apellido)<50)
    {
        strcpy(this->apellido,apellido);
        error = 0;
    }
    return error;
}

int Passenger_getApellido(Passenger* this, char* apellido)
{
    int error = 1;
    if(this != NULL && apellido !=NULL)
    {
        strcpy(apellido,this->apellido);
        error = 0;
    }
    return error;
}


int Passenger_setPrecio(Passenger* this, float precio)
{
    int error = 1;

    if(this != NULL && precio >=0)
    {
        this->precio = precio;
        error = 0;
    }
    return error;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
    int error = 1;
    if(this != NULL && precio !=NULL)
    {
        *precio = this->precio;
        error = 0;
    }
    return error;
}


int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
    int error = 1;

    if(this != NULL && tipoPasajero >0 && tipoPasajero <= 4)
    {
        this->tipoPasajero = tipoPasajero;
        error = 0;
    }
    return error;
}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
    int error = 1;
    if(this != NULL && tipoPasajero !=NULL)
    {
        *tipoPasajero = this->tipoPasajero;
        error = 0;
    }
    return error;
}


int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
    int error = 1;

    if(this != NULL && codigoVuelo != NULL)
    {
        strcpy(this->codigoVuelo,codigoVuelo);
        error = 0;
    }
    return error;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
    int error = 1;
    if(this != NULL && codigoVuelo !=NULL)
    {
        strcpy(codigoVuelo,this->codigoVuelo);
        error = 0;
    }
    return error;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
    int error = 1;

    if(this != NULL && estadoVuelo >0 && estadoVuelo <= 4)
    {
        this->estadoVuelo = estadoVuelo;
        error = 0;
    }
    return error;
}

int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
    int error = 1;
    if(this != NULL && estadoVuelo !=NULL)
    {
        *estadoVuelo = this->estadoVuelo;
        error = 0;
    }
    return error;
}
// Fin Setters y Getters ---------------------------------------------------------------------------------------



/*
void mostrarPasajero(Passenger* pasajero)
{
    char tipoPasaje[20];
    char estadoVuelo[20];

	cargarTipoPasaje(pasajero, tipoPasaje);

	cargarEstadoVuelo(pasajero, estadoVuelo);

    printf("  Id		: %d\n", pasajero->id);
    printf("  Nombre  	: %s\n", pasajero->nombre);
    printf("  Apellido	: %s\n", pasajero->apellido);
    printf("  Precio	: %.2f\n", pasajero->precio);
    printf("  Cod. vuelo	: %s\n", pasajero->codigoVuelo);
    printf("  Tipo pass	: %s\n", tipoPasaje);
    printf("  Est. Vuelo	: %s\n", estadoVuelo);
    printf("\n");
}
*/
//==============================================================
int cargarEstadoVuelo(int valor, char* desc)
{
    int exito = 0;

    if(valor > 0 && desc != NULL )
    {
    	switch(valor)
    	{
    	case 1:
    		strcpy(desc, "Aterrizado");
    		break;
    	case 2:
    		strcpy(desc, "En Vuelo");
    		break;
    	case 3:
    		strcpy(desc, "En Horario");
    		break;
    	case 4:
    		strcpy(desc, "Demorado");
    		break;
    	default:
    		break;
    	}

    	exito = 1;
    }

    return exito;
}

int pasarEstadoVueloAInt(char* desc, int *valor)
{
	int exito = 0;
	int descValor;

	if(desc != NULL )
	{
		if(stricmp(desc, "Aterrizado") == 0)
		{
			descValor = 1;
		}
		else if(stricmp(desc, "En Vuelo") == 0)
		{
			descValor = 2;
		}
		else if(stricmp(desc, "En Horario") == 0)
		{
			descValor = 3;
		}
		else if(stricmp(desc, "Demorado") == 0)
		{
			descValor = 4;
		}

		exito = 1;
		*valor = descValor;
	}

    return exito;
}

int cargarTipoPasaje(int valor, char* desc)
{
    int exito = 0;

    if(valor > 0 && desc != NULL )
    {
    	switch(valor)
    	{
    	case 1:
    		strcpy(desc, "FirstClass");
    		break;
    	case 2:
    		strcpy(desc, "ExecutiveClass");
    		break;
    	case 3:
    		strcpy(desc, "EconomyClass");
    		break;
    	default:
    		break;
    	}

    	exito = 1;
    }

    return exito;
}

int pasarTipoPasajeAInt(char* desc, int *valor)
{
	int exito = 0;
	char descValor;

	if(desc != NULL )
	{
		if(stricmp(desc, "FirstClass") == 0)
		{
			descValor = 1;
		}
		else if(stricmp(desc, "ExecutiveClass") == 0)
		{
			descValor = 2;
		}
		else if(stricmp(desc, "EconomyClass") == 0)
		{
			descValor = 3;
		}

		exito = 1;
		*valor = descValor;
	}

    return exito;
}
//---------------------------------------------------------------------
int mostrarPasajero(Passenger* pasajero)
{
    int error = 0;
    int id;
    char nombre[NOMBRE];
    char apellido[APELLIDO];
    float precio;
    int tipoPasaje;
    char codigoVuelo[CODIGO];
    int estadoVuelo;
    char descTipo[20];
    char descEstado[20];


        if(		!Passenger_getId(pasajero, &id) &&
        		!Passenger_getNombre(pasajero, nombre) &&
				!Passenger_getApellido(pasajero, apellido) &&
				!Passenger_getPrecio(pasajero, &precio) &&
                !Passenger_getTipoPasajero(pasajero, &tipoPasaje) &&
				!Passenger_getCodigoVuelo(pasajero, codigoVuelo) &&
				!Passenger_getEstadoVuelo(pasajero, &estadoVuelo) 	)
        {
        	cargarTipoPasaje(tipoPasaje, descTipo);

			cargarEstadoVuelo(estadoVuelo, descEstado);

			printf("  Id		: %d\n", id);
			printf("  Nombre  	: %s\n", nombre);
			printf("  Apellido	: %s\n", apellido);
			printf("  Precio	: %.2f\n", precio);
			printf("  Cod. vuelo	: %s\n", codigoVuelo);
			printf("  Tipo pass	: %s\n", descTipo);
			printf("  Est. Vuelo	: %s\n", descEstado);
			printf("\n");

            error = 1;
        }

    return error;
}

int mostrarPasajeroLinea(Passenger* pasajero)
{
    int error = 0;
    int id;
    char nombre[NOMBRE];
    char apellido[APELLIDO];
    float precio;
    int tipoPasaje;
    char codigoVuelo[20];
    int estadoVuelo;
    char descTipo[20];
    char descEstado[20];


        if(		!Passenger_getId(pasajero, &id) &&
        		!Passenger_getNombre(pasajero, nombre) &&
				!Passenger_getApellido(pasajero, apellido) &&
				!Passenger_getPrecio(pasajero, &precio) &&
				!Passenger_getCodigoVuelo(pasajero, codigoVuelo) &&
                !Passenger_getTipoPasajero(pasajero, &tipoPasaje) &&
				!Passenger_getEstadoVuelo(pasajero, &estadoVuelo) 	)
        {
        	cargarTipoPasaje(tipoPasaje, descTipo);

			cargarEstadoVuelo(estadoVuelo, descEstado);

			//pasarTipoPasajeAInt(bufferDatos[5], &tipoPasaje);
			//pasarEstadoVueloAInt(bufferDatos[6], &estadoPasaje);

			printf(" %4d %12s %12s % 10.2f 	%10s %15s 	%10s\n", id, nombre, apellido, precio, codigoVuelo, descTipo, descEstado);

            error = 1;
        }

    return error;
}


int passenger_generarId()
{
    return idPasajero++;
}


// Ordenamientos ---------------------------------------------------
int Passenger_ordenarPorId(void* pass1 ,void* pass2)
{
    int retorno = 0;

    Passenger* pasajero1 = NULL;
    Passenger* pasajero2 = NULL;

    if(pass1 != NULL && pass2 != NULL)
    {
    	pasajero1 = (Passenger*) pass1;
    	pasajero2 = (Passenger*) pass2;

        if(pasajero1->id > pasajero2->id)
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

int Passenger_ordenarNombre(void* pass1 ,void* pass2)
{
    int retorno = 0;
    Passenger* pasajero1 = NULL;
    Passenger* pasajero2 = NULL;

    if(pass1 != NULL && pass2 != NULL)
    {
    	pasajero1 = (Passenger*) pass1;
    	pasajero2 = (Passenger*) pass2;

        if(strcmp(pasajero1->nombre,pasajero2->nombre) > 0)
        {
            retorno = 1;
        }
        else
        {
            if(strcmp(pasajero1->nombre,pasajero2->nombre)== 0)
            {
                retorno = 0;
            }
            else
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}

int Passenger_ordenarApellido(void* pass1 ,void* pass2)
{
    int retorno = 0;
    Passenger* pasajero1 = NULL;
    Passenger* pasajero2 = NULL;

    if(pass1 != NULL && pass2 != NULL)
    {
    	pasajero1 = (Passenger*) pass1;
    	pasajero2 = (Passenger*) pass2;

        if(stricmp(pasajero1->apellido,pasajero2->apellido) > 0)
        {
            retorno = 1;
        }
        else
        {
            if(stricmp(pasajero1->apellido,pasajero2->apellido)== 0)
            {
                retorno = 0;
            }
            else
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}

int Passenger_ordenarPorPrecio(void* pass1 ,void* pass2)
{
    int retorno = 0;

    Passenger* pasajero1 = NULL;
    Passenger* pasajero2 = NULL;

    if(pass1 != NULL && pass2 != NULL)
    {
    	pasajero1 = (Passenger*) pass1;
    	pasajero2 = (Passenger*) pass2;

        if(pasajero1->precio > pasajero2->precio)
        {
            retorno = 1;
        }
        else
        {
            if(pasajero1->precio == pasajero2->precio)
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

int Passenger_ordenarPorTipoPass(void* pass1 ,void* pass2)
{
    int retorno = 0;
    char desc1[20];
    char desc2[20];

    Passenger* pasajero1 = NULL;
    Passenger* pasajero2 = NULL;

    if(pass1 != NULL && pass2 != NULL)
    {
    	pasajero1 = (Passenger*) pass1;
    	pasajero2 = (Passenger*) pass2;

    	cargarEstadoVuelo(pasajero1->tipoPasajero, desc1);
    	cargarEstadoVuelo(pasajero2->tipoPasajero, desc2);

        if(stricmp(desc1,desc2) )
        {
            retorno = 1;
        }
        else
        {
            if(stricmp(desc1,desc2) == 0 )
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

int Passenger_ordenarPorEstadoVuelo(void* pass1 ,void* pass2)
{
    int retorno = 0;
    char desc1[20];
    char desc2[20];

    Passenger* pasajero1 = NULL;
    Passenger* pasajero2 = NULL;

    if(pass1 != NULL && pass2 != NULL)
    {
    	pasajero1 = (Passenger*) pass1;
    	pasajero2 = (Passenger*) pass2;

    	cargarEstadoVuelo(pasajero1->estadoVuelo, desc1);
    	cargarEstadoVuelo(pasajero2->estadoVuelo, desc2);

        if(stricmp(desc1,desc2) )
        {
            retorno = 1;
        }
        else
        {
            if(stricmp(desc1,desc2) == 0)
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
/*int Passenger_ordenarPorTipoPass(void* pass1 ,void* pass2)
{
    int retorno = 0;

    Passenger* pasajero1 = NULL;
    Passenger* pasajero2 = NULL;

    if(pass1 != NULL && pass2 != NULL)
    {
    	pasajero1 = (Passenger*) pass1;
    	pasajero2 = (Passenger*) pass2;

        if(pasajero1->tipoPasajero > pasajero2->tipoPasajero)
        {
            retorno = 1;
        }
        else
        {
            if(pasajero1->tipoPasajero == pasajero2->tipoPasajero)
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

int Passenger_ordenarPorEstadoVuelo(void* pass1 ,void* pass2)
{
    int retorno = 0;

    Passenger* pasajero1 = NULL;
    Passenger* pasajero2 = NULL;

    if(pass1 != NULL && pass2 != NULL)
    {
    	pasajero1 = (Passenger*) pass1;
    	pasajero2 = (Passenger*) pass2;

        if(pasajero1->estadoVuelo > pasajero2->estadoVuelo)
        {
            retorno = 1;
        }
        else
        {
            if(pasajero1->estadoVuelo == pasajero2->estadoVuelo)
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
*/
