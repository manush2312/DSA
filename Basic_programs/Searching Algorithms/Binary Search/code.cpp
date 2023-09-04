// Binary Search

#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    
    int start = 0;
    int end = size-1;
    int mid = start + (end - start)/2;
    while(start <= end){

        if(arr[mid] == key){
            return mid;
        }

        // going to right part
        if(key > arr[mid]){
            start = mid + 1;
        }

        // going to left part
        if(key < arr[mid]){
            end = mid - 1;
        }

        // updating the mid 
        mid = start + (end - start)/2;

    }

    return -1;


}

int main(){

    int even[] = {2,4,6,8,12,18};  // sorted order
    int odd[] = {3,8,11,14,16};

    int evenanswer = binarySearch(even, 6, 12);

    if(evenanswer != -1){
        cout << "Element found at " << evenanswer <<endl;
    }else{
        cout << "Element not found" << endl;
    }

    int oddanswer = binarySearch(odd, 5, 8);

    if(oddanswer != -1){
        cout << "Element found at " << oddanswer <<endl;
    }else{
        cout << "Element not found" << endl;
    }



    return 0;
}