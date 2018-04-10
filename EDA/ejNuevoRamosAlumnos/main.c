#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    alumno* head = NULL;
    for(int i=0;i<2;i++){
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

    printf("Ingrese el nombre del alumno\n");
    char nombre[50];
    scanf(" %s",nombre);
    strcpy(new->nombre,nombre);
    //MODIFICAR TERMINAR
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

        printf("contenido head:%p\n",*head);
        printf("new next %p\n",new->next);
        printf("head rut:%i\n",(**head).rut);
        printf("head next:%p\n",(**head).next);

    }
        // insertar al inicio
    else if (new->rut < (**head).rut) //BLACK MAGIC!
    {
        new->next = *head;
        *head = new;
        printf("nuevo head rut:%i\n",(**head).rut);
        printf("nuevo head next:%p\n",(**head).next);
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
    ramo* new=malloc(sizeof(alumno));

    printf("Ingrese el nombre del ramo\n");
    char ramo[50];
    scanf(" %s",ramo);
    strcpy(new->ramo,ramo);

    if (*headRamo == NULL)
    {
        *headRamo = new;
    }
        //insertar al inicio
    else
    {
        new->next = *headRamo;
        *headRamo = new;
    }
    printf("head nombre ramo: %s\n",(**headRamo).ramo);
}

void mostrarLista(alumno* head) {
    // Recorriendo la lista
    printf("\nLista:\n");
    alumno *ptr = head;
    ramo *ptr2;
    while (ptr != NULL)//recorrer alumnos
    {
        printf("Rut: %i - ", ptr->rut);
        printf("Nombre: %s - ", ptr->nombre);
        printf("Ramos: ");
        ptr2 = ptr->ramoInicial;
        printf("vuelta del while grande\n");
        while (ptr2 != NULL) { //recorrer ramos LOOP INFINITO!
            printf("vuelta while chico\n");
            printf("%s ", ptr2->ramo);//error!
            printf("antes de ptr2=ptr2->next\n");
            ptr2 = ptr2->next;
            printf("fin while chico| ptr2= %p\n", ptr2); //por que es distinto de null al ir al 2do?
        }
        printf("wat\n");
        ptr = ptr->next;
    }
    printf("\n\n");
}