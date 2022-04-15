#ifndef PARDOTP1_H_
#define PARDOTP1_H_



#endif /* PARDOTP1_H_ */


/** \brief      muestra el menu de opciones y retorna la opcion seleccionada de 1 a 4
 *
 * \return int  devuelve el valor de la opcion elegida
 *
 */
int menu(int num1, int num2);


/**
 * \brief		recibe un valor y comprueba si es o no es un numero
 * \param num	valor ingresado
 * \return		1 si es un numero, 0 si no es un numero
 */
int validarEntero(int num);


/** \brief          recibe dos valores y los suma
 *
 * \param num1 int  primer valor
 * \param num2 int  segundo valor
 * \return int      devuelve el resultado
 *
 */
int suma(int num1, int num2, int*resultado);



/** \brief          recibe dos valores y los resta
 *
 * \param num1 int  primer valor
 * \param num2 int  segundo valor
 * \return void     imprime el resultado
 *
 */
int resta(int num1, int num2, int*resultado);



/**
 * \brief 				devuele al puntero resultado, el resultado de la division
 * \param num1			dividendo
 * \param num2			divisor
 * \param resultado		direccion donde se escribe el resultado
 * \return				1 si se pudo dividir, 0 si no se pudo dividir
 */
int division(int num1, int num2, float*resultado);



/** \brief          recibe dos valores y los multiplica
 *
 * \param num1 int  primer valor
 * \param num2 int  segundo valor
 * \return void     imprime el resultado
 *
 */
int multiplicacion(int num1, int num2, int* resultado);



/** \brief          recibe dos valores y calcula el factorial de cada uno
 *
 * \param num1 int  primer valor
 * \param num2      segundo valor
 * \return void     imprime el resultado de ambos
 *
 */
int factorial(int num1, unsigned long int* resultado);
