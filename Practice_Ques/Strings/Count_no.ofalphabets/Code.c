/*Write a program in C to count total number of alphabets, digits and special characters in a string.*/

#include<stdio.h>
#include<string.h>

int main(){
    char str[30];
    int alp=0, num=0, spch=0, i=0;

    printf("Enter the String:\n");
    fgets(str,30,stdin);
    while(str[i] != '\0')
    {
        if((str[i]>= 'a' && str[i] <= 'z') || (str[i]>= 'A' && str[i] <= 'Z'))
        {
            alp++;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            num++;
        }
        else 
        {
            spch++;
        }
        i++;
    }

    printf("The number of alphabets are: %d \n", alp);
    printf("The number of digits are: %d \n", num);
    printf("The number of special characters are: %d ",spch);



    return 0;
}