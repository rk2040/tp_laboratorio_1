#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "rPardo.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
	setbuf(stdout,NULL);

	int nextId = 0;
    int option = 0;
    int flagTexto = 1;
    int flagBinario = 1;
    char salir = 'n';

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	menu(&option);
        switch(option)
        {
            case 1:
            	if( !flagBinario )
            	{
            		printf("Ya esta trabajando con el archivo binario, debe guardarlo primero y salir, o salir sin guardar los cambios.\n");
            	}
            	else{
            		if( !flagTexto)
            		{
            			printf("Ya se abrio el archivo en modo texto.\n");
            		}
            		else
            		{
            			if( !controller_loadFromText("data.csv", listaPasajeros))
            			{
            				flagTexto = 0;
            				printf("Lista de pasajeros cargada en modo texto exitosamente.\n");
            				nextId = buscarMayorId(listaPasajeros) + 1;
            			}
            			else{
            				printf("Hubo un problema al cargar la lista en modo texto.\n");
            			}
            		}
            	}
                break;
            case 2:
            	if( !flagTexto)
            	{
            		printf("Ya esta trabajando con el archivo en texto, debe guardarlo primero y salir, o salir sin guardar los cambios.\n");
            	}
            	else{
					if( !flagBinario )
					{
						printf("Ya se abrio el archivo en modo binario.\n");
					}
					else{
						if( !controller_loadFromBinary("data.bin", listaPasajeros))
						{
							flagBinario = 0;
							printf("Lista de pasajeros cargada en modo binario exitosamente.\n");
							nextId = buscarMayorId(listaPasajeros) + 1;
						}
						else{
							printf("Hubo un problema al cargar la lista en modo binario.\n");
						}
					}
				}
            	break;
            case 3:
            	if( !flagTexto || !flagBinario)
            	{
            		if( !controller_addPassenger(listaPasajeros, &nextId))
            		{
            			printf("Alta exitosa.\n");
            		}
            		else{
            			printf("Hubo un error al realizar el alta.\n");
            		}
            	}
            	else{
            		printf("No se abrio ningun archivo para trabajar.\n");
            	}
            	break;
            case 4:
            	if( !flagTexto || !flagBinario)
            	{
            		if( !ll_isEmpty(listaPasajeros))
            		{
            			if( !controller_editPassenger(listaPasajeros))
            			{
            				printf("No se pudo modificar al pasajero.\n");
            			}
            		}
            	}
            	else{
            		printf("No cargo ninguna lista de pasajeros.\n");
            	}
            	break;
            case 5:
            	if( !flagTexto || !flagBinario)
            	{
            		if( !ll_isEmpty(listaPasajeros))
            		{
            			if( controller_removePassenger(listaPasajeros))
            			{
            				printf("Baja del pasajero exitosa.\n");
            			}
            			else{
            				printf("Baja cancelada por el usuario.\n");
            			}
            		}
            	}
            	else{
					printf("No cargo ninguna lista de pasajeros.\n");
				}
            	break;
            case 6:
            	if( !flagTexto || !flagBinario)
            	{
            		if( !ll_isEmpty(listaPasajeros))
					{
						controller_ListPassenger(listaPasajeros);
					}
					else{
						printf("La lista esta vacia, sin elementos.\n");
					}
            	}
            	else{
					printf("No cargo ninguna lista de pasajeros.\n");
				}
            	break;
            case 7:
            	if(flagBinario == 0 || flagTexto == 0)
				{
					if(!ll_isEmpty(listaPasajeros))
					{
						if(!controller_sortPassenger(listaPasajeros))
						{
							printf("Ordenamiento exitoso!\n");
						}
						else{
							printf("Error al ordenar los pasajeros\n");
						}
					}
					else{
						printf("No hay pasajeros en la lista para ordenar\n");
					}
				}
				else{
					printf("No se ha abierto el archivo para ordenar\n");
				}
            	break;
            case 8:
            	if( !flagTexto || !flagBinario)
            	{
					if(!controller_saveAsText("data.csv",listaPasajeros))
					{
						//flagTexto = 1;
						printf("\nEl archivo data.csv se guardo en modo texto\n");
					}
					else{
						printf("Ocurrio un problema al guardar el archivo en modo texto\n");
					}
            	}
            	else{
					printf("No cargo ninguna lista de pasajeros.\n");
				}
            	break;
            case 9:
            	if( !flagTexto || !flagBinario)
            	{
					if(!controller_saveAsBinary("data.bin",listaPasajeros))
					{
						printf("\nEl archivo data.bin se guardo en modo binario\n");
					}
					else{
						printf("Ocurrio un problema al guardar el archivo en modo binario\n");
					}
				}
				else{
					printf("No cargo ninguna lista de pasajeros.\n");
				}
            	break;
            case 10:
            	salir = opcionConfirmar("Seguro que quiere salir? s/n ", "Error, vuelva a intentarlo. Salir? s/n ");
            	break;
            default:
            	break;
        }
        system("pause");

    }while(salir == 'n');

    ll_deleteLinkedList(listaPasajeros);
    free(listaPasajeros);

    return 0;
}
