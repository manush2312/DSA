#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct node
{
    int data;
    struct node *link;
};
void display(struct node *ptr)
{
    while(ptr)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->link;
    }
    
}
void main()
{


     printf("------------------------------\n");
    printf("Registration Number: 210905298 (Manush Darji)\n");
    printf("------------------------------\n");
    struct node *head, *prev, *p;
    struct node *h1, *prev1, *p1; h1=NULL;
    struct node *h2, *prev2, *p2; h2=NULL;
    int i, n;
    printf("enter number of elements: ");
    scanf("%d", &n);
    int odd[n],even[n]; int o=0,e=0;
    head = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &p->data);
        p->link = NULL;
        if (head == NULL)
            head = p;
        else
            prev->link = p;
        prev = p;
    }
    printf("orginal list: ");
    display(head);
    while(head)
    {
        if(head->data%2==0)
        {
            even[e]=pow(head->data,3);
            e++;
            head=head->link;
        }
        else
        {
            odd[o]=pow(head->data,3);
            o++;
            head=head->link;
        }
    }
    
    for (i = 0; i < e; i++)
    {
        p1 = malloc(sizeof(struct node));
        p1->data=even[i];
        p1->link = NULL;
        if (h1 == NULL)
            h1 = p1;
        else
            prev1->link = p1;
        prev1 = p1;
    }
    printf("\nLIST1: ");
    display(h1);
    
    for(i=0;i<o;i++)
    {
        p2 = malloc(sizeof(struct node));
        p2->data=odd[i];
        p2->link = NULL;
        if (h2 == NULL)
            h2 = p2;
        else
            prev2->link = p2;
        prev2 = p2;
    }
    printf("\nLIST2: ");
    display(h2);
}