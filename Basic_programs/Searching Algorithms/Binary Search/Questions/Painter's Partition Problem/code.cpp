/* Painter's Partition Problem
Given an array "arr[]", and "K" painters. The array represents the boards and each element of given array represents the length of 
each board. To paint 1 unit of board, 1 unit of time is required. Painter can paint continous section of a board. Find minimum 
time to paint entire array.
*/

#include<iostream>
using namespace std;


bool isPossibleSolution(int arr[], int n, int k, int mid){

    int paintersCount = 1;
    int BoardLengthSum = 0;

    for(int i=0; i<n; i++){
        if(BoardLengthSum + arr[i] <= mid){
            BoardLengthSum = BoardLengthSum + arr[i];
        }else{
            paintersCount++;
            if(arr[i] > mid || paintersCount > k){
                return false;
            }

            BoardLengthSum = arr[i];
        }
    }

    return true;
}



int paintersPartition(int arr[], int n, int k){

    int s = 0, ans = -1, sum = 0;

    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    int e = sum;
    int mid = s + (e - s)/2;

    while(s <= e){
        if(isPossibleSolution(arr, n, k, mid)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }

    return ans;
}



int main(){
    
    int arr[] = {5, 5, 5, 5};
    int painters = 2;
    int answer = paintersPartition(arr, 4, 2);

    cout << "Minimum time to paint the entire Board is: " << answer << endl;

    return 0;
}