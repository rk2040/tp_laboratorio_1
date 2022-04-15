#ifndef PARDOTP1_H_
#define PARDOTP1_H_



#endif /* PARDOTP1_H_ */

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
 * @brief 				Ingresamos Bandera de control y la cantidad de kilometros de vuelo
 *
 * @param pFlagOpcion	Puntero a bandera de control para el menu
 * @param km			Puntero a kilometros ingresados que se imprimiran en el menu
 * @return				Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int ingresaKilometros(int* pFlagOpcion, int* km);


/**
 * @brief 				Ingresamos Bandera de control y dos precios de vuelos, uno para cada aerolinea
 *
 * @param pFlagOpcion	Puntero a bandera de control para el menu
 * @param pPrecio1		Puntero al 1er precio
 * @param pPrecio2		Puntero al 2do precio
 * @return				Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int ingresaPrecioVuelo(int* pFlagOpcion, float* pPrecio1, float* pPrecio2);


/**
 * @brief 			Muestra un sub menu de opciones y retorna la opcion seleccionada de 1 a 3
 *
 * @param pPrecio1	Puntero al 1er precio
 * @param pPrecio2	Puntero al 2do precio
 * @return			Retorna el valor de la opcion elegida
 */
int subMenu2(float* pPrecio1, float* pPrecio2);


/**
 * @brief 				Muestra un sub menu con las operaciones que se van a realizar
 *
 * @param pFlagOpcion	Puntero a bandera de control para el menu
 * @param bitcoin		Valor del precio del Bitcoin con que que se hara el calculo
 * @return				Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int subMenu3(int* pFlagOpcion, float bitcoin);


/**
 * @brief 			Realiza el calculo de descuento por x %
 *
 * @param precio	Puntero a precio ingresado sobre el que se calculara el descuento
 * @param resultado	Puntero a resultado donde se escribira el precio ya con el descuento realizado
 * @param descuento	Valor del descuento. Ejemplo: si es 10% de descuento, el valor del parametro seria 0.1 (Actualizable desde un #define en el main)
 * @return			Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int descuentoDebito(float* precio, float* resultado, float descuento);


/**
 * @brief 			Realiza el calculo de interes por x %
 *
 * @param precio	Puntero a precio ingresado sobre el que se calculara el interes
 * @param resultado	Puntero a resultado donde se escribira el precio ya con el descuento realizado
 * @param interes	Valor del interes. Ejemplo: si es 25% de interes, el valor del parametro seria 0.25 (Actualizable desde un #define en el main)
 * @return			Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int interesCredito(float* precio, float* resultado, float interes);


/**
 * @brief 			Realiza el calculo del precio si se pagara con Bitcoin
 *
 * @param precio	Puntero a precio ingresado sobre el que se calculara el precio a pagar en Bitconin
 * @param resultado	Puntero a resultado donde se escribira el precio ya con el descuento realizado
 * @param bitcoin	Valor del Bitcoin con el que se realizara el calculo (Actualizable desde un #define en el main)
 * @return			Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int bitcoin(float* precio, float* resultado, float bitcoin);


/**
 * @brief 			Realiza el calculo para sacar el precio por 1 kilometro
 *
 * @param km		Puntero a kiloemtros ingresados con los que se calculara el precio por kilometro
 * @param precio	Puntero a precio ingresado sobre el que se calculara el precio por kilometro
 * @param resultado	Puntero a resultado donde se escribira el precio ya con el descuento realizado
 * @return			Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int precioPorKm(int* km, float* precio, float* resultado);


/**
 * @brief 			Calcula la diferencia de precio que hay enpre el precio de una aerolinea con otra
 *
 * @param precio1	Puntero a 1er precio ingresado sobre el que se calculara la diferencia de precio
 * @param precio2	Puntero a 2do precio ingresado sobre el que se calculara la diferencia de precio
 * @param resultado	Puntero a resultado donde se escribira la diferencia de precio entre las aerolineas
 * @return			Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int diferenciaPrecios(float* precio1, float* precio2, float* resultado);


/**
 * @brief 				Carga y muestra de valores y resultados de las operaciones de forma forzada con valores ya preingresados
 *
 * @param pFlagOpcion	Puntero a bandera de control para el menu
 * @param km			Puntero a los kilometros preingresados (no por el usuario)
 * @param precio1		Puntero a 1er precio preingresados (no por el usuario)
 * @param precio2		Puntero a 2do precio preingresados (no por el usuario)
 * @param btc 			Valor del Bitcoin con el que se realizara el calculo (Actualizable desde un #define en el main)
 * @param resultado		Puntero a resultado donde se escribira el resultado de las operaciones
 * @return				Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int cargaForzada(int* pFlagOpcion, int* km, float* precio1, float* precio2, float btc, float* resultado);

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


/**
 * @brief 			Opcion para salir con confirmacion
 *
 * @param salir	 	Puntero a parametro de contro de opcion salir: 's' sale  y  'n' no sale
 * @return			Retorna 1 si pudo realizar bien la operacion y 0 si algo fallo
 */
int salida(char* salir);
