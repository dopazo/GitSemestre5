#include <stdio.h>
#include <stdlib.h>

//Diego Opazo

typedef struct ramo
{
    //char ramo[50];
    int nRamo; //mientras resuelvo lo de char
    struct alumno* next;
}ramo;

typedef struct alumno
{
    int rut;
    //char nombre[50];
    //ramo* ramoInicial;
    struct alumno* next;
}alumno;


void ingresarAlumno(alumno* *head);

int main() {
    alumno* head = NULL;
    ingresarAlumno(&head);
}

void ingresarAlumno(alumno* *head){

    alumno* new=malloc(sizeof(alumno));
    int rut;
    printf("Ingrese el rut del alumno, sin puntos ni guion\n");
    scanf(" %i",&rut);
    new->rut = rut;
    new->next = NULL;
    //char nombre[50];
    //printf("Ingrese el nombre del alumno\n");
    //scanf(" %s",nombre);
    //new->nombre=nombre;
    printf("head: %p\n",head);
    printf("*head: %p\n",*head);
    printf("&head: %p\n",&head);
    printf("new: %p\n",new);

    printf("new rut:%i\n",new->rut);
    printf("new next %p\n",new->next);
    if (*head == NULL)
    {
        *head = new;
        printf("contenido head:%p\n",*head);
        printf("new next %p\n",new->next);
        printf("new rut:%i\n",*head->next);
        //printf("new next %p\n",*head->next);
    }
    //printf("%i",*head->rut);
        // insertar al inicio
/*
    else if (new->rut < *head -> rut) //POR QUEEEEEE D:<
    {
        new->next = *head;
        *head = new;
    }
*/
    printf("a\n");
} 

void mostrarLista(alumno* head)
{
    // Recorriendo la lista
    printf("\nLista: ");
    alumno* ptr = head;
    while (ptr != NULL)
    {
        printf("%i ", ptr->rut);
        ptr = ptr->next;
    }
    printf("\n\n");
}