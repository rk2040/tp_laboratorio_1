#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

#include "calculos.h"
#include "menu.h"
#include "datos.h"
#include "misFunciones.h"

#define DESCUENTO 0.1
#define INTERES 0.25
#define BITCOIN 2621550.00 // Precio al 25/06/2022 ( 4631241.00 Precio al  15/04/2022 )


//3 Calcular Costos
float descuentoDebito(float precio)
{
	float resultado = 0;

	if(precio > 0)
		{
			resultado = precio - (precio * DESCUENTO);
		}
	return resultado;
}

float interesCredito(float precio)
{
	float resultado = 0;

	if(precio > 0)
		{
			(resultado) = precio + (precio * INTERES);
		}
	return resultado;
}


float bitcoin(float precio)
{
	float resultado = 0;

	if(precio > 0)
	{
		(resultado) = precio / BITCOIN;
	}
	return resultado;
}


float precioPorKm(int km, float precio)
{
	float resultado = 0;

	if(precio > 0 && km > 0)
	{
		(resultado) = precio / km;
	}
	return resultado;
}


float diferenciaPrecios(float precio1, float precio2)
{
	float resultado = 0;

	if(precio1 > 0 && precio2 > 0)
	{
		resultado = precio1 -  precio2;

		if(resultado < 0)
		{
			resultado = resultado * -1;
		}
	}
	return resultado;
}


int calcularCostos(int km, float precio, float* resultado1, float* resultado2, float* resultado3, float* resultado4)
{
	int exito = 0;

	if( resultado1 != NULL && resultado2 != NULL && resultado3 != NULL && resultado4 != NULL )
	{
		*resultado1 = descuentoDebito(precio);
		*resultado2 = interesCredito(precio);
		*resultado3 = bitcoin(precio);
		*resultado4 = precioPorKm(km, precio);

		exito = 1;
	}
	return exito;
}
