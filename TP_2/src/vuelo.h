/*
 * vuelo.h
 *
 *  Created on: 9 may. 2022
 *      Author: Roberto i3
 */

#ifndef VUELO_H_
#define VUELO_H_

typedef struct
{
	int id;
	char tipoPasaje[20];
	int isEmpty;
}eVuelo;

#endif /* VUELO_H_ */


/**
 * @brief
 *
 * @param vuelos
 * @param tam
 * @param id
 * @param desc
 * @return
 */
int cargarTipoPasaje(eVuelo vuelos[], int tam, int id, char desc[]);


/**
 * @brief		Verifica si existe un elemento en el array al ser buscado por su numero de Id
 *
 * @param vec	array de estructuras
 * @param tam	tamaño del array
 * @param id	id de busqueda con el que comparara a todos los elementos del array
 * @return		retorna 1 si encontro un elemento. retona 0 si no encontro
 */
int validarIdVuelo(eVuelo vec[], int tam, int id);


/**
 * @brief			muestra todos los elementos que no esten vacios de un array
 *
 * @param vuelos	array a mostrar
 * @param tam		tamaño del array
 * @return			retorna 1 si salio bien. retorna 0 si algo salio mal
 */
int listarVuelos(eVuelo vuelos[], int tam);


/**
 * @brief			busca un elemento de un array por su numero de Id
 *
 * @param vec		array a bucar
 * @param tam		tamaño del array
 * @param id		numero Id para buscar
 * @param pIndex
 * @return			retorna 1 si salio bien. retorna 0 si algo salio mal
 */
int buscarVuelo(eVuelo vec[], int tam, int id, int* pIndex);



