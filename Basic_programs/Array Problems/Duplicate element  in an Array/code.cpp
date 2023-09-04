// Duplicates in an array
// we have an array of size N, containing each number between 1 to N-1 at least once. There is a single integer value that is 
// present in the array twice. we have to find the duplicate integer.

#include<iostream>
using namespace std;

int duplicateElement(int arr[], int n){
    int ans = 0;

    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }

    for(int i=1; i<n; i++){
        ans = ans ^ i;
    }

    return ans;
}


int main(){
    
    int arr[] = {1,2,3,4,5,6,5};   // elements are from 1 to 6
    int n = 7;  
    int answer = duplicateElement(arr, n);

    cout << "Duplicate element is: " << answer << endl;

    return 0;
}