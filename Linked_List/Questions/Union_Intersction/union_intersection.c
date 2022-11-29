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

int search(struct node* ll1, int n){
    struct node *temp = ll1;
    while(temp != NULL){
        if(temp->data == n){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void findUnion(struct node** ll1, struct node** ll2, struct node** unionlist){
    printf("Manush");
    // adding all nodes of ll1 to union list..
    struct node* temp = *ll1;
    while(temp != NULL){
        insert_at_tail(&unionlist, temp->data);
        temp = temp->next;
    }

    //inserting thode nodes of ll2 to union list which are not present in ll1.. 
    while(*ll2 != NULL){
        if(!search(ll1, (*ll2)->data)){
            insert_at_tail(&unionlist, (*ll2)->data);
        }
        (*ll2) = (*ll2)->next;
    }

    
}

int main(){
    struct node* ll1 = NULL; 
    struct node* ll2 = NULL;
    struct node* unionlist = NULL;
    struct node* intersection = NULL; 
    

    int n1,n2,data;
    printf("Enter the size of list1 and list2:");
    scanf("%d %d",&n1,&n2);

    printf("Enter the elements for list1:\n");
    for(int i=0; i<n1; i++){
        printf("Enter the data for %d node: ",(i+1));
        scanf("%d",&data);
        insert_at_tail(&ll1,data);
    }

    printf("Enter the elements for list2:\n");
    for(int i=0; i<n2; i++){
        printf("Enter the data for %d node: ",(i+1));
        scanf("%d",&data);
        insert_at_tail(&ll2,data);
    }
    //print(ll1);

    findUnion(&ll1, &ll2, &unionlist);
    print(unionlist);
    
}