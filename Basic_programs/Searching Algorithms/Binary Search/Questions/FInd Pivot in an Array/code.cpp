// Find Pivot in an Array
// for details of the question refer to the notes

#include<iostream>
using namespace std;

int getPivot(int arr[], int n){
    int s = 0, e = n-1;
    int mid = s + (e - s)/2;

    while (s < e){
        if(arr[mid] >= arr[0]){  // lying on the first line..
            s = mid + 1;
        }else{
            e = mid;    // lying on the second line..
        }

        mid = s + (e - s)/2;

    }

    return s;
}

int main(){

    int arr[] = {8, 10, 17, 1, 3};

    cout << "Pivot element of the array is: " << getPivot(arr, 5) << endl;

}