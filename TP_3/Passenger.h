/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define NOMBRE 50
#define APELLIDO 50
#define TIPO 20
#define CODIGO 20

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[20];
	int estadoVuelo;
	//int isEmpty;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);
Passenger* Passenger_newParametrosInt(int id, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo);
void Passenger_delete(Passenger* this);

//----------
int passenger_generarId();
void passenger_setPrimerId(int valorInt);
//----------

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);



//----------
int cargarEstadoVuelo(int valor, char* desc);
int pasarEstadoVueloAInt(char* desc, int *valor);

int cargarTipoPasaje(int valor, char* desc);
int pasarTipoPasajeAInt(char* desc, int *valor);
//----------
int mostrarPasajero(Passenger* pasajero);
int mostrarPasajeroLinea(Passenger* pasajero);

// Ordenamientos ---------------------------------------------------
int Passenger_ordenarPorId(void* pass1 ,void* pass2);
int Passenger_ordenarNombre(void* pass1 ,void* pass2);
int Passenger_ordenarApellido(void* pass1 ,void* pass2);
int Passenger_ordenarPorPrecio(void* pass1 ,void* pass2);
int Passenger_ordenarPorTipoPass(void* pass1 ,void* pass2);
int Passenger_ordenarPorEstadoVuelo(void* pass1 ,void* pass2);

#endif /* PASSENGER_H_ */
