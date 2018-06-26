#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
} node;

//inicializar
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t data = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

node* head = NULL;

void print_list(node* head)
{
    node* cursor = head;
    while(cursor != NULL)
    {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
}

node* create(int data,node* next)
{
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;

    //count++;

    return new_node;
}

node* append(node* head, int data)
{
    /* go to the last node */
    node *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;
 
    /* create a new node */
    node* new_node =  create(data,NULL);
    cursor->next = new_node;
 
    return head;
}

node* remove_front(node* head)
{
    if(head == NULL)
        return NULL;
    node *front = head;
    head = head->next;
    front->next = NULL;
    /* is this the last node in the list */
    if(front == head)
        head = NULL;
    free(front);
    return head;
}

node* remove_back(node* head)
{
    if(head == NULL)
        return NULL;
 
    node *cursor = head;
    node *back = NULL;
    while(cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;
    }
    if(back != NULL)
        back->next = NULL;
 
    /* if this is the last node in the list*/
    if(cursor == head)
        head = NULL;
 
    free(cursor);
 
    return head;
}
int count=0;

void *fullLinkedList(void *arg){
  int i;
  int largo = (int) arg;
  for(i=0;i<largo;i++){
    pthread_mutex_lock(&lock);
    if(head==NULL)
      head=create(0,head);
    else
      append(head,count);
    count++;
    //printf("(%p)",&i);
    pthread_mutex_unlock(&lock);
    //for(int j=0;j<99999;j++){;} //se alternan los threads?
  }
}

int main(void) {

  //head=create(0,head);

  // inserte código para agregar 100 nodos
  // primero secuencialmente (usando un ciclo)
  /*for (int i = 1; i < 100; i++){
    append(head, i);
  }*/
  
  // luego en paralelo
  
  pthread_t p1, p2;
  pthread_create(&p1, NULL, fullLinkedList, (void*)(MAX/2));
  pthread_create(&p2, NULL, fullLinkedList, (void*)(MAX/2));

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);

  print_list(head);
  printf("\nListo!\n");
  return 0;
}