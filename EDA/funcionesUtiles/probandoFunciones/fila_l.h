//
// Created by Rodrigo Martínez on 04-04-2018.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int n;
    struct node* next;
}node;

//agregar a la fila
void queue(int n, first){
    node* ptrnew = (node*)malloc(sizeof(node));
    ptrnew->n= n;
    ptrnew->next=NULL;
    if(first == NULL){
        first = ptrnew;
    }
    else{
        node* tmp = first;
        while(1>0){
            if(tmp->next != NULL){
                tmp = tmp->next;
            }
            if(tmp->next == NULL){
                tmp->next=ptrnew;
                break;
            }
        }}
}

//sacar el primero de la fila
int dequeue(){
    if(first != NULL){
        int n;
        node *tmp=first;
        first = tmp->next;
        n = tmp->n;
        free(tmp);
        return n;}
    else
        return 0;


}

//mirar el primero de la fila
void peek(){
    if(first != NULL)
        printf("%i\n", first->n);
    else
        printf("Fila vacía\n");
}

void isempty(){
    if(first == NULL){
        printf("Fila vacia\n");
    }
    else{
        printf("Fila no vacia\n");
    }
}

node* INVERTIR_LISTA(node* first){
    node* last = first;
    while(last->next != NULL) {
        last = last->next;
    }
    node* lasttmp = last;
    while(lasttmp != first){
        node* tmp = first;
        while (tmp->next != lasttmp) {
            tmp = tmp->next;
        }
        lasttmp->next = tmp;
        lasttmp=tmp;
    }
    lasttmp->next = NULL;
    first = last;
    return first;
}


