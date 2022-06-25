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

#include "calculos.h"
#include "menu.h"
#include "datos.h"
#include "misFunciones.h"

int main(void) {

	setbuf(stdout,NULL);	// necesario para eclipse

    int km = 0;
    float precioA = 0;
    float precioL = 0;
    float precioAADebito = 0;
    float precioAACredito = 0;
    float precioAABit = 0;
    float precioAAKmUnitario = 0;
    float precioLatamDebito = 0;
    float precioLatamCredito = 0;
    float precioLatamBit = 0;
    float precioLatamKmUnitario = 0;

    int flagOpcion = 0;
    char salir = 'n';

    do{
		system("cls");

        switch(menu(km, precioA, precioL))
        {
            case 1:
            	if( !ingresaKilometros(&flagOpcion, &km) )
            	{
            		printf("Hubo un problema en la carga de datos.\n");
            	}
                break;

            case 2:
            	if( !ingresaPrecioVuelo(&flagOpcion, &precioA, &precioL) )
            	{
            		printf("Hubo un problema en la carga de datos.\n");
            	}
            	break;

            case 3:
            	menuOperaciones(&flagOpcion);
				calcularCostos(km, precioA, &precioAADebito, &precioAACredito, &precioAABit, &precioAAKmUnitario);
				calcularCostos(km, precioL, &precioLatamDebito, &precioLatamCredito, &precioLatamBit, &precioLatamKmUnitario);
            	break;

            case 4:
            	if(flagOpcion == 3)
            	{
            		printf("KMs ingresados: %.d\n\n", km);
//------------------Aerolineas
					printf("Precio Aerolineas: %.2f\n", precioA);
					informarResultados(precioAADebito, precioAACredito, precioAABit, precioAAKmUnitario);
					printf("\n");
//------------------LATAM
            		printf("Precio Latam: %.2f\n", precioL);
            		informarResultados(precioLatamDebito, precioLatamCredito, precioLatamBit, precioLatamKmUnitario);
					printf("\n");
					printf("e) La diferencia de precio es: %.2f \n", diferenciaPrecios(precioA, precioL) );

	            	resetValores(&flagOpcion, &km, &precioA, &precioL);
            	}
            	else{
            		printf("Antes tienen que mostrar las operaciones o salir si desea terminar el programa.\n");
            	}
                break;

            case 5:
            	cargaForzada(&km, &precioA, &precioL);
            	printf("KMs ingresados: %.d\n\n", km);
//--------------Aerolineas
				printf("Precio Aerolineas: %.2f\n", precioA);
				calcularCostos(km, precioA, &precioAADebito, &precioAACredito, &precioAABit, &precioAAKmUnitario);
				informarResultados(precioAADebito, precioAACredito, precioAABit, precioAAKmUnitario);
				printf("\n");
//--------------LATAM
				printf("Precio Latam: %.2f\n", precioL);
				calcularCostos(km, precioL, &precioLatamDebito, &precioLatamCredito, &precioLatamBit, &precioLatamKmUnitario);
				informarResultados(precioLatamDebito, precioLatamCredito, precioLatamBit, precioLatamKmUnitario);
				printf("\n");
				printf("e) La diferencia de precio es: %.2f \n", diferenciaPrecios(precioA, precioL) );

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
