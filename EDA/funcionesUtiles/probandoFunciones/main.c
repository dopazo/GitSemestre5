#include <stdio.h>
#include "lista.h"
#include "pila_l.h"

typedef struct node
{
    int n;
    struct node* next;
}node;

int main() {
    //probando pila_l.h
    node* headPila=malloc(sizeof(node));
    headPila=NULL;
    headPila=push(2,headPila);
    headPila=push(4,headPila);
    peek(headPila);



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