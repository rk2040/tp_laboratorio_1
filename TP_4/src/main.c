/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

#include "jugador.h"
#include "parser.h"


int main(void)
{
//    int indiceId;
//    int from;
//    int to;
//    int id;
//    int tamLinkedList;
    int indice;

    LinkedList* listaDeJugadores;
    LinkedList* listaDeJugadoresCopia;
    LinkedList* subListaDeJugadores;

    printf("--------------------------------------------------------\n");
    printf("==========            Linked List             ==========\n");
    printf("--------------------------------------------------------\n\n");

// 1- creo un nueva lista
printf("--- ll_newLinkedList    (1) --- \n\n");
    listaDeJugadores = ll_newLinkedList();

    if(listaDeJugadores != NULL)
    {
        printf("Se pudo crear una nueva Lista\n\n");
    }

    printf("\n\n");
// 12- ll_isEmpty   veo si la lista esta vacia (antes de cargarla, para probar)
    printf("--- ll_isEmpty      (12) --- \n\n");
    if(ll_isEmpty(listaDeJugadores))
    {
        int valorIsEmpty = ll_isEmpty(listaDeJugadores);
        printf("listaDeJugadores esta vacia. \nll_isEmpty devuelve: %d \n\n", valorIsEmpty);
    }

    printf("\n\n");
// cargo la lista nueva
    printf("- Cargo una Lista de jugadores de prueba - \n\n");
    loadFromText("jugadores.csv", listaDeJugadores);


    printf("\n\n");
// 2- ll_len  cantidad de elementos en la lista
    printf("--- ll_len     (2) --- \n\n");
    printf("La cantidad de jugadores en la lista es (ll_len): %d \n\n", ll_len(listaDeJugadores));


    printf("\n\n");
    printf("- Muestro Lista de jugadores cargada - \n\n");
    mostrarJugadores(listaDeJugadores); // muestro lista antes de agregar


    printf("\n\n");
// 5- ll_add  agrego a la lista
    eJugador* nuevo1 = jugador_newParametrosChar("24","Juan","Foyth","Defensa","24");
    eJugador* nuevo2 = jugador_newParametrosChar("25", "Alexis", "MacAllister", "Mediocampo", "23");
    eJugador* nuevo3 = jugador_newParametrosChar("26", "Paulo", "Dybala", "Delantero", "28");
    eJugador* nuevo4 = jugador_newParametrosChar("27", "Enzo", "Perez", "Mediocampo", "36");

    printf("--- ll_add     (5) --- \n\n");
    printf("Se extendio la lista para el mundial a 26 Jugadores\n\n");
    ll_add(listaDeJugadores, nuevo1);
    ll_add(listaDeJugadores, nuevo2);
    ll_add(listaDeJugadores, nuevo3);
    ll_add(listaDeJugadores, nuevo4);

    printf("- Lista Con los agregados - \n\n");
    mostrarJugadores(listaDeJugadores); // muestro lista despues de agregar


    printf("\n\n");
// 8-  ll_remove  elimino un elemento de la lista
    printf("La cantidad de jugadores en la lista es (ll_len): %d \n\n", ll_len(listaDeJugadores));
    printf("\nSe agrego un jugador de mas.\nSe pasa a eliminar un jugador\n");

    printf("--- ll_remove     (8) --- \n\n");
    ll_remove(listaDeJugadores, 24);    // saco a McAllister

    printf("\n--- Lista Con uno eliminado eliminado ---\n");
    mostrarJugadores(listaDeJugadores);
    printf("\nLa cantidad de jugadores en la lista es (ll_len): %d \n\n", ll_len(listaDeJugadores));


    printf("\n\n");
// 11-  ll_indexOf   indice de un elemento de la lista. Al primer elemento que encuentra en la lista de ese tipo (en este caso tipo   eJugador )
    printf("--- ll_indexOf     (11) --- \n\n");
    indice = ll_indexOf(listaDeJugadores, nuevo1);

    if(indice >= 0)
    {
        printf("\nEl indice del elemento que retorno ll_indexOf es: %d \n", indice);


        printf("\n\n");
    // 6-  ll_get  puntero al elemento que le pasamos por indice
        printf("--- ll_get    (6) --- \n\n");
        mostrarJugador(ll_get(listaDeJugadores, indice));
    }


    printf("\n\n");
// 13- ll_push  desplaza los elementos de la liste y mete un elemente en medio de la lista en la posicion que le indicamos
    printf("--- ll_push    (13) --- \n\n");

    eJugador* nuevo5 = jugador_newParametrosChar("28","Juan","Musso","Arquero","28");
    ll_push(listaDeJugadores,3, nuevo5);
    printf("\n--- Lista Con la insercion de un Arquero extra ---\n");
    mostrarJugadores(listaDeJugadores);


    printf("\n\n");
// 14- ll_pop  devuelve puntero al elemento de la lista del indice que le pasamos y lo elimina. (podemos copiarlo a una nueva variable del mismo tipo antes de que lo elimine)
    printf("--- ll_pop    (14) --- \n\n");

    eJugador* nuevoCopiaPop = ll_pop(listaDeJugadores,2);
    printf("\nEl elemento eliminado es: %d \n", nuevoCopiaPop->id);
    printf("El elemento era: ");
    printf("\n");
    mostrarJugador(nuevoCopiaPop);
    printf("\n--- Lista Eliminando y copiando a %s %s---\n", nuevoCopiaPop->nombre, nuevoCopiaPop->apellido);
    mostrarJugadores(listaDeJugadores);


    printf("\n\n");
// 18- ll_clone  copio la lista en otra LinkedList
    printf("--- ll_clone    (18) --- \n\n");

    listaDeJugadoresCopia = ll_clone(listaDeJugadores);
    printf("\n--- Lista Copiada/clonada ---\n");
    mostrarJugadores(listaDeJugadoresCopia);


    printf("\n\n");
// 15- ll_contains  verifica si un elemento esta en la lista (usar el retorno)
    printf("--- ll_contains    (15) --- \n\n");

    if(ll_contains(listaDeJugadores, nuevo2))
    {
        printf("%s %s esta en la lista\n\n", nuevo2->nombre, nuevo2->apellido);
    }
    else
    {
        printf("%s %s no esta en la lista\n\n", nuevo2->nombre, nuevo2->apellido);
    }


    printf("\n\n");
// 16- ll_containsAll   verifica si una lista contiene todos los mismos elementos de otra lista
    printf("--- ll_containsAll    (16) --- \n\n");

    if(ll_containsAll(listaDeJugadores, listaDeJugadoresCopia))
    {
        printf("\nLas listas contienen los mismos elementos\n");
    }
    else
    {
        printf("\nLas listas no contienen los mismos elementos\n");
    }


    printf("\n\n");
// 17- ll_sublist
    printf("--- ll_sublist   (17) --- \n\n");

    subListaDeJugadores = ll_subList(listaDeJugadores, 0,9);
    printf("Sub Lista de los 10 primero de la lista (ll_sublist)\n\n");
    mostrarJugadores(subListaDeJugadores);


    printf("\n\n");
// 19- ll_sort  ordena los elementos de la lista reciviendo los paramentros de la funcion de ordenamiento que queremos usar
    printf("--- ll_sort    (19) --- \n\n");
    ll_sort(listaDeJugadores, jugador_ordenarApellido,1);
    printf("\n--- Lista ordenada por Apellido de menor a mayor (ll_sort) ---\n");
    mostrarJugadores(listaDeJugadores);


    printf("\n\n");
// 9-  ll_clear   borro todos los elementos de la lista
    printf("--- ll_clear    (11) --- \n\n");
    if( !ll_isEmpty(listaDeJugadores))  // si la lista no esta vacia, la vacio
    {
        ll_clear(listaDeJugadores);
        printf("\nSe borraron todos los elementos de la lista\n\n");
    }
    printf("La cantidad de jugadores en la lista es (ll_len): %d \n\n", ll_len(listaDeJugadores));


    printf("\n\n");
// 10- ll_deleteLinkedList   elimino la lista LinkedList
    printf("--- ll__deleteLinkedList    (10) --- \n\n");
    ll_deleteLinkedList(listaDeJugadores);
    printf("\nLista eliminada completamente\n");

//    eJugador jugador;
//    eJugador* auxJugador1;
//    eJugador* auxJugador2;
//    startTesting(1);  // ll_newLinkedList
//    startTesting(2);  // ll_len
//    startTesting(3);  // getNode - test_getNode
//    startTesting(4);  // addNode - test_addNode
//    startTesting(5);  // ll_add
//    startTesting(6);  // ll_get
//    startTesting(7);  // ll_set
//    startTesting(8);  // ll_remove
//    startTesting(9);  // ll_clear
//    startTesting(10); // ll_deleteLinkedList
//    startTesting(11); // ll_indexOf
//    startTesting(12); // ll_isEmpty
//    startTesting(13); // ll_push
//    startTesting(14); // ll_pop
//    startTesting(15); // ll_contains
//    startTesting(16); // ll_containsAll
//    startTesting(17); // ll_subList
//    startTesting(18); // ll_clone
//    startTesting(19); // ll_sort

    return 0;
}

































