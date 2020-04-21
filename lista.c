# include <assert.h>
 # include <stdlib.h>
 # include "lista.h"
#include <stdio.h>


 typedef struct _NodoLista NodoLista ;
 struct _Lista {
NodoLista * cabeza ;
 NodoLista * rabo ;
 int longitud ;
 };

 struct _NodoLista {
 void * elemento ;
 NodoLista * anterior ;
 NodoLista * siguiente ;
 };

 static NodoLista * nodo_lista_nuevo ( void * elemento ) {
 assert ( elemento != NULL );
 // implementa
 }

 Lista * lista_nueva ( void ) {
    Lista* nuevaLista;
    nuevaLista = malloc(sizeof(struct _Lista));
    return nuevaLista;
 }

 NodoLista * lista_cabeza ( Lista * lista ) {
 assert ( lista != NULL );
    return lista->cabeza;
 }

 NodoLista * lista_rabo ( Lista * lista ) {
 assert ( lista != NULL );
    return lista->rabo;
 }
// la lista se recorre asi:
// rabo -anterior-------->cabeza
// rabo <---------siguiente cabeza
 int lista_longitud ( Lista * lista ) {
 assert ( lista != NULL );
    if (lista->cabeza == NULL){
        return 0;
    }
    int longitud = 1;
    NodoLista* recorre = lista->cabeza;
    while (recorre != lista->rabo){
        longitud ++;
        recorre = recorre->siguiente;
    }
    return longitud;
 }
// el inicio es la cabeza
 void lista_agrega_inicio ( Lista *lista , void * elemento ) {
 assert ( lista != NULL && elemento != NULL ) ;
    //estas lineas crean el nuevo nodo
    NodoLista* nuevoPrimer;
    nuevoPrimer = malloc(sizeof(NodoLista));
    nuevoPrimer->elemento = elemento;

    //ahora lo ubicamos
    lista->cabeza->anterior = nuevoPrimer;
    nuevoPrimer->siguiente = lista->cabeza;
    lista->cabeza = nuevoPrimer;
 }

 void lista_agrega_final ( Lista *lista , void * elemento ) {
 assert ( lista != NULL && elemento != NULL ) ;
    //estas lineas crean el nuevo nodo
    NodoLista* nuevoUltimo;
    nuevoUltimo = malloc(sizeof(NodoLista));
    nuevoUltimo->elemento = elemento;

    //ahora lo ubicamos
    lista->rabo->siguiente = nuevoUltimo;
    nuevoUltimo->anterior= lista->rabo;
    lista->rabo = nuevoUltimo;   
 }

 void lista_inserta_antes ( Lista *lista , NodoLista *nodo , void * elemento ) {
 assert ( lista != NULL && nodo != NULL && elemento != NULL );
 assert (( nodo -> anterior != NULL && nodo != lista -> cabeza ) ||
 (nodo -> anterior == NULL && nodo == lista->cabeza ));
    
    
    if (nodo == lista->cabeza){
        lista_agrega_inicio(lista, elemento);
    }else{

        //estas lineas crean el nuevo nodo
        NodoLista* nuevoAntes;
        nuevoAntes = malloc(sizeof(NodoLista));
        nuevoAntes->elemento = elemento;
    
        nuevoAntes->anterior = nodo->anterior;
        nuevoAntes->siguiente = nodo;
        nodo->anterior = nuevoAntes;
    
    }
}

 void lista_inserta_despues ( Lista *lista , NodoLista *nodo , void * elemento ) {
 assert ( lista != NULL && nodo != NULL && elemento != NULL );
 assert (( nodo -> siguiente != NULL && nodo != lista -> rabo ) ||
 (nodo -> siguiente == NULL && nodo == lista -> rabo ));
 
    if (nodo == lista->rabo){
        lista_agrega_final(lista, elemento);
    }else{

        //estas lineas crean el nuevo nodo
        NodoLista* nuevoDespues;
        nuevoDespues = malloc(sizeof(NodoLista));
        nuevoDespues->elemento = elemento;
    
        nuevoDespues->siguiente = nodo->siguiente;
        nuevoDespues->anterior = nodo;
        nodo->siguiente = nuevoDespues;
    
    }
 }


 void * lista_elimina_primero ( Lista * lista ) {
 assert ( lista != NULL && lista->cabeza != NULL ) ;
    NodoLista* eliminado;
    eliminado = lista->cabeza;
    
    lista->cabeza = lista->cabeza->siguiente;
    
    free(eliminado);
 }

 void * lista_elimina_ultimo ( Lista * lista ) {
 assert ( lista != NULL && lista->rabo != NULL );
    NodoLista* eliminado;
    eliminado = lista->rabo;
    
    lista->rabo = lista->rabo->anterior;
    
    free(eliminado);
 }

 void lista_elimina_nodo ( Lista *lista , NodoLista * nodo ) {
 assert ( lista != NULL && nodo != NULL );
    if (nodo == lista->cabeza){
        lista_elimina_primero(lista);
    }else if (nodo == lista->rabo){
        lista_elimina_ultimo(lista);
    }else {
        nodo->anterior->siguiente = nodo->siguiente;
        nodo->siguiente->anterior = nodo->anterior;
        free (nodo);
        }
 }


 NodoLista * lista_dame ( Lista *lista , int indice ) {
 assert ( lista != NULL && indice >= 0 && indice < lista->longitud ) ;
        NodoLista* recorre = lista->cabeza;
        
        for (int i = 0; i < indice; i++){
            recorre = recorre->siguiente;
        }
        return recorre;
 }

 void lista_libera ( Lista * lista ) {
 assert ( lista != NULL );
        
       free(lista);
            
 }

 void lista_libera_todo ( Lista * lista ) {
 assert ( lista != NULL );
        NodoLista* recorre = lista->cabeza;
        
        while (recorre != lista->rabo){
            NodoLista * temp = recorre;
            recorre = recorre->siguiente;
            temp->siguiente=NULL;
            temp->anterior = NULL;
            free(temp);
        }
        free(lista->cabeza);
         free(lista->rabo);
        free(lista);
 }

 void * nodo_lista_elemento ( NodoLista * nodo ) {
 assert ( nodo != NULL );
   return nodo->elemento;
 }

 NodoLista * nodo_lista_anterior ( NodoLista * nodo ) {
 assert ( nodo != NULL );
       return nodo->anterior;
 }

 NodoLista * nodo_lista_siguiente ( NodoLista * nodo ) {
 assert ( nodo != NULL );
        return nodo->siguiente;
 }

int main(){
    Lista* miLista = lista_nueva();
    printf("%d\n", lista_es_vacia(miLista));
    int x = 3;
    lista_agrega_inicio(miLista, &x);
    printf("%d\n", *(int*)(miLista->cabeza->elemento));
    int y = 5;
    lista_agrega_inicio(miLista, &y);
    printf("%d\n", *(int*)(miLista->cabeza->elemento));
    lista_elimina_ultimo(miLista);
    printf("%d\n", *(int*)(miLista->cabeza->elemento));
    printf("%d\n", lista_es_vacia(miLista));
    lista_libera(miLista);
}
