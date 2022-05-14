/*
 ============================================================================
 Name        : TP2_Pruebas.c
 Author      : Roberto Pardo
 Version     :
 Copyright   : Roberto Pardo
 Description : TP_2 1G UTN Fra
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "utn.h"
#include "rPardo.h"

#define TAM 2000
#define TAM_NOMBRE 51
#define TAM_APELLIDO 51
#define TAM_FLYCODE 10
#define TAM_VUELO 4

#define ASC 1
#define DESC 0

int main(void) {
	setbuf(stdout,NULL);

	eVuelo vuelos[TAM_VUELO] = {
		{1, "Turista"},
		{2, "Turista +"},
		{3, "Ejecutiva"},
		{4, "Primera"}
	};

	Passenger lista[TAM];

	int nextId = 1;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];
	float precio;
	char flycode[TAM_FLYCODE];
	int tipoPasaje;
	int estadoPasaje;
	char salir = 'n';
	char continuarOpciones;
	char salirOrden = 'n';
	int flag = 0;

	if(initPassengers(lista, TAM) == -1)
	{
		printf("Hubo un problema al inicializar.\n");
	}

	harcodearPasajeros(lista, TAM, 20, &nextId);

	do{
		system("cls");

		switch(menu())
		{
		case 1:
			continuarOpciones = opcionConfirmar("Continuar con el alta?: s/n","Error, vuelva a intentarlo.\nContinuar con el alta?: s/n");
			if(continuarOpciones == 's' && (cargaDatosPasajero(nombre, apellido, &precio, flycode, &tipoPasaje,&estadoPasaje, TAM_NOMBRE, TAM_APELLIDO, TAM_FLYCODE, vuelos, TAM_VUELO)))
			{
				addPassenger(lista, TAM, nextId, nombre, apellido, precio, tipoPasaje, flycode, estadoPasaje);

				printf("Alta exitosa.\n");

				nextId ++;
				flag = 1;
			}
			break;
		case 2:
			if( flag )
			{
				ordenarPorId(lista, TAM, ASC);
				if( !modificarPasajero(lista, TAM, vuelos, TAM_VUELO) )
				{
					printf("Hubo un problema con los datos de los pasajeros.\n");
				}
			}
			else{
				printf("No hay pasajeros cargados en el sistema\n");
			}
			break;
		case 3:
			if( flag )
			{
				ordenarPorId(lista, TAM, ASC);
				if( !removePassenger(lista, TAM, nextId, vuelos, TAM_VUELO) )
				{
					printf("Hubo un problema con los datos de los pasajeros.\n");
				}
			}
			else{
				printf("No hay pasajeros cargados en el sistema\n");
			}
			break;
		case 4:
			if( flag )
			{
				do{
					system("cls");
					switch(menuInformar())
					{
					case 1:
						if( sortPassengers(lista, TAM, subMenuInformar()))
						{
							printPassenger(lista, TAM, vuelos, TAM_VUELO);
						}
						else{
							printf("Hubo un error al realizar el ordenamiento\n");
						}
						break;
					case 2:
						if( !mostrarPromedioYTotal(lista, TAM))
						{
							printf("Hubo un error al realizar el ordenamiento\n");
						}
						break;
					case 3:
						if( sortPassengersStatus(lista, TAM, subMenuInformar()))
						{
							printPassenger(lista, TAM, vuelos, TAM_VUELO);
							//ordenarPorId(lista, TAM, ASC);
						}
						else{
							printf("Hubo un error al realizar el ordenamiento\n");
						}
						break;
					case 4:
							if( ordenarPorId(lista, TAM, subMenuInformar()))
							{
								printPassenger(lista, TAM, vuelos, TAM_VUELO);
								//ordenarPorId(lista, TAM, ASC);
							}
							else{
								printf("Hubo un error al realizar el ordenamiento\n");
							}
						break;
					case 5:
						salirOrden = opcionConfirmar("Seguro que quiere salir? s/n ", "Error, vuelva a intentarlo. Salir? s/n ");
					default:
						printf("Opcion invalida. Intente nuevamente.\n");
						break;
					}
					system("pause");
				}while(salirOrden == 'n');
			}
			else{
				printf("No hay pasajeros cargados en el sistema\n");
			}
			break;
		case 5:
			salir = opcionConfirmar("Seguro que quiere salir? s/n ", "Error, vuelva a intentarlo. Salir? s/n ");
			break;
		default:
			printf("Opcion invalida. Intente nuevamente.\n");
			fflush(stdin);
		}
		system("pause");

	}while(salir == 'n');

	return EXIT_SUCCESS;
}
