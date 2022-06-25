/*
 * misFuncines.c
 *
 *  Created on: 24 jun. 2022
 *      Author: Roberto i3
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFunciones.h"
//#include "utn.h"



float calcularPromedio(int num1, int num2){
    float promedio;

    promedio = (float) (num1 + num2) / 2;

    return promedio;
}



char opcionConfirmar(char* mensaje, char* mensajeError){
	char confirmar = 'n';
	printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &confirmar);
		confirmar = tolower(confirmar);
		while(confirmar != 's' && confirmar != 'n')
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &confirmar);
			confirmar = tolower(confirmar);
		}
	return confirmar;
}



int compruebaLimitesCadena(char cadena[], int maximo, int minimo){
    int todoOk = 0;
    if(strlen(cadena) > maximo || strlen(cadena) < minimo){
        todoOk = 1;
    }
    return todoOk;
}



void formatoInicialMayuscula(char cadena[]){    // ACA ELIMINE EL PARAMETRO tam PORQUE CON UN WHILE NO HACE FALTA

    int i = 0;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);

    while(cadena[i] != '\0'){   // VAMOS A ENTRAR HASTA LLEGAR AL FINAL DE LA CADENA QUE ESL EL CARTACTER '\0'
        if(cadena[i] == ' '){
            cadena[i+1] = toupper(cadena[i+1]);
        }
        i++;
    }
}



int pedirEntero(){
	int entero;
	printf("Ingrese un numero entero: ");
	scanf("%d", &entero);
	return entero;
}

int pedirEnteroRango(int min, int max){
	int entero;
	printf("Ingrese un numero entero: ");
	scanf("%d", &entero);
	while (entero < min || entero > max) {
		printf(
				"El numero debe estar dentro del rango ingresado, ingreselo nuevamente: ");
		scanf("%d", &entero);
	}
	return entero;
}

int validarDistintoDeCero(int numero){
	int todoOk = 0;
	if (numero != 0) {
		todoOk = 1;
	}
	return todoOk;
}

int validarDecimales(float numero){
	int todoOk = 0;
	if (numero == (int) numero) {
		todoOk = 1;
	}
	return todoOk;
}

int miStrlen(char vect[]){
	int cantidad = 0;
	int i = 0;
	if (vect != NULL) {
		while (vect[i] != '\0') {
			cantidad++;
			i++;
		}
	}
	return cantidad;
}

int validarCadena(char vect[]){
	int todoOk = 0;
	for (int i = 0; i < miStrlen(vect); i++) {
		if (!(isalpha(vect[i]))) {
			todoOk = 1;
			break;
		}
	}
	return todoOk;
}

int pedirCadena(char cadena[], char mensaje[], int limite){
	int todoOk = 0;
	char auxCad[100];
	if (cadena != NULL && mensaje != NULL) {
		todoOk = 1;
		printf("%s", mensaje);
		fflush(stdin);
		gets(auxCad);

		while (miStrlen(auxCad) > limite || validarCadena(auxCad) == 1) {
			printf("Por favor ingresar solo letras (maximo %d): ", limite);
			fflush(stdin);
			gets(auxCad);
		}

		mayusculaPrimerCaracter(auxCad);

		strcpy(cadena, auxCad);
	}
	return todoOk;
}

int mayusculaPrimerCaracter(char cadena[]){
	int todoOk = 0;
	if (cadena != NULL) {
		todoOk = 1;
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);
	}
	return todoOk;
}

int getInt(int *pResultado){
	int retorno = -1;
	char buffer[4096];
	if (myGets(buffer, sizeof(buffer)) && esNumerica(buffer)) {
		retorno = 0;
		*pResultado = atoi(buffer);
	}
	return retorno;
}

int myGets(char *cadena, int longitud){
	char buffer[4096];
	fflush(stdin);
	scanf("%s", buffer);
	strncpy(cadena, buffer, longitud);
	return -1;
}

int validarEntero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){
	int todoOk = 0;
	int buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);

			if (getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				todoOk = 1;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		} while (reintentos >= 0);
	}
	return todoOk;
}

int esNumerica(char *cadena){
	int retorno = 1;
	for (int i = 0; cadena[i] != '\0'; i++) {
		if (cadena[0] == '-') {
			i = 1;
		}
		if (cadena[i] > '9' || cadena[i] < '0') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int getFloat(float *pResultado){
	int retorno = -1;
	char buffer[4096];
	if (myGets(buffer, sizeof(buffer)) && esNumericoFlotante(buffer)) {
		retorno = 0;
		*pResultado = atof(buffer);
	}
	return retorno;
}

int validarFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos){
	int todoOk = 0;
	float buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);

			if (getFloat(&buffer) == 0 && buffer >= minimo
					&& buffer <= maximo) {
				*pResultado = buffer;
				todoOk = 1;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		} while (reintentos >= 0);
	}
	return todoOk;
}

int esNumericoFlotante(char cadena[]){
	int i = 0;
	int cantidadPuntos = 0;
	while (cadena[i] != '\0') {
		if (i == 0 && cadena[i] == '-') {
			i++;
			continue;
		}
		if (cadena[i] == '.' && cantidadPuntos == 0) {
			cantidadPuntos++;
			i++;
			continue;
		}
		if (cadena[i] < '0' || cadena[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

int pedirAlfaNumerico(char cadena[], char mensaje[], int limite){
	int todoOk = 0;
	char auxCad[100];
	if (cadena != NULL && mensaje != NULL) {
		todoOk = 1;
		printf("%s", mensaje);
		fflush(stdin);
		gets(auxCad);

		while (miStrlen(auxCad) > limite) {
			printf("Ingrese nuevamente. (maximo %d): ", limite);
			fflush(stdin);
			gets(auxCad);
		}

		//mayusculaPrimerCaracter(auxCad);

		strcpy(cadena, auxCad);
	}
	return todoOk;
}
