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

struct node* kreverse(struct node **head, int k){
    //struct node* temp = *head;
    if(*head == NULL){
        return NULL;
    }

    // step 1: reverse first "K" nodes-->
    struct node *prev = NULL;
    struct node *curr = *head;
    struct node *forward = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step 2: Recursion will do the rest..
    if(forward != NULL){
        (*head)->next = kreverse(&forward,k);
    }

    //step 3: Updating the head..
    return prev;
}

int main(){
    struct node *head = NULL;
    int n,k,data;
    printf("Enter the size of list:");
    scanf("%d",&n);

    printf("Enter the elements for the list:\n");
    for(int i=0; i<n; i++){
        printf("Enter the data for %d node: ",(i+1));
        scanf("%d",&data);
        insert_at_tail(&head,data);
    }

    print(head);

    printf("Enter the number of elements in group or K: ");
    scanf("%d",&k);
    struct node* newHead = kreverse(&head, k);
    printf("Printing the reversed linked list: ");
    print(newHead);

}