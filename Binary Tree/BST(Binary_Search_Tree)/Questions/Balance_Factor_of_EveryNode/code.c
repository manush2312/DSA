#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node* insert(struct node ** root, int data){
    struct node* new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->left = new->right = NULL;

    if((*root) == NULL){
        (*root) = new;
    }
    else if((*root)->data > data){
        (*root)->left = insert(&(*root)->left, data);
    }else if((*root)->data < data){
        (*root)->right = insert(&(*root)->right, data);
    }

    return (*root);
}


void takeInput(struct node **root){
    int data;
    while(data != -1){
        printf("Enter the data:\n");
        scanf("%d", &data);
        if(data == -1){
            break;
        }else{
            insert(&(*root), data);
        }
    }
}

void Inorder(struct node* root){
    
    if((root) == NULL){
        return ;
    }
    Inorder(root->left);
    printf("%d \t", root->data); 
    Inorder(root->right);
}

int max(int a, int b){
    return a>b ? a:b ;
}

int height(struct node* root){
    if(root == NULL){
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1,h2)+1 ;
}

void BalanceFactor(struct node *root){
    if(root){
        int balance = height(root->left)-height(root->right);
        printf("\n%d ---> %d", root->data, balance);
        BalanceFactor(root->left);
        BalanceFactor(root->right);
    }
}


int main(){

    struct node *root = NULL;
    printf("Enter the data for the tree:\n");
    takeInput(&root);

    Inorder(root);

    BalanceFactor(root);

    return 0;
}