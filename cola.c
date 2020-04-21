# include <stdlib.h>
 # include <stdio.h>
 # include <assert.h>


 # include "cola.h"
 
typedef struct _NodoCola NodoCola;

struct _NodoCola {
void * elemento ;
NodoCola * siguiente ;
 };

 struct _Cola {
 NodoCola * primero ;
 NodoCola * ultimo ;
};

 Cola * cola_nueva () {
    struct _Cola* nuevaCola;
    nuevaCola = malloc(sizeof(struct _Cola));
    return nuevaCola;
 }

 bool cola_es_vacia ( Cola * cola ) {
assert ( cola != NULL );
 if (cola->primero ==NULL){
    return 1;
    }
    else{ 
        return 0;
    }
 }

 void cola_mete ( Cola * cola , void * elemento ) {
 assert ( cola != NULL && elemento != NULL );
 
 struct _NodoCola* nuevoNodo;
 nuevoNodo = malloc(sizeof(struct _NodoCola));
 nuevoNodo->elemento = elemento;
    if(cola_es_vacia(cola)){//si la cola esta vacía este también será el último elemento
        cola->ultimo = nuevoNodo;
        cola->primero = nuevoNodo;
        nuevoNodo->siguiente =NULL;//como es el primero no tiene siguiente
    } else {
    cola->primero->siguiente = nuevoNodo;//a diferencia de la cola ahora se pone el siguiente del antiguo primero
    cola->primero = nuevoNodo;//el primero ahora es el nuevo
    }
 


 }

 void * cola_saca ( Cola * cola ) {
 assert ( cola != NULL );
 cola->ultimo = cola->ultimo->siguiente;//el último ahora punta al penúltimo
 }



 void cola_libera ( Cola * cola ) {
 assert ( cola != NULL );
 NodoCola *temp;
    while (cola->ultimo != NULL){
         temp = cola->ultimo->siguiente;
         free (cola->ultimo);
         cola->ultimo = temp;
    }
    free (cola->primero);
    free (cola->ultimo);
    free (cola);
 }


int main(){
    Cola* miCola = cola_nueva();
    printf("%d\n", cola_es_vacia(miCola));
    int x = 3;
    cola_mete(miCola, &x);
    printf("%d\n", *(int*)(miCola->primero->elemento));
    int y = 5;
    cola_mete(miCola, &y);
    printf("%d\n", *(int*)(miCola->primero->elemento));
    cola_saca(miCola);
    printf("%d\n", *(int*)(miCola->primero->elemento));
    printf("%d\n", cola_es_vacia(miCola));
    cola_libera(miCola);
}
