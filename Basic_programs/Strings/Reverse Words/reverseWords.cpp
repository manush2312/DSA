/*
input :  My name is Manush.
output : yM eman si hsunaM.
*/

#include<iostream>
using namespace std;

string wordReverse(string str){

    int s = 0, e = str.length()-1;

    while(s <= e){
        swap(str[s], str[e]);
        s++;
        e--;
    }

    return str;

}


string reverseWords(string s){
    string temp = "";
    string word = "";
    int k = 0;
    for(int i=0; i<s.length(); i++){

        // " k " will always start from 0 in every iteration for loop.

        //cout << "Value of K in " << i << "th round is " << k << endl;

        if (s[i] != ' ') {
            word += s[i];
        } else {
            temp = temp + wordReverse(word) + " ";
            word = "";   // clearing the string to store the next word of string
        }
    }   

    // Add the last word
    temp = temp + wordReverse(word);
    return temp;
}


int main(){

    string str = "My name is Manush";
    
    cout << "Original String: "<< str << endl;

    cout << "After reversing words: " << reverseWords(str)<< endl;
    


    return 0;
}