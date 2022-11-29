// Sorting the String in ascending order:

#include<stdio.h>
#include<string.h>



int main()
{
    char str[20];
    int i=0;
    printf("Enter the string:\n");
    fgets(str,20,stdin);

    for(i=1; i<strlen(str); i++)
    {
        for(int j=1; j<(strlen(str))-i; j++)
        {
            if(str[j] > str[j+1])
            {
                char ch;
                ch = str[j];
                str[j] = str[j+1];
                str[j+1] = str[j];
            }
           
        }
        
    }

     printf("The string after sorting is:\n");
    printf("%s",str);

    



    return 0;
}