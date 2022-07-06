

/**
 * @brief Carga los datos del archivo data.csv en modo texto
 *
 * @param  path ruta del archivo que tiene los datos
 * @param  pArrayListPassenger puntero al archivo de lista de pasajeros
 * @return 0 si salio ok -1 si salio mal
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief Carga los datos del archivo databin.csv en modo binario
 *
 * @param  path ruta del archivo que tiene los datos
 * @param  pArrayListPassenger puntero al archivo de lista de pasajeros
 * @return 0 si salio ok -1 si salio mal
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief Realiza el alta del pasajero recibiendo un puntero a la lista
 *
 * @param  pArrayListPassenger punteroa la lista de pasajeros
 * @return 0 si salio ok -1 si hubo error
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* pNextId);

/**
 * @brief Realiza  la modificacion de un pasajero de la lista solicitando el id como referencia
 *
 * @param pArrayListPassenger punteroa la lista de pasajeros
 * @return 0 si salio ok -1 si hubo error
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief Realiza la baja de un pasajero de la lista solicitando el id como referencia
 *
 * @param pArrayListPassenger punteroa la lista de pasajeros
 * @return
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/**
 * @brief Realiza la muestra de los empleados cargados en la lista
 *
 * @param pArrayListPassenger punteroa la lista de pasajeros
 * @return 0 si salio ok -1 si hubo error
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief
 *
 * @param pArrayListPassenger
 * @return
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/**
 * @brief Realiza el guardado de los datos en modo texto con los que se opero luego de abrir el archivo
 * recibe el puntero a la lista y la ruta al archivo con el que trabajamos (data.csv)
 *
 * @param path ruta al archivo csv
 * @param pArrayListPassenger punteroa la lista de empleado
 * @return 0 si salio ok -1 si hubo error
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
 * @brief Realiza el guardado de los datos en modo binario con los que se opero luego de abrir el archivo
 * recibe el puntero a la lista y la ruta al archivo con el que trabajamos (databin.csv)
 *
 * @param path ruta al archivo csv
 * @param pArrayListPassenger punteroa la lista de empleado
 * @return 0 si salio ok -1 si hubo error
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


//----------
int buscarPorId(LinkedList* this, int idBuscado);

int buscarMayorId(LinkedList* pArrayListPassenger);
