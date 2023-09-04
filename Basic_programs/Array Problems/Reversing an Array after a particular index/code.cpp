#include<iostream>
using namespace std;

void reverse(int arr[], int position, int n){
    int s = position, e = n-1;

    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main(){

    int arr[10], n, position;
    cout << "Enter the number of elements of array: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Array before reversal: " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }  
    cout << endl;

    cout << "Enter the position after which you want to reverse the array: " ;
    cin >> position;

    reverse(arr, position, n);

    cout << "Array after reversal: " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }  
    cout << endl;  

    


    return 0;
}