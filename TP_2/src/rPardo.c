/*
 * rPardo.c
 *
 *  Created on: 8 may. 2022
 *      Author: Roberto i3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "rPardo.h"
#include "utn.h"



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

