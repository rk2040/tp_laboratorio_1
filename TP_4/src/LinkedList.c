#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);              // Obtengo un Nodo "un vagon"
static int addNode(LinkedList* this, int nodeIndex,void* pElement); // Agrego un nuevo nodo

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));    // (casteo) consigo, pido espacio en memoria

    if(this != NULL){
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){

            nodo = this->pFirstNode;    //nodo 0    Primer "vagon"

            while(nodeIndex > 0){
                nodo = nodo->pNextNode;
                nodeIndex--;
            }
        }

    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo = NULL;
    Node* previousNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) )    // no validamos pElement que != NULL por como ya esta programado el test, pero si deberiamos validarlo
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));   // (casteo) consigo, pido espacio en memoria

        if(nuevoNodo != NULL)
        {
            nuevoNodo->pElement = pElement; // Le paso la dire donde tiene que apuntar el nuevo nodo
            nuevoNodo->pNextNode = NULL;

            if(nodeIndex == 0)
            {
                nuevoNodo->pNextNode = this->pFirstNode;    //Hago primero esta linea para no perder el resto del "tren" copiando la dire
                this->pFirstNode = nuevoNodo;               //Conecto la "Locomotora" al nuevoNodo que es el nuevo "primer vagon"
            }
            else
            {
                previousNode = getNode(this, nodeIndex-1);
                nuevoNodo->pNextNode = previousNode->pNextNode;
                previousNode->pNextNode = nuevoNodo;
            }

            this->size++;   //agrego cantidad de elementos en la estructura ( ver  LinkedList.h  linea 30 )

            returnAux = 0;
        }

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    returnAux = addNode(this, ll_len(this), pElement);

    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado // Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux = NULL;

    aux = getNode(this, index);     // no lo valido antes, porque getNode ya tiene las validaciones

    if(aux != NULL)
    {
        returnAux = aux->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista     // Piso el campo pElement de un vagon ubicado en ese indice
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this) )     //Pisa un indice existente, NO agrega uno nuevo al final
    {
        auxNode = getNode(this, index);

        if(auxNode != NULL)
        {
            auxNode->pElement = pElement;

            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
   // Node* aux;
    Node* previousNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this) )
    {
     //   aux = getNode(this, index);
      //  if(aux != NULL)
     //   {
            if(index == 0)
            {
          //      this->pFirstNode = aux->pNextNode;

                this->pFirstNode = this->pFirstNode->pNextNode;
            }
            else
            {
                previousNode = getNode(this, index -1);
                if(previousNode != NULL)
                {
                    previousNode->pNextNode = previousNode->pNextNode->pNextNode;

                }
            }
          //  free(aux);
            this->size--;
            returnAux = 0;
      //  }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        while(ll_len(this) )
        {
            ll_remove(this, 0);
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_clear(this) == 0)
        {
            free(this);
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
           //Retorna el índice de la primera aparición de un elemento (element) en el LinkedList.
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        int tam = ll_len(this);
        for(int i=0; i<tam; i++)
        {
            if(pElement == ll_get(this, i) )
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 1;
        if( ll_len(this) )
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
           //Desplaza los elementos e inserta en la posición index.
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    returnAux = addNode(this, index, pElement);

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    returnAux = ll_get(this, index);
    ll_remove(this, index);

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) si No contiene el elemento
                        ( 1) Si contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this, pElement) >= 0 )
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElemento = NULL;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;

        int tam = ll_len(this2);

        for(int i=0; i<tam; i++)
        {
            auxElemento = ll_get(this2, i);
            if( !ll_contains(this, auxElemento) )
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (NO incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                              o (si el indice from es menor a 0 o mayor al len de la lista)
                                              o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL && from >= 0 && to <= ll_len(this) && to > from)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {

            for(int i=from; i<to; i++)
            {
                ll_add(cloneArray, ll_get(this, i) );   // ll_get() me devuelve el elemento de la lista en la posicion i, para usarlo en la funcion ll_add
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
/*
    LinkedList* cloneArray = NULL;
    int tam;

    if(this != NULL )
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            tam = ll_len(this);
            for(int i=0; i<tam; i++)
            {
                ll_add(cloneArray, ll_get(this, i) );
            }
        }
    }
    return cloneArray;
*/
 return ll_subList(this, 0, ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente
                     [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int tam;

    void* aux = NULL;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        tam = ll_len(this);

        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if( ( pFunc(ll_get(this,i), ll_get(this, j)) > 0 && order ) ||   // Llamamos a la funcion que le vamos a pasar por parametro
                    ( pFunc(ll_get(this,i), ll_get(this, j)) < 0 && !order ) )   // segun que funcion necesitemos usar en ese momento
                {
                   aux = ll_get(this, i);
                   ll_set(this, i, ll_get(this, j) );
                   ll_set(this, j, aux);
                }
            }
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista Filtrada) Si ok
 */LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* filterList = NULL;
    void* elemento = NULL;
    int tam;

    if(this != NULL && pFunc != NULL)
    {
        filterList = ll_newLinkedList();

        if(filterList != NULL)
        {
            tam = ll_len(this);

            for(int i=0; i<tam; i++)
            {
                elemento = ll_get(this, i);

                if(pFunc(elemento))
                {
                    ll_add(filterList, elemento);
                }
            }
        }
    }

    return filterList;
}
