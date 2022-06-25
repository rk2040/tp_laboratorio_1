/*
 * calculos.h
 *
 *  Created on: 24 jun. 2022
 *      Author: Roberto i3
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_



#endif /* CALCULOS_H_ */

/**
 * @brief 			Realiza el calculo de descuento por x %
 *
 * @param precio	precio ingresado sobre el que se calculara el descuento
 * @return			Retorna el valor obtenido
 */
float descuentoDebito(float precio);


/**
 * @brief 			Realiza el calculo de interes por x %
 *
 * @param precio	Precio ingresado sobre el que se calculara el interes
 * @return			Retorna el valor obtenido
 */
float interesCredito(float precio);


/**
 * @brief 			Realiza el calculo del precio si se pagara con Bitcoin
 *
 * @param precio	Precio ingresado sobre el que se calculara el precio a pagar en Bitconin
 * @return			Retorna el valor obtenido
 */
float bitcoin(float precio);


/**
 * @brief 			Realiza el calculo para sacar el precio por 1 kilometro
 *
 * @param km		kiloemtros ingresados con los que se calculara el precio por kilometro
 * @param precio	Precio ingresado sobre el que se calculara el precio por kilometro
 * @return			Retorna el valor obtenido
 */
float precioPorKm(int km, float precio);


/**
 * @brief 			Calcula la diferencia de precio que hay enpre el precio de una aerolinea con otra
 *
 * @param precio1	1er precio ingresado sobre el que se calculara la diferencia de precio
 * @param precio2	2do precio ingresado sobre el que se calculara la diferencia de precio
 * @return			Retorna el valor obtenido
 */
float diferenciaPrecios(float precio1, float precio2);

/**
 * @brief realiza el calculo de todos los precios: debito, credito, bitcoin, precio unitario por km
 *
 * @param km			kilometros ingresados ya validado con los que se calculara el precio
 * @param precio		precio ingresado sobre el que se haran los calculos
 * @param resultado1	Guarda le resultado del calculo pagando con debito
 * @param resultado2	Guarda le resultado del calculo pagando con credrito
 * @param resultado3	Guarda le resultado del calculo pagando con bitcoin
 * @param resultado4	Guarda le resultado del calculo del precio por km
 * @return
 */
int calcularCostos(int km, float precio, float* resultado1, float* resultado2, float* resultado3, float* resultado4);



