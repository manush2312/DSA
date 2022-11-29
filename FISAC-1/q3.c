#include <stdio.h>
#include <stdlib.h>
//----------------------
struct node
{
    int data;
    struct node *link;
};
//----------------------
void display(struct node *ptr,int n)
{
    int i=1;
    while (ptr->link != NULL)
    {
        if(i!=n) 
        {
            printf("%d ->", ptr->data);
            i++;
        }
        else
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
}
//----------------------
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
//----------------------
int main()
{

    printf("------------------------------\n");
    printf("Registration Number: 210905294\n");
    printf("------------------------------\n");

     struct node *prev,*head,*p;
    int n,i;
    printf ("enter n:");
    scanf("%d",&n);
    head=NULL;
    for(i=0;i<=n;i++)
    {
        p=malloc(sizeof(struct node));
        p->data=fib(i);
        p->link=NULL;
        if(head==NULL)
            head=p;
        else
            prev->link=p;
        prev=p;
    }
    display(head,n);
    free(head);
    return 0;
}