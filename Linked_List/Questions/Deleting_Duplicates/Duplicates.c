#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_tail(struct node** head, int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));  // allocating the memory for the node..
    // initializing the node..
    newnode->data = data;
    newnode->next = NULL;

    if(*head == NULL){
        *head = newnode;
    }else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void print(struct node *head){
    while(head != NULL){
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}   