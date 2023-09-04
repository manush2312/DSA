#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right; 
};

struct node* insert(struct node** root, int data){
    //allocating memory and initializing the newnode with data "data"..
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    if(*root == NULL ){
        *root = newnode;

    //agar data is smaller than root -- left sub tree.. 
    }else if((*root)->data > data){
        (*root)->left = insert(&((*root)->left), data);

    //agar data is bigger than root -- right sub tree..
    }else if((*root)->data < data){
        (*root)->right = insert(&((*root)->right), data);
    }

    return *root;
}

int Ksmallest(struct node** root, int i, int k){

    //base case
    if
}


void takeInput(struct node** root){
    int data;
    while (data != -1){  // jab tak data -1 nhi hota it will take input..
        printf("Enter the data: ");
        scanf("%d",&data);
        if(data == -1){
            break;
        }else{
        insert(&(*root), data);
        }
    }
}

int main(){
    int ele, num;

    struct node* root = NULL;

    printf("Please enter the data into the BST\n");
    takeInput(&root);

   


}