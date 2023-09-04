// Intersection of two arrays
// provided with two arrays and both of them are "SORTED" in "non-decreasing order".

#include<iostream>
using namespace std;



void Intersection(int arr[], int brr[], int n, int m){

    // this approach is called "2 Pointer Approach"

    int i=0, j=0;

    while(i<n && j<m){

        if(arr[i] == brr[j]){
            cout << arr[i];
            i++;
            j++;
        }
        else if (arr[i] < brr[j]){   // because os sorted array condition 
            i++;
        }
        else{
            j++;
        }
    }

}

int main(){
    int arr[] = {1,2,2,3,4,4,6};
    int brr[] = {2,2,3,3,4};

    Intersection(arr, brr, 7, 5);

    return 0;
}