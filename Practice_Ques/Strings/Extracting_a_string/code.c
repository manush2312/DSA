// Extracting a substring from a string:

#include<stdio.h>

int main(){
    char str[20], sstr[20];
    int c=0 , pos , l;
    printf("--Enter the String: --\n");
    fgets(str,20,stdin);

    printf("Enter the position from where to start extracting:\n");
    scanf("%d",&pos);

    printf("Enter the length of Sub-String:\n");
    scanf("%d",&l);

    while(c < l)
    {
        sstr[c] = str[pos+c-1];
        c++;
    }

    printf("The substring is: %s", sstr);
    



    return 0;
}