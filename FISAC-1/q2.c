/*Create a singly linked list. Create an exact copy of this list. Rotate the original list to the right k number times where k<= number of nodes in the list. 
Display the list. Now take the copy of the list rotate the list k number of times to the left where k<= number of nodes in the list . Display the modified lists. 
Sample Output:
Input k : 2
LIST: 3->4->5->6->7
Left rotate: 5->6->7->3->4 Right rotate: 6->7->3->4->5*/


#include <stdio.h>
#include <stdlib.h>
//-----------------------
struct node{
    int data;
    struct node*link;
};
//-----------------------
void display(struct node *ptr, int n)
{
    int i = 1;
    while (ptr)
    {
        if (i != n)
        {
            printf("%d ->", ptr->data);
            i++;
        }
        else
            printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
//-----------------------
struct node* shift(struct node *head, int k)
{
    struct node *p = head;
    int j = 1;
    while (j < k )
    {
        p = p->link;
        j++;
    }
    struct node *node_k = p;
    while (p->link != NULL)
        p = p->link;
    p->link = head;
    head = node_k->link;
    node_k->link = NULL;
    return (head);
}
//-----------------------
int main()
{

    printf("------------------------------\n");
    printf("Registration Number: 210905294\n");
    printf("------------------------------\n");

    struct node *head, *prev, *p;
    struct node *head2, *prev2, *p2;
    int i,n,k;
    printf("enter number of nodes: ");
    scanf("%d", &n);
    head = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        p2 = malloc(sizeof(struct node));
        printf("enter node: ");
        {scanf("%d", &p->data); p2->data=p->data;}
        p->link = NULL; p2->link=NULL;
        if (head == NULL)
            {head = p; head2=p2;}
        else
            {prev->link = p; prev2->link=p2;}
        prev = p;
        prev2=p2;
    }
    printf("LIST:");
    display(head,n);
    printf("\nenter k: ");
    scanf("%d",&k);
    if (k == 0 || k == n)
    {
        printf("Left rotate: ");
        display(head,n);
        printf("Right rotate: ");
        display(head,n);
    }
    else
    {
        head = shift(head, k);
        printf("Left rotate: ");
        display(head,n);
        printf("\nRight rotate: ");
        head2 = shift(head2, (n-k));
        display(head2,n);
    }
    return 0;
}