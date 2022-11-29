#include<stdio.h>
#include<stdlib.h>
int *stack, top=-1,n;

void push()
{
    int  num;
    if(n-top>1)
    {
        printf("Enter the element to be inserted:\n");
        scanf("%d",&num);
        top++;
        *(stack+top)=num;
    }else{
        printf("--STACK OVERFLOW--\n");
    }
}

void pop(){
    if(top>=0)
    {
        top--;
    }else{
        printf("--STACK UNDERFLOW--\n");
    }
}

void display(){
    if(top==-1)
    {
        printf("--EMPTY STACK--\n");
    }else{
        printf("STACK:\n");
        for(int i=top; i>=0; i--)
        {
            printf("%d\n",*(stack+i));
        }
    }
}

int main()
{
    int choice;
    printf("Enter the size of the stack:\n");
    scanf("%d",&n);
    stack=(int*)calloc(n,sizeof(int));
    printf("----The basic STACK OPERATION are:----\n");
    printf("1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT\n");

    do{
        
        printf("--Enter your choice:--\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("---Exiting---");
            }
            default :
            {
                printf("Enter a valid choice:\n");
                printf("1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT\n");
            }
        }



    }while(choice!=4);




    return 0;
}