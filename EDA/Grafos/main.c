#include <stdio.h>
#include <stdlib.h>

typedef struct edges
{
    //campos que tenga el edge
    struct node* nextNode; //hacia donde apunta este edge
    //int weight(?) //peso de edge
    //siguiente edge del mismo node
    struct edges* nextEdge;
}edges;

typedef struct node
{
    //campos que tenga el nodo
    int n;
    //todos sus "nexts"
    edges* firstEdge;
    //next node(?) necesario? no perder ningun nodo
    struct node* nextNode;
}node;

node* insertNode(int n,node* head);
int insertEdge(int nNode1, int nNode2);
int insertUndirectedEdge(int nNode1, int nNode2);
node* searchNode(int nNode);
void mostrarGrafo(node* head);

node* head=NULL;

int main(){
    head=insertNode(1,head);
    head=insertNode(2,head);
    head=insertNode(3,head);
    head=insertNode(4,head);
    insertUndirectedEdge(1,2);
    insertUndirectedEdge(1,4);
    insertUndirectedEdge(2,3);
    insertUndirectedEdge(2,4);
    insertUndirectedEdge(3,4);

    mostrarGrafo(head);
}

node* insertNode(int n, node* head){
    node* ptrnew = (node*)malloc(sizeof(node));
    ptrnew->n= n;
    ptrnew->nextNode=NULL;
    ptrnew->firstEdge=NULL; //lo crea sin ninguna unión
    if(head == NULL){ //si lista de nodos esta vacia
        head = ptrnew;
        return head;
    }
    else{ //sino, insertar en lista de todos los nodos
        node* tmp = head;
        while(1>0){
            if(tmp->nextNode != NULL){
                tmp = tmp->nextNode;
            }
            if(tmp->nextNode == NULL){
                tmp->nextNode=ptrnew;
                return head;
            }
        }
    }
}
int insertEdge(int nNode1, int nNode2){
    //buscar si existen
    node* node1=searchNode(nNode1);
    node* node2=searchNode(nNode2);
    if(node1==NULL){ //si no existe alguno, return 1
        printf("Nodo %i no existe\n",nNode1);
        return 1;
    }
    if(node2==NULL){
        printf("Nodo %i no existe\n",nNode2);
        return 1;
    }

    edges* newEdge=(edges*)malloc(sizeof(edges*));
    newEdge->nextEdge=NULL;
    newEdge->nextNode=node2; //edge une node1 con node2

    if(node1->firstEdge==NULL){ //si no tiene ningun edge
        node1->firstEdge=newEdge;
        return 0;
    }

    //TODO codigo para evitar uniones ya existentes?

    //recorrer lista de edges del node1
    edges* tmpEdges=node1->firstEdge;
    while(tmpEdges->nextEdge!=NULL) {
        tmpEdges = tmpEdges->nextEdge;
    }
    tmpEdges->nextEdge=newEdge;
    return 0;
}

int insertUndirectedEdge(int nNode1, int nNode2){
    insertEdge(nNode1,nNode2);
    insertEdge(nNode2,nNode1);
    return 0;
}

node* searchNode(int nNode){
    if(head==NULL){
        return NULL;
    }
    else{
        node* tmp=head;
        while(tmp!=NULL){
            if(tmp->n==nNode){
                return tmp;
            }
            else{
                tmp=tmp->nextNode;
            }
        }
    }
    return NULL;
}
void mostrarGrafo(node* head){
    // Recorriendo la lista
    printf("Lista:\n");
    node* ptrNode = head;
    edges* ptrEdges=head->firstEdge;
    while (ptrNode != NULL)
    {
        printf("%i-> ", ptrNode->n);
        while(ptrEdges!=NULL){
            printf("%i ", ptrEdges->nextNode->n);
            ptrEdges=ptrEdges->nextEdge;
        }
        printf("\n");
        ptrNode = ptrNode->nextNode;
        if(ptrNode!=NULL)
            ptrEdges=ptrNode->firstEdge;
    }
    printf("\n\n");
}