#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limpiarPantalla system("cls")

//Diego Opazo

typedef struct ramo
{
    char ramo[50];
    struct ramo* next;
}ramo;

typedef struct alumno
{
    int rut;
    char nombre[50];
    ramo* ramoInicial;
    struct alumno* next;
}alumno;

void ingresarAlumno(alumno** head);
void ingresarRamos(ramo** headRamo);
void mostrarLista(alumno* head);

int main() {
    limpiarPantalla;
    alumno* head = NULL;
    int cantidad;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%i",&cantidad);
    limpiarPantalla;
    for(int i=0;i<cantidad;i++){
        limpiarPantalla;
        ingresarAlumno(&head);
    }
    mostrarLista(head);
}

void ingresarAlumno(alumno* *head){

    alumno* new=malloc(sizeof(alumno));
    int rut;

    printf("Ingrese el rut del alumno, sin puntos ni guion\n");
    scanf(" %i",&rut);
    new->rut = rut;

    new->next = NULL;
    new->ramoInicial=NULL;
    limpiarPantalla;
    printf("Ingrese el nombre del alumno\n");
    char nombre[50];
    scanf(" %[^\n]s",nombre);
    strcpy(new->nombre,nombre);
    limpiarPantalla;
    ingresarRamos(&new->ramoInicial);

/*
    printf("new nombre: %s\n",new->nombre);
    printf("head: %p\n",head);
    printf("*head: %p\n",*head);
    printf("&head: %p\n\n",&head);

    printf("new: %p\n",new);
    printf("new rut:%i\n",new->rut);
    printf("new next %p\n",new->next);
*/
    if (*head == NULL)
    {
        *head = new;
/*
        printf("contenido head:%p\n",*head);
        printf("new next %p\n",new->next);
        printf("head rut:%i\n",(**head).rut);
        printf("head next:%p\n",(**head).next);
*/

    }
        // insertar al inicio
    else if (new->rut < (**head).rut)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        alumno* ptr = *head;
        alumno* tmp = *head;
        while (1>0)
        {
            // Insertando al final
            if (ptr->next == NULL)
            {
                tmp = ptr;
                ptr->next = new;
                break;
            }

                // Caso donde el nodo tiene que ser agregado al medio
            else if (ptr->next->rut > new->rut)
            {
                //tmp = ptr;
                new->next = ptr->next;
                ptr->next = new;
                break;
            }

            // Cambiando el puntero

            ptr = ptr->next;
        }
    }
    printf("\n");
} 

void ingresarRamos(ramo** headRamo){
    limpiarPantalla;
    printf("Ingrese los ramos, ingrese 'q' para salir\n");
    do {
        ramo* new=malloc(sizeof(alumno));
        printf("Ingrese el nombre del ramo\n");
        char ramo[50];
        scanf(" %[^\n]s",ramo);
        if(strcmp(ramo,"q")==0)
            break;
        strcpy(new->ramo,ramo);

        if (*headRamo == NULL)
        {
            new->next=NULL;
            *headRamo = new;
        }
            //insertar al inicio
        else
        {
            new->next = *headRamo;
            *headRamo = new;
        }
    } while (1);
}

void mostrarLista(alumno* head) {
    limpiarPantalla;
    // Recorriendo la lista
    printf("\nLista:\n");
    alumno *ptr = head;
    ramo *ptr2;
    while (ptr != NULL)//recorrer alumnos
    {
        printf("Rut: %i - ", ptr->rut);
        printf("Nombre: %s \n", ptr->nombre);
        printf("      Ramos: ");
        ptr2 = ptr->ramoInicial;
        while (ptr2 != NULL) { //recorrer ramos
            printf("%s. ", ptr2->ramo);
            ptr2 = ptr2->next;
        }
        printf("\n");
        ptr = ptr->next;
    }
    printf("\n\n");
}