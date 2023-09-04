// Swapping of Alternate Elements
// input = {1,2,3,4,5,6}    output = {2,1,4,3,6,5}

#include<iostream>
using namespace std;

void swapAlternate(int arr[], int n){
    for(int i=0; i+1<n; i=i+2){
        swap(arr[i], arr[i+1]);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){

    int arr[6] = {1,2,3,4,5,6};
    int brr[5] = {2,4,6,8,10};

    swapAlternate(arr, 6);
    swapAlternate(brr, 5);

    printArray(arr, 6);
    printArray(brr, 5);


    return 0;
}