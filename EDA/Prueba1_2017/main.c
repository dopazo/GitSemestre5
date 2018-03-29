#include <stdio.h>
#include "pila_l.h"

void konun(int n);
void pushImpar(int numero);
void pekenun(void);
int tripan(void);
void menu();
/*
Ejemplo que aparecia en la prueba para probar si funciona
    pekenun();
    konun(2); konun(8); pekenun();
    konun(13); konun(6); pekenun();
    konun(7); pekenun();
    konun(23); pekenun();
    konun(20); pekenun();
    tripan(); pekenun();
    tripan(); pekenun();
    tripan(); pekenun();

    lo que debería desplegar:

    Akeyatun: Akeyatun vacio
    Akeyatun: 8 2
    Akeyatun: 6 13 8 2
    Akeyatun: 6 13 7 8 2
    Akeyatun: 6 23 13 7 8 2
    Akeyatun: 20 6 23 13 7 8 2
    Akeyatun: 6 23 13 7 8 2
    Akeyatun: 23 13 7 8 2
    Akeyatun: 23 13 8 2
*/

int main(){
    menu();

    //borrando la lista al salir
    node* ptr = head;
    while (ptr != NULL)
    {
        node* preptr = ptr;
        ptr = ptr->next;
        free(preptr);
    }
    free(ptr);
}

void menu(){
    int x;
    do {
        printf("\n");
        printf("(1) Ingresar un numero al akeyatun(operador konun)\n");
        printf("(2) Sacar un numero del akeyatun(operador tripan)\n");
        printf("(3) Mostrar el contenido del akeyatun(operador pekenun)\n");
        printf("(4) Salir del programa\n");

        scanf(" %i", &x);
        switch(x){
            case 1: printf("Numero a ingresar: "); scanf(" %i", &x); konun(x); system("cls"); printf("Ingresado\n");break;
            case 2: x=tripan(); system("cls"); printf("%i Eliminado\n",x); break;
            case 3: system("cls"); pekenun(); break;
            case 4: system("cls"); break;
    }
    }while(x!=4);
}

int tripan(void){
    int x=peek();
    node* tmp=head;
    if(x%2==0){
        head=tmp->next;
        free(tmp);
        return x;
    }
    else{
        node* ptr = head;
        while (ptr != NULL)
        {
            if(ptr->n%2!=0){ //si es impar el de la posicion de ptr
                if(ptr->next->n%2==0){ //si el sgte es par
                    if(ptr==head){ //si sigo en el head
                        head=tmp->next;
                        free(tmp);
                        return x;
                    }
                    else{//si ya no estoy en el head
                        x=ptr->n;
                        tmp->next=ptr->next;
                        free(ptr);
                        return x;
                    }
                }
            }
            tmp=ptr;
            ptr=ptr->next;
        }
    }
}


void konun(int numero){

    if(numero%2==0){  //if es par
        push(numero);
    }
    else{
        pushImpar(numero);
    }
}

void pushImpar(int numero){
    node* newptr = (node*) malloc(sizeof(node));
    newptr->n = numero;
    newptr->next = NULL;
    int hayImpar=0;
    //Verificando si la lista esta vacia
    if (head == NULL)
    {
        head = newptr;
        return;
    }
    node* ptr = head;
    node* tmp = head;
    while(ptr!=NULL){
        if (newptr->n > head->n) //si es el del head
        {
            if(ptr->n%2!=0){ //si es impar
                newptr->next = head;
                head = newptr;
                break;
            }
            else{ //si es par, seguir avanzando para encontrar el impar
                tmp=ptr;
                ptr = ptr->next;
            }
        }
        if( (ptr->n%2!=0) && (ptr!=head) ){ //si es impar el de la posicion de ptr
            if(ptr->n < newptr->n){ //si el de la posicion < n
                tmp->next=newptr;
                newptr->next=ptr;
                hayImpar++;
                break;
            }
            else{ //si el de la posicion > n
                if ((ptr->next->n)%2==0) //si el sgte es par, por ende, si no hay mas impares
                {
                    newptr->next=ptr->next;
                    ptr->next=newptr;
                    break;
                }
            }
        }
        if (ptr->next == NULL) //si llegue al final
        {
            if(hayImpar==0){ //si no supe donde, poner donde el head
                ptr->next=NULL;
                newptr->next = head;
                head = newptr;
                break;
            }
        }
        tmp=ptr;
        ptr = ptr->next;
    }
}

//mostrar la lista
void pekenun(void)
{
    // Recorriendo la lista
    printf("Akeyatun: ");
    node* ptr = head;
    if(ptr==NULL){
        printf("Akeyatun vacio");
    }
    while (ptr != NULL)
    {
        printf("%i ", ptr->n);
        ptr = ptr->next;
    }
    printf("\n");
}
