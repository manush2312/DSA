#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char name[100];
    int roll, marks;
}info;

typedef struct
{
    info data;
    struct node *next;
}node;

void insert_end(node** head_ptr, info data)
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

void insert_at_front(node** head_ptr, info data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head_ptr;
    *head_ptr = new_node;
}

info value_at(node* head, int index)
{
    node* temp = head;

    for(int i = 0; i < index; i++)
        temp = temp->next;
    
    return temp->data;
}

void insert_at(node** head_ptr, info data, int index)
{
    
    if (index == 0)
    {
        insert_at_front(head_ptr, data);
        return;
    }
    
    node *temp, *new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    temp = *head_ptr;

    for(int i = 0; i < index-1; i++)
        temp = temp->next;

    new_node->next = temp->next;
    temp->next = new_node;

}

void display(node* head)
{
    node* temp = head;
    while (temp != NULL){
        printf("%d  ", temp->data.marks);
        temp = temp->next;
    }
    printf("\n");
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

node* insert_sort(node** head_ptr)
{
    node *temp, *c, *new_head = NULL;
    info data;
    int i, len;

    temp = *head_ptr;

    while(temp != NULL)
    {
        printf("Marks: %d\n", temp->data.marks);
        // For each element in original list
        data = temp->data;
        i = 0;
        len = length(new_head);
        while(i < len && value_at(new_head, i).marks > data.marks )
            i++;

        // i = (i > len) ? len: i;
        printf("Index %d\n", i);
        insert_at(&new_head, data, i);
        c = temp;
        temp = temp->next;    
        free(c);
    }

    return new_head;

}