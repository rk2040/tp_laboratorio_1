#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Transforma los datos del archivo de empleados data.csva modo texto
 * \param pFile ruta al archiv data.csv
 * \param pArrayListEmployee puntero al array de empleados donde van los dat
 * \return devuelve 0 si salio ok -1 si salio mal
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Transforma los datos del archivo de empleados databin.csv modo binario
 * \param pFile ruta al archiv databin.csv
 * \param pArrayListEmployee puntero al array de empleados donde van los datos
 * \return devuelve 0 si salio ok -1 si salio mal
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


int loadFromText(char* path, LinkedList* pArrayListaDeJugadores);

#endif // PARSER_H_INCLUDED
