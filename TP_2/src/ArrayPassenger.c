/*
 * ArrayPassenger.c
 *
 *  Created on: 8 may. 2022
 *      Author: Roberto i3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "utn.h"
#include "rPardo.h"
#include "vuelo.h"



int menu()
{
    int opcion;
    printf("-------------------------------------\n");
    printf("        *** ABM Pasajeros ***        \n");
    printf("-------------------------------------\n");
    printf("1- Altas \n");
    printf("2- Modificar \n");
    printf("3- Baja \n");
    printf("4- Informar \n");
    printf("5- Salir \n");
    scanf("%d", &opcion);

    return opcion;
}


//===============================================================================================
//	2.1 Funcion
int initPassengers(Passenger* list, int len)
{
    int exito = 0;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
        	list[i].isEmpty = 1;
        }
        exito = 1;
    }

    return exito;
}


//===============================================================================================
int buscarLibre(Passenger vec[], int tam)
{
    int indice = -1;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


int cargaDatosPasajero(char* nombre, char* apellido, float* precio, char* flycode, int* tipoPasaje, int* estadoPasaje, int tamNombre, int tamApellido, int tamFlycode, eVuelo* vuelos, int tamVuelos){
	int todoOk = 0;
	//int codigoVuelo;

	if(nombre != NULL && apellido != NULL && precio != NULL && flycode != NULL && tipoPasaje != NULL)
	{
		utn_getCadena(nombre, tamNombre, "Ingrese nombre del pasajero: ", "Error. Ingrese nombre nuevamente: ", 4);
		while(!esNombreValido(nombre, tamNombre))
		{
			printf("Error. Ingrese nombre nuevamente: ");
			utn_getCadena(nombre, tamNombre, "Ingrese nombre del pasajero: ", "Error. Ingrese nombre nuevamente: ", 4);
		};
		formatoInicialMayuscula(nombre);

		utn_getCadena(apellido, tamApellido, "Ingrese apellido del pasajero: ", "Error. Ingrese apellido nuevamente: ", 4);
		while(!esNombreValido(apellido, tamApellido))
		{
			printf("Error. Ingrese apellido nuevamente: ");
			utn_getCadena(apellido, tamApellido, "Ingrese apellido del pasajero: ", "Error. Ingrese apellido nuevamente: ", 4);
		};
		formatoInicialMayuscula(apellido);

		utn_getNumeroFloat(precio, "Ingrese Precio de vuelo: ", "Error. Ingrese Precio de vuelo nuevamente: ", 0, 999999999, 4);

		utn_getCadena(flycode, tamFlycode, "Ingrese Codigo de Vuelo: (XX111)", "Error. Ingrese Codigo de Vuelo: (XX111)", 4);
		strcpy(flycode,strupr(flycode));

		listarVuelos(vuelos, tamVuelos);
		utn_getNumero(tipoPasaje, "Ingrese tipo de pasaje: 1 - 4: ", "Error. Ingrese tipo de pasaje nuevamente: ", 1, 4, 4);

		utn_getNumero(estadoPasaje, "Ingrese estado de vuelo: \n1 Activo\n2 Inactivo\n ", "Error. Ingrese estado de vuelo: \n1 Activo\2 Inactivo\n ", 1, 2, 4);

		todoOk = 1;
	}
	return todoOk;
}




//	2.2 Funcion
//int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], eVuelo* vuelo, int tamVuelo)
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int estadoPasaje)
{
	int estado = -1;
	int indice;
	Passenger auxPasajero;


	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && flycode != NULL)
	{
		indice = buscarLibre(list, len);

		if(indice == -1)
		{
			printf("No hay espacio disponible en el sistema\n");
		}
		else{

			auxPasajero.id = id;
			strcpy(auxPasajero.name, name);
			strcpy(auxPasajero.lastname, lastName);
			auxPasajero.price = price;
			strcpy(auxPasajero.flycode, flycode);
			auxPasajero.idVuelo = typePassenger;
			auxPasajero.statusFlight = estadoPasaje;
			auxPasajero.isEmpty = 0;

			list[indice] = auxPasajero;

			estado = 0;
		}
	}

	return estado;
}


//===============================================================================================
//	2.3 Funcion
int findPassengerById(Passenger* list, int len, int id)
{
    int index = -1;

    if(list != NULL && len > 0 )
    {
        //*pIndex = -1;
        for(int i=0; i<len; i++)
        {
            if( !list[i].isEmpty && list[i].id == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

//===============================================================================================
//	2.4 Funcion
int removePassenger(Passenger* list, int len, int id, eVuelo* vuelo, int tamVuelo)
{
	int exito = 0;
	int indice;
	//int id;
	char confirma;

	if(list != NULL && len > 0 )
	{
		printPassenger(list, len, vuelo, tamVuelo);

		//printf("Ingrese Id: ");
		//scanf("%d", &id);

		utn_getNumero(&id, "Ingrese Id: ", "Error. Ingrese Id: \n ", 1, 2000, 4);

		indice = findPassengerById(list, len, id);
		if( indice == -1)
		{
		   printf("No existe un pasajero con Id: %d en el sistema\n", id);
		}
		else{
			system("cls");
			mostrarPasajero(list[indice], vuelo, tamVuelo);
			confirma = opcionConfirmar("Quiere realizar la baja?:  s/n ", "Error, vuelva a intentarlo. \nQuiere realizar la baja?:  s/n ");

			if(confirma == 's')
			{
				list[indice].isEmpty = 1;
				printf("Baja exitosa\n");
			}
			else{
				printf("Baja cancelada por el usuario\n");
			}
		}
		exito = 1;
	}

	return exito;
}


//===============================================================================================
//	2.5 Funcion
int sortPassengers(Passenger* list, int len, int order)
{
	int exito = -1;

	Passenger auxPasajero;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len-1; i++)
		{
			for(int j=i+1; j<len; j++)
			{
				if( order && ( (list[i].idVuelo == list[j].idVuelo && strcmp(list[i].lastname, list[j].lastname) > 0)  ||
						(list[i].idVuelo != list[j].idVuelo && list[i].idVuelo > list[j].idVuelo ) ) )
				{
					auxPasajero = list[i];
					list[i] = list[j];
					list[j] = auxPasajero;
				}
				else if( !order && ( (list[i].idVuelo == list[j].idVuelo && strcmp(list[i].lastname, list[j].lastname) < 0) ||
						(list[i].idVuelo != list[j].idVuelo && list[i].idVuelo > list[j].idVuelo ) ) )
				{
					auxPasajero = list[i];
					list[i] = list[j];
					list[j] = auxPasajero;
				}
			}
		}
	}

	return exito;
}


int menuInformar()
{
	int opcion;

    printf("----------------------------------------------------\n");
    printf("          *** ABM Informe de Pasajeros ***          \n");
    printf("----------------------------------------------------\n");
    printf("1- Listado de los pasajeros ordenados:\n   Alfabeticamente por apellido y Tipo de pasajero. \n");
    printf("2- Total y promedio de los precios de los pasajes y:\n   Cuantos pasajeros superaron el precio promedio. \n");
    printf("3- Listado de los pasajeros por:\n   Codigo de vuelco y estados de vuelos 'ACTIVO' \n");
    printf("4- Listado de pasajeros por Id\n");
    printf("5- Volver al menu anterior. \n");
    scanf("%d", &opcion);

    return opcion;
}


int subMenuInformar()
{
    int opcion;

    printf("0. Ordenar de forma Descendente\n");
    printf("1. Ordenar de forma Ascendente\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while( !(opcion == 0 || opcion == 1) )
    {
        printf("Opcion invalida\nIngrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}


//===============================================================================================
//	2.6 Funcion
int printPassenger(Passenger* list, int length, eVuelo* vuelo, int tamVuelo)
{
	int exito = 0;
	int flag = 0;

	    if(list != NULL && length > 0)
	    {
	        system("cls");
	        printf("    ----------------------------------------------------------------------------------------\n");
	        printf("                        *** Listado de Pasajeros ***        \n");
	        printf("    Id        Nombre       Apellido      Precio     Cod. Vuelo   Tipo Pasaje	Estado Vuevo\n");
	        printf("    ----------------------------------------------------------------------------------------\n");

	        for(int i=0; i<length; i++)
	        {
	            if( !list[i].isEmpty)
	            {
	                mostrarPasajeroFila(list[i], vuelo, tamVuelo);
	                flag = 1;
	            }
	        }
	        if( !flag)
	        {
	            printf("     No hay empleados cargados en el sistema.\n");
	        }
	        exito = 1;
	    }

	    return exito;
}






void mostrarPasajero(Passenger vec, eVuelo* vuelo, int tamVuelo)
{
    char tipoPasaje[20];
    char estadoPasaje[20];

	cargarTipoPasaje(vuelo, tamVuelo, vec.idVuelo, tipoPasaje);

	cargarEstadoPasaje(vec, estadoPasaje);

    printf("  Id		: %d\n", vec.id);
    printf("  Nombre  	: %s\n", vec.name);
    printf("  Apellido	: %s\n", vec.lastname);
    printf("  Precio	: %.2f\n", vec.price);
    printf("  Cod. vuelo	: %s\n", vec.flycode);
    printf("  Tipo pass	: %s\n", tipoPasaje);
    printf("  Est. Vuelo	: %s\n", estadoPasaje);
    printf("\n");
}

void mostrarPasajeroFila(Passenger vec, eVuelo* vuelo, int tamVuelo)
{
	char tipoPasaje[20];
	char estadoPasaje[20];

	cargarTipoPasaje(vuelo, tamVuelo, vec.idVuelo, tipoPasaje);

	cargarEstadoPasaje(vec, estadoPasaje);

    printf("  %4d    %10s	%10s     %9.2f   %10s    %10s	%10s\n",
           vec.id, vec.name, vec.lastname, vec.price, vec.flycode, tipoPasaje, estadoPasaje);
}

int cargarEstadoPasaje(Passenger vec, char desc[])
{
    int exito = 0;

    if(desc != NULL )
    {
    	if(vec.statusFlight)
    	{
    		strcpy(desc, "Activo");
    	}
    	if(vec.statusFlight == 2)
    	{
    		strcpy(desc, "Inactivo");
    	}

    	exito = 1;
    }

    return exito;
}



//===============================================================================================
//	2.7 Funcion 	por codigo de vuelo y estado
int sortPassengersStatus(Passenger* list, int len, int order)
{
	int exito = -1;

	Passenger auxPasajero;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len-1; i++)
		{
			for(int j=i+1; j<len; j++)
			{
				if( order && ( (list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flycode, list[j].flycode) > 0) ||
						(list[i].statusFlight != list[j].statusFlight && list[i].statusFlight > list[j].statusFlight ) ) )
				{
					auxPasajero = list[i];
					list[i] = list[j];
					list[j] = auxPasajero;
				}
				else if( !order && ( (list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flycode, list[j].flycode) < 0) ||
						(list[i].statusFlight != list[j].statusFlight && list[i].statusFlight > list[j].statusFlight ) ) )
				{
					auxPasajero = list[i];
					list[i] = list[j];
					list[j] = auxPasajero;
				}
			}
		}
	}

		return exito;
}

//===============================================================================================
// Calcular Precio total de los pasajes y promedio de los pasajes. Y cuantos pasajeros superan el precio promedio
int mostrarPromedioYTotal(Passenger* vec, int tam)
{
    int exito = 0;
    int cont = 0;
    float precio = 0;
    float promedio;
    int superaPromedio = 0;
    int flag = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if( !vec[i].isEmpty)
            {
            	precio += vec[i].price;
                cont ++;
                flag = 1;
            }
        }
		if( !flag)
		{
			printf("     No hay empleados cargados en el sistema.\n");
		}

		if(cont != 0)
		{
			printf("El precio de total de los Pasajes es	: %.2f\n", precio);
			promedio = precio / cont;
			printf("El promedio de precio de los Pasajes es	: %.2f\n", promedio);

			for(int i=0; i<tam; i++)
			{
				if( !vec[i].isEmpty && vec[i].price > promedio)
				{
					superaPromedio ++;
				}
			}
			printf("La cantidad de pasajeseros que superan\nel precio promedio de pasaje es		: %d\n", superaPromedio);
			exito = 1;
		}
    }

    return exito;
}

//===============================================================================================
// Orden por Id para volver a darle orden despues de los informes
int ordenarPorId(Passenger* list, int len, int order)
{
	int exito = -1;

	Passenger auxPasajero;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len-1; i++)
		{
			for(int j=i+1; j<len; j++)
			{
				if( order && ( (list[i].id > list[j].id ) ) )
				{
					auxPasajero = list[i];
					list[i] = list[j];
					list[j] = auxPasajero;
				}
				else if( !order && ( (list[i].id < list[j].id ) ) )
				{
					auxPasajero = list[i];
					list[i] = list[j];
					list[j] = auxPasajero;
				}
			}
		}
	}

	return exito;
}



//===============================================================================================
int modificarPasajero(Passenger* vec, int tam, eVuelo* vuelo, int tamVuelo)
{
	int exito = 0; //
	int indice;
	int id;
	char confirma;
	char salir = 'n';

	int tamNombre = 51;
	int tamApellido = 51;
	int tamFlycode = 10;
	//int flycode;
	//float precio;
	Passenger auxPasajero;

	if(vec != NULL && tam > 0 && vuelo != NULL && tamVuelo > 0)
	{
		printPassenger(vec, tam, vuelo, tamVuelo);

		utn_getNumero(&id, "Ingrese Id: ", "Error. Ingrese Id: \n ", 1, 2000, 4);
		indice = findPassengerById(vec, tam, id);

		if(indice == -1)
		{
			printf("No existe un pasajero con el Id %d.\n", id);
		}
		else{
			mostrarPasajero(vec[indice], vuelo, tamVuelo);

			confirma = opcionConfirmar("Quiere modificar este pasajero?: s/n \n", "Error.\nQuiere modificar este pasajero?: s/n \n");

			if(confirma == 's')
			{
				do{
					system("cls");
					mostrarPasajero(vec[indice], vuelo, tamVuelo);

					switch(menuModificar())
					{
					case 1:
						utn_getCadena(auxPasajero.name, tamNombre, "Ingrese nombre del pasajero: ", "Error. Ingrese nombre nuevamente: ", 4);
						while(!esNombreValido(auxPasajero.name, tamNombre))
						{
							printf("Error. Ingrese nombre nuevamente: ");
							utn_getCadena(auxPasajero.name, tamNombre, "Ingrese nombre del pasajero: ", "Error. Ingrese nombre nuevamente: ", 4);
						};
						formatoInicialMayuscula(auxPasajero.name);
						strcpy(vec[indice].name,auxPasajero.name);
						break;
					case 2:
						utn_getCadena(auxPasajero.lastname, tamApellido, "Ingrese apellido del pasajero: ", "Error. Ingrese apellido nuevamente: ", 4);
						while(!esNombreValido(auxPasajero.lastname, tamApellido))
						{
							printf("Error. Ingrese nombre nuevamente: ");
							utn_getCadena(auxPasajero.lastname, tamApellido, "Ingrese apellido del pasajero: ", "Error. Ingrese apellido nuevamente: ", 4);
						};
						formatoInicialMayuscula(auxPasajero.lastname);
						strcpy(vec[indice].lastname,auxPasajero.lastname);
						break;
					case 3:
						utn_getNumeroFloat(&auxPasajero.price, "Ingrese Precio de vuelo: ", "Error. Ingrese Precio de vuelo nuevamente: ", 0, 999999999, 4);
						vec[indice].price = auxPasajero.price;
						break;
					case 4:
						utn_getCadena(auxPasajero.flycode, tamFlycode, "Ingrese Codigo de Vuelo: (XX111)", "Error. Ingrese Codigo de Vuelo: (XX111)", 4);
						strcpy(auxPasajero.flycode,strupr(auxPasajero.flycode));
						strcpy(vec[indice].flycode,auxPasajero.flycode);
						break;
					case 5:
						listarVuelos(vuelo, tamVuelo);
						utn_getNumero(&auxPasajero.idVuelo, "Ingrese tipo de pasaje: 1 - 4: ", "Error. Ingrese tipo de pasaje nuevamente: ", 1, 4, 4);
						vec[indice].idVuelo = auxPasajero.idVuelo;
						break;
					case 6:
						utn_getNumero(&auxPasajero.statusFlight, "Ingrese estado de vuelo: \n1 Activo\n2 Inactivo\n ", "Error. Ingrese estado de vuelo: \n1 Activo\2 Inactivo\n ", 1, 2, 4);
						vec[indice].statusFlight = auxPasajero.statusFlight;
						break;
					case 7:
						salir = opcionConfirmar("Seguro que quiere salir? s/n ", "Error, vuelva a intentarlo. Salir? s/n ");
					break;
					default:
						printf("Opcion invalida. Intente nuevamente.\n");
						break;
					}
				}while(salir == 'n');
			}
			else{
				printf("Modificacion cancelada por el usuario.\n");
			}
		}
		exito = 1;
	}
	return exito;
}


int menuModificar()
{
    int opcion;
    printf("-------------------------------------\n");
    printf("        *** ABM Pasajeros ***        \n");
    printf("-------------------------------------\n");
    printf("1- Modificar nombre del pasajero \n");
    printf("2- Modificar apellido del pasajero \n");
    printf("3- Modificar precio del pasaje \n");
    printf("4- Modificar codigo de vuelo \n");
    printf("5- Modificar tipo de pasaje \n");
    printf("6- Modificar estado de vuelo \n");
    printf("7- Salir \n");
    scanf("%d", &opcion);

    return opcion;
}


//===============================================================================================
//===============================================================================================

int harcodearPasajeros(Passenger vec[], int tam, int cant, int* pNextId)   // cant: cantidad de elemento del array que queremos harcodear
{
    int exito = 0;

    Passenger pasajeros[] = {
    {0,"Juan","Perez",21000.00,"AR001",1,2,0},
    {0,"Miguel","Sanchez",21500.00,"AR011",1,1,0},
    {0,"Juana","Dearco",23000.00,"AR017",1,2,0},
    {0,"Andrea","Rivas",120000.00,"MX033",2,1,0},
    {0,"Juliana","Frias",195000.00,"CL001",3,2,0},
    {0,"Martin","Demichelis",51000.00,"UY049",2,1,0},
    {0,"Dario","Husain",81000.00,"CL001",2,1,0},
    {0,"Alicia","Latina",183000.00,"MX102",3,2,0},
    {0,"Javier","Masche",201000.00,"BR012",4,1,0},
    {0,"Diego","Mastro",220000.00,"AR010",4,1,0},
    {0,"Frida","Raij",111000.00,"MX301",2,2,0},
    {0,"Marcos","Aurelio",184000,"MX237",3,1,0},
    {0,"Julian","Alvares",254000,"UK149",4,1,0},
    {0,"Andres","Dalesandro",45000,"BR334",1,2,0},
    {0,"Jose","Zosa",29000,"AR764",1,1,0},
    {0,"Martina","Francci",66000,"AR942",1,2,0},
    {0,"Donna","Dominich",182000,"CL457",2,1,0},
    {0,"Angel","Diaz",37000,"AR649",1,2,0},
    {0,"Josefina","Latorre",96000,"UY937",3,1,0},
    {0,"Dolores","Paz",35000,"AR723",1,2,0}
    };

    if(vec != NULL && pNextId != NULL && tam > 0 && tam <= 2000 && cant <= 20)
    {
        for(int i=0; i<cant; i++)
        {
            vec[i] = pasajeros[i];
            vec[i].id = *pNextId;
            (*pNextId) ++;
        }
    }

    return exito;
}



