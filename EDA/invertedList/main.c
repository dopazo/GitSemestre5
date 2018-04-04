#include <stdio.h>
#include "lista.h"

node* invertList(node* head);

int main() {
    insertar(0);
    insertar(1);
    //insertar(2);
    //insertar(3);
    //insertar(4);
    //insertar(5);
    mostrarLista(head);
    head=invertList(head);
    mostrarLista(head);
    //printf("head: %i\n",head->n);

}

node* invertList(node* head){
    if(head==NULL || head->next==NULL){ //si, vacia o largo 1
        return head;
    }
    if(head->next->next==NULL){ //si, largo 2
        node* tmp=head->next;
        head->next->next=head;
        head->next=NULL;
        return tmp;
    }
    node* tmp=head;
    node* ptr=head->next;
    node* tmp2=ptr->next;
    //cambiar direccion, nodo inicial
    tmp->next=NULL;
    ptr->next=tmp;
        //pasar al sgte
    tmp=ptr;
    ptr=tmp2;
    tmp2=tmp2->next;
    while(tmp2->next!=NULL) {
        //cambiar direccion, dpues del nodo inicial
        ptr->next = tmp;
        //pasar al sgte
        tmp = ptr;
        ptr = tmp2;
        tmp2 = tmp2->next;
    }
    //ultima iteracion
    ptr->next=tmp;
    tmp2->next=ptr;
    //final
    head=tmp2;
    return head;
}