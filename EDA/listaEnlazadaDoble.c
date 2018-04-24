/**
 * lista.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Demonstrates a linked list for numbers.
 * Modificada por Sebastian Moreno
 * Modificado nuevamente por Diego Opazo y Rodrigo Martínez
 * lista doblemente enlazada
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct node
{
    int n;
    struct node* next;
    struct node* pre;
}
node;

// Lista puntero inicial
node* first = NULL;
node* last = NULL;

// prototipos
void insertar(int numero);
void mostrarLista(int sentido);
void borrarNodo(void);
void menu();
void salir();

int main(void)
{
    menu();
    salir();
}

void menu(){
    int c;
    
    do
    {
        //imprimir instrucciones
        printf("\nMENU\n\n"
               "1 - insertar nodo\n"
               "2 - mostrar lista izquierda a derecha\n"
               "3 - mostrar lista derecha a izquierda\n"
               "4 - borrar nodo \n"
               "0 - quit\n\n");
        
        printf("Elija una opción: ");
        scanf(" %i", &c);
        
        switch (c)
        {
            case 1: insertar(0); break;
            case 2: mostrarLista(0); break;
            case 3: mostrarLista(1); break;
            case 4: borrarNodo(); break;
        }
    }
    while (c != 0);
}

void salir(){
    //borrando la lista al salir
    node* ptr = first;
    while (ptr != NULL)
    {
        node* predptr = ptr;
        ptr = ptr->next;
        free(predptr);
    }
}

void insertar(int numero)
{
    if (numero==0){
        printf("Ingrese numero: ");
        scanf(" %i", &numero);
    }
    
    //crea un nuevo nodo vacio
    node* newptr = (node*) malloc(sizeof(node));
    
    //inicialización del nodo
    newptr->n = numero;
    newptr->next = NULL;
    newptr->pre = NULL;
    
    //Verificando si la lista esta vacia
    if (first == NULL)
    {
        first = newptr;
        last = newptr;
    }
    //insertar al inicio 
    else if (newptr->n < first->n)
    {
        newptr->next = first;
        first = newptr;
    }
    else
    {
        node* ptr = first;
        node* tmp = first;
        while (1>0)
        {
            // Insertando al final
            if (ptr->next == NULL)
            {
                tmp = ptr;
                ptr->next = newptr;
                newptr->pre = tmp;
                last = newptr;
                break;
            }
            
            // Caso donde el nodo tiene que ser agregado al medio
            else if (ptr->next->n > newptr->n)
            {
                //tmp = ptr;
                newptr->next = ptr->next;
                newptr->pre = ptr;
                ptr->next->pre = newptr;
                ptr->next = newptr;
                break;
            }
            // Cambiando el puntero
            
            ptr = ptr->next;
        }
    }
}

//Recorriendo la lista
void mostrarLista(int sentido)
{
    // Recorriendo la lista
    printf("\nLista: ");
    
    if(sentido==0){
    node* ptr = first;
    while (ptr != NULL)
    {
        printf("%i ", ptr->n);
        ptr = ptr->next;
    }
    }
    if(sentido==1)
    {
        
    node* ptr = last;
    while (ptr != NULL)
    {
        printf("%i ", ptr->n);
        ptr = ptr->pre;
    }
    }
    
    
    printf("\n\n");
}

void borrarNodo(void)
{
    printf("Ingrese el numero a borrar:\n");
    int num;
    scanf(" %i", &num);
    node* temp=first;
    node* pretemp;
    
    while(temp!=NULL)
    {
        
        if ((first->n==num) && (first!=NULL)){//al inicio
            //pretemp=temp;
            if(temp->next!=NULL){
                first=temp->next;
                first->pre = NULL; 
            }
            else{ //caso que no quede ningun nodo
                first=NULL;
                last=NULL;
            }
            free(temp);
            break;
        }
         
        
        if ((temp->n==num) && (temp->next!=NULL)){//al medio
            pretemp->next=temp->next;
            temp->next->pre=pretemp;
            free(temp);
            break;
        }
        
        
        if ((temp->next==NULL) && (temp->n==num)){//al final
            pretemp->next=NULL;
            last = pretemp;
            free(temp);
            break;
        }
        pretemp=temp;
        temp=temp->next;
      }
}