/*
 * datos.c
 *
 *  Created on: 25 jun. 2022
 *      Author: Roberto i3
 */

#include <stdio.h>
#include <stdlib.h>

#include "datos.h"
#include "menu.h"
#include "calculos.h"

#define DESCUENTO 0.1
#define INTERES 0.25
#define BITCOIN 2621550.00 // Precio al 25/06/2022 ( 4631241.00 Precio al  15/04/2022 )

// 1- ingresa la cantidad ed kilometros del vuelo
int ingresaKilometros(int* pFlagOpcion, int* km)
{
	int exito = 0;

	if(pFlagOpcion != NULL)
	{
		if(*pFlagOpcion == 0)
		{
			do
			{
				printf("Ingrese los Kilometros de vuelo: ");
				fflush(stdin);
				scanf("%d", km);
				*pFlagOpcion = 1;

				if(km < 0)
				{
					printf("Error, los Kilomretos deben ser mayor a 0 km y solo puede ingresar numeros.\nReingrese los Kilometros de vuelo: ");
					fflush(stdin);
					scanf("%d", km);
				}

			}while (*km < 0);
		}
		else{
			printf("Antes tiene que terminar todas las opciones para volver a empezar o salir si desea terminar el programa.\n");
		}

	exito = 1;
	}

	return exito;
}

// 2- ingresa precio de las aerolineas
float ingresarPrecio()
{
	float precio;
	printf("Ingrese el precio: ");
	do{
		scanf("%f",&precio);
		if(precio <= 0){
			printf("- Error, el precio debe ser mayor a 0 y solo puede ingresar numeros.\nReingrese el precio: ");
		}
	}while(precio <= 0);

	fflush(stdin);
	system("cls");

	return precio;
}


int ingresaPrecioVuelo(int* pFlagOpcion, float* pPrecio1, float* pPrecio2)
{
	int exito = 0;
	char salir = 'n';
	int flagA = 0;
	int flagL = 0;

	if(pFlagOpcion != NULL)
	{
		if(*pFlagOpcion == 1)
		{
			do{
				system("cls");
				switch(menuPrecio(pPrecio1, pPrecio2))
				{
				case 1:
					*pPrecio1 = ingresarPrecio();

					flagA = 1;
					break;

				case 2:
					*pPrecio2 = ingresarPrecio();

					flagL = 1;
					break;
	            case 3:
	            	if(flagA && flagL)
	            	{
						salir = 's';
	            	}
					else{
						printf("Debe ingresar los precios de las dos aerolineas antes de salir.\n");
					}
	                break;

				default:
					printf("Opcion invalida. Intente nuevamente.");
				}
		        //system("pause");
			}while(salir == 'n');

			*pFlagOpcion = 2;
		}
		else{
			printf("Antes tiene que ingresar los Kilometros de vuelo o salir si desea terminar el programa.\n");
		}

		exito = 1;
	}

	return exito;
}


//4- Listar Calculos
void informarResultados(float resultado1, float resultado2, float resultado3, float resultado4)
{

	printf("a) Precio con tarjeta de debito (-10%%)	: %.2f \n", resultado1);
	printf("b) Precio con tarjeta de credito (+25%%) : %.2f \n", resultado2);
	printf("c) Precio pagado con BTC (%.2f)	: %f \n", BITCOIN, resultado3);
	if(resultado4 <= 0)
	{
		printf("d) Precio unitario por kilometro	: ERROR. No puede tener 0 km.\n");
	}
	else{
		printf("d) Precio unitario por kilometro	: %.2f \n", resultado4);
	}
}

// 5- carga forzada: Kilometros  7079 /  Precio Aerolineas 162565  /  Precio Latam 159339 / Precio BTC (actualizable desde #define en el main() )
void cargaForzada(int* km, float* precio1, float* precio2)
{
	*km = 7090;
	*precio1 = 162965;
	*precio2 = 159339;
}


int resetValores(int* pFlagOpcion, int* km, float* precio1, float* precio2)
{
	int exito = 0;

	if(pFlagOpcion != NULL && km != NULL && precio1 != NULL && precio2 != NULL)
	{
		*km = 0;
		*precio1 = 0;
		*precio2 = 0;
		*pFlagOpcion = 0;
		exito = 1;
	}
	return exito;
}




