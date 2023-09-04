#include<iostream>
using namespace std;

int lengthOfString(char name[]){
    int count = 0;
    for (int i=0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}


bool checkPalindrome(char str[], int n){
    int s = 0, e = n-1;
    while(s <= e){
        if(str[s] == str[e]){
            s++;
            e--;
        }else{
            return false;
        }
    }

    return true;
}


int main(){

    char str[10];
    cout << "Enter the string: " ;
    cin >> str;

    int length = lengthOfString(str);

    bool ans = checkPalindrome(str, length);
    if(ans){
        cout << "Yes the string is Palindrome." <<endl;
    }else{
        cout << "No it's not Palindrome." << endl;
    }


    return 0;
}