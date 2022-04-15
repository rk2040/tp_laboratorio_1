#include <stdio.h>
#include <stdlib.h>
#include "pardoTp1.h"


int menu(int num1, int num2)
{
    int opcion;

    system("cls");
    printf("====  Calculadora  ====\n\n");
    printf("==== Menu Opciones ====\n\n");
    printf("Elija una opcion: \n\n");
    printf("1. Ingresar el 1er operando A: ");
    printf("%d\n", num1);
    printf("2. Ingresar el 2do operando B: ");
    printf("%d\n", num2);
    printf("3. Calcular todas las operaciones: \n");
    printf("4. Informar resultados: \n");
    printf("5. Salir \n");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int suma(int num1, int num2, int*resultado)
{
    int todoOk = 0;

    if(resultado != NULL){
		(*resultado) = num1 + num2;
		todoOk = 1;
    }

    return todoOk;
}


int resta(int num1, int num2, int*resultado)
{
    int todoOk = 0;

    if(resultado != NULL){
		(*resultado) = num1 - num2;

		todoOk = 1;
    }

    return todoOk;
}


int division(int num1, int num2, float*resultado)
{    int todoOk = 0;

    if(resultado != NULL && num2 != 0){
        (*resultado) = (float) num1 / num2;

        todoOk = 1;
    }

    return todoOk;
}

int multiplicacion(int num1, int num2, int* resultado)
{
    int todoOk = 0;

    if(resultado != NULL){
    	(*resultado) = num1 * num2;
    	todoOk = 1;
    }

    return todoOk;
}


int factorial(int num1, unsigned long int* resultado)
{
    int todoOk = 0;
	unsigned long int resultado1 = num1;

	if((resultado != NULL) && num1  >= 0){
		for(int i=2; i<num1; i++)
		{
			resultado1 *= i;
		}
		todoOk = 1;
	}

    (*resultado) = resultado1;

    return todoOk;
}
