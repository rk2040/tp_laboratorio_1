/*
 ============================================================================
 Name        : TP_1.c
 Author      : Pardo Roberto
 Version     :
 Copyright   : utnFra 1G
 Description : TP1 Agencia de viaje
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

#include "pardoTp1.h"

#define DESCUENTO 0.1
#define INTERES 0.25
#define BITCOIN 4631241.00	// Precio al  15/04/2022  22:20 hs

int main(void) {

	setbuf(stdout,NULL);	// necesario para eclipse

	//fflush(stdin);
    int km = 0;
    float precioA = 0;
    float precioL = 0;
    float resultado;
    int flagOpcion = 0;
    char salir = 'n';

    do{
		system("cls");

        switch(menu(km, precioA, precioL))
        {
            case 1:
            	if(!ingresaKilometros(&flagOpcion, &km))
            	{
            		printf("Hubo un problema en la carga de datos.");
            	}
                break;

            case 2:
            	if(!ingresaPrecioVuelo(&flagOpcion, &precioA, &precioL))
            	{
            		printf("Hubo un problema en la carga de datos.");
            	}
            	break;

            case 3:
            	if(!subMenu3(&flagOpcion, BITCOIN))
            	{
            		printf("Hubo un problema en la carga de datos.");
            	}
            	break;

            case 4:
            	if(flagOpcion == 3)
            	{
            		printf("KMs ingresados: %.d\n\n", km);

//------------------Aerolineas
					printf("Precio Aerolineas: %.2f\n", precioA);

					if(!descuentoDebito(&precioA, &resultado, DESCUENTO)){
						printf("Hubo un problema en la carga de datos.");
					}

					if(!interesCredito(&precioA, &resultado, INTERES)){
						printf("Hubo un problema en la carga de datos.");
					}

					if(!bitcoin(&precioA, &resultado, BITCOIN)){
						printf("Hubo un problema en la carga de datos.");
					}

					if(!precioPorKm(&km, &precioA, &resultado)){
						printf("Hubo un problema en la carga de datos.");
					}
//------------------LATAM
					printf("\n");
            		printf("Precio Latam: %.2f\n", precioL);

					if(!descuentoDebito(&precioL, &resultado, DESCUENTO)){
						printf("Hubo un problema en la carga de datos.");
					}

					if(!interesCredito(&precioL, &resultado, INTERES)){
						printf("Hubo un problema en la carga de datos.");
					}

					if(!bitcoin(&precioL, &resultado, BITCOIN)){
						printf("Hubo un problema en la carga de datos.");
					}

					if(!precioPorKm(&km, &precioL, &resultado)){
						printf("Hubo un problema en la carga de datos.");
					}

					printf("\n");
					if(!diferenciaPrecios(&precioA, &precioL, &resultado))
					{
						printf("Hubo un problema en la carga de datos.");
					}

	            	if(!resetValores(&flagOpcion, &km, &precioA, &precioL))
	            	{
	            		printf("Hubo un problema al resetear los valores");
	            	}
            	}
            	else{
            		printf("Antes tienen que mostrar las operaciones o salir si desea terminar el programa.\n");
            	}
                break;

            case 5:
            	if(!cargaForzada(&flagOpcion, &km, &precioA, &precioL, BITCOIN, &resultado))
            	{
            		printf("Hubo un problema con la Carga forzada.\n");
            	}

            	if(!resetValores(&flagOpcion, &km, &precioA, &precioL))
            	{
            		printf("Hubo un problema al resetear los valores");
            	}
            	break;

            case 6:
            	if(!salida(&salir))
            	{
            		printf("Hubo un problema con la carga de datos.\n");
            	}
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.");
        }

        system("pause");

    }while(salir == 'n');

    return EXIT_SUCCESS;
}
