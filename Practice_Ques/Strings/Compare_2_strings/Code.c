/*Compare two strings without using library....*/

#include <stdio.h>

int test(char *str1, char *str2){
    int flag = 0; 
    while(*str1 != '\0' && *str2 != '\0')
    {
        if(*str1 == *str2)
        {
            str1++;
            str2++;
        }
        else if((*str1 == '\0' && *str2 != '\0') || (*str1 != '\0' && *str2 == '\0') || (*str1 != *str2))
        {
            flag = 1;
            break;
        }
    }

    return flag;
}


int main(){
    char str1[20], str2[20];
    printf("Enter the first string:\n");
    fgets(str1, 20, stdin);
    printf("Enter the second String\n");
    fgets(str2, 20, stdin);
    printf("The two string are:\n %s\n %s", str1, str2);

    int flg = test(str1, str2);

    if(flg == 0 )
    {
        printf("The Strings are equal\n");
    }else{
        printf("Strings are not equal.\n");
    }

    return 0;
}
