#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_tail(struct node ** tail, int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if(*tail == NULL){
        newnode->next = newnode; // one element pointing to itself..
        *tail = newnode;
    }else{
        newnode->next = (*tail)->next;
        (*tail)->next = newnode;
        *tail = newnode;   
    }
}

void print(struct node *tail){
    struct node *head = tail->next;
    struct node *temp = head;
    printf("Printing the circular linked list\n: ");
    do{
        printf("%d  ",head->data);
        head = head->next;
    }while(head != temp);
}

int isCircular(struct node **tail){
    struct node* temp = (*tail)->next;

    while(temp != NULL && temp != *tail){
        temp = temp->next;
    }

    if(temp == *tail){
        return 1;
    }
    if(temp == NULL){
        return 0;
    }
}


int main(){
    struct node *tail = NULL;
    int n, data;
    printf("Enter the size of the list:\n");
    scanf("%d",&n);
    
    printf("Enter the elements for the list:\n");
    for(int i=0; i<n; i++){
        printf("Enter the data for %d node: ",(i+1));
        scanf("%d",&data);
        insert_at_tail(&tail, data);
    }

    print(tail);

    int circular = isCircular(&tail);

    if(circular == 1){
        printf("\nYes it is CIRCULAR.");
    }else{
        printf("\nNo it is NOT circular.");
    }
    
}