//
// Hecho por Juan Francisco Ternicien y Diego Opazo
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//crear en el main el struct node
/*
typedef struct node
{
    int n;
    struct node* next;
}node;
*/

//funciones
node* push(int numero,node* head);
node* pop(node* head);
int peek(node* head);
int isempty(node* head);

//agregar elemento
node* push(int numero, node* head)
{
    //crea un nuevo nodo vacio
    node* newptr = (node*) malloc(sizeof(node));

    //inicialización del nodo
    newptr->n = numero;
    newptr->next = NULL;

    //Verificando si la lista esta vacia
    if (head == NULL)
    {
        head = newptr;
    }
        //insertar al inicio
    else
    {
        newptr->next = head;
        head = newptr;
    }
    return head;
}

//quitar elemento
node* pop(node* head)
{
    node* temp=head;
    if(temp!=NULL) //si existe una pila
    {
        if(temp->next!=NULL){ //si sigue existiendo una pila
            head=temp->next;
        }
        else{ //si pila queda vacia
            head=NULL;
        }
        free(temp);
        printf("Eliminado el ultimo de la pila (desde pop) \n");
    }
    else{
        printf("Pila vacia (desde pop)\n");
    }
    return head;
}

//Mirar el inicial
int peek(node* head)
{
    node* ptr = head;
    if(ptr != NULL)
    {
        return ptr->n;
    }
    else{
        printf("Pila vacia (desde peek)\n");
        return 0;
    }

    printf("\n\n");
}


int isempty(node* head){
    if(head != NULL) //si no esta vacia
    {
        return 0;
    }
    else{ //si esta vacia
        return 1;
    }
}