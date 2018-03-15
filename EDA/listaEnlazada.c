/**
 * lista.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Demonstrates a linked list for numbers.
 * Modificada por Sebastian Moreno
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lista.h"

// Lista puntero inicial
node* first = NULL;

// prototipos
void insertar(int numero);
void mostrarLista(void);
void borrarNodo(void);
void contarNumeros(void);

int main(void)
{
    int c;
    
    do
    {
        //imprimir instrucciones
        printf("\nMENU\n\n"
               "1 - insertar nodo\n"
               "2 - mostrar lista\n"
               "3 - borrar nodo \n"
               "4 - contar numero\n"
               "0 - quit\n\n");
        
        // obtener una opción
        printf("Elija una opción: ");
        c = GetInt();
        
        // Ejecutar la opción
        switch (c)
        {
            case 1: insertar(0); break;
            case 2: mostrarLista(); break;
            case 3: borrarNodo(); break;
            case 4: contarNumeros(); break;
        }
    }
    while (c != 0);
    
    //borrando la lista al salir
    node* ptr = first;
    while (ptr != NULL)
    {
        node* predptr = ptr;
        ptr = ptr->next;
        free(predptr);
    }
}

/**
 * Agregando un número a la lista
 */
void insertar(int numero)
{
    if (numero==0){
        printf("Ingrese numero: ");
        numero=GetInt();
    }
    
    //crea un nuevo nodo vacio
    node* newptr = (node*) malloc(sizeof(node));
    if (newptr == NULL)
    {
        return;
    }
    
    //inicialización del nodo
    newptr->n = numero;
    newptr->next = NULL;
    
    //Verificando si la lista esta vacia
    if (first == NULL)
    {
        first = newptr;
    }
    
    //Verifica si el número tiene que ser insertado al principio
    else if (newptr->n < first->n)
    {
        newptr->next = first;
        first = newptr;
    }
    else
    {
        node* predptr = first;
        while (true)
        {
            // Verificando si el número tiene que ser insertado al final
            if (predptr->next == NULL)
            {
                predptr->next = newptr;
                break;
            }
            
            // Caso donde el nodo tiene que ser agregado al medio
            else if (predptr->next->n > newptr->n)
            {
                newptr->next = predptr->next;
                predptr->next = newptr;
                break;
            }
            
            // Cambiando el puntero
            predptr = predptr->next;
        }
    }
}

//Recorriendo la lista
void mostrarLista(void)
{
    // Recorriendo la lista
    printf("\nLista: ");
    node* ptr = first;
    while (ptr != NULL)
    {
        printf("%i ", ptr->n);
        ptr = ptr->next;
    }
    printf("\n\n");
}

/*
 * Función contar
 */
void contarNumeros(void)
{
    printf("Ingrese el numero que desea contar:\n");
    int num=GetInt();
    int contador=0;
    node* ptr = first;
    while(ptr!=NULL)
    {
     if (ptr->n==num)
      {
        contador++;
        
      }
      ptr = ptr->next;
    }
     if (contador==0)
      {
       printf("existe %i numero\n",0);
      }
      else if(contador==1)
      {
        printf("existe %i numero\n",1);
      }
      else
      {
        printf("existen %i numeros\n",contador);
      }
}

/*
 * Función para borrar un nodo
 */
void borrarNodo(void)
{
    printf("Ingrese el numero a borrar:\n");
    int num=GetInt();
    node* temp=first;
    node* pretemp;
    
    while(temp!=NULL)
    {
        
        if ((first->n==num) && (first!=NULL)){//al inicio
            pretemp=temp;
            first=temp->next;
            free(pretemp);
            break;
        }
         
        
        if ((temp->n==num) && (temp->next!=NULL)){//al medio
            pretemp->next=temp->next; //arreglado despues de entregar la tarea :c, decia pretemp en vez de pretemp->next
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