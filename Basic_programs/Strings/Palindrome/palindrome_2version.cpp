/*
Your are given a String "S", our task is to check if the string is palindrome or not. Consider only alphabets and numbers, ignore 
the symbols and whitespaces.

NOTE :- "S" is not case senditive.
*/
#include<iostream>
using namespace std;

int lengthOfString(char ch[]){
    int count = 0;
    for(int i=0; ch[i] != '\0'; i++){
        count++;
    }
    return count;
}

char toLowercase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int checkPalindrome(char ch[], int n){
    int s = 0, e = n-1;

    while(s <= e){
        // if( toLowercase(ch[s]) != toLowercase(ch[e]) ){
        //     return 0;
        // }else{
        //     s++;
        //     e--;
        // }

        if(!(ch[s] >= 'a' && ch[s] <= 'z')){
            s++;
        }
        else if(!(ch[e] >= 'a' && ch[e] <= 'z')){
            e--;
        }
        else if(ch[s] == ch[e]){
            s++;
            e--;
        }else{
            return 0;
        }

    }
    return 1;
}


int main(){
    char ch[10];
    cout << "Enter the String: ";
    cin >> ch;

    int length = lengthOfString(ch);

    bool ans = checkPalindrome(ch, length);

    if(ans){
        cout << "Yes it is " << endl;
    }else{
        cout << "NOO" << endl;
    }


    return 0;
}
