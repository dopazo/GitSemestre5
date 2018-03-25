#include <stdio.h>
#include "pila_l.h"

int main(void){
    printf("agregando un 5 \n");
    push(5);

    int x= peek();
    printf("El de arriba en la pila es %i \n", x);

    pop();

    x=peek();
    x=isempty();
    if(x==1){
        printf("la pila esta vacia \n");
    }
    else {
        printf("la pila no esta vacia");
    }
}