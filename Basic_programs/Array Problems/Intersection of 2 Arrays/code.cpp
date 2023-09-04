// Intersection of two arrays
// provided with two arrays and both of them are sorted in non-decreasing order.


// Note --> this solution is not optimized one

#include<iostream>
using namespace std;

void Intersection(int arr[], int brr[], int n, int m){
    
    for(int i=0; i<n; i++){
        int element = arr[i];

        for(int j=0; j<m; j++){
            if(element == brr[j]){
                cout << element << " ";
                brr[j] = INT_MIN; // updating the number that was matched 
                break;  
            }
        }
    }
}

int main(){
    int arr[] = {1,3,5,2,7,8,2};   // this both arrays are not in sorted order but in question they are in sorted manner
    int brr[] = {3,6,2,10,2,8};

    Intersection(arr, brr, 7, 6);

    return 0;
}