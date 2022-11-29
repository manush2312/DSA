// reversing a string using array--->>


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 char str[15], stack[15];
 int top = -1;

 void push(char ch){
    if(20-top>1){
        top++;
        stack[top] = ch;
    }else{
        printf("---Stack Overflow---");
    }
 }

 void pop(){
    while(top>=0){
        char rev = stack[top];
        printf("%c",rev);   // printing every element of stack in reverse order
        top--;    
    }
 }


int main(){
   
    int i; 
    printf("Enter the string to be reversed:");
    fgets(str, 15, stdin);

    for(i=0; i<(strlen(str)); i++)  // pushing every element of string into stack 
    {
        char ch = str[i];
        push(str[i]);
    }

    pop();


    
    


    return 0;
}