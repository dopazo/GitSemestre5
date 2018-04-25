// C program to demonstrate delete operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct node
{
    int key;
    struct node *left, *right;
    int enElCamino;
}node;

//function to search a given key in a given BST using recursion
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

//function to create a new node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    int enElCamino=(rand()%7)-2; //random entre -2 y 3 tesoros o monstruos
    //if(enElCamino==0)  //disminuir probabilidad de 0
    //    enElCamino=(rand()%4)-3;
    temp->enElCamino=enElCamino;
    temp->left = temp->right = NULL;
    return temp;
}

//function to data stored in each node, in order
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        printf("%d | ", root->enElCamino);
        inorder(root->right);
    }
}

//function to insert a new node with given key in BST
struct node* insert(struct node* node, int key)
{
    //If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    //Otherwise, recur down the tree
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    //return the (unchanged) node pointer
    return node;
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

        // if key is same as root's key, then This is the node
        // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

node* arbol(node* root){
    //mas facil meterle numeros random xd, total no importa que valor tengan
    // Meterle un "selecciona largo del juego" mas grande el for y el rand%, mas grande el juego
    // Juego corto, juego medio, juego largo (?)
    for(int i=0; i<20; i++){
        int nrandom=rand()%20;
        root=insert(root,nrandom);
    }

    /*root=insert(root,8);
    root=insert(root,4);
    root=insert(root,12);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root,5);
    root=insert(root,7);
    root=insert(root,11);
    root=insert(root,14);
    root=insert(root,9);
    root=insert(root,10);
    root=insert(root,13);
    root=insert(root,15);*/
    return root;
}

int juego(node* root);

// Driver Program to test above functions
int puntaje=0;
int main()
{
    //create a game using a BST
    srand(time(NULL));
    node* root=malloc(sizeof(node));
    root=NULL;
    root=arbol(root);
    inorder(root); printf("\n");
    juego(root);
}

int juego(node* root){
    if (root==NULL){
        printf("Terminaste\n");
        printf("puntaje: %i\n",puntaje);

        return 0;
    }
    printf("estas en la posicion: %d\n",root->key);
    printf("encuentras un: %d\n",root->enElCamino);
    if(root->enElCamino==0){
        printf("Hay fuego en esta parte de la cueva, logras ver lo que hay más adelante\n");
        printf("a la izquierda hay un %i\na la derecha hay un %i\n",root->left->enElCamino,root->right->enElCamino);
    }
    puntaje=puntaje+(root->enElCamino);
    printf("A donde quieres ir:\n (1) izquierda - (2) derecha\n");
    int seleccion;
    scanf(" %i",&seleccion);
    if(seleccion==1){
        juego(root->left);
    }
    else{
        juego(root->right);
    }
}