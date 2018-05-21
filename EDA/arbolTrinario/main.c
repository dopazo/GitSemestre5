#include <stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct node
{
    int key;
    struct node *left, *mid, *right;
}node;

int nrandom=0;
struct node *newNode()
{
    //int nrandom=rand()%10;
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = nrandom;
    printf("'%i' ",nrandom);
    nrandom++;
    temp->left = temp->mid = temp->right = NULL;
    return temp;
}

void createLevel(node** root,int level){
    if(level==1){
        printf("-lv 1-\n");
        *root=newNode();
    }
    else if(level>1){
        printf("level: %i | ",level);
        createLevel(&(**root).left,level-1);
        printf("postLeft, vieneDelNodo: %i\n",(**root).key);
        createLevel(&(**root).mid,level-1);
        printf("postMid, vieneDelNodo: %i\n",(**root).key);
        createLevel(&(**root).right,level-1);
        printf("postRight, vieneDelNodo: %i\n",(**root).key);
    }
}

void fullCreate(node** root){
    for(int i=1; i<=4; i++)
        createLevel(root, i);
}

void printByLevel(node* root,int level){
    if(root==NULL)
        return;
    if(level==1){
        printf("%i ",root->key);
    }
    else if(level>1){
        printByLevel(root->left,level-1);
        printByLevel(root->mid,level-1);
        printByLevel(root->right,level-1);
    }
}

int main() {
    srand(time(NULL));
    node* root=NULL;
    fullCreate(&root);
    printf("\n");
    printf("printLevelByLevel: \n");
    for(int i=1; i<=4; i++){
        printByLevel(root, i);
        printf("\n");
    }
}