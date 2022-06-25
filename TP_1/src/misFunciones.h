/*
 * misFunciones.h
 *
 *  Created on: 24 jun. 2022
 *      Author: Roberto i3
 */

#ifndef MISFUNCIONES_H_
#define MISFUNCIONES_H_



#endif /* MISFUNCIONES_H_ */


char opcionConfirmar(char* mensaje, char* mensajeError);

float calcularPromedio(int num1, int num2);

void formatoInicialMayuscula(char cadena[]);

int pedirEntero();
int pedirEnteroRango(int min, int max);
int validarDistintoDeCero(int numero);
int validarDecimales(float numero);
int miStrlen(char vect[]);
int validarCadena(char vect[]);
int pedirCadena(char cadena[], char mensaje[], int limite);
int mayusculaPrimerCaracter(char cadena[]);
int getInt(int *pResultado);
int myGets(char *cadena, int longitud);
int validarEntero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int esNumerica(char *cadena);
int getFloat(float *pResultado);
int validarFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);
int esNumericoFlotante(char cadena[]);

int pedirAlfaNumerico(char cadena[], char mensaje[], int limite);
