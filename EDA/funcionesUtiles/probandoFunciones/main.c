#include <stdio.h>
#include "pila_l.h"
//#include "lista.h"

int main() {
    //probando pila_l.h
    node* headPila=malloc(sizeof(node));
    headPila=NULL;
    headPila=push(2,headPila);
    headPila=push(4,headPila);
    printf("peek: %i\n",peek(headPila));
    pop(headPila); // ???
    printf("headPila es: %i\n",headPila->n);
    printf("peek: %i\n",peek(headPila));


    //probando lista.h
    /*
    node* head=malloc(sizeof(node));
    head=NULL;
    head=insertar(1,head);
    head=insertar(2,head);
    head=insertar(3,head);
    head=insertar(4,head);
    mostrarLista(head);
    head=borrarNodo(3, head);
    head=invertList(head);
    mostrarLista(head);
    */
}