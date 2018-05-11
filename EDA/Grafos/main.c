#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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
    //next node, no perder ninguno
    struct node* nextNode;
}node;

node* insertNode(int n,node* head);
int insertEdge(int nNode1, int nNode2);
int insertUndirectedEdge(int nNode1, int nNode2);
node* searchNode(int nNode);
void mostrarGrafo(node* head);
int importarRed();
int mostrarVecinos(int nNode);

node* head=NULL;

int main(){
    /*head=insertNode(1,head);
    head=insertNode(2,head);
    head=insertNode(3,head);
    head=insertNode(4,head);
    insertUndirectedEdge(1,2);
    insertUndirectedEdge(1,4);
    insertUndirectedEdge(2,3);
    insertUndirectedEdge(2,4);
    insertUndirectedEdge(3,4);
    */
    importarRed();
    mostrarGrafo(head);
    int vecino;
    int errorVecinos;
    do {
        printf("Ingrese el numero del nodo que desea conocer vecinos: ");
        scanf(" %i",&vecino);
        errorVecinos=mostrarVecinos(vecino);
    } while (errorVecinos==1);

}

int importarRed(){

    //ver cantidad de nodos a crear
    FILE *archivo;
    char dato;
    int lineas=0;
    archivo = fopen("red.txt", "r" );
    if (!archivo)
        return 1;
    for(;;){
        fscanf(archivo, "%c",&dato);
        if (feof(archivo)) break;
        if(dato=='\n'){
            lineas++;
        }
    }
    fclose (archivo);

    //crear nodos
    FILE *ptr_file;
    int nodo;
    int creados[MAX];
    int z=0;
    ptr_file =fopen("red.txt","r");
    if (!ptr_file)
        return 1;

    for(int i =0; i<lineas;i++){ //5 porque es la "altura" del txt
        for(int j=0;j<2; j++){  //2 porque es la cantidad de datos hacia el lado que hay
            fscanf(ptr_file,"%d", &nodo); //almacena el primer numero en variable nodo
            if(z>0){
                int repetido=0; //revisa para no crear nodos con mismo numero
                for(int t=0; t<z; t++){
                    if(nodo == creados[t]) repetido++;
                }
                if(repetido == 0){
                    creados[z] = nodo;  //si no es repetido lo almacena en array
                    z++;
                    //printf("nodo: %d\n",nodo);
                }
            }
            else {
                creados[z] = nodo;  //caso base
                z++;
                //printf("nodo: %d\n",nodo);
            }
        }
    }
    fclose(ptr_file);
    for(int i=0; i<z; i++) head = insertNode(creados[i], head); //crea los nodos

    //hacer uniones
    FILE *ptr_file2 = fopen("red.txt","r");
    int nodo2;
    for(int i=0; i<lineas; i++){
        int n1 = 0;
        int n2 = 0;
        for(int j=0;j<2;j++){
            fscanf(ptr_file2, "%d", &nodo2);
            if(j==0) n1 = nodo2;
            if(j==1) n2 = nodo2;
        }
        insertUndirectedEdge(n1, n2);
    }
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
    edges* ptrEdges=NULL;
    if(ptrNode!=NULL) {
        ptrEdges = head->firstEdge;
    }
    else{
        printf("Vacia\n");
    }
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

int mostrarVecinos(int nNode) {
    node *ptrNode = searchNode(nNode);
    if(ptrNode==NULL){
        printf("No existe tal nodo\n");
        return 1;
    }
    edges *ptrEdges = ptrNode->firstEdge;
    printf("Vecinos de %i:\n",nNode);
    while (ptrEdges != NULL) {
        printf("%i ", ptrEdges->nextNode->n);
        ptrEdges = ptrEdges->nextEdge;
    }
    return 0;
}