#include<iostream>
using namespace std;

void reverse(int arr[], int n){
    int s = 0, e = n-1;
    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main(){
    int arr[10], n;
    cout << "Enter the number of elements in an array: " << endl;
    cin >> n;

    cout << "Enter the elements of array: " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Array before reversal: " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }  
    cout << endl;

    reverse(arr, n);

    cout << "Array after reversal: " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }  
    cout << endl;    

    
}