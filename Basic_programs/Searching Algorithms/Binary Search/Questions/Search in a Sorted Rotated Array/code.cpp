// Search in a Sorted Rotated Array
// Given a sorted array of size "N", also given an integer "K". Now the array is rotated at some pivot point. For example the array is 
// arr[] = {1, 3, 5, 7, 8}. Then after rotating the array at index 3, the array will be arr[] = {7, 8, 1, 3, 5}.

#include<iostream>
using namespace std;

int getPivot(int arr[], int n){

    int s = 0, e = n-1;
    int mid = s + (e - s)/2;

    while(s < e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }else{
            e = mid;
        }

        mid = s + (e - s)/2;
    }

    return s;
}

int binarySearch(int arr[], int s, int e, int key){
    // s --> starting of the array to find a particular element
    // e --> ending of the array to find a particular element
    int mid = s + (e - s)/2;

    while(s <= e){
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid > key]){
            e = mid - 1;
        }
        if(arr[mid] < key){
            s = mid + 1;
        }

        mid = s + (e - s)/2;
    }
    return -1;  // element not present
}

int findPosition(int arr[], int n, int key){
    int pivot = getPivot(arr, n);

    if(key >= arr[pivot] && key <= arr[n-1]){

        return binarySearch(arr, pivot, n-1, key);   // binary search on first line

    }else{

        return binarySearch(arr, 0, pivot-1, key);   // binary search on second line

    }
}

int main(){

    int arr[] = {7, 8, 1, 3, 5};

    int answer = findPosition(arr, 5, 3);
    cout << "Position of the element is: " << answer << endl;

    return 0;
}