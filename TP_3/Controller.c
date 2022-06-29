#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "parser.h"
#include "menu.h"
#include "utn.h"
#include "rPardo.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* f;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		f = fopen(path,"r");
		if(f != NULL && !parser_PassengerFromText(f, pArrayListPassenger))
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

/** \brief Carga los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* f;

	if(path !=NULL && pArrayListPassenger != NULL)
	{
		f = fopen(path,"rb");

		if(f != NULL )
		{
			parser_PassengerFromBinary(f, pArrayListPassenger);
			retorno = 0;
		}

		fclose(f);
	}

	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int error = -1;
    int id;
    char nombre[50];
    char apellido[50];
	float precio;
    int tipoPasajero;
    char descTipoPas[20];
    char codigoVuelo[10];
    int estadoVuelo;
    char descEstadoVuelo[20];

    Passenger* nuevoPasajero;
    nuevoPasajero = NULL;

    if(pArrayListPassenger != NULL)
    {
    	nuevoPasajero = Passenger_new();
    	//id = passenger_generarId();
		id = buscarMayorId(pArrayListPassenger);	// Busco el ultimo id de la lista
		id = id +1;									// y le sumo 1 al id del nuevo elemento

		pedirCadena(nombre, "Ingrese nombre del pasajero: ", 50);
		while(strlen(nombre)<=0)
		{
			pedirCadena(nombre, "Ingrese nombre del pasajero: ", 50);
		}
		formatoInicialMayuscula(nombre);

		pedirCadena(apellido, "Ingrese apellido del pasajero: ", 50);
		while(strlen(apellido)<=0)
			{
				pedirCadena(apellido, "Ingrese apellido del pasajero: ", 50);
			}
		formatoInicialMayuscula(apellido);

		validarFloat(&precio, "Ingrese Precio de vuelo: ", "Error. Ingrese Precio de vuelo nuevamente: ", 0, 999999999, 4);

		pedirAlfaNumerico(codigoVuelo, "Ingrese Codigo de Vuelo: (XX111)", 20);
		while(strlen(codigoVuelo)<=0)
				{
				pedirAlfaNumerico(codigoVuelo, "Ingrese Codigo de Vuelo: (XX111)", 20);
				}
		strcpy(codigoVuelo,strupr(codigoVuelo));

		validarEntero(&tipoPasajero, "Ingrese tipo de pasaje:\n1- FirstClass\n2- ExecutiveClass\n3- EconomyClass", "Error. Ingrese tipo de pasaje nuevamente: ", 1, 3, 4);

		validarEntero(&estadoVuelo, "Ingrese estado de vuelo:\n1- Aterrizado\n2- En Vuelo\n3- En Horario\n4- Demorado", "Error. Ingrese tipo de pasaje nuevamente: ", 1, 4, 4);


		cargarTipoPasaje(tipoPasajero, descTipoPas);
		cargarEstadoVuelo(estadoVuelo, descEstadoVuelo);

		if( !Passenger_setId(nuevoPasajero, id) &&
			!Passenger_setNombre(nuevoPasajero, nombre) &&
			!Passenger_setApellido(nuevoPasajero, apellido) &&
			!Passenger_setPrecio(nuevoPasajero, precio) &&
			!Passenger_setCodigoVuelo(nuevoPasajero, codigoVuelo) &&
			!Passenger_setTipoPasajero(nuevoPasajero, tipoPasajero) &&
			!Passenger_setEstadoVuelo(nuevoPasajero, estadoVuelo)
			)
		{
			ll_add(pArrayListPassenger,nuevoPasajero);
			printf("Pasajero cargado exitosamente.\n");
		}
		else
		{
			Passenger_delete(nuevoPasajero);
		}

		error = 0;
    }

    return error;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int indice;
	char confirma;
	char salir = 'n';
	int opcionMenuModif = 0;

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero = 0;
	//char descTipoPas[20];
	char codigoVuelo[10];
	int estadoVuelo = 0;
	//char descEstadoVuelo[20];

	Passenger* auxPasajero;
	auxPasajero = NULL;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);

		if( validarEntero(&id,"Ingrese el Id del Pasajero que desea modificar\n", "Error, ingrese un numero valido\n",0,10000,4))
		{
			indice = buscarPorId(pArrayListPassenger, id);

			if(indice == -1)
			{
				printf("No hay pasajeros con ese Id\n");

			}
			else
			{
				auxPasajero = ll_get(pArrayListPassenger, indice);

				printf("\n PASAJERO A MODIFICAR\n\n");
				mostrarPasajero((Passenger*)ll_get(pArrayListPassenger, indice));

				confirma = opcionConfirmar("Quiere modificar este pasajero?: s/n \n", "Error.\nQuiere modificar este pasajero?: s/n \n");

				if(confirma == 's')
				{
					do
					{
						system("cls");

						printf("\n PASAJERO A MODIFICAR\n\n");
						mostrarPasajero((Passenger*)ll_get(pArrayListPassenger, indice));

						menuModificar(&opcionMenuModif);
						switch(opcionMenuModif)
						{
						case 1:
							pedirCadena(nombre, "Ingrese nombre del pasajero: ", 50);
							formatoInicialMayuscula(nombre);

							if( !Passenger_setNombre(auxPasajero, nombre))
							{
								printf("El nombre se modifico exitosamente\n");
								ll_set(pArrayListPassenger, indice, auxPasajero);
							}
							break;
						case 2:
							pedirCadena(apellido, "Ingrese apellido del pasajero: ", 50);
							formatoInicialMayuscula(apellido);

							if( !Passenger_setApellido(auxPasajero, apellido))
							{
								printf("El apellido se modifico exitosamente\n");
								ll_set(pArrayListPassenger, indice, auxPasajero);
							}
							break;
						case 3:
							validarFloat(&precio, "Ingrese Precio de vuelo: ", "Error. Ingrese Precio de vuelo nuevamente: ", 0, 999999999, 4);

							if( !Passenger_setPrecio(auxPasajero, precio))
							{
								printf("El precio se modifico exitosamente\n");
								ll_set(pArrayListPassenger, indice, auxPasajero);
							}
							break;
						case 4:
							pedirAlfaNumerico(codigoVuelo, "Ingrese Codigo de Vuelo: (XX111)", 10);
							strcpy(codigoVuelo,strupr(codigoVuelo));

							if( !Passenger_setCodigoVuelo(auxPasajero, codigoVuelo))
							{
								printf("El codigo de vuelo se modifico exitosamente\n");
								ll_set(pArrayListPassenger, indice, auxPasajero);
							}
							break;
						case 5:
							validarEntero(&tipoPasajero, "Ingrese tipo de pasaje:\n1- FirstClass\n2- ExecutiveClass\n3- EconomyClass", "Error. Ingrese tipo de pasaje nuevamente: ", 1, 3, 4);
							//auxPasajero->tipoPasajero = tipoPasajero;
							//cargarTipoPasaje(auxPasajero, descTipoPas);
							if( !Passenger_setTipoPasajero(auxPasajero, tipoPasajero))
							{
								printf("El codigo de vuelo se modifico exitosamente\n");
								ll_set(pArrayListPassenger, indice, auxPasajero);
							}
							break;
						case 6:
							validarEntero(&estadoVuelo, "Ingrese estado de vuelo:\n1- Aterrizado\n2- En Vuelo\n3- En Horario\n4- Demorado", "Error. Ingrese tipo de pasaje nuevamente: ", 1, 4, 4);
							//auxPasajero->estadoVuelo = estadoVuelo;
							//cargarEstadoVuelo(auxPasajero, descEstadoVuelo);
							if( !Passenger_setCodigoVuelo(auxPasajero, codigoVuelo))
							{
								printf("El estado de vuelo se modifico exitosamente\n");
								ll_set(pArrayListPassenger, indice, auxPasajero);
							}
							break;
						case 7:
							salir = opcionConfirmar("Seguro que quiere salir? s/n ", "Error, vuelva a intentarlo. Salir? s/n ");
							break;
							}

					}while(salir == 'n');

					retorno = 1;
				}
				else
				{
					printf("Modificacion cancelada por el usuario.\n");
				}
			}
		}
	}

	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 0;
    int id;
    int confirmaBaja = 0;
    int indice;

    Passenger* auxPasajero;
    auxPasajero = NULL;

    if(pArrayListPassenger != NULL)
    {
    	controller_ListPassenger(pArrayListPassenger);

        if( validarEntero(&id,"\nIngrese la id del pasajero que desea dar de baja\n", "\nError, ingrese un numero valido\n",0,10000,4))
        {
            indice = buscarPorId(pArrayListPassenger,id);

            if(indice == -1)
            {
                printf("No hay pasajeros con ese id\n");

            }
            else
            {
            	auxPasajero = ll_get(pArrayListPassenger, indice);

                printf("\n PASAJERO A DAR DE BAJA\n\n");

                mostrarPasajero(auxPasajero);

                confirmaBaja = opcionConfirmar("Quiere modificar este pasajero?: s/n \n", "Error.\nQuiere modificar este pasajero?: s/n \n");

				if(confirmaBaja == 's')
				{
					retorno = 1;
					ll_remove(pArrayListPassenger,indice);
					printf("Baja exitosa.\n");
				}

			}

		}
	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int error = 1;
    int flag = 1;
    int tam;
    char descTipoPass[20];
    char descEstadoVuelo[20];
    Passenger* auxPasajero;

    if(pArrayListPassenger != NULL)
    {
        error = 0;
        printf("-------------------------------------------------------------------------------------------\n");
        printf(" ID         NOMBRE	APELLIDO   PRECIO	COD. VUELO	TIPO PASAJE	 EST. VUELO \n");
        printf("-------------------------------------------------------------------------------------------\n\n");

        tam = ll_len(pArrayListPassenger);
        for(int i = 0; i<tam; i++)
        {
            if(((Passenger*)ll_get(pArrayListPassenger,i))!= NULL)
            {
            	auxPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
            	mostrarPasajeroLinea(auxPasajero);
            	cargarTipoPasaje(auxPasajero->tipoPasajero, descTipoPass);
            	cargarEstadoVuelo(auxPasajero->estadoVuelo, descEstadoVuelo);

            	//printf(" %4d %12s %12s % 10.2f 	%10s %15s 	%10s\n",
            		//	auxPasajero->id, auxPasajero->nombre, auxPasajero->apellido, auxPasajero->precio, auxPasajero->codigoVuelo, descTipoPass, descEstadoVuelo);

                flag = 0;
            }
        }


        if(flag )
        {
            printf("\nNo hay empleados en la lista\n");
        }

        error = 0;
    }

    return error;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int error = -1;
    int pOpcionMenu;
    int criterio;
    int tam;

    if(pArrayListPassenger != NULL)
    {
        tam = ll_len(pArrayListPassenger);


        if(tam > 2)
        {
        	menuOrdenar(&pOpcionMenu);

			if(utn_getNumero(&criterio,"Ingrese el criterio para ordenar\n1 Ascendente\n0 Descendente\n","Error, re ingrese criterio\n",0,1,4))
			{
				error = 0;

					switch(pOpcionMenu)
					{
					case 1:
							if(!criterio)
							{
								printf("\nListado ordenardo por Id descendente\n");
								ll_sort(pArrayListPassenger, Passenger_ordenarPorId,criterio);
							}else
							{
								printf("\nListado ordenardo por Id ascendente\n");
								ll_sort(pArrayListPassenger, Passenger_ordenarPorId,criterio);
							}
							controller_ListPassenger(pArrayListPassenger);
						break;
					case 2:
						if(!criterio)
						{
							printf("\nListado ordenardo por Nombre descendente\n");
							ll_sort(pArrayListPassenger,Passenger_ordenarNombre,criterio);
						}else
						{
							printf("\nListado ordenardo por Nombre ascendente\n");
							ll_sort(pArrayListPassenger,Passenger_ordenarNombre,criterio);
						}
							controller_ListPassenger(pArrayListPassenger);
						break;
					case 3:
						if(!criterio)
						{
							printf("\nListado ordenardo por Apellido descendente\n");
							ll_sort(pArrayListPassenger,Passenger_ordenarApellido,criterio);
						}else
						{
							printf("\nListado ordenardo por Apellido ascendente\n");
							ll_sort(pArrayListPassenger,Passenger_ordenarApellido,criterio);
						}
						controller_ListPassenger(pArrayListPassenger);
						break;
					case 4:
						if(!criterio)
						{
							printf("\nListado ordenardo por Precio descendente\n");
							ll_sort(pArrayListPassenger,Passenger_ordenarPorPrecio,criterio);
						}else
						{
							printf("\nListado ordenardo por Precio ascendente\n");
							ll_sort(pArrayListPassenger,Passenger_ordenarPorPrecio,criterio);
						}
						controller_ListPassenger(pArrayListPassenger);
						break;
					default:
						break;
					}
			}

        }
        else
        {
            printf("\nNo hay empleados en la lista\n");
            error = 1;
        }
    }
    return error;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int error = -1;
    int id;
    char nombre[NOMBRE];
    char apellido[APELLIDO];
    float precio;
    int tipoPasajero;
    char descTipoPasajero[20];
    char codigoVuelo[20];
    int estadoVuelo;
    char descEstadoVuelo[20];
    int tamanio;

    Passenger* auxPasajero;
    auxPasajero = NULL;

    FILE* f;


    if(pArrayListPassenger != NULL && path != NULL)
    {
        f = fopen("data.csv","w");

        if(f != NULL)
        {
            tamanio = ll_len(pArrayListPassenger);
            fprintf(f,"id,nombre,apellido,precio,descTipoPasaje,codigoVuelo,descEstadoVuelo\n");
            for(int i = 0; i<tamanio; i++)
            {
            	auxPasajero = (Passenger*) ll_get(pArrayListPassenger,i);

                if(		!Passenger_getId(auxPasajero,&id) &&
                		!Passenger_getNombre(auxPasajero,nombre) &&
                        !Passenger_getApellido(auxPasajero, apellido) &&
                        !Passenger_getPrecio(auxPasajero, &precio) &&
						!Passenger_getCodigoVuelo(auxPasajero, codigoVuelo) &&
						!Passenger_getTipoPasajero(auxPasajero, &tipoPasajero) &&
						!Passenger_getEstadoVuelo(auxPasajero, &estadoVuelo) )
                {
                	cargarTipoPasaje(tipoPasajero, descTipoPasajero);
                	cargarEstadoVuelo(estadoVuelo, descEstadoVuelo);

                    fprintf(f,"%d,%s,%s,%.0f,%s,%s,%s\n",id,nombre,apellido,precio,descTipoPasajero,codigoVuelo,descEstadoVuelo);
                    error = 0;
                }
            }
            fclose(f);
        }
    }
    return error;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int error = -1;
    int tamanio;
    Passenger* auxpasajero;
    auxpasajero = NULL;

    FILE* f;

    if(path != NULL && pArrayListPassenger != NULL)
    {
        f = fopen(path,"wb");

        if(f != NULL)
        {

            tamanio = ll_len(pArrayListPassenger);

            for(int i = 0; i<tamanio; i++)
            {
            	auxpasajero = ll_get(pArrayListPassenger,i);
            	fwrite(auxpasajero, sizeof(Passenger), 1,f);

                if(auxpasajero != NULL)
                {

                    fwrite(auxpasajero,sizeof(Passenger),1,f);
                    error = 0;
                }
            }

        }
        fclose(f);
    }
    return error;
}

//------------------------------------------------------------------------------------------------------------------

int buscarPorId(LinkedList* this, int idBuscado)
{
    int retorno = -1;
    int auxiliarId;
    int tam;
    Passenger* auxPasajero;

    if(this != NULL && idBuscado > 0)
    {
        tam = ll_len(this);
        for(int i = 0; i<tam; i++)
        {
            auxPasajero = ll_get(this, i);

            if( !Passenger_getId(auxPasajero, &auxiliarId) && auxiliarId == idBuscado )
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}


int buscarMayorId(LinkedList* pArrayListPassenger)
{
    Passenger* auxPasajero = NULL;
    int mayor = 0;
    int id = 0;
    if(pArrayListPassenger != NULL)
    {
        for( int i = 0; i < ll_len(pArrayListPassenger); i++)
        {
        	auxPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
            Passenger_getId(auxPasajero, &id);
            if( i==0 || id > mayor)
            {
                mayor = id;
            }
        }
    }
    return mayor;
}


// Ordenamientos ---------------------------------------------------
