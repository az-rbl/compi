# include <stdbool.h>

/**
 * Estructura para pilas.
*/

typedef struct _Pila Pila;

/**
 * Crea uan nueva pila.
 */
Pila* pila_nueva (void);

/**
 * Permite introducir un elemento a una pila.
 */

void pila_mete (Pila* pila, void * elemento);

/**
 * Permite sacar el primer elemento del a pila
*/

void* pila_saca (Pila* pila);

/**
 * Incica si uan pila no contiene elemntos
*/
bool pila_es_vacia (Pila* pila);

/**
 * Permite liberar la memoria que utiliza la pila
*/
void pila_libera (Pila* pila);
