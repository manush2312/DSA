/*
A phrase is a palindrome, if after converting all uppercase into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include numbers and aplhabets.

Example: s = "A man, a plan, a canal: Panama"      output = True
*/

#include<iostream>
using namespace std;

bool is_validCharacter(char ch){

    if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ){
        return true;
    }

    return false;
     
}

char is_lowerCase(char ch){
    if( (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') ){
        return ch;
    }else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool check_palindrome(string a){
    int s = 0, e = a.length();

    while(s <= e){
        if(a[s] == a[e]){
            s++;
            e--;
        }else{
            return false;
        }
    }

    return true;
}

bool is_validPalindrome(string str){

    // remove unnecessary characters
    string temp = "";

    for (int j=0; j<str.length(); j++){
        if(is_validCharacter(str[j])){
            temp.push_back(str[j]);
        }
    }

    // convert all to lowercase
    for(int j=0; j<temp.length(); j++){
        temp[j] = is_lowerCase(temp[j]);
    }


    // checking palindrome or not
    return(check_palindrome(temp));

}

int main(){

    string str;
    cout << "Enter the String: " ;
    cin >> str;

    cout << str << endl;

    if(is_validPalindrome(str)){
        cout << "Yes, it is." << endl;
    }else{
        cout << "No, it is not." << endl;
    }

    

    return 0;
}