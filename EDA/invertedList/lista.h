#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    int n;
    struct node* next;
}node;

// Lista puntero inicial
node* head = NULL;

// prototipos
void insertar(int numero);
void mostrarLista(node* head);
void borrarNodo(void);
void salir();

void salir(){
    //borrando la lista al salir
    node* ptr = head;
    while (ptr != NULL)
    {
        node* predptr = ptr;
        ptr = ptr->next;
        free(predptr);
    }
}

void insertar(int numero)
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

void borrarNodo(void)
{
    printf("Ingrese el numero a borrar:\n");
    int num;
    scanf(" %i", &num);
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
}