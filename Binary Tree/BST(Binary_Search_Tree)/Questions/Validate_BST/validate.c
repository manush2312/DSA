#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* Insert(struct node** root, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    if((*root) == NULL){
        *root = newnode;
    }
    else if((*root)->data > data){
        (*root)->left = Insert(&((*root)->left), data);
    }
    else if((*root)->data < data){
        (*root)->right = Insert(&((*root)->right), data);
    }

    return *root;

}
// Validate a Binary Search Tree..
// that is we need to check whether a given tree is a BST or not..
// Approach 1: if inorder of the tree is in a sorted manner then it is a BST.
// Approach 2: if it satisfies all the condition of a BST then it is a Binary Search Tree..
void takeinput(struct node** root){
    int data;
    printf("Enter the data for BST:\n");
    while(data != -1){
        printf("Enter the data for the node: ");
        scanf("%d",&data);
        if(data != -1){
            Insert(&(*root), data);
        }else{
            break;
        }
    }
}

void Inorder(struct node *root){

    if(root == NULL){
        return;
    }

    Inorder(root->left);
    printf("%d",root->data);
    Inorder(root->right);
}

//function to check whether a given tree is BST or not.. 
int isBST(struct node* root, int min, int max){
    
    //base case..
    if(root == NULL){
        return 1;
    }

    if(root->data >= min && root->data <= max){
        int left = isBST(root->left , min, root->data);
        int right = isBST(root->right, root->data, max);
        return left && right;
    }
    else{
        return 0;
    }
}

int main(){
    struct node* root = NULL;

    //taking the input..
    takeinput(&root);

    Inorder(root);

    int validate = isBST(root,0,100);
    if(validate == 1){
        printf("Yes it is a BST");
    }else{
        printf("No it is not a binary tree.");
    }


}