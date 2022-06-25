/*
 * menu.h
 *
 *  Created on: 24 jun. 2022
 *      Author: Roberto i3
 */

#ifndef MENU_H_
#define MENU_H_



#endif /* MENU_H_ */

/**
 * @brief			Muestra el menu de opciones y retorna la opcion seleccionada de 1 a 6
 *
 * @param num1		Kilometros ingresados que se imprimiran en el menu
 * @param num2		1er precio ingresado que se imprimiran en el menu
 * @param num3		2do precio ingresado que se imprimiran en el menu
 * @return			retorna el valor de la opcion elegida
 */
int menu(int num1, float num2, float num3);


/**
 * @brief 			Muestra un sub menu de opciones y retorna la opcion seleccionada de 1 a 3
 *
 * @param pPrecio1	Puntero al 1er precio
 * @param pPrecio2	Puntero al 2do precio
 * @return			Retorna el valor de la opcion elegida
 */
int menuPrecio(float* pPrecio1, float* pPrecio2);


/**
 * @brief 				Muestra un sub menu con las operaciones que se van a realizar
 *
 * @param pFlagOpcion	Puntero a bandera de control para el menu
 * @return				Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int menuOperaciones(int* pFlagOpcion);



/**
 * @brief 			Opcion para salir con confirmacion
 *
 * @param salir	 	Puntero a parametro de contro de opcion salir: 's' sale  y  'n' no sale
 * @return			Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int salida(char* salir);
