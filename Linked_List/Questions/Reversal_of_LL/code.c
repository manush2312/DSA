#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_head(struct node** head, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); // allocating the memory..
    // initializing the node..
    newnode->data =data;
    newnode->next = NULL;

    if(*head == NULL){
        *head = newnode;
    }else{
        newnode->next = *head;
        *head = newnode;
    }
}

void print(struct node *head){
    while(head != NULL){
        printf("%d  ",head->data);
        head= head->next;
    }
}

struct node* reverse(struct node **head){
    if(*head == NULL){
        return *head;
    }

    struct node* prev= NULL;
    struct node* curr= *head;
    struct node* forward= NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;  // beacuse we need to update the head..
}


int main(){
    int n, data;
    struct node *head = NULL;
    printf("Enter the size of the list:");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter the data for %d node: ", (i+1));
        scanf("%d", &data);
        insert_at_head(&head, data);
    }

    print(head);
    printf("\n");

    struct node *head1 = reverse(&head);
    print(head1);
}