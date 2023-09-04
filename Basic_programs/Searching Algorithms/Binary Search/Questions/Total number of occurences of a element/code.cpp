// total number of occurences of a element in an array
// given an array of size "N", in a sorted manner and we need to find the total number of occurences of an integer in that array.

#include<iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key){
    int s = 0, e = n-1, ans = -1;
    int mid = s + (e - s)/2;

    while(s <= e){
        if(arr[mid] == key){
           ans = mid;
           e = mid - 1;     
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }

        mid = s + (e - s)/2;
    }

    return ans;
}

int lastOccurence(int arr[], int n, int key){
    int s = 0, e = n-1, ans = -1;
    int mid = s + (e - s)/2;

    while(s <= e){
        if(arr[mid] == key){
           ans = mid;
           s = mid + 1;     
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }

        mid = s + (e - s)/2;
    }

    return ans;
}

int main(){

    int even[] = {1,2,3,3,3,5};
    int firstOccur = firstOccurence(even, 6, 3);
    int lastOccur = lastOccurence(even, 6, 3);

    int number = (lastOccur - firstOccur) + 1;   // formula to calculate number of occurences.. 

    cout << "NUmber of occurences of element is: " << number << endl;

}