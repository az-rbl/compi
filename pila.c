#include <stdlib.h>
#include <assert.h>
# include <stdbool.h>
# include <stdio.h>
#include "pila.h"
//typedef struct _Pila Pila;

typedef struct _NodoPila NodoPila ;

 struct _NodoPila {
 void * elemento ;
 NodoPila * anterior ;
 };

 struct _Pila {
 NodoPila * primero ;
 NodoPila * ultimo ;
 };

Pila * pila_nueva () {
    struct _Pila* nuevaPila;
    nuevaPila = malloc(sizeof(struct _Pila));
    return nuevaPila;
 }
 bool pila_es_vacia ( Pila * pila ) {
 assert ( pila != NULL );
 if (pila->primero ==NULL){
    return 1;
    }
    else 
        return 0;
 }


 void pila_mete ( Pila * pila , void * elemento ) {
 assert ( pila != NULL && elemento != NULL );
 
 struct _NodoPila* nuevoNodo;
 nuevoNodo = malloc(sizeof(struct _NodoPila));
 nuevoNodo->elemento = elemento;
    if(pila_es_vacia(pila)){//si la pila esta vacía este también será el último elemento
        pila->ultimo = nuevoNodo;
        pila->primero = nuevoNodo;
        nuevoNodo->anterior =NULL;
    } else {
    nuevoNodo->anterior = pila->primero;
    pila->primero = nuevoNodo;
    }
 }

 void * pila_saca ( Pila * pila ) {
 assert ( pila != NULL );
 pila->primero = pila->primero->anterior;
 }


 void pila_libera ( Pila * pila ) {
 assert ( pila != NULL );
    NodoPila *temp;
    while (pila->primero != NULL){
         temp = pila->primero->anterior;
         free (pila->primero);
        pila->primero = temp;
    }
    free (pila->primero);
    free (pila->ultimo);
    free (pila);

 }
/*
int main(){
    Pila* miPila = pila_nueva();
    printf("%d\n", pila_es_vacia(miPila));
    int x = 3;
    pila_mete(miPila, &x);
    printf("%d\n", *(int*)(miPila->primero->elemento));
    int y = 5;
    pila_mete(miPila, &y);
    printf("%d\n", *(int*)(miPila->primero->elemento));
    pila_saca(miPila);
    printf("%d\n", *(int*)(miPila->primero->elemento));
    printf("%d\n", pila_es_vacia(miPila));
    pila_libera(miPila);
}
*/
