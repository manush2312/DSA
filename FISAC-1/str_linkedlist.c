#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char data[100];
    struct node* next;
}node;

void insert_end(node** head_ptr, char data[100])
{
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->data, data);
    new_node->next=NULL;
    node* temp_node = *head_ptr;

    if (temp_node == NULL)
        *head_ptr = new_node;
    
    else
    {
        while(temp_node->next!=NULL)
            temp_node=temp_node->next;
        
        temp_node->next = new_node;
    }
}

int length(node* head)
{
    int len=0;
    node* temp = head;
    while(temp != NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void display(node* head)
{
    node* temp = head;
    while (temp != NULL){
        printf("%s  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

char* value_at(node* head, int index)
{
    node* temp = head;

    for(int i = 0; i < index; i++)
        temp = temp->next;
    
    return temp->data;
}