

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert(struct node** list, int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    if(*list == NULL){
        *list = new;
    }else{
        struct node* temp = *list;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
}

void display(struct node* head){
    while(head != NULL){
        printf("%d  ",head->data);
        head = head->next;
    }
    printf("\n");
}

void sorting(struct node** list){
    printf("MAnush");
    struct node* curr = *list;
    struct node* forward = NULL;
    struct node* temp;

    while(curr != NULL){
        forward = curr->next;
        if(curr->data > forward->data){
            temp->data = curr->data;
            curr->data = forward->data;
            forward->data = temp->data;
        }
        forward =forward->next;
        curr = curr->next;
    }

    
}

int main(){
    struct node* list = NULL;
    int n,data;
    printf("Enter the size of the linked list:");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter the data for %d node",(i+1));
        scanf("%d",&data);
        insert(&list,data);
    }

    printf("\nThe Linked List is:\n");
    display(list);

    sorting(&list);
    printf("Linked list after sorting is:\n");
    display(list);

}


