/*
 * utn.c
 *
 *  Created on: 8 may. 2022
 *      Author: Roberto i3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/** \brief 	Lee el Stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
*			un maximo de 'longitud -1' Caracteres.
*
* \param pResultado al espacio de memoria donde se copiara la cadena obtenida
* \param longitude Define el tamaño de cadena
* \return int Return 0 (EXITO) si se obtiene una cadena. Y -1 (ERROR) si no se obtiene una cadena
*
*/
static int myGets(char* cadena, int tamanio);


/** \brief 	Verifica si la cadena ingresada es numerica
*
* \param cadena 	Cadena de caracteres a ser analizada
* \return int Return 1 (verdadero) si la cadena es numerica. Y 0 (falso) si no lo es
*
*/
static int esNumerica(char* cadena);


/** \brief
*
* \param pResultado		Punterto al espacio de memoria donde se dejara el resultado de la funcion
* \return int Return 0 (EXITO) si se obtiene un numero entero. Y .1 (ERROR) si no se obtiene un numero entero
*
*/
static int getInt(int* pResultado);


static int getFloat(float* pResultado);
static int esFlotante(char* cadena);



//------------------------------------------------------------------------------------------

static int myGets(char* cadena, int tamanio)
{

	fflush(stdin);
	fgets(cadena,tamanio,stdin);

	cadena[strlen(cadena)-1] = '\0';
	return 0;
}

static int esNumerica(char* cadena)
{
	int retorno = 1; // devuelve true or false solamente
	int i = 0;

	if(cadena != NULL && strlen(cadena)>0)
	{
		if(cadena[0]=='-')
		{
				i = 1;
		}

		for(; cadena[i] != '\0';i++)	// la primero posicion del for puede quedar vacia
		{
			if(cadena[i]>'9'|| cadena[i]<'0')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			retorno = 0;
			*pResultado = atoi(buffer);	// atoi convierte todos los caracteres a numero int (solo si son todos numeros en tabla ansii) (similar a parseInt)
		}
	}
	return retorno;
}



int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);

			if(getInt(&buffer)== 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}


int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}




static int esFlotante(char* cadena)
{
	int retorno = 1; // devuelve true or false solamente
	int i = 0;
	int contadorPuntos = 0;

	if(cadena != NULL && strlen(cadena)>0)
	{
		for(; cadena[i] != '\0';i++)	// la primero posicion del for puede quedar vacia
		{
			if(i == 0 && (cadena[i]=='-' || cadena[i] == '+'))
			{
				continue;
			}

			if(cadena[i] < '0'|| cadena[i] >'9')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}else
				{
				  retorno = 0;
				  break;
				}
			}
		}
	}

	return retorno;
}


static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esFlotante(buffer))
		{
			retorno = 0;
			*pResultado = atof(buffer);
		}
	}
	return retorno;
}



int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if(getFloat(&buffer) == 0 &&
					buffer >= minimo &&
					buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}


int utn_getCadena(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{

	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && len>0 && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do{
			printf("%s",mensaje);

			if(myGets(buffer,sizeof(buffer))==0 && strlen(buffer) < len)
			{
				strncpy(pResultado,buffer,len-1);
				retorno = 1;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



int esNombreValido(char* cadena, int len)
{
	int retorno = 1;

	if( cadena!= NULL && len > 0)
	{
		for(int i=0; i<=len && cadena[i] != '\0';i++)
		{
			if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				cadena[i] != ' ' && cadena[i] != '-')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


