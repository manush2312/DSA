/*
We will be given an Array as an input and we need to move all the 0's to right side of the array.

Examples:- 
input :- {0, 1, 0, 3, 12}     output :- {1, 3, 12, 0, 0}
input :- {2, 0, 1, 3, 0, 0, 0}     output :- {2, 1, 3, 0, 0, 0, 0}
*/

#include<iostream>
using namespace std;

void moveZeroes(int arr[], int n){
    cout << "Im" ;
    int i=0;

    for(int j=0; i<n; j++){
        
        if(arr[j] != 0){
            swap(arr[j], arr[i]);
            i++;
        }
        
        
    }
}


int main(){
    int arr[10];
    int n;
    cout << "Enter the number of elements in an array: " ;
    cin >> n;

    cout << "Enter the elements: " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;

    moveZeroes(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i]<< " ";
    }

}