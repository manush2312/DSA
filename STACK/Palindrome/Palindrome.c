


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,mid,top=-1;
char str[30],newstr[30], *stack;


void push(char c)
{
    if(n-top>1)
    {
        top++;
        *(stack+top)=c;
    }
}

void pop()
{
    if(top>=0)
    {
        top--;
    }else{
        printf("STACK UNDERFLOW\n");
    }
}

void compare(){
    for (int i=top; i>=0; i--)
    {
        newstr[i] = *(stack+i);
        pop();
    }
    printf("%s",newstr);
}



void display()
{

    
    for(int i=top; i>=0; i--)
    {
        printf("%c\n",*(stack+i));
    }
}

int main()
{
    int i;
    
    printf("Enter the string:\n");
    scanf("%s",str);
    n=strlen(str);
    mid = n/2;
    stack = (char*)calloc(n,sizeof(char));

    for(i=0; i<n; i++)
    {
        char c;
        c=str[i];
        push(c);
        
    }
    
    printf("Stack is:\n");
    display();

    compare();
    



    return 0;
}