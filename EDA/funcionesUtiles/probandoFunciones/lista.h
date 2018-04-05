#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//-------------------
//   Sorted List
//-------------------

//crear en el main el struct node
/*
typedef struct node
{
    int n;
    struct node* next;
}node;
*/

// funciones (numero, nodo inicial) la mayoria
node* insertar(int numero, node* head);
void mostrarLista(node* head);
node* borrarNodo(int num, node* head);
node* invertList(node* head);
node* salir(node* head);

node* salir(node* head){
    //borrando la lista al salir
    node* ptr = head;
    while (ptr != NULL)
    {
        node* predptr = ptr;
        ptr = ptr->next;
        free(predptr);
    }
    return head;
}

node* insertar(int numero, node* head)
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
    else if (newptr->n < head->n)
    {
        newptr->next = head;
        head = newptr;
    }
    else
    {
        node* ptr = head;
        node* tmp = head;
        while (1>0)
        {
            // Insertando al final
            if (ptr->next == NULL)
            {
                tmp = ptr;
                ptr->next = newptr;
                break;
            }

                // Caso donde el nodo tiene que ser agregado al medio
            else if (ptr->next->n > newptr->n)
            {
                //tmp = ptr;
                newptr->next = ptr->next;
                ptr->next = newptr;
                break;
            }
            // Cambiando el puntero

            ptr = ptr->next;
        }
    }
    return head;
}

//Recorriendo la lista
void mostrarLista(node* head)
{
    // Recorriendo la lista
    printf("\nLista: ");
        node* ptr = head;
        while (ptr != NULL)
        {
            printf("%i ", ptr->n);
            ptr = ptr->next;
        }
    printf("\n\n");
}

node* borrarNodo(int num, node* head)
{
    node* temp=head;
    node* pretemp;

    while(temp!=NULL)
    {

        if ((head->n==num) && (head!=NULL)){//al inicio
            //pretemp=temp;
            if(temp->next!=NULL){
                head=temp->next;
            }
            else{ //caso que no quede ningun nodo
                head=NULL;
            }
            free(temp);
            break;
        }


        if ((temp->n==num) && (temp->next!=NULL)){//al medio
            pretemp->next=temp->next;
            free(temp);
            break;
        }


        if ((temp->next==NULL) && (temp->n==num)){//al final
            pretemp->next=NULL;
            free(temp);
            break;
        }
        pretemp=temp;
        temp=temp->next;
    }
    return head;
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
    if(tmp2->next==NULL){
        tmp2->next=ptr;
        head=tmp2;
        return head;
    }
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