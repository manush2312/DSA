#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct node* next;
}node;

void insert_end(node** head_ptr, int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data=data;
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
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int value_at(node* head, int index)
{
    node* temp = head;

    for(int i = 0; i < index; i++)
        temp = temp->next;
    
    return temp->data;
}

node* copy(node* head)
{
    node *new_head = NULL, *temp = head;

    while(temp != NULL)
    {
        insert_end(&new_head, temp->data);
        temp = temp->next;
    }
    // display(new_head);
    return new_head;
}

void rot_right(node** head_ptr, int k)
{
    node *temp = *head_ptr, *new_head;

    int len = length(*head_ptr);

    for(int i = 0; i < len - k -1; i++)
        temp = temp->next;

    printf("Data: %d\n", temp->data);

    new_head = temp->next;
    temp->next = NULL;

    temp = new_head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = *head_ptr;

    *head_ptr = new_head;
}

void rot_left(node** head_ptr, int k)
{
    node *temp = *head_ptr, *new_head;

    for(int i = 0; i < k - 1; i++)
    {        
        
        temp = temp->next;
    }
    
    new_head = temp->next;

    temp->next = NULL;

    temp = new_head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = *head_ptr;
    *head_ptr = new_head; 
}

void delete_front(node** head)
{
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at(node** head, int index)
{
    node* temp = *head, *del;

    if (index == 0)
        delete_front(head);

    else
    {
        for (int i = 0; i < index-1; i++)
            temp = temp->next;
        del = temp->next;
        temp->next = del->next;
        free(del);
    }

}
