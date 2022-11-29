/* We have to split the input string in indilividual words like: 
INPUT: hello my name is manush
OUTPUT: 
hello 
my 
name
is
manush*/

#include<stdio.h>
#include<string.h>

int main(){
    char str[20], search[20];
    char newstr[10][10];
    int i=0, j=0, ctr = 0,count=0;
    printf("---Program to split a input string into spaces---");
    printf("\n------------------------------------\n");
    printf("Enter the input String:");
    gets(str);
    
    for( i=0; i<=(strlen(str)); i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            newstr[ctr][j] = '\0';
            ctr++;
            j=0;
        }else{
            newstr[ctr][j] = str[i];
            j++;
        }
    }

    printf("\nThe string seperated by spaces are:\n");
    for(i=0; i<ctr; i++)
    {
        printf("%s\n",newstr[i]);
    }

    printf("Enter the string or word to be searched:\n");
    fgets(search, 20, stdin);

    for(i=0; i<ctr; i++){
        if(strcmp(newstr[i],search)== 0)
        {
            count++;
            printf("heloo");
        }
    }
    printf("%d",count);
    return 0;

}

