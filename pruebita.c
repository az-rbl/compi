#include "pila.c"

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
