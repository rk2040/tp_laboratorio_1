#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED


#define NOMBRE 128
#define APELLIDO 128
#define POSICION 128
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    char posicion[128];
    int edad;
}eJugador;

/**
 * \brief Constructor del espacio de memoria para el jugador
 *
 * \return devuelve un puntero al espacio de memoria que encontro y si no devuelve NULL
 */
eJugador* jugador_new();

/** \brief Constructor que inicializa las variables que va recibe por parametro
 * de tipo int mayoritariamente
 *
 * \param  id a asignar al jugador
 * \param   nombre a asigna al jugador
 * \param   posicion a asigna al jugador
 * \param   edad a asignar al jugador
 * \param   altura a asigna al jugador
 * \return puntero al jugador generado
 *
 */

eJugador* jugador_newParametrosInt(int id, char* nombre, char* apellido, char* posicion, int edad);
/** \brief Constructor en formato char que inicializa las variables que va recibe por parametro


 * que son de tipo char mayormente
 *
 * \param  id a asignar al jugador
 * \param   nombre a asigna al jugador
 * \param   posicion a asigna al jugador
 * \param   edad a asignar al jugador
 * \param   altura a asigna al jugador
 * \return puntero al jugador generado
 *
 */
eJugador* jugador_newParametrosChar(char* idStr, char* nombreStr, char* apellidoStr, char* posicionStr, char* edadStr);

/** \brief libera el espacio de memoria donde se encuentra el jugador que le pasamos
 * \param puntero al jugador que deseamos borrar
 */

void jugador_delete(eJugador* this);

int destroyJugador(eJugador* jugador);

/**
 * \brief copia el valor introducido del id y lo copia al array
 * \param puntero array en el guardamos los ids
 * \param número de id introducido
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int jugador_setId(eJugador* this, int id);

/**
 * \brief Obtiene el valor de Id contenido en ese espacio del array
 * \param puntero array en el guardamos los ids
 * \param número de id que obtenimos
 * \return 0 si lo obtuvo sin problemas, 1 si hubo un error.
 */
int jugador_getId(eJugador* this,int* id);

/**
 * \brief recibre el nombre y lo copia al array de nombres
 * \param puntero array en el guardamos el nombres
 * \param nombre introducido
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int jugador_setNombre(eJugador* this, char* nombre);

/**
 * \brief Obtiene el valor de nopmbre contenido en ese espacio del array
 * \param puntero array en el guardamos los nombres
 * \param nombre obtenido
 * \return 0 si lo obtuvo sin problemas, 1 si hubo un error.
 */
int jugador_getNombre(eJugador* this,char* nombre);

/**
 * \brief recibre el apellido y lo copia al array de apellido
 * \param puntero array en el guardamos el apellido
 * \param apellido introducido
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int jugador_setApellido(eJugador* this, char* apellido);

/**
 * \brief Obtiene el valor de Id contenido en ese espacio del array
 * \param puntero array en el guardamos los ids
 * \param número de id que obtenimos
 * \return 0 si lo obtuvo sin problemas, 1 si hubo un error.
 */
int jugador_getApellido(eJugador* this, char* apellido);

int jugador_setPosicion(eJugador* this, char* posicion);

int jugador_getPosicion(eJugador* this,char* posicion);

/**
 * \brief recibre las horas trabajadas y lo copia al array de emp en horas trabajadas
 * \param puntero array en el guardamos las horas trabajadas
 * \param horas trabajadas introducidas
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int jugador_setEdad(eJugador* this, int edad);
/**
 * \brief Obtiene el valor de horas trabajadas en ese espacio del array
 * \param puntero array en el obtenemos las horas
 * \param horas obtenidas
 * \return 0 si lo obtuvo sin problemas, 1 si hubo un error.
 */
int jugador_getEdad(eJugador* this,int* edad);



/** \brief Muestra el jugador pasado por el puntero a donde se ubicad
 *
 * \param jugador puntero a la direccion del jugador a mostrar
 * \param
 * \return  0 si lo devolvió sin problemas, -1 si hubo un error.
 *
 */

int mostrarJugador(eJugador* jugador);


int mostrarJugadores(LinkedList* pArrayListaDeJugadores);


/** \brief Genera el proximo id del jugador a partir de la busqueda del ultimo id generado
 * y se lo asgina al nuevo jugador creado
 * \param pArrayListaDeEmpleados puntero a la lista de empleados
 * \param
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 *
 */

//int generarIdJugador(LinkedList* pArrayListaDeJugadores);

/** \brief Realiza el incremento de la constante ID que esta inicializada en 0 y la retorna
 * \return ID autoincremental
 */
int jugador_generarId();

/** \brief Realiza el seteo de la ultima ID que tomaremos como referencia
 * \return void no retorna nada
 */
void jugador_setPrimerId(int valorInt);

/** \brief Realiza la busqueda del jugador por el Id pasado por ferencia
 * \param pArrayListaDeEmpleados puntero a la lista de empleados
 * \param IdBuscado
 * \return 0 si lo econtro sin problemas, -1 si hubo un error.
 */

int jugador_buscarPorId(LinkedList* pArrayListaDeJugadores, int idBuscado);

/** \brief Realiza el ordenamiento segun el criterio en este caso el ID
 * \param emp1 puntero a void de jugador
 * \param emp2 puntero a void de jugador
 * \return 0 si lo ordeno sin problemas, 1 si no ordeno
 */
int jugador_ordenarPorId(void* jug1,void* jug2);

/** \brief Realiza el ordenamiento segun el criterio en este caso el nombre
 * \param emp1 puntero a void de jugador
 * \param emp2 puntero a void de jugador
 * \return 0 si lo ordeno sin problemas, 1 si no ordeno
 */
int jugador_ordenarNombre(void* jug1,void* jug2);

/** \brief Realiza el ordenamiento segun el criterio en este caso el apellido
 * \param emp1 puntero a void de jugador
 * \param emp2 puntero a void de jugador
 * \return 0 si lo ordeno sin problemas, 1 si no ordeno
 */int jugador_ordenarApellido(void* jug1,void* jug2);


int jugador_ordenarPosicion(void* jug1,void* jug2);


/** \brief Realiza el ordenamiento segun el criterio en este caso horas trabajadsa
 * \param emp1 puntero a void de jugador
 * \param emp2 puntero a void de jugador
 * \return 0 si lo ordeno sin problemas, 1 si no ordeno
 */
int jugador_edad(void* jug1,void* jug2);


int filtrar_porPosicion(void* jugador, char* posicion);

#endif // JUGADOR_H_INCLUDED
