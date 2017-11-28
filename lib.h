#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

/**
* \brief Solicita un numero al usuario y lo valida
* \param input se carga el numero ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit limite inferior a validar
* \param hiLimit limite superior a validar
* \return si obtuvo el numero devuelve "0", en caso contrario devuelve "-1"
*/
int getInt(int* input,char* mensaje,char* eMensaje,int lowLimit,int hiLimit);

/**
* \brief Solicita un numero al usuario y lo valida
* \param input se carga el numero ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit limite inferior a validar
* \param hiLimit limite superior a validar
* \return si obtuvo el numero devuelve "0", en caso contrario devuelve "-1"
*/
int getLong(long* input,char* mensaje,char* eMensaje,long lowLimit,long hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y lo valida
* \param input se carga el string ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit longitud minima de la cadena
* \param hiLimit longitud maxima de la cadena
* \return si obtuvo la cadena devuelve "0", en caso contrario devuelve "-1"
*/
int getStringLetras(char* input,char* mensaje,char* eMensaje,int lowLimit,int hiLimit);

/**
* \brief Solicita s o n al usuario y la valida
* \param input Se carga el caracter validado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \return Void No devuelve nada
*/
void getSN(char* input,char* mensaje,char* eMensaje);

/**
 * \brief Solicita una cadena de caracteres al usuario
 * \param mensaje Es el mensaje a  ser mostrado
 * \param input Array donde se cargara la cadena
 * \return Void No devuelve nada
 */
void getString(char* mensaje, char* input);

/**
 * \brief Verifica si el valor recibido es numerico
 * \param string Es el array con la cadena a ser analizada
 * \return Si es numerico devuelve "0" si no lo es devuelve "-1"
 */
int esNumerico(char* string);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param string Es el array con la cadena a ser analizada
 * \return Si contiene solo letras devuelbe "0" en caso contrario devuelve "-1"
 */
int esSoloLetras(char* string);

/**
 * \brief Coloca la primer letra en mayuscula
 * \param string Es el array con la cadena a ser analizada
 * \return Void No devuelve nada
 */
void formatoTitulo(char* string);

/**
 * \brief Muestra el menu por pantalla
 * \param listado Es el listado de opciones que mostrara
 * \return Devuelve la opcion seleccionada por el usuario
 */
int menu(char* listado);

#endif // LIB_H_INCLUDED
