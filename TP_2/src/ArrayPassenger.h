/*
 * ArrayPassenger.h
 *
 *  Created on: 8 may. 2022
 *      Author: Roberto i3
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "vuelo.h"

typedef struct
{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int idVuelo;		// económica o turística. económica superior. Business o Ejecutiva. Primera clase.
//	int typePasseger;	// Activo o Inactivo
	int statusFlight;
	int isEmpty;
}Passenger;

#endif /* ARRAYPASSENGER_H_ */



/**
 * @brief	menu de opciones
 *
 * @return	retorna la opcion ingresada
 */
int menu();


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);


/**
 * @brief
 *
 * @param vec
 * @param tam
 * @param pIndex
 * @return
 */
int buscarLibre(Passenger vec[], int tam);


/**
 * @brief
 *
 * @param nombre
 * @param apellido
 * @param precio
 * @param flycode
 * @param tipoPasaje
 * @param estadoPasaje
 * @param tamNombre
 * @param tamApellido
 * @param tamFlycode
 * @param vuelos
 * @param tamVuelos
 * @return
 */
int cargaDatosPasajero(char* nombre, char* apellido, float* precio, char* flycode, int* tipoPasaje, int* estadoPasaje, int tamNombre, int tamApellido, int tamFlycode, eVuelo* vuelos, int tamVuelos);


/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int estadoPasaje);



/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len, int id);



/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id, eVuelo* vuelo, int tamVuelo);




/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);


/**
 * @brief	menu de opciones
 *
 * @return	retorna la opcion ingresada
 */
int menuInformar();


/**
 * @brief	menu de opciones
 *
 * @return	retorna la opcion ingresada
 */
int subMenuInformar();



/**
 * @brief
 *
 * @param vec		Array de elementos a ordenar
 * @param tam		Tamaño del array
 * @param criterio	forma de ordenar. 1 Ascendente. 0 Descendente
 * @return
 */
int ordenamiento(Passenger* vec, int tam, int criterio);



/** \brief print the content of passengers array
*
* \param list Passenger*	Array de pasajeros a mostrar
* \param length int			Tamaño del array
* \return int				retorna 0 si algo fallo. retorna 1 si termino bien
*
*/
int printPassenger(Passenger* list, int length, eVuelo* vuelo, int tamVuelo);


/**
 * @brief			muestra los datos de un solo elemento en columna
 *
 * @param vec		el elemento a ser mostrado
 * @param vuelo		array de otra estructura que contiene datos del elemento a mostrar
 * @param tamVuelo	tamaño del array de la otra estructura
 */
void mostrarPasajero(Passenger vec, eVuelo* vuelo, int tamVuelo);


/**
 * @brief
 *
 * @param vec		muestra los datos de un solo elemento en una fila
 * @param vuelo		array de otra estructura que contiene datos del elemento a mostrar
 * @param tamVuelo	tamaño del array de la otra estructura
 */
void mostrarPasajeroFila(Passenger vec, eVuelo* vuelo, int tamVuelo);


/**
 * @brief		Recibe un elementos lee un campo de la estuctura que recibio y segun que valor tenga el campo
 * 				carga en la cadena una descrpcion u otra
 *
 * @param vec	estructura con el campo a analizar
 * @param desc	cadena donde se cargara la descrcipcion
 * @return		retorna 0 si algo fallo. retorna 1 si termino bien
 */
int cargarEstadoPasaje(Passenger vec, char desc[]);



/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersStatus(Passenger* list, int len, int order);


/**
 * @brief 		Recibe un array de elementos y se suma el valor de cada elemento y se saca el promedio total
 * 				tambien cuantos elementos superan ese valor promedio
 *
 * @param list	Array de elementos
 * @param len	tamaño del array
 * @return
 */
int mostrarPromedioYTotal(Passenger* list, int len);


/**
 * @brief		Recibe un array de elemento y lo devuelve ordenado por Id segun criterio elegido 1 Ascendente. 0 Descendente
 *
 * @param list	Array a ordenar
 * @param len	tamaño  del array
 * @param order	criterio de orden. 1 Ascendente. 0 Descendente
 * @return		retorna 1 si salio bien. retorna 0 si algo salio mal
 */
int ordenarPorId(Passenger* list, int len, int order);


/**
 * @brief			Recibe un array de estructuras las que se podran modificar los valores de sus campos
 *
 * @param vec		array de estructuras
 * @param tam		tamaño del array
 * @param vuelo		otro array de estructuras que contiene datos del array principal
 * @param tamVuelo	tamaño del otro array
 * @return
 */
int modificarPasajero(Passenger* vec, int tam, eVuelo* vuelo, int tamVuelo);


/**
 * @brief	menu de opciones
 *
 * @return	retorna la opcion ingresada
 */
int menuModificar();


/**
 * @brief			Carga forzada de datos para realizar pruebas
 *
 * @param vec		array de estructuras
 * @param tam		tamaño del array
 * @param cant		cantidad de elementos del array que queremos cargar
 * @param pNextId	puntero a entero que tiene el valor de Id de cada elemento segun se va cargando
 * @return
 */
int harcodearPasajeros(Passenger vec[], int tam, int cant, int* pNextId);
