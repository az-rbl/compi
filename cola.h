# include <stdbool.h>


 typedef struct _Cola Cola ;

 /**
 * Crea una nueva cola que debe ser liberada por el usuario .
 */
 Cola * cola_nueva ( void ) ;

 /**
 * Permite introducir un nuevo elemento en la cola .
 */
 void cola_mete ( Cola *cola , void * elemento );

 /**
 * Permite obtener sacar el primer elemento de la cola
 */
 void * cola_saca ( Cola * cola );

 /**
 * Indica si la cola no tiene elementos
 */
 bool cola_es_vacia ( Cola * cola ) ;

 /**
 * Permite liberar la cola de la memoria
 */
 void cola_libera ( Cola * cola );
