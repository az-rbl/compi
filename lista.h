# include <stdbool.h>
// # include <util.h>

 /**
 * Estructura para listas doblemente ligadas .
*/
 typedef struct _Lista Lista ;

 /**
 * @brief Estructura para nodos de listas doblemente ligadas .
 */
 typedef struct _NodoLista NodoLista ;

 /**
 * Crea una nueva lista
 */
 Lista * lista_nueva ( void );

 /**
 * Regresa el primer nodo de una lista .
 */
 NodoLista * lista_cabeza ( Lista * lista );

 /**
 * Regresa el ultimo nodo de una lista .
 */
 NodoLista * lista_rabo ( Lista * lista );

 /**
 * Regresa la longitud de una lista .
 */
 int lista_longitud ( Lista * lista );


 /**
 * Agrega un elemento al inicio de una lista .
 */
 void lista_agrega_inicio ( Lista * lista ,
 void * elemento );
 /**
 * Agrega un elemento al final de una lista .
 */
 void lista_agrega_final ( Lista * lista ,
 void * elemento );

 /**
 * Inserta un elemento en la lista antes del nodo recibido .
 */
 void lista_inserta_antes ( Lista * lista ,
 NodoLista * nodo ,
 void * elemento );

 /**
 * Inserta un elemento en la lista despues del nodo recibido .
 */
 void lista_inserta_despues ( Lista * lista ,
 NodoLista * nodo ,
 void * elemento );

 /**
1 * Elimina un elemento de la lista .
*/
 void lista_elimina ( Lista * lista ,
 void * elemento );

 /**
 * Elimina el primer elemento de la lista .
 */
 void * lista_elimina_primero ( Lista * lista );

 /**
 * Elimina el ultimo elemento de la lista .
 */
 void * lista_elimina_ultimo ( Lista * lista ) ;

 /**
 * Regresa el i- esimo nodo de una lista , comenzando desde 0.
 */
 NodoLista * lista_dame ( Lista * lista ,
 int indice );

 /**
 * La funcion libera la memoria usada por la lista , pero no la que
* utilizan los elementos dentro de ella .
 */
 void lista_libera ( Lista * lista );

 /**
 * Libera la memoria usada por la lista y sus elementos .
 */
 void lista_libera_todo ( Lista * lista );


/**
 * Regresa el elemento de un nodo .
 */
 void * nodo_lista_elemento ( NodoLista * nodo );

 /**
 * Regresa el nodo anterior de un nodo .
 */
 NodoLista * nodo_lista_anterior ( NodoLista * nodo );
 /**
* Regresa el nodo siguiente de un nodo .
 */
 NodoLista * nodo_lista_siguiente ( NodoLista * nodo );
