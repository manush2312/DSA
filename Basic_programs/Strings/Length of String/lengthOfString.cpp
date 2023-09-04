#include<iostream>
using namespace std;

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

    int length = lengthOfString(name);

    cout << "Length of String is " << length << endl;

    return 0;
}