#include <stdio.h>
#include "lista.h"

int main() {
    insertar(5);
    insertar(4);
    insertar(3);
    insertar(2);
    insertar(1);
    insertar(0);
    mostrarLista(head);
    head=invertList(head);
    mostrarLista(head);
    //printf("head: %i\n",head->n);
}