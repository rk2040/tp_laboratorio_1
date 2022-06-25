/*
 * datos.h
 *
 *  Created on: 25 jun. 2022
 *      Author: Roberto i3
 */

#ifndef DATOS_H_
#define DATOS_H_



#endif /* DATOS_H_ */


/**
 * @brief 				Ingresamos Bandera de control y la cantidad de kilometros de vuelo
 *
 * @param pFlagOpcion	Puntero a bandera de control para el menu
 * @param km			Puntero a kilometros ingresados que se imprimiran en el menu
 * @return				Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int ingresaKilometros(int* pFlagOpcion, int* km);



/**
 * @brief	Pide que ingresamos un precio
 *
 * @return	Retorna el precio ingresado
 */
float ingresarPrecio();


/**
 * @brief 				Ingresamos Bandera de control y dos precios de vuelos, uno para cada aerolinea
 *
 * @param pFlagOpcion	Puntero a bandera de control para el menu
 * @param pPrecio1		Puntero al 1er precio
 * @param pPrecio2		Puntero al 2do precio
 * @return				Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int ingresaPrecioVuelo(int* pFlagOpcion, float* pPrecio1, float* pPrecio2);


void informarResultados(float resultado1, float resultado2, float resultado3, float resultado4);

/**
 * @brief 				Carga de valores  de las operaciones de forma forzada con valores ya preingresados
 *
 * @param km			Puntero a los kilometros preingresados (no por el usuario)
 * @param precio1		Puntero a 1er precio preingresados (no por el usuario)
 * @param precio2		Puntero a 2do precio preingresados (no por el usuario)
 */
void cargaForzada(int* km, float* precio1, float* precio2);

/**
 * @brief 				Vuelve todos los valores cargados a 0, incluyndo las Banderas
 *
 * @param pFlagOpcion	Puntero a bandera de control para el menu
 * @param km			Puntero a los kilometros
 * @param precio1		Puntero a 1er precio
 * @param precio2		Puntero a 2do precio
 * @return				Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int resetValores(int* pFlagOpcion, int* km, float* precio1, float* precio2);
