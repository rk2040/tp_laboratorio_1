/*
 * menu.c
 *
 *  Created on: 24 jun. 2022
 *      Author: Roberto i3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"
#define BITCOIN 2621550.00 // Precio al 25/06/2022 ( 4631241.00 Precio al  15/04/2022 )

int menu(int num1, float num2, float num3)
{
    int opcion;

    system("cls");
    printf("====  Agencia de Viaje  ====\n\n");
    printf("====   Menu Opciones    ====\n\n");
    printf("Elija una opcion: \n\n");
    printf("1. Ingresar Kilometros: (km = %d)\n", num1);
    printf("2. Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f)\n", num2, num3);
    printf("3. Calcular todos los costos: \n");
    printf("4. Informar Resultados: \n");
    printf("5. Carga forzada: \n");
    printf("6. Salir \n");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int menuPrecio(float* pPrecio1, float* pPrecio2)
{
	int opcion;

	system("cls");
	printf("1- Ingrese el precio de Aerolineas: %.2f\n", *pPrecio1);
	printf("2- Ingrese el precio de Latam: %.2f\n", *pPrecio2);
    printf("3- Salir y volver al menu principal. \n");

    fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}


// 3- Muestra las operaciones a realizar
int menuOperaciones(int* pFlagOpcion)
{
	int exito = 0;

	if(pFlagOpcion != NULL)
	{
		if(*pFlagOpcion == 2)
		{
			printf("a) Tarjeta de debito (descuento 10%%)\n");
			printf("b) Tarjeta de credito (interes 25%%)\n");
			printf("c) Bitcoin (1BTC -> %.2f Pesos Argentinos)\n", BITCOIN);
			printf("d) Mostrar precio por km (precio unitario)\n");
			printf("e) Mostrar diferencia de precio ingresada (Latam - Aerrolineas)\n");
			*pFlagOpcion = 3;
		}
		else{
			printf("Antes tiene que ingresar los precios de los vuelos o salir si desea terminar el programa.\n");
		}
		exito = 1;
	}
	return exito;
}



// 6- Salir
int salida(char* salir)
{
    int exito = 0;

    if(salir != NULL)
    {
        printf("Seguro que quiere salir? s/n ");
        fflush(stdin);
        scanf("%c", salir);
        *salir = tolower(*salir);
        while(*salir != 's' && *salir != 'n')
        {
            printf("Error, vuelva a intentarlo. Salir? s/n ");
            fflush(stdin);
            scanf("%c", salir);
            *salir = tolower(*salir);
        }
        exito = 1;
    }

    return exito;
}
