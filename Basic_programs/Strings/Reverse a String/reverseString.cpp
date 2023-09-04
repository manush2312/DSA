#include<iostream>
using namespace std;

void reverse(char name[], int n){
    int s = 0, e = n-1;
    while(s < e){
        swap(name[s], name[e]);
        s++;
        e--;
    }
}

int lengthOfString(char name[]){
    int count = 0;
    for (int i=0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}


int main(){

    char name[10];
    cout << "Enter your name: ";
    cin >> name;
    cout << endl;

    int length = lengthOfString(name);

    cout << "Length of String is " << length << endl;
    cout << endl;

    cout << "String after reversal is: " << endl;
    reverse(name, length);
    cout << name;

    return 0;
}