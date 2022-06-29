#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int error = -1;
	//char bufferDatos[7][128];
	//char tipoPasaje;
	//char estadoPasaje;
	int bufferint;
	char id[50];
	char nombre[50];
	char apellido[50];
	char precio[50];
	char tipoPasaje[50];
	char codigoVuelo[50];
	char estadoVuelo[50];
	int maxId = -1;
	int cantidadElementos;
	Passenger* nuevoPasajero;
	nuevoPasajero = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasaje,estadoVuelo);

				//pasarTipoPasajeAInt(bufferDatos[5], &tipoPasaje);
				//pasarEstadoVueloAInt(bufferDatos[6], &estadoPasaje);
		do{
			cantidadElementos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasaje,estadoVuelo);

			if(cantidadElementos == 7)
			{

				nuevoPasajero = Passenger_newParametros(id,nombre,apellido,precio,codigoVuelo,tipoPasaje,estadoVuelo);

				if(nuevoPasajero != NULL)
				{
					if(!ll_add(pArrayListPassenger, nuevoPasajero))
					{
						Passenger_getId(nuevoPasajero, &bufferint);

						if(bufferint>maxId)
						{
							maxId = bufferint;
						}
					}

					error = 0;
				}
			}
			else
			{
				break;
			}

		}while(!feof(pFile));
		//passenger_setPrimerId(maxId+1);

		//fclose(pFile);
	}

	return error;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int error = -1;
	int cant;
	Passenger* nuevoPasajero;
	nuevoPasajero = NULL;


	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		do
		{
			nuevoPasajero = Passenger_new();

			if(nuevoPasajero != NULL)
			{
				cant = fread(nuevoPasajero, sizeof(Passenger),1,pFile);
				if(cant == 1)
				{
					ll_add(pArrayListPassenger, nuevoPasajero);
					error = 0;
					nuevoPasajero = NULL;
				}
			}
			else
			{
				Passenger_delete(nuevoPasajero);
				break;
			}
		}while(!feof(pFile));

	}
	  //fclose(pFile);
	return error;
}
