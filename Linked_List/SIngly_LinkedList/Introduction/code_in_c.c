#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

// insertion of node..(Inserting at tail)
void insert(struct node** head, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); // allocating the memory for the node to insert..
    newnode->data = data;
    newnode->next = NULL;

    if(*head == NULL){
            *head = newnode;
    }else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}


//Deletion of node..
void delete(struct node** head, int pos){
    struct node* curr = *head;
    struct node* prev = NULL;

    for(int i=1; i<pos; i++){
        prev = curr;
        curr= curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    free(curr);

}


// Traversing a list..
void print(struct node* head){
    //struct node *temp = *head;
    while(head != NULL){
        printf("%d", head->data);
        head = head->next;
    }
}

int main(){
    struct node* head = NULL;

    insert(head,2);
    insert(head,32);
    insert(head,33);
    insert(head,22);
    
    print(head);



    return 0;
}