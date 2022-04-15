#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

#include "pardoTp1.h"


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

// 1- ingresa la cantidad ed kilometros del vuelo
int ingresaKilometros(int* pFlagOpcion, int* km)
{
	int exito = 0;

	if(pFlagOpcion != NULL)
	{
		if(*pFlagOpcion == 0)
		{
			printf("Ingrese los Kilometros de vuelo: ");
			fflush(stdin);
			scanf("%d", km);
			*pFlagOpcion = 1;

			while (*km <= 0)
			{
				printf("Error, los Kilomretos deben ser mayor a 0km y solo puede ingresar numeros.\nReingrese los Kilometros de vuelo: ");
				fflush(stdin);
				scanf("%d", km);
			}
		}
		else{
			printf("Antes tiene que terminar todas las opciones para volver a empezar o salir si desea terminar el programa.\n");
		}

	exito = 1;
	}

	return exito;
}

// 2- ingresa precio de las aerolineas
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
				switch(subMenu2(pPrecio1, pPrecio2))
				{
				case 1:
					printf("- Ingrese el precio de Aerolineas: %.2f ", *pPrecio1);
					fflush(stdin);
					scanf("%f", pPrecio1);
					while(*pPrecio1 <= 0)
					{
						printf("- Error, el precio debe ser mayor a 0 y solo puede ingresar numeros.\nReingrese el precio de Aerolineas: ");
						fflush(stdin);
						scanf("%f", pPrecio1);
					}
					flagA = 1;
					break;

				case 2:
					printf("- Ingrese el precio de Latam: %.2f ", *pPrecio2);
					fflush(stdin);
					scanf("%f", pPrecio2);
					while(*pPrecio2 <= 0)
					{
						printf("- Error, el precio debe ser mayor a 0 y solo puede ingresar numeros.\nReingrese el precio de Latam: %.2f ", *pPrecio2);
						fflush(stdin);
						scanf("%f", pPrecio2);
					}
					flagL = 1;
					break;
	            case 3:
	            	if(flagA && flagL)
	            	{
						if(!salida(&salir))
						{
							printf("Hubo un problema con la carga de datos.\n");
						}
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

int subMenu2(float* pPrecio1, float* pPrecio2)
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
int subMenu3(int* pFlagOpcion, float bitcoin)
{
	int exito = 0;

	if(pFlagOpcion != NULL)
	{
		if(*pFlagOpcion == 2)
		{
			printf("a) Tarjeta de debito (descuento 10%%)\n");
			printf("b) Tarjeta de credito (interes 25%%)\n");
			printf("c) Bitcoin (1BTC -> %.2f Pesos Argentinos)\n", bitcoin);
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


//4- a) tarjeta de debito 10% de descuento
int descuentoDebito(float* precio, float* resultado, float descuento)
{
	int exito = 0;

	if(resultado != NULL && precio != NULL)
	{
		if(*precio > 0)
		{
			(*resultado) = *precio - (*precio * descuento);
			printf("a) Precio con tarjeta de debito	: %.2f \n", *resultado);
		}
		else{
			printf("a) Precio con tarjeta de debito	: No se pudo calcular el descuento.\n");
		}

		exito = 1;
	}

	return exito;
}

// 4- b) tarjeta de credito 25% de interes
int interesCredito(float* precio, float* resultado, float interes)
{
	int exito = 0;

	if(resultado != NULL && precio != NULL)
	{
		if(*precio > 0)
		{
			(*resultado) = *precio + (*precio * interes);
			printf("b) Precio con tarjeta de credito: %.2f \n", *resultado);
		}
		else{
			printf("b) Precio con tarjeta de credito: No se pudo calcular el interes.\n");
		}
		exito = 1;
	}

	return exito;
}

// 4- c) 1 Bitcoin =  Precio BTC (actualizable desde #define en el main() )
int bitcoin(float* precio, float* resultado, float bitcoin)
{
	int exito = 0;

	if(resultado != NULL && precio != NULL)
	{
		if(*precio > 0)
		{
			(*resultado) = *precio / bitcoin;
			printf("c) Precio pagado con BTC	: %f \n", *resultado);
		}
		else{
			printf("c) Precio pagado con BTC	: No se pudo calcular.\n");
		}
		exito = 1;
	}

	return exito;
}

// 4- d) precio unitario por km
int precioPorKm(int* km, float* precio, float* resultado)
{
	int exito = 0;

	if(resultado != NULL && precio != NULL)
	{
		if(precio > 0 && km > 0)
		{
			(*resultado) = *precio / *km;
			printf("d) Precio unitario		: %.2f \n", *resultado);
		}
		else{
			printf("d) Precio unitario: No se pudo calcular.\n");
		}
		exito = 1;
	}

	return exito;
}

// 4- e) diferencia de precio entre una aerolinea y otra
int diferenciaPrecios(float* precio1, float* precio2, float* resultado)
{
	int exito = 0;

	if(precio1 != NULL && precio2 != NULL && resultado != NULL)
	{
		(*resultado) = *precio1 - * precio2;

		if(*resultado < 0)
		{
			(*resultado) = *resultado * -1;
		}

		printf("e) La diferencia de precio es: %.2f \n", *resultado);

		exito = 1;
	}

	return exito;
}

// 5- carga forzada: Kilometros  7079 /  Precio Aerolineas 162565  /  Precio Latam 159339 / Precio BTC (actualizable desde #define en el main() )
int cargaForzada(int* pFlagOpcion, int* km, float* precio1, float* precio2, float btc, float* resultado)
{
	int exito = 0;

	if(pFlagOpcion != NULL)
	{
		*km = 7090;

		*precio1 = 162565;

		*precio2 = 159339;

		*pFlagOpcion = 3;

		if(*pFlagOpcion == 3)
		{
			printf("KMs ingresados: %.d\n\n", *km);

			printf("Precio Aerolineas: %.2f\n", *precio1);

			if(!descuentoDebito(precio1, resultado, 0.1)){
				printf("Hubo un problema en la carga de datos.");
			}

			if(!interesCredito(precio1, resultado, 0.25)){
				printf("Hubo un problema en la carga de datos.");
			}

			if(!bitcoin(precio1, resultado, btc)){
				printf("Hubo un problema en la carga de datos.");
			}

			if(!precioPorKm(km, precio1, resultado)){
				printf("Hubo un problema en la carga de datos.");
			}
	//------------------
			printf("\n");
			printf("Precio Latam: %.2f\n", *precio2);

			if(!descuentoDebito(precio2, resultado, 0.1)){
				printf("Hubo un problema en la carga de datos.");
			}

			if(!interesCredito(precio2, resultado, 0.25)){
				printf("Hubo un problema en la carga de datos.");
			}

			if(!bitcoin (precio2, resultado, btc))
			{
				printf("Hubo un problema en la carga de datos.");
			}

			if(!precioPorKm(km, precio2, resultado)){
				printf("Hubo un problema en la carga de datos.");
			}

			printf("\n");
			if(!diferenciaPrecios(precio1, precio2, resultado))
			{
				printf("Hubo un problema en la carga de datos.");
			}

		}
		else{
			printf("Antes tienen que mostrar las operaciones o salir si desea terminar el programa.\n");
		}
		*pFlagOpcion = 0;

		exito = 1;
	}

	return exito;
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
