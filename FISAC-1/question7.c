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

int is_palin(char str[100])
{
    int len, i = 0;
    while(str[i] != '\0')
        i++;
    len= i;

    for(i = 0; i < len/2; i++)
    {
        if (str[i] != str[len-1-i])
            return 0;
    }
    return 1;
}

int main()
{

     printf("------------------------------\n");
    printf("Registration Number: 210905298 (Manush Darji)\n");
    printf("------------------------------\n");
    node *list = NULL, *pslist = NULL, *npslist =NULL;
    int n;
    char str[100];

    printf("Enter Size of List: ");
    scanf("%d", &n);

    printf("Size: %d", n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d: ", i);
        scanf("%s", str);
        insert_end(&list, str);
    }
    display(list);


    for (int i = 0; i < n; i++ )
    {
        if (is_palin(value_at(list, i)))
            insert_end(&pslist, value_at(list, i));
        else
            insert_end(&npslist, value_at(list, i));
    }

    display(pslist);
    display(npslist);

    return 0;
}