#include<iostream>
using namespace std;

void binaryRepresentation(int n){
    if(n > 1){
        binaryRepresentation(n / 2);

    }

    cout << n % 2;
}

int main(){
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    binaryRepresentation(n);

    return 0;
}
